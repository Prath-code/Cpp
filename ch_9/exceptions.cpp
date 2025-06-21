#include <iostream>
using namespace std;

/*
    Errors
        1. Occor by user/programmer
    
    Exceptions
        1. Not Occor by user/programmer
*/

int main()
{
    string solution = "Can not divide by zero";
    int errorCode = 1001;

    try
    {
        int a = 5, b = 0;
        if (b == 0)
        {
            throw solution;
        }
        cout << "Result: " << a / b << endl;
    }
    catch (const string& error)
    {
        cerr << "Error: " << error << endl;
    }

    try
    {
        int a = 5, b = 0;
        if (b == 0)
        {
            throw errorCode;
        }
        cout << "Result: " << a / b << endl;
    }
    catch (const int& error)
    {
        cerr << "Error code: " << error << endl;
    }
    catch (...)
    {
        cerr << "An unknown error occurred." << endl;
    }
    return 0;
}
