#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Example {
private:
    int value;

public:
    Example(int value) {
        // Using 'this' to refer to the current object's member
        this->value = value;
    }

    void display() {
        cout << "Value: " << this->value << endl;
    }

    ~Example() {
        cout << "Example object destroyed." << endl;
    }
};

class Car {
private:
    string name;
    string model;
    string id;

public:
    Car(string name, string model, string id) {
        this->name = name;
        this->model = model;
        this->id = id;
    }

    void update(string name, string model, string id) {
        this->name = name;
        this->model = model;
        this->id = id;
    }

    void display() {
        cout << "Name: " << name << ", Model: " << model << ", ID: " << id << endl;
    }
};

void displayMenu();

int main() {
    // Dynamically allocating memory for the Example object
    Example* obj = new Example(42);
    obj->display();

    // Deleting the dynamically allocated object
    delete obj;

    vector<Car*> cars;
    int choice;

    do {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name, model, id;
            cout << "Enter car name: ";
            cin >> name;
            cout << "Enter car model: ";
            cin >> model;
            cout << "Enter car ID: ";
            cin >> id;
            cars.push_back(new Car(name, model, id));
            break;
        }
        case 2: {
            int index;
            string name, model, id;
            cout << "Enter car index to update: ";
            cin >> index;
            if (index >= 0 && index < cars.size()) {
                cout << "Enter new car name: ";
                cin >> name;
                cout << "Enter new car model: ";
                cin >> model;
                cout << "Enter new car ID: ";
                cin >> id;
                cars[index]->update(name, model, id);
            } else {
                cout << "Invalid index!\n";
            }
            break;
        }
        case 3: {
            int index;
            cout << "Enter car index to delete: ";
            cin >> index;
            if (index >= 0 && index < cars.size()) {
                delete cars[index];
                cars.erase(cars.begin() + index);
            } else {
                cout << "Invalid index!\n";
            }
            break;
        }
        case 4: {
            for (Car* car : cars) {
                delete car;
            }
            cars.clear();
            cout << "All cars deleted.\n";
            break;
        }
        case 5: {
            int index;
            cout << "Enter car index to view: ";
            cin >> index;
            if (index >= 0 && index < cars.size()) {
                cars[index]->display();
            } else {
                cout << "Invalid index!\n";
            }
            break;
        }
        case 6: {
            for (int i = 0; i < cars.size(); ++i) {
                cout << "Car " << i << ":\n";
                cars[i]->display();
            }
            break;
        }
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    // Clean up dynamically allocated memory
    for (Car* car : cars) {
        delete car;
    }

    return 0;
}

void displayMenu() {
    cout << "+----------------------------+\n";
    cout << "|     Car Management Menu    |\n";
    cout << "+----------------------------+\n";
    cout << "| 1. Add Car                 |\n";
    cout << "| 2. Update Car              |\n";
    cout << "| 3. Delete Car              |\n";
    cout << "| 4. Delete All Cars         |\n";
    cout << "| 5. View Car                |\n";
    cout << "| 6. View All Cars           |\n";
    cout << "| 0. Exit                    |\n";
    cout << "+----------------------------+\n";
}

