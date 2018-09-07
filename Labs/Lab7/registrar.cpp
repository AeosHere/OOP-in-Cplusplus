#include "registrar.h"
#include "course.h"
#include "student.h"
#include <iostream>
using namespace BrooklynPoly;
using namespace std;

namespace BrooklynPoly {
	Registrar::Registrar() {}

	Registrar::~Registrar() {
		for (size_t i = 0; i < courses.size(); ++i) {
			delete courses[i];
		}
		for (size_t i = 0; i < students.size(); ++i) {
			delete students[i];
		}
	}

	void Registrar::printReport(ostream& input) const {
		cout << "Registrar Courses:" << endl;
		if (courses.size() == 0) {
			cout << "None" << endl;
		}
		else {
			for (size_t i = 0; i < courses.size(); ++i) {
				courses[i]->display();
			}
		}
		cout << "Registrar Students:" << endl;
		if (students.size() == 0) {
			cout << "None" << endl;
		}
		else {
			for (size_t i = 0; i < students.size(); ++i) {
				cout << students[i]->getName() << endl;
			}
		}
		cout << endl;
	}

	bool Registrar::addCourse(const string& courseName) {
		for (size_t i = 0; i < courses.size(); ++i) {
			if (courses[i]->getName() == courseName) {
				return false;
			}
		}
		Course* c = new Course(courseName);	
		courses.push_back(c);
		return true;
	
	}

	bool Registrar::addStudent(const string& studentName) {
		for (size_t i = 0; i < students.size(); ++i) {
			if (students[i]->getName() == studentName) {
				return false;
			}
		}
		Student* s = new Student(studentName);
		students.push_back(s);
		return true;
	}

	size_t Registrar::findStudent(const vector<Student*>& students, const string& studentName) {
		for (size_t i = 0; i < students.size(); ++i) {
			if (students[i]->getName() == studentName) {
				return i;
			}
		}
		return students.size();
	}

	size_t Registrar::findCourse(const vector<Course*>& courses, const string& courseName) {
		for (size_t i = 0; i < courses.size(); ++i) {
			if (courses[i]->getName() == courseName) {
				return i;
			}
		}
		return courses.size();
	}

	bool Registrar::enrollStudentInCourse(const string& studentName, const string& courseName) {
		size_t studentLoc = findStudent(students, studentName);
		if (studentLoc == students.size()) {
			return false;
		}
		size_t courseLoc = findCourse(courses, courseName);
		if (courseLoc == courses.size()) {
			return false;
		}

		if (students[studentLoc]->hasCourse(courseName)) {
			return false;
		}
		courses[courseLoc]->addStudent(students[studentLoc]);
		students[studentLoc]->addCourse(courses[courseLoc]);
		return true;
	}

	bool Registrar::cancelCourse(const string& courseName) {
		size_t courseLoc = findCourse(courses, courseName);
		if (courseLoc == courses.size()) {
			return false;
		}

		courses[courseLoc]->removeStudents();

		delete courses[courseLoc];
		courses[courseLoc] = courses.back();
		courses.pop_back();
	}

	void Registrar::purge() {
		for (size_t i = 0; i < courses.size(); ++i) {
			delete courses[i];
		}
		courses.clear();
		for (size_t i = 0; i < students.size(); ++i) {
			delete students[i];
		}
		students.clear();

	}
}