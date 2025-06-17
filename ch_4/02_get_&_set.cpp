#include <iostream>
#include <iomanip>
using namespace std;

/*
	class Name
	{
		1. Variables => Data Members / Data Attributes / Data Properties
		2. Functions => Data Member Functions / Methods
		3. Constructor
		4. Destructor
	}
*/

class Employee
{
public:
	int id;
	string name;
	double salary;

	void setData(int emp_id, string emp_name, double emp_salary)
	{
		id = emp_id;
		name = emp_name;
		salary = emp_salary;
	}
	void getData()
	{
		cout << "Id: " << id << endl
			 << "Name: " << name << endl
			 << "Salary: " << fixed << setprecision(0)<< salary << endl;
	}
};

int main()
{
    int numEmployees;
    cout << "Enter the number of employees: ";
    cin >> numEmployees;

    Employee *employees = new Employee[numEmployees];

    for (int i = 0; i < numEmployees; ++i)
    {
        int id;
        string name;
        double salary;

        cout << "Enter details for employee " << i + 1 << ":\n";
        cout << "Id: ";
        cin >> id;
        cout << "Name: ";
        cin >> name;
        cout << "Salary: ";
        cin >> salary;

        employees[i].setData(id, name, salary);
    }

    for (int i = 0; i < numEmployees; ++i)
    {
        employees[i].getData();
    }

    delete[] employees;

    return 0;
}

