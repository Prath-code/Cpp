#include <iostream>
using namespace std;

int main()
{
    int a, b, c;

    cout << "Enter the value of a: ";
    cin >> a;

    cout << "Enter the value of b: ";
    cin >> b;

    cout << "Enter the value of c: ";
    cin >> c;

    if (a > b && a > c)
    {
        cout << "Value of a: " << a << " is the greatest." << endl;
    }
    else if (b > a && b > c)
    {
        cout << "Value of b: " << b << " is the greatest." << endl;
    }
    else if (c > a && c > b)
    {
        cout << "Value of c: " << c << " is the greatest." << endl;
    }
    else if (a == b && a == c)
    {
        cout << "All values are equal: a = b = c = " << a << endl;
    }
    else if (a == b && a > c)
    {
        cout << "Value of a and b: " << a << " are the greatest, while c: " << c << " is lesser." << endl;
    }
    else if (a == c && a > b)
    {
        cout << "Value of a and c: " << a << " are the greatest, while b: " << b << " is lesser." << endl;
    }
    else if (b == c && b > a)
    {
        cout << "Value of b and c: " << b << " are the greatest, while a: " << a << " is lesser." << endl;
    }
    else
    {
        cout << "There is no single greatest value among a, b, and c." << endl;
    }
    
}