#include <iostream>
using namespace std;

class Data
{
public:
    int x;
    void display()
    {
        cout << "Value of x: " << x << endl;
    }
};

class DerivedData : public Data
{
public:
    DerivedData()
    {
        cout << "Enter value for x: ";
        cin >> x;
    }
};

void setData()
{
    Data d;
    cout << "Enter value for x: ";
    cin >> d.x;
    d.display();
}

int main()
{
    Data d;
    cout << "Enter value for x: ";
    cin >> d.x;
    d.display();

    setData();

    DerivedData dd;
    
    return 0;
}
