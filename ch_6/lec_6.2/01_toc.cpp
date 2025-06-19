#include <iostream>
#include <limits>
using namespace std;

/*
    Types of Constructors:
        1. Copy Constructor: A constructor that
            creates a new object as a copy of an
            existing object.
*/

class Points;
void displayMenu();
void process(int choice);

class Points
{
private:
    int p1, p2;

    void comparePoints() const
    {
        cout << "p1: " << p1 << ", p2: " << p2 << endl;
        cout << endl;
        if (p1 > p2)
            cout << "p1 is greater than p2" << endl;
        else if (p1 < p2)
            cout << "p1 is less than p2" << endl;
        else
            cout << "p1 is equal to p2" << endl;
    }

public:
    Points(int n1, int n2) : p1(n1), p2(n2)
    {
        cout << "Parameterized Constructor Called" << endl;
        comparePoints();
    }

    Points()
    {
        cout << "Default Constructor Called" << endl;
        cout << "Enter the value of p1: ";
        cin >> p1;
        cout << "Enter the value of p2: ";
        cin >> p2;
        comparePoints();
    }

    Points(const Points &other)
    {
        cout << "Copy Constructor Called" << endl;
        p1 = other.p1;
        p2 = other.p2;
        comparePoints();
    }
};

void displayMenu()
{
    int choice;
    do
    {
        cout << "\nMENU\n";
        cout << "1. Create Points with default constructor" << endl;
        cout << "2. Create Points with parameterized constructor" << endl;
        cout << "3. Create Points using copy constructor" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number." << endl;
            continue;
        }

        process(choice);
    } while (choice != 0);
}

void process(int choice)
{
    switch (choice)
    {
    case 1:
    {
        Points p1;
        break;
    }
    case 2:
    {
        int n1, n2;
        cout << "Enter the value of p1: ";
        cin >> n1;
        cout << "Enter the value of p2: ";
        cin >> n2;
        Points p2(n1, n2);
        break;
    }
    case 3:
    {
        int n1, n2;
        cout << "Enter the value of p1: ";
        cin >> n1;
        cout << "Enter the value of p2: ";
        cin >> n2;
        Points original(n1, n2);
        Points copy = original;
        break;
    }
    case 0:
        cout << "Exiting..." << endl;
        break;
    default:
        cout << "Invalid choice! Please try again." << endl;
    }
}

int main()
{
    displayMenu();
    return 0;
}
