#include <iostream>
using namespace std;

/*
    UDF => User Defined Function
*/

// Take nothing and return something(TNRS)

// Function prototyping
int calculate_sum();

int main()
{
    int sum = calculate_sum();
    cout << "The sum is: " << sum << endl;
    return 0;
}

// Function definition
int calculate_sum()
{
    int a, b;
    cout << "Enter value of a: ";
    cin >> a;
    cout << "Enter value of b: ";
    cin >> b;
    return a + b;
}
