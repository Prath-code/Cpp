#include <iostream>
#include <algorithm>
using namespace std;

/*
    Meaning of Polymorphism:

        1. Poly => Multiple
        2. Morphism => Behaviors

        Polymorphism
        => Multiple Behaviors
*/

/*
    Method Overloading:

        1. Multiple methods
            (2 or more methods)

        2. All methods name
            must be same

        3. Parameters must
            be different
*/

string to_lower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

class A {
public:
    void vehical() {
        string choice;
        cout << "Truck or car: ";
        cin >> choice;
        show_vehicle(choice);
    }

    void vehical(string choice) {
        show_vehicle(choice);
    }

private:
    void show_vehicle(string choice) {
        string lower_choice = to_lower(choice);
        if (lower_choice == "truck") {
            cout << "                    ______" << endl;
            cout << "                   |      \\" << endl;
            cout << "   _______________/        \\____" << endl;
            cout << "  |   _   _   _   |  [] []  |   \\" << endl;
            cout << "  |  | | | | | |  |         |    |" << endl;
            cout << "  |__|_|_|_|_|_|__|_________|____|" << endl;
            cout << " |                                 \\" << endl;
            cout << "[__]                             [__]" << endl;
            cout << " (O)                             (O)  (O)" << endl;
        } else if (lower_choice == "car") {
            cout << "        ______" << endl;
            cout << "       /|_||_\\`.__" << endl;
            cout << "      (   _    _ _\\ " << endl;
            cout << "      =`-(_)--(_)-'" << endl;
        } else {
            cout << "Invalid choice" << endl;
        }
    }
};

int main() {
    A obj;
    int choice;

    cout << "+------------------------------------+" << endl;
    cout << "|         VEHICLE MENU SYSTEM        |" << endl;
    cout << "+------------------------------------+" << endl;
    cout << "| 1. With parameter                  |" << endl;
    cout << "| 2. Without parameter               |" << endl;
    cout << "+------------------------------------+" << endl;
    cout << "| Enter your choice: ";
    cin >> choice;
    cout << "+------------------------------------+" << endl;

    switch (choice) {
    case 1: {
        string type;
        cout << "Truck or car: ";
        cin >> type;
        obj.vehical(type);
        break;
    }
    case 2:
        obj.vehical();
        break;
    default:
        cout << "Invalid choice" << endl;
    }

    return 0;
}
