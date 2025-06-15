#include <iostream>
using namespace std;

/*
    SAE: Special Assignment Expression
        1. Chained Expression
        2. Embedded Expression
        3. Compound Expression
*/

int main()
{
    cout << "+----------------------------------+" << endl;
    cout << "|         SAE Premium Menu         |" << endl;
    cout << "+----------------------------------+" << endl;
    cout << "| Welcome to the Special Assignment|" << endl;
    cout << "| Expressions Showcase Experience! |" << endl;
    cout << "+----------------------------------+" << endl
         << endl;

    cout << "Starter: Chained Expression" << endl;
    cout << "--------------------------------" << endl;

    int a, b, c;
    cout << "Please enter a value for your base ingredient (a): ";
    cin >> a;

    c = a;
    a = b = c;

    cout << endl
         << "Chained Assignment Result" << endl;
    cout << "Your dish is crafted as:" << endl;
    cout << "  a = " << a << endl;
    cout << "  b = " << b << endl;
    cout << "  c = " << c << endl
         << endl;

    cout << "Main Course: Embedded Expression" << endl;
    cout << "-----------------------------------" << endl;

    int x, y, answer, e;
    cout << "Please enter the core value (x): ";
    cin >> x;

    cout << "Please enter the embedded spice (e): ";
    cin >> e;

    answer = x + (y = e);

    cout << endl
         << "Embedded Expression Result" << endl;
    cout << "Ingredients:" << endl;
    cout << "  x = " << x << endl;
    cout << "  y = " << y << "  (assigned from e)" << endl;
    cout << "Resulting Value (x + y): " << answer << endl
         << endl;

    cout << "Dessert: Compound Expression" << endl;
    cout << "-------------------------------" << endl;

    int m, n;
    cout << "Please enter first layer (m): ";
    cin >> m;

    cout << "Please enter second layer (n): ";
    cin >> n;

    m += n;

    cout << endl
         << "Compound Expression Result" << endl;
    cout << "Before mixing:" << endl;
    cout << "  m = " << m - n << ", n = " << n << endl;
    cout << "After applying (m += n):" << endl;
    cout << "  New m = " << m << endl
         << endl;

    cout << "+------------------------------------+" << endl;
    cout << "|                                    |" << endl;
    cout << "|   Thank you for dining with us     |" << endl;
    cout << "|   at the SAE Expression Menu!      |" << endl;
    cout << "|                                    |" << endl;
    cout << "+------------------------------------+" << endl;

    return 0;
}
