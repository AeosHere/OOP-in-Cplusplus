#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <vector>
#include <iostream>

namespace BrooklynPoly {
	class Student;

	class Course {
	public:
		Course(const std::string& courseName);
		void display(std::ostream& = std::cout) const;
		const std::string& getName() const;
		void addStudent(Student*);
		bool removeStudent(Student*);
		bool checkStudentExist(const std::string&);
		void removeStudents();
	private:
		std::string name;
		std::vector<Student*> students;
	};
}
#endif
