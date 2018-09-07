#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iostream>
#include <vector>

namespace BrooklynPoly {

	class Course;
	class Registrar;

	class Student {
	public:
		Student(const std::string& name);
		const std::string& getName() const;
		void addCourse(Course*);
		void removedFromCourse(Course* cp);
		void changeName(const std::string& name);
		bool hasCourse(const std::string& courseName);
	private:
		std::string name;
		std::vector<Course*> courses;
	};

	std::ostream& operator<<(std::ostream&, const Student&);
}
#endif
