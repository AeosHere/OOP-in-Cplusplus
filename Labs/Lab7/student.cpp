#include "student.h"
#include "course.h"

using namespace BrooklynPoly;
using namespace std;

namespace BrooklynPoly {
	Student::Student(const string& name) : name(name) {}

	const string& Student::getName() const { 
		return name; 
	}

	void Student::addCourse(Course* course) {
		courses.push_back(course);
	}

	void Student::removedFromCourse(Course* course) {
		for (size_t i = 0; i < courses.size(); ++i) {
			if (courses[i] == course) {
				courses[i] = courses.back();
				courses.pop_back();
			}
		}
	}

	bool Student::hasCourse(const string& courseName) {
		for (size_t i = 0; i < courses.size(); ++i) {
			if (courses[i]->getName() == courseName) {
				return true;
			}
		}
		return false;
	}
}