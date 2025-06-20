#include <iostream>
#include <iomanip>
using namespace std;

/*
    Inheritance => Passing a data from one class
                    to another
*/

/*
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

// Multiple Inheritance

// Function to validate and get user input
void getInput(int &a, int &b) {
    while (true) {
        cout << "Enter Value of a: ";
        cin >> a;
        cout << "Enter Value of b: ";
        cin >> b;

        if (a < 0 || b < 0) {
            cerr << "Error: Negative values are not allowed. Please re-enter.\n";
        } else if (a == 0 || b == 0) {
            cerr << "Error: Zero values are not allowed. Please re-enter.\n";
        } else if (a < b) {
            cerr << "Error: a should be greater than b. Please re-enter.\n";
        } else {
            break;
        }
    }
}

// User-defined function to calculate power
double power(double base, int exponent) {
    double result = 1;
    for (int i = 0; i < abs(exponent); ++i) {
        result *= base;
    }
    return (exponent < 0) ? 1 / result : result;
}

// User-defined function to calculate square root
double squareRoot(double num) {
    return num * num;
}

// User-defined function to calculate cube root
double cubeRoot(double num) {
    return num * num * num;
}

class A {
public:
    int a;
};

class B {
protected:
    int b;
};

class C : public A, public B {
private:
    void displayResults() const {
        cout << "Value of a: " << a << endl;
        cout << "Value of b: " << b << endl;
        cout << "Sum: " << a + b << endl;
        cout << "Difference: " << a - b << endl;
        cout << "Product: " << a * b << endl;
        cout << "Division: " << static_cast<double>(a) / b << endl;
        cout << "Modulus: " << a % b << endl;
        cout << "Power: " << fixed << setprecision(0) << power(a, b) << endl;
        cout << "Square root of a: " << squareRoot(a) << endl;
        cout << "Square root of b: " << squareRoot(b) << endl;
        cout << "Cube root of a: " << cubeRoot(a) << endl;
        cout << "Cube root of b: " << cubeRoot(b) << endl;
    }

public:
    C() {
        getInput(a, b);
        displayResults();
    }
};

int main() {
    C obj;
    return 0;
}
