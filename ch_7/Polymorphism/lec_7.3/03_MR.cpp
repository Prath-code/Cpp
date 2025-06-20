#include <iostream>
using namespace std;

/*
    Meaning of Polymorphism:

        1. Poly => Multiple
        2. Morphism => Behaviors

        Polymorphism
        => Multiple Behaviors
*/

/*
    Method Overriding:

        1. Multiple methods
            (2 or more methods)

        2. All methods name
            must be same

        3. Parameters must
            be same
        4. Multiple classes
            (2 or more classes)
        5. Inheritance is required
*/
class Class;
class SubClass;

int main()
{
    Class c;
    SubClass sc;

    Class* ptr;
    ptr = &c;
    ptr->display();

    ptr = &sc;
    ptr->display();

    return 0;
}
class Class
{
public:
    void display()
    {
        cout << "Display from Class" << endl;
    }
};
class SubClass : public Class
{
public:
    void display()
    {
        cout << "Display from SubClass" << endl;
    }
};
