#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// Student class
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

// Manager class to handle all student operations
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

// Displays menu options
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

int main()
{
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

	return 0;
}
