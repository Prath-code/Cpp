#include <iostream>
using namespace std;

class Data
{
private:
    int x;
    void display()
    {
        cout << "Value of x: " << x << endl;
    }
};

/*
    class DerivedData : public Data
    {
    public:
        DerivedData()
        {
            cout << "Enter value for x: ";
            cin >> x;
        }
    };
*/
// not allowed because x is private

/*
    void setData()
    {
        Data d;
        cout << "Enter value for x: ";
        cin >> d.x;
        d.display();
    }
*/
// not allowed because x is private


int main()
{
    /*
        Data d;
        cout << "Enter value for x: ";
        cin >> d.x;
        d.display();

        setData();
    */
    // not allowed because x is private

    // DerivedData dd;
    // not allowed because x is private

    return 0;
}
