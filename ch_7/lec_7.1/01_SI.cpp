#include <iostream>
#include <iomanip>
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

// Single Inheritance

void getInput(int &a, int &b)
{
    while (true)
    {
        cout << "Enter Value of a: ";
        cin >> a;
        cout << "Enter Value of b: ";
        cin >> b;

        if (a < 0 || b < 0)
        {
            cerr << "Error: Negative values are not allowed. Please re-enter.\n";
        }
        else if (a == 0 || b == 0)
        {
            cerr << "Error: Zero values are not allowed. Please re-enter.\n";
        }
        else if (a < b)
        {
            cerr << "Error: a should be greater than b. Please re-enter.\n";
        }
        else
        {
            break;
        }
    }
}

// User-defined function to calculate square root
double sqrt_custom(double number)
{
    return number * number;
}

// User-defined function to calculate cube root
double cbrt_custom(double number)
{
    return number * number * number;
}

// User-defined function to calculate power
long long power_custom(int base, int exponent)
{
    long long result = 1;
    for (int i = 0; i < exponent; ++i)
    {
        result *= base;
    }
    return result;
}

class A
{
public:
    int a;
};

class B : public A
{
private:
    int b;

    void displayResults() const
    {
        cout << "Value of a: " << a << endl;
        cout << "Value of b: " << b << endl;
        cout << "Sum: " << a + b << endl;
        cout << "Difference: " << a - b << endl;
        cout << "Product: " << a * b << endl;
        cout << "Division: " << static_cast<double>(a) / b << endl;
        cout << "Modulus: " << a % b << endl;
        cout << "Power: " << fixed << setprecision(0) << power_custom(a, b) << endl;
        cout << "Square root of a: " << sqrt_custom(a) << endl;
        cout << "Square root of b: " << sqrt_custom(b) << endl;
        cout << "Cube root of a: " << cbrt_custom(a) << endl;
        cout << "Cube root of b: " << cbrt_custom(b) << endl;
    }

public:
    B()
    {
        getInput(a, b);
        displayResults();
    }
};

int main()
{
    B obj;
    return 0;
}
