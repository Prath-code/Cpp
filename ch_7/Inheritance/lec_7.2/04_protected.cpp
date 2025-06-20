#include <iostream>
using namespace std;

class Data
{
protected:
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

/*
    void setData()
    {
        Data d;
        cout << "Enter value for x: ";
        cin >> d.x;
        d.display();
    }
*/
// not allowed because x is protected


int main()
{
    /*
        Data d;
        cout << "Enter value for x: ";
        cin >> d.x;
        d.display();

        setData();
    */
    // not allowed because x is protected

    DerivedData dd;
    /* 
    allowed because DerivedData
    is a public derived class
    of Data
    */

    return 0;
}
