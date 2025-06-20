#include <iostream>
using namespace std;

/*
    Meaning of Polymorphism:

        1. Poly => Multiple
        2. Morphism => Behaviors

        Polymorphism
        => Multiple Behaviors
*/

/*
    Method Overloading:

        1. Multiple methods
            (2 or more methods)

        2. All methods name
            must be same

        3. Parameters must
            be different
*/

void menuManagement();
class Student;

int main()
{
    void menuManagement();

    Student s1;
    Student s2("John");
    Student s3("Alice", 20);
    Student s4("Bob", 22, 85.5);
    Student s5("Charlie", 21, 90.0, "charlie@example.com");
    Student s6("David", 23, 88.0, "david@example.com", 12);
}
class Student
{
private:
    string name;
    int age;
    float percentage;
    string email;
    int grade;

public:
    // Default constructor
    Student()
    {
        name = "";
        age = 0;
        percentage = 0.0;
        email = "";
        grade = 0;
    }
    // Parameterized constructor
    Student(string n)
    {
        name = n;
        int age;
        float percentage;
        string email;
        int grade;

        cout << "Enter age: ";
        cin >> age;

        cout << "Enter percentage: ";
        cin >> percentage;

        cout << "Enter email: ";
        cin >> email;

        cout << "Enter grade: ";
        cin >> grade;
    }
    Student(string n, int a)
    {
        name = n;
        age = a;
        float percentage;
        string email;
        int grade;

        cout << "Enter percentage: ";
        cin >> percentage;

        cout << "Enter email: ";
        cin >> email;

        cout << "Enter grade: ";
        cin >> grade;
    }
    Student(string n, int a, float p)
    {
        name = n;
        age = a;
        percentage = p;
        string email;
        int grade;

        cout << "Enter email: ";
        cin >> email;

        cout << "Enter grade: ";
        cin >> grade;
    }
    Student(string n, int a, float p, string e)
    {
        name = n;
        age = a;
        percentage = p;
        email = e;
        int grade;

        cout << "Enter grade: ";
        cin >> grade;
    }
    Student(string n, int a, float p, string e, int g)
    {
        name = n;
        age = a;
        percentage = p;
        email = e;
        grade = g;
    }
    // Method to display student details
    ~Student()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Percentage: " << percentage << "%" << endl;
        cout << "Email: " << email << endl;
        cout << "Grade: " << grade << endl;
    }
};
void menuManagement()
{
    cout << "Student Management System" << endl;
    cout << "1. Add Student" << endl;
    cout << "2. Add multiple Students" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        // Add Student
        cout << "1. Parameterized Constructor" << endl;
        cout << "2. Default Constructor" << endl;
        cout << "Enter your choice: ";
        int subChoice;
        cin >> subChoice;
        switch (subChoice)
        {
        case 1:
        {
            cout << "1. With Name" << endl;
            cout << "2. With Name and Age" << endl;
            cout << "3. With Name, Age, and Percentage" << endl;
            cout << "4. With Name, Age, Percentage, and Email" << endl;
            cout << "5. With Name, Age, Percentage, Email, and Grade" << endl;
            cout << "Enter your choice: ";
            int subSubChoice;
            cin >> subSubChoice;
            switch (subSubChoice)
            {
            case 1:
            {
                string name;
                cout << "Enter Name: ";
                cin >> name;
                Student s(name);
            }
            }
        }
        break;
        case 2:
        {
            string name;
            int age;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Age: ";
            cin >> age;
            Student s(name, age);
        }
        break;
        case 3:
        {
            string name;
            int age;
            float percentage;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter Percentage: ";
            cin >> percentage;
            Student s(name, age, percentage);
        }
        break;
        case 4:
        {
            string name;
            int age;
            float percentage;
            string email;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter Percentage: ";
            cin >> percentage;
            cout << "Enter Email: ";
            cin >> email;
            Student s(name, age, percentage, email);
        }
        break;
        case 5:
        {
            string name;
            int age;
            float percentage;
            string email;
            int grade;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter Percentage: ";
            cin >> percentage;
            cout << "Enter Email: ";
            cin >> email;
            cout << "Enter Grade: ";
            cin >> grade;
            Student s(name, age, percentage, email, grade);
        }
        break;
        }

        break;
    case 2:
        // Add multiple Students
        cout << "Enter number of students to add: ";
        int numStudents;
        cout << "Enter number of students to add: ";
        cin >> numStudents;
        for (int i = 1; i <= numStudents; i++)
        {
            // Add Student
            cout << "1. Parameterized Constructor" << endl;
            cout << "2. Default Constructor" << endl;
            cout << "Enter your choice: ";
            int subChoice;
            cin >> subChoice;
            switch (subChoice)
            {
            case 1:
            {
                cout << "1. With Name" << endl;
                cout << "2. With Name and Age" << endl;
                cout << "3. With Name, Age, and Percentage" << endl;
                cout << "4. With Name, Age, Percentage, and Email" << endl;
                cout << "5. With Name, Age, Percentage, Email, and Grade" << endl;
                cout << "Enter your choice: ";
                int subSubChoice;
                cin >> subSubChoice;
                switch (subSubChoice)
                {
                case 1:
                {
                    string name;
                    cout << "Enter Name: ";
                    cin >> name;
                    Student s(name);
                }
                }
            }
            break;
            case 2:
            {
                string name;
                int age;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Age: ";
                cin >> age;
                Student s(name, age);
            }
            break;
            case 3:
            {
                string name;
                int age;
                float percentage;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Age: ";
                cin >> age;
                cout << "Enter Percentage: ";
                cin >> percentage;
                Student s(name, age, percentage);
            }
            break;
            case 4:
            {
                string name;
                int age;
                float percentage;
                string email;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Age: ";
                cin >> age;
                cout << "Enter Percentage: ";
                cin >> percentage;
                cout << "Enter Email: ";
                cin >> email;
                Student s(name, age, percentage, email);
            }
            break;
            case 5:
            {
                string name;
                int age;
                float percentage;
                string email;
                int grade;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Age: ";
                cin >> age;
                cout << "Enter Percentage: ";
                cin >> percentage;
                cout << "Enter Email: ";
                cin >> email;
                cout << "Enter Grade: ";
                cin >> grade;
                Student s(name, age, percentage, email, grade);
            }
            break;
            }
        }

        break;

    default:
        break;
    }
}
