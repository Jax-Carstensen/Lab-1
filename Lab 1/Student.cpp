/*

	Name:         Jax Carstensen

	Semester:     2

	Due:          1/20/2021

	Lab:          Lab 1 (C++ Class Example)

	Description:  Create a student class that will store important information about a student.
	As a part of this lab, a client file needs to be created to test the class by displaying to
	the screen all the attributes and display all classes that match a user requested grade.

*/
#include "Student.h"

//Simple getters and setters
void Student::setStudentName(string newStudentName) { studentName = newStudentName; }
void Student::setStudentId(int newStudentId) { studentId = newStudentId; }
string Student::getStudentName() { return studentName; }
int Student::getStudentId() { return studentId; }
float Student::getGPA() { return gpa; }
int Student::getLastClassListSize() { return lastSize; }

//Loops through all classes to locate given class
int Student::getGradeByClass(string className) {
	for (int i = 0; i < 100; i++)
		if (classes[i] == className)
			return grades[i];
	return -1;
}

//Returns semester of given class
int Student::getSemesterByClass(string className) {
	for (int i = 0; i < 100; i++)
		if (classes[i] == className)
			return semesters[i];
	return -1;
}

//Adds a class to the student
void Student::addClass(string name, int grade, int semester) {
	if (currentIndex == 100) {
		cout << "The user " << studentName << " has reached their 100 class limit!" << endl;
		return;
	}
	grades[currentIndex] = grade;
	classes[currentIndex] = name;
	semesters[currentIndex] = semester;
	currentIndex++;
}

//GPA calculation
void Student::calculateGPA() {
	float total = 0.0;
	//Adds to the total variable based on how high the grade is
	for (int i = 0; i < currentIndex; i++) {
		int g = grades[i];
		if (g >= 90) { total += 4; continue; }
		else if (g >= 80) { total += 3; continue; }
		else if (g >= 70) { total += 2; continue; }
		else if (g >= 60) { total += 1; continue; }
	}
	//Ensure we don't divide by 0
	if (total > 0)
		gpa = total / (float)currentIndex;
	//Rounds GPA to 3 decimals
	gpa = (float)((int)(gpa * 1000 + 0.5)) / 1000;
}

//Returns an array of all class names with a given grade
string* Student::getClassesByGrade(char grade) {
	grade = toupper(grade);
	int gradeInt;
	//Converts letter grade to number
	switch (grade) {
		case 'A': gradeInt = 90; break;
		case 'B': gradeInt = 80; break;
		case 'C': gradeInt = 70; break;
		case 'D': gradeInt = 60; break;
		case 'F': gradeInt = 50; break;
		default: cout << "Grade InputError: " << grade << " is not a valid grade!" << endl; return new string[0];
	}
	//Keeps track of number of classes found so we don't return an array too long or too short
	int total = 0;
	for (int i = 0; i < currentIndex; i++) {
		//If the first number of the grade is the same (89 = 81) (79 != 80) (52 = 58)
		if ((grade == 'A' && grades[i] >= 100)
			|| ((int)((float)grades[i] / 10) == (int)((float)gradeInt / 10))
			|| (grade == 'F' && grades[i] <= 50)) {
			total += 1;
		}
	}
	//Creates array at length of variable total
	string* newClasses = new string[total];
	int index = 0;
	//Same loop as before, but adds that class to the array
	for (int i = 0; i < currentIndex; i++) {
		if ((grade == 'A' && grades[i] >= 100)
			|| ((int)((float)grades[i] / 10) == (int)((float)gradeInt / 10))
			|| (grade == 'F' && grades[i] <= 50)) {
			newClasses[index] = classes[i];
			index += 1;
		}
	}
	lastSize = total;
	return newClasses;
}