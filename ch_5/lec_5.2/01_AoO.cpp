#include <iostream>
using namespace std;

/*
    Array of Objects
*/

class Student
{
private:
    string id;
    string name;
    int age;
    static string school;
    string address;
    string email;
    string phone;
public:
    void setDetails(string studentId, string studentName, int studentAge, string studentAddress, string studentEmail, string studentPhone = "N/A") {
        id = studentId;
        name = studentName;
        age = studentAge;
        address = studentAddress;
        email = studentEmail;
        phone = studentPhone;
    }

    void getData() const {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "School: " << school << endl;
        cout << "Address: " << address << endl;
        cout << "Email: " << email << endl;
        cout << "Phone: " << phone << endl;
    }
};

string Student::school = "Default School";

int main() {
    int numStudents;

    cout << "Enter the number of students: ";
    cin >> numStudents;

    Student students[numStudents];

    for (int i = 0; i < numStudents; ++i) {
        string id, name, address, email, phone;
        int age;

        cout << "Enter details for student " << i + 1 << ":\n";
        cout << "ID: ";
        cin >> id;
        cout << "Name: ";
        cin >> name;
        cout << "Age: ";
        cin >> age;
        cout << "Address: ";
        cin >> address;
        cout << "Email: ";
        cin >> email;

        cout << "Phone (optional, press Enter to skip): ";
        cin.ignore();
        getline(cin, phone);
        if (phone.empty()) {
            phone = "N/A";
        }

        students[i].setDetails(id, name, age, address, email, phone);
    }

    cout << "\nDisplaying student details:\n";
    for (int i = 0; i < numStudents; ++i) {
        cout << "\nStudent " << i + 1 << ":\n";
        students[i].getData();
    }

    return 0;
}
