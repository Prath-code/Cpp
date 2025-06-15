#include <iostream>
using namespace std;

/*
    Type conversion
        1. Implicit Conversion
        2. Explicit Conversion
*/

int main()
{
    cout << "+----------------------------------+" << endl;
    cout << "|         Type Conversion          |" << endl;
    cout << "+----------------------------------+" << endl;
    cout << "| Welcome to the Type Conversion   |" << endl;
    cout << "| Showcase Experience!             |" << endl;
    cout << "+----------------------------------+" << endl
         << endl;

    cout << "Starter: Implicit Conversion" << endl;
    cout << "-----------------------------" << endl;

    int intValue ;

    cout << "Enter an integer value: ";
    cin >> intValue;

    double doubleValue = intValue; // Implicit conversion from int to double

    cout << "Implicit Conversion Result:" << endl;
    cout << "  intValue = " << intValue << endl;
    cout << "  doubleValue = " << doubleValue << endl
         << endl;

    cout << "Main Course: Explicit Conversion" << endl;
    cout << "-------------------------------" << endl;

    double anotherDouble = 3.14;
    int anotherInt = static_cast<int>(anotherDouble); // Explicit conversion from double to int

    cout << "Explicit Conversion Result:" << endl;
    cout << "  anotherDouble = " << anotherDouble << endl;
    cout << "  anotherInt = " << anotherInt << endl
         << endl;

    int num1, num2;
    cout << "Enter num1 number: ";
    cin >> num1;

    cout << "Enter num2 number: ";
    cin >> num2;

    cout << "You entered: " << num1 << " and " << num2 << endl;

    return 0;
}