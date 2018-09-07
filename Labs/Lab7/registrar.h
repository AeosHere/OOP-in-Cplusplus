#ifndef REGISTRAR_H
#define REGISTRAR_H
#include <iostream>
#include <vector>
#include <string>

namespace BrooklynPoly {

	class Course;
	class Student;

	class Registrar {
	public:
		Registrar();
		~Registrar();
		void printReport(std::ostream& = std::cout) const;
		bool addCourse(const std::string&);
		bool addStudent(const std::string&);
		size_t findStudent(const std::vector<Student*>&, const std::string&);
		size_t findCourse(const std::vector<Course*>&, const std::string&);
		bool enrollStudentInCourse(const std::string& studentName,
			const std::string& courseName);
		bool cancelCourse(const std::string& courseName);
		bool changeStudentName(const std::string& oldName, const std::string& newName);
		bool dropStudentFromCourse(const std::string& studentName,
			const std::string& courseName);
		bool removeStudent(const std::string& studentName);

		void purge();
	private:
		std::vector<Course*> courses;
		std::vector<Student*> students;
	};

	std::ostream& operator<<(std::ostream&, const Registrar&);
}
#endif