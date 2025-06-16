#include <iostream>
using namespace std;

/*
    UDF => User Defined Function
*/

// Take something and return something(TSRS)

// Function prototyping

int cube(int a);

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    int cube_num = cube(num);
    cout << "The cube of " << num << " is: " << cube_num << endl;
    return 0;
}

int cube(int a)
{
    return a * a * a;
}
