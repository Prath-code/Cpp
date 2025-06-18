#include <iostream>
using namespace std;

/*
    Constructor:-
        A constructor is a special
        member function of a class
        that is automatically called
        when an object of the class
        is created. It is used to
        initialize the object's
        data members.
*/

/*
    How to Create a Constructor:-
        1. The constructor has the
            same name as the class.
        2. It does not have a return type,
            not even void.
        3. It can have parameters, but
            it is not mandatory.
        4. It can be overloaded, meaning
            you can have multiple constructors
            with different parameters.
        5. It is called automatically
            when an object of the class
            is created.
        6. If no constructor is defined,
            the compiler provides a default
            constructor that does nothing.
        7. Constructors can be used to
            allocate resources, initialize
            data members, or perform any
            setup required for the object.
        8. If a class has a constructor,
            the compiler does not provide
            a default constructor unless
            you explicitly define one.
        9. Constructors can be used to
            enforce invariants or constraints
            on the object's state.
        10. Constructors can be used to
            initialize static members of the class.
*/

/*
    Types of Constructors:-
        1. Default Constructor: A constructor
            that takes no parameters.
        2. Parameterized Constructor: A constructor
            that takes parameters to initialize
            the object's data members.
*/

class Home
{
private:
    int id;
    string name;
    int age;

public:
    // Default Constructor
    Home()
    {
        cout << "Welcome to my Home!" << endl;
    }

    // Parameterized Constructor
    Home(int id, string name, int age)
    {
        this->id = id;
        this->name = name;
        this->age = age;

        cout << "Welcome to my Home!" << endl;

        this->getData();
    }
    void getData()
    {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class City
{
private:
    int id;
    string name;
    int age;
public:
    /*
        Our compiler will provide a
        empty default constructor
    */
};

int main()
{
    Home h1;                   // Default constructor
    Home h2(123, "Prath", 10); // Parameterized constructor

    City c1;

    return 0;
}
