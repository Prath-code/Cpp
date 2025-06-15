#include <iostream>
using namespace std;

/*
    Reference Variables = Alias Name / nickname of another Variable
*/

int main()
{
    cout << "+-----------------------------------+" << endl;
    cout << "|         Reference Variables       |" << endl;
    cout << "+-----------------------------------+" << endl;
    cout << "| Welcome to the Reference Variables|" << endl;
    cout << "| Showcase Experience!              |" << endl;
    cout << "+-----------------------------------+" << endl
         << endl;

    int originalValue; // Original variable

    cout << "Enter an integer value: ";
    cin >> originalValue; // Input for the original variable

    int &refValue = originalValue; // Reference variable

    cout << "Original Value: " << originalValue << endl;
    cout << "Reference Value: " << refValue << endl;

    cout << "Modify Reference Value: ";
    cin >> refValue; // Modify the reference variable

    cout << "After modifying reference:" << endl;
    cout << "Original Value: " << originalValue << endl;
    cout << "Reference Value: " << refValue << endl;

    return 0;
}
