#include <iostream>
#include <limits>
using namespace std;

/*
    Pure Virtual Functions
        (Abstract Classes)
        (PVF)
*/

class Movie
{
public:
    // Future movies
    virtual void Sonic4() = 0;
    virtual void MahaMunjia() = 0;
    virtual void SitareZameenPar() = 0;
};
class futureMovie : public Movie
{
public:
    void Sonic4() override
    {
        cout << "Sonic 4: The Return of the Hedgehog" << endl;
    }
    void MahaMunjia() override
    {
        cout << "Maha Munjia: The Epic Adventure" << endl;
    }
    void SitareZameenPar() override
    {
        cout << "Sitare Zameen Par: Stars on Earth" << endl;
    }
};
int main()
{
    Movie *ptr;
    futureMovie f1;

    cout << "Choose movie to display (Sonic4/MahaMunjia/SitareZameenPar): ";
    string choice;
    getline(cin, choice);

    if (choice == "Sonic4" || choice == "sonic4" || choice == "Sonic 4" || choice == "SONIC 4" || choice == "SONIC4" || choice == "s4" || choice == "S4")
    {
        ptr = &f1;
        ptr->Sonic4();
    }
    else if (choice == "MahaMunjia" || choice == "mahamunjia" || choice == "Maha Munjia" || choice == "MAHA MUNJIA" || choice == "MAHAMUNJIA" || choice == "mm" || choice == "MM")
    {
        ptr = &f1;
        ptr->MahaMunjia();
    }
    else if (choice == "SitareZameenPar" || choice == "sitarezameenpar" || choice == "Sitare Zameen Par" || choice == "SITARE ZAMEEN PAR" || choice == "SITAREZAMEENPAR" || choice == "szp" || choice == "SZP")
    {
        ptr = &f1;
        ptr->SitareZameenPar();
    }
    else
    {
        cout << "Invalid choice!" << endl;
        return 1;
    }

    return 0;
}
