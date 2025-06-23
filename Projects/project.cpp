#include <iostream>      // standard input/output
#include <vector>        // stores list of products
#include <deque>         //visits
#include <list>          // order
#include <set>           // categories
#include <map>           // stock count
#include <string>        // string manipulation
#include <ctime>         // time manipulation
#include <unordered_set> // for unique product IDs
#include <unordered_map> // for customer data
#include <fstream>       // file operations
#include <sstream>       // string stream for parsing input
#include <algorithm>     // for find_i =f
#include <limits>       // for numeric limits

using namespace std;

class Customer {
public:
    string customerID, name, email, address;
    Customer(const string &id = "", const string &n = "", const string &e = "", const string &a = "")
        : customerID(id), name(n), email(e), address(a) {}
};

class Product {
public:
    int productID;
    string name, category;
    Product(int id = 0, const string &n = "", const string &c = "") : productID(id), name(n), category(c) {}
};

class Order {
public:
    int orderID, productID, quantity;
    string customerID;
    time_t orderDate;
    Order(int oid, int pid, int qty, const string &cid, time_t date)
        : orderID(oid), productID(pid), quantity(qty), customerID(cid), orderDate(date) {}
};

void loadCustomers(unordered_map<string, Customer> &customerData, const string &filename) {
    ifstream infile(filename);
    string line;
    while (getline(infile, line)) {
        stringstream ss(line);
        string id, name, email, address;
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, email, ',');
        getline(ss, address);
        customerData[id] = Customer(id, name, email, address);
    }
}

void saveCustomers(const unordered_map<string, Customer> &customerData, const string &filename) {
    ofstream outfile(filename);
    for (const auto &entry : customerData) {
        outfile << entry.second.customerID << "," << entry.second.name << ","
                << entry.second.email << "," << entry.second.address << "\n";
    }
}

