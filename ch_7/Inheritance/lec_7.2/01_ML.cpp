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

// Multilevel Inheritance

class A
{
public:
    int a;
    A()
    {
        cout << "Enter value of a: ";
        cin >> a;
    }
};

class B : public A
{
public:
    int b;
    B()
    {
        cout << "Enter value of b: ";
        cin >> b;
    }
};

class C : public B
{
public:
    int c;
    C()
    {
        c = a + b;
        cout << "a(" << a << ") + b(" << b << ") = c(" << c << ")" << endl;
    }
};

int main()
{
    C o1;
    cout << "Value of a: " << o1.a << endl;
    cout << "Value of b: " << o1.b << endl;
    cout << "Value of c: " << o1.c << endl;

    return 0;
}
