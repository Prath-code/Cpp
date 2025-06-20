#include <iostream>
using namespace std;

/*
    Inheritance => Passing a data from one class
                    to another
*/

/*`
    Types of inheritance:
        1. Single Inheritance
        2. Multiple Inheritance
        3. Hierarchical Inheritance
        4. Multilevel Inheritance
        5. Hybrid Inheritance
*/

/*
    Types of class inheritance:
    1. Parent class
        - Super class
        - Base class
    2. Child class
        - Sub class
        - Derived class
*/

/*
    Access specifiers:
    1. Public
    2. Private
    3. Protected
*/

// Hierarchical Inheritance

class movie {
private:
    string name;
    string favourite;
    string director;

public:
    movie() {
        name = "Unknown";
        favourite = "Unknown";
        director = "Unknown";

        cout << "Movie details are unknown.\n";
        if (getYesOrNo("Want to set them? (yes/no): ")) {
            cout << "Enter movie name: ";
            getline(cin, name);
            cin.ignore();

            cout << "Is it favourite (yes/no, press Enter to skip): ";
            getline(cin, favourite);
            if (favourite.empty()) favourite = "Unknown";

            cout << "Enter director (optional, press Enter to skip): ";
            getline(cin, director);
            if (director.empty()) director = "Unknown";
        }

        if (getYesOrNo("Want to display them? (yes/no): ")) {
            display();
        }
    }

    void display() const {
        cout << "Movie Name: " << name << endl;
        cout << "Favourite: " << favourite << endl;
        cout << "Director: " << director << endl;
    }

private:
    bool getYesOrNo(const string& prompt) {
        string input;
        cout << prompt;
        cin >> input;
        return input == "yes" || input == "Yes" || input == "YES" || input == "y" || input == "Y";
    }
};

class hollywood : public movie {
public:
    hollywood() {
        cout << "Hollywood movie created." << endl;
    }

    void displayDetails() {
        cout << "Hollywood Movie Details:" << endl;
        display();
    }
};

class bollywood : public movie {
public:
    bollywood() {
        cout << "Bollywood movie created." << endl;
    }

    void displayDetails() {
        cout << "Bollywood Movie Details:" << endl;
        display();
    }
};

class custom : public movie {
public:
    custom() {
        cout << "Custom movie created." << endl;
    }

    void displayDetails() {
        cout << "Custom Movie Details:" << endl;
        display();
    }
};

int main() {
    cout << "Choose movie category (1 = Hollywood, 2 = Bollywood, 3 = Custom): ";
    int choice;
    cin >> choice;

    switch (choice) {
        case 1: {
            hollywood h;
            h.displayDetails();
            break;
        }
        case 2: {
            bollywood b;
            b.displayDetails();
            break;
        }
        case 3: {
            custom c;
            c.displayDetails();
            break;
        }
        default:
            cout << "Invalid category." << endl;
    }

    return 0;
}
