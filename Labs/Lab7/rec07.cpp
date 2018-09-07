#include "Registrar.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace BrooklynPoly;
using namespace std;

void readFile(ifstream& ifs, Registrar& registrar) {
	if (!ifs) {
		cerr << "Cannot find file" << endl;
		exit(1);
	}
	string current, command, courseName, studentName;
	while (ifs >> current) {
		if (current == "PrintReport") {
			cout << "PrintReport" << endl;
			registrar.printReport();
		}
		if (current == "AddCourse") {
			ifs >> courseName;
			cout << "AddCourse " << courseName << endl;
			registrar.addCourse(courseName);
		}
		if (current == "AddStudent") {
			ifs >> studentName;
			cout << "AddStudent " << studentName << endl;
			registrar.addStudent(studentName);
		}
		if (current == "EnrollStudentInCourse") {
			ifs >> studentName >> courseName;
			cout << "EnrollStudentInCourse " << studentName << " " << courseName << endl;
			if (courseName != "PrintReport" && courseName != "AddCourse" && courseName != "AddStudent" && courseName != "EnrollStudentInCourse") {
				registrar.enrollStudentInCourse(studentName, courseName);
			}
			else {
				cerr << "Error transacting" << endl;
			}
		}
		if (current == "Purge") {
			cout << "Purge" << endl;
			registrar.purge();
		}
	}
}
int main() {

	Registrar registrar;
	ifstream ifs("transaction.txt");
	if (!ifs) {
		cerr << "Cannot find file" << endl;
		exit(1);
	}
	string line, command;
	while (getline(ifs, line)) {
		stringstream is(line);
		string courseName, studentName;
		is >> command;
		if (command == "PrintReport") {
			cout << "PrintReport" << endl;
			registrar.printReport();
		}
		if (command == "AddCourse") {
			is >> courseName;
			cout << "AddCourse " << courseName << endl;
			registrar.addCourse(courseName);
		}
		if (command == "AddStudent") {
			is >> studentName;
			cout << "AddStudent " << studentName << endl;
			registrar.addStudent(studentName);
		}
		if (command == "CancelCourse") {
			is >> courseName;
			cout << "CancelCourse " << courseName << endl;
			registrar.cancelCourse(courseName);
		}
		if (command == "EnrollStudentInCourse") {
			is >> courseName >> studentName;
			cout << "EnrollStudentInCourse " << courseName << " " << studentName << endl;
			registrar.enrollStudentInCourse(courseName, studentName);
		}
		if (command == "Purge") {
			cout << "Purge" << endl;
			registrar.purge();
		}
	}

	/*
	cout << "No courses or students added yet\n";
	//cout << registrar << endl;  // or 
	registrar.printReport();
	
	cout << "AddCourse CS101.001\n";
	registrar.addCourse("CS101.001");
	//cout << registrar << endl;  // or 
	registrar.printReport();

	cout << "AddStudent FritzTheCat\n";
	registrar.addStudent("FritzTheCat");
	//cout << registrar << endl;  // or 
	registrar.printReport();
	
	cout << "AddCourse CS102.001\n";
	registrar.addCourse("CS102.001");
	//cout << registrar << endl;  // or 
	registrar.printReport();
	
	cout << "EnrollStudentInCourse FritzTheCat CS102.001\n";
	registrar.enrollStudentInCourse("FritzTheCat", "CS102.001");
	cout << "EnrollStudentInCourse FritzTheCat CS101.001\n";
	registrar.enrollStudentInCourse("FritzTheCat", "CS101.001");
	//cout << registrar << endl;  // or 
	registrar.printReport();
	
	cout << "EnrollStudentInCourse Bullwinkle CS101.001\n";
	cout << "Should fail, i.e. do nothing, since Bullwinkle is not a student.\n";
	registrar.enrollStudentInCourse("Bullwinkle", "CS101.001");
	//cout << registrar << endl;  // or 
	registrar.printReport();
	
	cout << "CancelCourse CS102.001\n";
	registrar.cancelCourse("CS102.001");
	//cout << registrar << endl;  // or 
	registrar.printReport();

								/*
								// [OPTIONAL - do later if time]
								cout << "ChangeStudentName FritzTheCat MightyMouse\n";
								registrar.changeStudentName("FritzTheCat", "MightyMouse");
								cout << registrar << endl;  // or registrar.printReport()

								cout << "DropStudentFromCourse MightyMouse CS101.001\n";
								registrar.dropStudentFromCourse("MightyMouse", "CS101.001");
								cout << registrar << endl;  // or registrar.printReport()

								cout << "RemoveStudent FritzTheCat\n";
								registrar.removeStudent("FritzTheCat");
								cout << registrar << endl;  // or registrar.printReport()
								*/
	/*
	cout << "Purge for start of next semester\n";
	registrar.purge();
	//cout << registrar << endl;  // or 
	registrar.printReport();
	*/
	
}
