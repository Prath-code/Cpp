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

// Hybrid Inheritance

class A
{
public:
    int a;

    A()
    {
        cout << "Enter value for a (Base class A): ";
        cin >> a;
    }
};

class B : public A
{
public:
    int b;

    B()
    {
        cout << "Enter value for b (Derived class B): ";
        cin >> b;
    }
};

class C : public A
{
public:
    int c;

    C()
    {
        cout << "Enter value for c (Base class C): ";
        cin >> c;
    }
};

class D : public B, public C
{
public:
    int d;

    D()
    {
        cout << "Enter value for d (Derived class D): ";
        cin >> d;

        cout << "Values are:" << endl;
        cout << "a: " << B::a << endl;
        cout << "b: " << b << endl;
        cout << "c: " << C::c << endl;
        cout << "d: " << d << endl;
        cout << "a(" << B::a << ") + b(" << b << ") + c(" << C::c << ") + d(" << d << ") = " << (B::a + b + C::c + d) << endl;
    }
};

int main()
{
    D obj;
    return 0;
}