int main() {
    vector<Product> products = {
        {101, "Laptop", "Electronics"}, {102, "SmartPhone", "Electronics"}, {103, "Coffee Maker", "Kitchen"},
        {104, "Blender", "Kitchen"}, {105, "Desk lamp", "Home"}, {106, "Headphones", "Electronics"},
        {107, "Microwave", "Kitchen"}, {108, "Office Chair", "Furniture"}, {109, "Backpack", "Accessories"},
        {110, "Water Bottle", "Accessories"}, {111, "Monitor", "Electronics"}, {112, "Keyboard", "Electronics"},
        {113, "Mouse", "Electronics"}, {114, "Printer", "Electronics"}, {115, "Toaster", "Kitchen"},
        {116, "Sofa", "Furniture"}, {117, "Bookshelf", "Furniture"}, {118, "Table Lamp", "Home"},
        {119, "Curtains", "Home"}, {120, "Wall Clock", "Home"}, {121, "Shoes", "Fashion"},
        {122, "Jacket", "Fashion"}, {123, "Sunglasses", "Accessories"}, {124, "Watch", "Accessories"},
        {125, "Fitness Tracker", "Electronics"}, {126, "Camera", "Electronics"}, {127, "Tripod", "Electronics"},
        {128, "Mixer Grinder", "Kitchen"}, {129, "Rice Cooker", "Kitchen"}, {130, "Bed Sheet", "Home"},
    };

    deque<string> recentCustomers = {"C000001"};
    list<Order> orderHistory;
    cout << "Available products:\n";
    for (const auto &p : products)
        cout << p.productID << ": " << p.name << " (" << p.category << ")\n";

    products.clear();
    int n;
    cout << "Enter number of products: ";
    cin >> n;

    unordered_set<int> uniqueProductIDs;
    for (int i = 0; i < n; ++i) {
        int id;
        string name, category;
        cout << "Enter product ID: ";
        cin >> id;
        if (uniqueProductIDs.count(id)) {
            cout << "Duplicate ID. Try again.\n";
            --i;
            continue;
        }
        uniqueProductIDs.insert(id);
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Category: ";
        getline(cin, category);
        products.emplace_back(id, name, category);
    }

    set<string> categories;
    for (const auto &product : products)
        categories.insert(product.category);

    map<int, int> productStock;
    cout << "Enter stock for each product (ID stock):\n";
    for (const auto &product : products) {
        int stock;
        cout << product.productID << ": ";
        cin >> stock;
        productStock[product.productID] = stock;
    }

    int orderCount;
    cout << "\nEnter number of orders: ";
    cin >> orderCount;

    for (int i = 0; i < orderCount; ++i) {
        int orderID, productID, quantity;
        string customerID;
        cout << "Order " << i + 1 << ":\nOrder ID: ";
        cin >> orderID;
        cout << "Customer ID: ";
        cin >> customerID;
        cout << "Product ID: ";
        cin >> productID;
        cout << "Quantity: ";
        cin >> quantity;
        time_t now = time(0);
        orderHistory.emplace_back(orderID, productID, quantity, customerID, now);
    }

    multimap<string, Order> customerOrders;
    for (const auto &order : orderHistory)
        customerOrders.insert({order.customerID, order});

    unordered_map<string, Customer> customerData;
    loadCustomers(customerData, "customers.txt");

    if (!recentCustomers.empty())
        cout << "Your customer ID is: " << recentCustomers.front() << endl;

    string oldID, newID;
    char choice;
    cout << "\nDo you want to change a customer ID? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        cout << "Enter existing customer ID: ";
        cin >> oldID;
        if (customerData.find(oldID) != customerData.end()) {
            cout << "Enter new customer ID: ";
            cin >> newID;
            if (customerData.find(newID) != customerData.end()) {
                cout << "Error: New customer ID already exists.\n";
            } else {
                Customer cust = customerData[oldID];
                cust.customerID = newID;
                customerData.erase(oldID);
                customerData[newID] = cust;

                auto range = customerOrders.equal_range(oldID);
                vector<Order> tempOrders;
                for (auto it = range.first; it != range.second; ++it) {
                    Order updatedOrder = it->second;
                    updatedOrder.customerID = newID;
                    tempOrders.push_back(updatedOrder);
                }
                customerOrders.erase(oldID);
                for (const auto &o : tempOrders)
                    customerOrders.insert({newID, o});

                for (auto &cid : recentCustomers)
                    if (cid == oldID) cid = newID;

                saveCustomers(customerData, "customers.txt");
                cout << "Customer ID successfully changed from " << oldID << " to " << newID << ".\n";
            }
        } else {
            cout << "Customer ID not found.\n";
        }
    }

    ofstream custProdFile("customer_products.txt");
    if (!custProdFile) {
        cerr << "Error: Could not create customer_products.txt" << endl;
        return 1;
    }

    unordered_map<string, vector<int>> customerProductIDs;
    for (const auto &order : orderHistory)
        customerProductIDs[order.customerID].push_back(order.productID);

    unordered_map<int, Product> productMap;
    for (const auto &p : products)
        productMap[p.productID] = p;

    cout << "\nProducts bought by each customer:\n";
    for (const auto &entry : customerProductIDs) {
        cout << "Customer ID: " << entry.first << "\nProducts: ";
        custProdFile << entry.first << ": ";
        for (int pid : entry.second) {
            auto it = productMap.find(pid);
            if (it != productMap.end()) {
                cout << it->second.name << " (" << it->second.category << "), ";
                custProdFile << it->second.name << " (" << it->second.category << "), ";
            }
        }
        cout << endl;
        custProdFile << endl;
    }
    custProdFile.close();

    cout << "\nCustomer IDs in the system:\n";
    for (const auto &entry : customerData)
        cout << entry.first << endl;

    if (choice != 'y' && choice != 'Y')
        cout << "You chose not to change the customer ID.\n";

    string queryID;
    cout << "Enter customer ID to view their purchased products: ";
    cin >> queryID;

    ifstream inFile("customer_products.txt");
    if (!inFile) {
        cerr << "Error: Could not open customer_products.txt" << endl;
        return 1;
    }

    cout << "Your customer ID is: " << queryID << endl;
    string line;
    bool found = false;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string idPart;
        if (getline(ss, idPart, ':') && idPart == queryID) {
            string productInfo;
            getline(ss, productInfo);
            cout << "Products for customer " << queryID << ": " << productInfo << endl;
            found = true;
            break;
        }
    }
    if (!found)
        cout << "No products found for customer ID: " << queryID << endl;

    return 0;
}
