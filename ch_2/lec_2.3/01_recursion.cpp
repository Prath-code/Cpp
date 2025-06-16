#include <iostream>
using namespace std;

// Recursion => A function that calls itself

// Function prototyping
int factorial(int n);

int main()
{
    int num;
    cout << "Enter a number to calculate its factorial: ";
    cin >> num;

    if (num <= 0)
    {
        num = 1;
        
        int result = factorial(num);
        cout << "The factorial of " << num << " is: " << result << endl;
    }
    else
    {
        int result = factorial(num);
        cout << "The factorial of " << num << " is: " << result << endl;
    }

    return 0;
}

int factorial(int n)
{
    // Base case
    if (n == 0 || n == 1)
    {
        return 1;
    }
    // Recursive case
    return n * factorial(n - 1);
}
