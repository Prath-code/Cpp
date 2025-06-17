#include <iostream>
#include<string>
using namespace std;

class Employee
{
	public:
		int id;
		string name;
		double salary;
};

int main()
{
	Employee e1, e2;
	
	e1.id = 1;
	e1.name = "Prath";
	e1.salary = 10000;
	
	e2.id = 2;
	e2.name = "Hetsh";
	e2.salary = 9999;
	
	cout << "Id: " << e1.id << endl << "Name: " << e1.name << endl << "Salary: " << e1.salary << endl << endl;
	cout << "Id: " << e2.id << endl << "Name: " << e2.name << endl << "Salary: " << e2.salary << endl << endl;
	
	return 0;
}

