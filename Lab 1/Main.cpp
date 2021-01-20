/*

	Name:         Jax Carstensen

	Semester:     2

	Due:          1/20/2021

	Lab:          Lab 1 (C++ Class Example)

	Description:  Create a student class that will store important information about a student.
	As a part of this lab, a client file needs to be created to test the class by displaying to
	the screen all the attributes and display all classes that match a user requested grade.

*/
#include <iostream>
#include "Student.h"
#include <array>
#include <iomanip>

using namespace std;

int main() {
	//Setting up the student
	Student bob = Student();
	bob.setStudentName("Bob Halterman");
	bob.setStudentId(123456);
	bob.addClass("Data Structures", 100, 2);
	bob.addClass("C++",             95,  1);
	bob.addClass("Python",          97,  1);
	bob.addClass("Java",            98,  2);
	bob.addClass("Intro To Art",    87,  1);
	bob.addClass("Government",      89,  2);
	bob.addClass("Basic Python A",  100, 1);
	bob.addClass("Basic Python B",  100, 2);
	bob.addClass("Drawing A",       84,  2);
	bob.addClass("Pre Calculus",    98,  1);
	bob.addClass("Algebra II",      96,  1);
	bob.addClass("History",         91,  2);
	bob.addClass("Lunch",           15,  1);
	bob.addClass("Recess",          50,  2);

	//User inputs grade
	string className;
	int classGrade;
	int classSemester;
	char exitLetter = 'y';
	while (exitLetter != 'n') {
		cout << "Enter bob's class name: ";
		cin >> className;
		cout << "\nEnter bob's grade for " << className << " (0-100): ";
		cin >> classGrade;
		cout << "\nEnter the semester that Bob took " << className << " (1-2): ";
		cin >> classSemester;

		bob.addClass(className, classGrade, classSemester);
		cout << "\nWould you like to add another class for bob? y/n: ";
		cin >> exitLetter;
		exitLetter = tolower(exitLetter);
	}

	//User searches for grades
	char letterGrade;
	exitLetter = 'y';
	while (exitLetter != 'n') {
		cout << "Enter a letter grade to find Bob's matching classes: ";
		cin >> letterGrade;

		//Gets the array of classes and the array's length
		string* classes = bob.getClassesByGrade(letterGrade);
		int classCount = bob.getLastClassListSize();

		//Displays class information
		if (classCount > 0) {
			cout << endl << bob.getStudentName() << "'s classes with " << (char)toupper(letterGrade) << "s:\n";
			for (int i = 0; i < classCount; i++) {
				cout << "-\t" << setw(25) << left << classes[i] << " (" << bob.getGradeByClass(classes[i]) << "/100)\n";
			}
		}
		cout << "\nWould you like to search for another one of bob's grades? y/n: ";
		cin >> exitLetter;
		exitLetter = tolower(exitLetter);
	}
	bob.calculateGPA();

	//Uses all getter methods
	cout << "\nBob's GPA: " << bob.getGPA() << endl;
	cout << "Bob's History Grade: " << bob.getGradeByClass("History") << endl;
	cout << "Bob's Student Id: " << bob.getStudentId() << endl;
	cout << "Bob's Government Semester: " << bob.getSemesterByClass("Government") << endl;
	return 0;
}