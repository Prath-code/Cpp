#include <iostream>
#include <string>
using namespace std;

/*
    Destructor:-
    A destructor is a special member
    function that is called when an
    object of a class goes out of
    scope or is explicitly deleted.
*/

class Home {
private:
    string address;
    int rooms;

public:
    Home(string addr = "Unknown", int rm = 0)
        : address(addr), rooms(rm) {
        cout << "Home created!" << endl;
    }

    ~Home() {
        cout << "Home destroyed!" << endl;
    }

    const string &getAddress() const {
        return address;
    }

    void display() const {
        cout << "Address: " << address << ", Rooms: " << rooms << endl;
    }

    void update(string newAddress, int newRooms) {
        address = newAddress;
        rooms = newRooms;
        cout << "Home updated!" << endl;
    }
};

void displayMenu() {
    cout << endl;
    cout << "+-------------------------------+" << endl;
    cout << "|            Menu               |" << endl;
    cout << "+-------------------------------+" << endl;
    cout << "| 1. Create Home                |" << endl;
    cout << "| 2. View All Homes             |" << endl;
    cout << "| 3. Update Home by Address     |" << endl;
    cout << "| 4. Delete Home by Address     |" << endl;
    cout << "| 5. Delete All Homes           |" << endl;
    cout << "| 6. View Home by Address       |" << endl;
    cout << "| 0. Exit                       |" << endl;
    cout << "+-------------------------------+" << endl;
    cout << "Enter your choice: ";
}

Home *findHomeByAddress(Home *homes[], int count, const string &address) {
    for (int i = 0; i < count; ++i) {
        if (homes[i] && homes[i]->getAddress() == address) {
            return homes[i];
        }
    }
    return NULL;
}

int findHomeIndexByAddress(Home *homes[], int count, const string &address) {
    for (int i = 0; i < count; ++i) {
        if (homes[i] && homes[i]->getAddress() == address) {
            return i;
        }
    }
    return -1;
}

void viewAllHomes(Home *homes[], int count) {
    bool any = false;
    for (int i = 0; i < count; ++i) {
        if (homes[i]) {
            homes[i]->display();
            any = true;
        }
    }
    if (!any) {
        cout << "No homes to display." << endl;
    }
}

void deleteAllHomes(Home *homes[], int &count) {
    for (int i = 0; i < count; ++i) {
        if (homes[i]) {
            delete homes[i];
            homes[i] = NULL;
        }
    }
    count = 0;
    cout << "All homes deleted." << endl;
}

int main() {
    const int MAX_HOMES = 100;
    Home *homes[MAX_HOMES];
    for (int i = 0; i < MAX_HOMES; i++) {
        homes[i] = NULL;
    }

    int homeCount = 0;
    int choice;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore();

        string address, newAddress;
        int rooms;

        switch (choice) {
        case 1:
            if (homeCount < MAX_HOMES) {
                cout << "Enter address: ";
                getline(cin, address);
                cout << "Enter number of rooms: ";
                cin >> rooms;
                cin.ignore();
                homes[homeCount++] = new Home(address, rooms);
            } else {
                cout << "Home storage full." << endl;
            }
            break;

        case 2:
            viewAllHomes(homes, homeCount);
            break;

        case 3:
            cout << "Enter address of home to update: ";
            getline(cin, address);
            {
                Home *home = findHomeByAddress(homes, homeCount, address);
                if (home) {
                    cout << "Enter new address: ";
                    getline(cin, newAddress);
                    cout << "Enter new number of rooms: ";
                    cin >> rooms;
                    cin.ignore();
                    home->update(newAddress, rooms);
                } else {
                    cout << "Home not found." << endl;
                }
            }
            break;

        case 4:
            cout << "Enter address of home to delete: ";
            getline(cin, address);
            {
                int index = findHomeIndexByAddress(homes, homeCount, address);
                if (index != -1) {
                    delete homes[index];
                    homes[index] = homes[homeCount - 1];
                    homes[homeCount - 1] = NULL;
                    homeCount--;
                    cout << "Home deleted." << endl;
                } else {
                    cout << "Home not found." << endl;
                }
            }
            break;

        case 5:
            deleteAllHomes(homes, homeCount);
            break;

        case 6:
            cout << "Enter address to view: ";
            getline(cin, address);
            {
                Home *home = findHomeByAddress(homes, homeCount, address);
                if (home) {
                    home->display();
                } else {
                    cout << "Home not found." << endl;
                }
            }
            break;

        case 0:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice." << endl;
        }

    } while (choice != 0);

    deleteAllHomes(homes, homeCount);
    return 0;
}
