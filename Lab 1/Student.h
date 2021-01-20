/*

	Name:         Jax Carstensen

	Semester:     2

	Due:          1/20/2021

	Lab:          Lab 1 (C++ Class Example)

	Description:  Create a student class that will store important information about a student.
	As a part of this lab, a client file needs to be created to test the class by displaying to
	the screen all the attributes and display all classes that match a user requested grade.

*/
#pragma once
#include <iostream>

using namespace std;

class Student {
private:
	string studentName;
	int studentId;
	string classes[100];
	int grades[100];
	int semesters[100];
	float gpa;
	int currentIndex = 0;
	int lastSize = 0;
public:
	int getLastClassListSize();
	string* getClassesByGrade(char grade);
	void calculateGPA();
	float getGPA();
	int getSemesterByClass(string className);
	void addClass(string name, int grade, int semester);
	void setStudentName(string newStudentName);
	void setStudentId(int newStudentId);
	string getStudentName();
	int getStudentId();
	int getGradeByClass(string className);
};