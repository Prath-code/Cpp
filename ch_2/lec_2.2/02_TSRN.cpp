#include <iostream>
using namespace std;

/*
    UDF => User Defined Function
*/

// Take something and return nothing(TSRN)

void print_name(string name, int age);

int main()
{
    string name;
    int age;

    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your age: ";
    cin >> age;
    cout << endl;
    print_name(name, age);

    return 0;
}

void print_name(string name, int age)
{
    cout << "Hello, " << name << endl;
    cout << "You are " << age << " years old." << endl;
}
