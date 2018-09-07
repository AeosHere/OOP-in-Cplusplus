#include "course.h"
#include "student.h"

using namespace BrooklynPoly;
using namespace std;

namespace BrooklynPoly {
	Course::Course(const string& courseName) : name(courseName) {}

	void Course::display(ostream& input) const {
		cout << name << endl;
		cout << "  Students: ";
		if (students.size() == 0) {
			cout << "None" << endl;
		}
		else {
			for (size_t i = 0; i < students.size(); ++i) {
				cout << students[i]->getName();
			}
			cout << endl;
		}
	}

	const string& Course::getName() const { 
		return name; 
	}

	void Course::addStudent(Student* student) {
		students.push_back(student);
	}

	bool Course::removeStudent(Student* student) {
		for (size_t i = 0; i < students.size(); ++i) {
			if (students[i] == student) {
				students[i] = students.back();
				students.pop_back();
				return true;
			}
		}
		return false;
	}

	bool Course::checkStudentExist(const string& studentName) {
		for (size_t i = 0; i < students.size(); ++i) {
			if (students[i]->getName() == studentName) {
				return true;
			}
		}
		return false;
	}

	void Course::removeStudents() {
		for (size_t i = 0; students.size(); ++i) {
			removeStudent(students[i]);
		}
	}
}