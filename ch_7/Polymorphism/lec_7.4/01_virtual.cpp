#include <iostream>
using namespace std;

class A
{
public:
    virtual void show()
    {
        cout << "Display from class A" << endl;
    }
};

class B : public A
{
public:
    void show() override
    {
        cout << "Display from class B" << endl;
    }
};

int main()
{
    A *ptr;
    A a1;
    B b1;

    cout << "Choose class to display (A/B): ";
    char choice;
    cin >> choice;
    if (choice == 'A' || choice == 'a')
    {
        ptr = &a1;
    }
    else if (choice == 'B' || choice == 'b')
    {
        ptr = &b1;
    }
    else
    {
        cout << "Invalid choice!" << endl;
        return 1;
    }

    ptr->show();
    return 0;
}
