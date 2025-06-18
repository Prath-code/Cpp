#include <iostream>
#include <iomanip>
using namespace std;

/*
    Friend Functions


    A friend function is a function that is not a member of a class but has access to its private and protected members.
    It is declared using the `friend` keyword inside the class definition.
    Friend functions can be useful for operator overloading or when you need to access private data of
    multiple classes without making them members of those classes.
*/

class Prath
{
private:
    double money;
    int number_of_properties;

public:
    void setDetails(double m, int n)
    {
        cout << "Prath's money: ";
        cin >> money;
        cout << "Prath's number of properties: ";
        cin >> number_of_properties;
    }
    void getData() const
    {
        cout << "Prath's money: " << money << endl;
        cout << "Prath's number of properties: " << number_of_properties << endl;
    }

    friend void Hetsh_thief(Prath);
};

void Hetsh_thief(Prath p)
{

    cout << "Enter the amount of money to steal from Prath: ";
    cin >> p.money;
    cout << "Enter the number of properties to steal from Prath: ";
    cin >> p.number_of_properties;

    cout << "Hetsh Thief stole " << fixed << setprecision(0) << p.money << " and " << p.number_of_properties << " properties from Prath." << endl;
};

int main()
{
    Prath p;
    p.setDetails(0, 0);
    p.getData();

    Hetsh_thief(p);

    return 0;
}
