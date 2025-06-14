#include <iostream>
using namespace std;

int main()
{
    int start, end;

    cout << "Enter the start year: ";
    cin >> start;

    cout << "Enter the end year: ";
    cin >> end;

    if (start > end)
    {
        cout << "Start year cannot be greater than end year." << endl;
        return 1;
    }

    // Leap year between start and end
    cout << "Leap years between " << start << " and " << end << ":" << endl;
    if (start < 0 || end < 0)
    {
        cout << "Years cannot be negative." << endl;
        return 1;
    }
    for (int i = start; i <= end; i++)
    {
        if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
        {
            cout << i << " ";
        }
        else
        {
            // Do nothing
        }
    }

    return 0;
}
