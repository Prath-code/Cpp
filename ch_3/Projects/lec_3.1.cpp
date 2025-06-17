#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

class Student
{
public:
    int id;
    string name;
    int age;
    string email;
    string password;

    Student(int id, const string &name, int age, const string &email, const string &password)
        : id(id), name(name), age(age), email(email), password(password) {}
};

class Employee
{
public:
    int id;
    string name;
    string email;
    string address;
    double salary;
    string role;

    Employee(int id, const string &name, const string &email, const string &address, double salary, const string &role)
        : id(id), name(name), email(email), address(address), salary(salary), role(role) {}
};

class StudentManager
{
private:
    vector<Student> students;

    void clear_input_buffer()
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

public:
    void add_student()
    {
        int id, age;
        string name, email, password;

        cout << "Enter ID: ";
        cin >> id;
        clear_input_buffer();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;
        clear_input_buffer();

        cout << "Enter Email: ";
        getline(cin, email);

        cout << "Enter Password: ";
        getline(cin, password);

        students.emplace_back(id, name, age, email, password);
        cout << "Student added successfully." << endl;
    }

    void delete_student()
    {
        int id;
        cout << "Enter ID of student to delete: ";
        cin >> id;

        for (auto it = students.begin(); it != students.end(); ++it)
        {
            if (it->id == id)
            {
                students.erase(it);
                cout << "Student deleted successfully." << endl;
                return;
            }
        }
        cout << "Student not found." << endl;
    }

    void update_student()
    {
        int id;
        cout << "Enter ID of student to update: ";
        cin >> id;
        cin.ignore();

        for (auto &student : students)
        {
            if (student.id == id)
            {
                cout << "Enter new Name: ";
                getline(cin, student.name);

                cout << "Enter new Age: ";
                cin >> student.age;
                clear_input_buffer();

                cout << "Enter new Email: ";
                getline(cin, student.email);

                cout << "Enter new Password: ";
                getline(cin, student.password);

                cout << "Student updated successfully." << endl;
                return;
            }
        }
        cout << "Student not found." << endl;
    }

    void view_all_students() const
    {
        if (students.empty())
        {
            cout << "No students available." << endl;
            return;
        }

        for (const auto &student : students)
        {
            cout << "ID: " << student.id << endl;
            cout << "Name: " << student.name << endl;
            cout << "Age: " << student.age << endl;
            cout << "Email: " << student.email << endl;
            cout << "Password: " << string(student.password.length(), '*') << endl;
            cout << "-----------------------------" << endl;
        }
    }

    void delete_all_students()
    {
        students.clear();
        cout << "All students deleted successfully." << endl;
    }
};

class EmployeeManager
{
private:
    vector<Employee> employees;

    void clear_input_buffer()
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

public:
    void add_employee()
    {
        int id;
        string name, email, address, role;
        double salary;

        cout << "Enter Employee ID: ";
        cin >> id;
        clear_input_buffer();

        cout << "Enter Employee Name: ";
        getline(cin, name);

        cout << "Enter Employee Email: ";
        getline(cin, email);

        cout << "Enter Employee Address: ";
        getline(cin, address);

        cout << "Enter Employee Salary: ";
        cin >> salary;
        clear_input_buffer();

        cout << "Enter Employee Role: ";
        getline(cin, role);

        employees.emplace_back(id, name, email, address, salary, role);
        cout << "Employee added successfully!" << endl;
    }

    void display_employees() const
    {
        if (employees.empty())
        {
            cout << "No employees available." << endl;
            return;
        }

        for (const auto &employee : employees)
        {
            cout << "ID: " << employee.id << endl;
            cout << "Name: " << employee.name << endl;
            cout << "Email: " << employee.email << endl;
            cout << "Address: " << employee.address << endl;
            cout << "Salary: " << employee.salary << endl;
            cout << "Role: " << employee.role << endl;
            cout << "-----------------------------" << endl;
        }
    }

    void remove_employee()
    {
        int id;
        cout << "Enter Employee ID to remove: ";
        cin >> id;

        auto it = remove_if(employees.begin(), employees.end(), [id](const Employee &employee) {
            return employee.id == id;
        });

        if (it != employees.end())
        {
            employees.erase(it, employees.end());
            cout << "Employee removed successfully!" << endl;
        }
        else
        {
            cout << "Employee not found!" << endl;
        }
    }

    void delete_all_employees()
    {
        employees.clear();
        cout << "All employees deleted successfully." << endl;
    }
};

void display_menu()
{
    cout << "+------------------------------+" << endl;
    cout << "|         MAIN MENU            |" << endl;
    cout << "+------------------------------+" << endl;
    cout << "| 1. Add Student               |" << endl;
    cout << "| 2. Delete Student            |" << endl;
    cout << "| 3. Update Student            |" << endl;
    cout << "| 4. View All Students         |" << endl;
    cout << "| 5. Delete All Students       |" << endl;
    cout << "| 0. Exit                      |" << endl;
    cout << "+------------------------------+" << endl;
}

void employee_menu()
{
    cout << "+------------------------------+" << endl;
    cout << "|       EMPLOYEE MENU          |" << endl;
    cout << "+------------------------------+" << endl;
    cout << "| 1. Add Employee              |" << endl;
    cout << "| 2. Remove Employee           |" << endl;
    cout << "| 3. Display All Employees     |" << endl;
    cout << "| 4. Delete All Employees      |" << endl;
    cout << "| 0. Exit                      |" << endl;
    cout << "+------------------------------+" << endl;
}

int main()
{
    string userType;
    cout << "Are you an Employee or a Student? (Enter 'Employee' or 'Student'): ";
    cin >> userType;

    if (userType == "Employee")
    {
        cout << "Welcome, Employee!" << endl;

        EmployeeManager e_manager;
        int e_choice;

        do
        {
            employee_menu();
            cout << "Enter your choice: ";
            cin >> e_choice;

            switch (e_choice)
            {
            case 1:
                e_manager.add_employee();
                break;
            case 2:
                e_manager.remove_employee();
                break;
            case 3:
                e_manager.display_employees();
                break;
            case 4:
                e_manager.delete_all_employees();
                break;
            case 0:
                cout << "Exiting... Goodbye." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
            }
        } while (e_choice != 0);
    }
    else if (userType == "Student")
    {
        cout << "Welcome, Student!" << endl;

        StudentManager manager;
        int choice;

        do
        {
            display_menu();
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                manager.add_student();
                break;
            case 2:
                manager.delete_student();
                break;
            case 3:
                manager.update_student();
                break;
            case 4:
                manager.view_all_students();
                break;
            case 5:
                manager.delete_all_students();
                break;
            case 0:
                cout << "Exiting... Goodbye." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
            }
        } while (choice != 0);
    }
    else
    {
        cout << "Invalid input. Please restart the program and enter 'Employee' or 'Student'." << endl;
    }

    return 0;
}
