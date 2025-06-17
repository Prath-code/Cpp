#include <iostream>
using namespace std;

const int MAX_STUDENTS = 100;

class Student
{
private:
    int id;
    string name;
    string schoolName;
    string address;
    string email;
    string phoneNumber;

public:
    void setDetails(int id, string name, string schoolName, string address, string email, string phoneNumber = "")
    {
        this->id = id;
        this->name = name;
        this->schoolName = schoolName;
        this->address = address;
        this->email = email;
        this->phoneNumber = phoneNumber;
    }

    int getId() const
    {
        return id;
    }

    void display() const
    {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "School Name: " << schoolName << endl;
        cout << "Address: " << address << endl;
        cout << "Email: " << email << endl;
        if (!phoneNumber.empty())
        {
            cout << "Phone Number: " << phoneNumber << endl;
        }
        cout << endl;
    }
};

void displayMenu()
{
    cout << endl;
    cout << "+----------------------------+" << endl;
    cout << "|   Student Management Menu  |" << endl;
    cout << "+----------------------------+" << endl;
    cout << "| 1. Add Student             |" << endl;
    cout << "| 2. Update Student          |" << endl;
    cout << "| 3. Delete Student          |" << endl;
    cout << "| 4. Delete All Students     |" << endl;
    cout << "| 5. View Student            |" << endl;
    cout << "| 6. View All Students       |" << endl;
    cout << "| 0. Exit                    |" << endl;
    cout << "+----------------------------+" << endl;
}

int findStudentIndexById(Student students[], int count, int id)
{
    for (int i = 0; i < count; ++i)
    {
        if (students[i].getId() == id)
        {
            return i;
        }
    }
    return -1;
}

void getStudentDetails(int &id, string &name, string &schoolName, string &address, string &email, string &phoneNumber)
{
    cout << "ID: ";
    cin >> id;
    cout << "Name: ";
    getline(cin >> ws, name);
    cout << "School Name: ";
    getline(cin, schoolName);
    cout << "Address: ";
    getline(cin, address);
    cout << "Email: ";
    getline(cin, email);
    cout << "Phone Number (optional): ";
    getline(cin, phoneNumber);
}

int main()
{
    Student students[MAX_STUDENTS];
    int studentCount = 0;

    int initial;
    cout << "Enter initial number of students: ";
    cin >> initial;

    if (initial > MAX_STUDENTS)
    {
        cout << "Maximum is " << MAX_STUDENTS << ". Setting to max.\n";
        initial = MAX_STUDENTS;
    }

    for (int i = 0; i < initial; ++i)
    {
        int id;
        string name, schoolName, address, email, phoneNumber;

        cout << "\nEnter details for student " << (i + 1) << ":\n";
        getStudentDetails(id, name, schoolName, address, email, phoneNumber);
        students[studentCount].setDetails(id, name, schoolName, address, email, phoneNumber);
        studentCount++;
    }

    int choice;
    do
    {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: // Add Student
            if (studentCount >= MAX_STUDENTS)
            {
                cout << "Maximum student limit reached.\n";
                break;
            }
            {
                int id;
                string name, schoolName, address, email, phoneNumber;
                cout << "\nEnter details for new student:\n";
                getStudentDetails(id, name, schoolName, address, email, phoneNumber);
                students[studentCount].setDetails(id, name, schoolName, address, email, phoneNumber);
                studentCount++;
                cout << "Student added.\n";
            }
            break;

        case 2: // Update Student
        {
            int id;
            cout << "Enter ID of student to update: ";
            cin >> id;
            int index = findStudentIndexById(students, studentCount, id);
            if (index != -1)
            {
                string name, schoolName, address, email, phoneNumber;
                cout << "Enter new details:\n";
                getStudentDetails(id, name, schoolName, address, email, phoneNumber);
                students[index].setDetails(id, name, schoolName, address, email, phoneNumber);
                cout << "Student updated.\n";
            }
            else
            {
                cout << "Student not found.\n";
            }
        }
        break;

        case 3: // Delete Student
        {
            int id;
            cout << "Enter ID of student to delete: ";
            cin >> id;
            int index = findStudentIndexById(students, studentCount, id);
            if (index != -1)
            {
                for (int i = index; i < studentCount - 1; ++i)
                {
                    students[i] = students[i + 1];
                }
                studentCount--;
                cout << "Student deleted.\n";
            }
            else
            {
                cout << "Student not found.\n";
            }
        }
        break;

        case 4: // Delete All Students
            studentCount = 0;
            cout << "All student records deleted.\n";
            break;

        case 5: // View Student
        {
            int id;
            cout << "Enter ID of student to view: ";
            cin >> id;
            int index = findStudentIndexById(students, studentCount, id);
            if (index != -1)
            {
                students[index].display();
            }
            else
            {
                cout << "Student not found.\n";
            }
        }
        break;

        case 6: // View All Students
            if (studentCount == 0)
            {
                cout << "No student records available.\n";
            }
            else
            {
                for (int i = 0; i < studentCount; ++i)
                {
                    students[i].display();
                }
            }
            break;

        case 0: // Exit
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
