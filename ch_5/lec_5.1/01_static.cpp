#include <iostream>
#include <string.h>
using namespace std;

class Student
{
	public:
		int id;
		static string school;
		float percentage;

		void aboutSchool()
		{

		}
};

string Student::school = "Sanskar Bharti Vidyalaya";

int main()
{
	Student s1, s2;
	
	cout << "Enter ID for student 1: ";
	cin >> s1.id;

	cout << "Enter school for student 1: " << s1.school << endl;

	cout << "Enter percentage for student 1: ";
	cin >> s1.percentage;

	Student::school = "Global Indian International School";

	cout << "Enter ID for student 2: ";
	cin >> s2.id;

	cout << "Enter school for student 2: " << s2.school << endl;

	cout << "Enter percentage for student 2: ";
	cin >> s2.percentage;

	cout << "Student 1 ID: " << s1.id << endl;
	cout << "Student 1 School: " << s1.school << endl;
	cout << "Student 1 Percentage: " << s1.percentage << endl;

	cout << "Student 2 ID: " << s2.id << endl;
	cout << "Student 2 School: " << s2.school << endl;
	cout << "Student 2 Percentage: " << s2.percentage << endl;

	return 0;
}
