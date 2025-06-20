#include <iostream>
using namespace std;

class Data
{
private:
    int p = 7;

public:
    int y = 3;

protected:
    int x = 10;
};

class NewDataPublic : public Data
{
public:
    Data::y;
protected:
    Data::x;
};

class NewDataProtected : protected Data
{
public:
    Data::y;
protected:
    Data::x;
};

class NewDataPrivate : private Data
{
private:
    Data::x;
    Data::y;
    // Data::p;
    /*
            not allowed because
        private members of
        the base class (Data::p)
        are not accessible in derived
        classes
    */
};
