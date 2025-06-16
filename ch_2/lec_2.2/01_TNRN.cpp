#include <iostream>
#include <iomanip>
using namespace std;

/*
    UDF => User Defined Function
*/

// Take nothing and return nothing(TNRN)

// Function prototyping
void display_menu();

int main()
{
    string food;

    while (1)
    {
        display_menu();

        cout << "Enter the food item you want to order: ";
        cin >> food;
        cout << endl;

        if (food == "Burger" || food == "burger" || food == "BURGER" || food == "1")
        {
            cout << setw(20) << left << "You ordered a Burger." << endl;
        }
        else if (food == "Fries" || food == "fries" || food == "FRIES" || food == "2")
        {
            cout << setw(20) << left << "You ordered Fries." << endl;
        }
        else if (food == "Soda" || food == "soda" || food == "SODA" || food == "3")
        {
            cout << setw(20) << left << "You ordered a Soda." << endl;
        }
        else if (food == "Exit" || food == "exit" || food == "EXIT" || food == "4")
        {
            cout << setw(20) << left << "Exiting the program." << endl;
            break;
        }
        else if (food == "1")
        {
            cout << "You ordered a Burger." << endl;
        }
        else if (food == "2")
        {
            cout << "You ordered Fries." << endl;
        }
        else if (food == "3")
        {
            cout << "You ordered a Soda." << endl;
        }
        else if (food == "4")
        {
            cout << "Exiting the program." << endl;
            break;
        }
        else if (food == "Burger")
        {
            cout << "You ordered a Burger." << endl;
        }
        else if (food == "Fries")
        {
            cout << "You ordered Fries." << endl;
        }
        else if (food == "Soda")
        {
            cout << "You ordered a Soda." << endl;
        }
        else if (food == "Exit")
        {
            cout << "Exiting the program." << endl;
            break;
        }
        else if (food == "burger")
        {
            cout << "You ordered a Burger." << endl;
        }
        else if (food == "fries")
        {
            cout << "You ordered Fries." << endl;
        }
        else if (food == "soda")
        {
            cout << "You ordered a Soda." << endl;
        }
        else if (food == "exit")
        {
            cout << "Exiting the program." << endl;
            break;
        }
        else if (food == "BURGER")
        {
            cout << "You ordered a Burger." << endl;
        }
        else if (food == "FRIES")
        {
            cout << "You ordered Fries." << endl;
        }
        else if (food == "SODA")
        {
            cout << "You ordered a Soda." << endl;
        }
        else if (food == "EXIT")
        {
            cout << "Exiting the program." << endl;
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

// definition of function
void display_menu()
{
    cout << endl
         << "+-----------------------------+" << endl;
    cout << "|        FAST FOOD MENU       |" << endl;
    cout << "+-----+-------------+---------+" << endl;
    cout << "| No. | Item        | Price   |" << endl;
    cout << "+-----+-------------+---------+" << endl;

    cout << "| " << setw(3) << left << "1." << " | "
         << setw(11) << left << "Burger" << " | "
         << setw(7) << right << "$4.99" << " |" << endl;

    cout << "| " << setw(3) << left << "2." << " | "
         << setw(11) << left << "Fries" << " | "
         << setw(7) << right << "$2.49" << " |" << endl;

    cout << "| " << setw(3) << left << "3." << " | "
         << setw(11) << left << "Soda" << " | "
         << setw(7) << right << "$1.50" << " |" << endl;

    cout << "| " << setw(3) << left << "4." << " | "
         << setw(11) << left << "Exit" << " | "
         << setw(7) << right << "" << " |" << endl;

    cout << "+-----------------------------+" << endl
         << endl;
}
