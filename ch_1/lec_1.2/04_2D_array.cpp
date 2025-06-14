#include <iostream>
using namespace std;

int main()
{
    int row_size, col_size;
    cout << "Enter the row size of the array: ";
    cin >> row_size;

    cout << "Enter the column size of the array: ";
    cin >> col_size;

    int a[row_size][col_size];

    // Input
    cout << endl <<"Enter " << row_size * col_size << " integers: " << endl;
    for (int i = 0; i < row_size; i++)
    {
        for (int j = 0; j < col_size; j++)
        {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }

    // Display
    cout << "You entered: " << endl;
    for (int i = 0; i < row_size; i++)
    {
        for (int j = 0; j < col_size; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
