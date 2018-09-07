#include <string>
#include <vector>
#include <iostream>

using namespace std;

const int WEEKS = 14;

class Section {
public:
	Section(const string& sN, const string& sD, int sT) : sectionName(sN), sectionTimeSlot(sD, sT) {}
	void display() const {
		cout << "Section: " << sectionName << ", Time Slot:"; 
		sectionTimeSlot.display();
		cout << ", Students: ";
		if (sectionStudents.size() == 0) {
			cout << "None" << endl;
		}
		else {
			cout << endl;
			for (size_t i = 0; i < sectionStudents.size(); ++i) {
				sectionStudents[i]->display();
				cout << endl;
			}
		}
	}
	void addStudent(const string& studentName) {
		Student* s = new Student(studentName);
		sectionStudents.push_back(s);
	}

	size_t findStudent(const string& studentName) {
		for (size_t i = 0; i < sectionStudents.size(); ++i) {
			if (sectionStudents[i]->getStudentName() == studentName) {
				return i;
			}
		}
		return sectionStudents.size();
	}

	void changeStudentGrade(const string& studentName, int grade, int week) {
		size_t recordIdx = findStudent(studentName);
		sectionStudents[recordIdx]->changeGrade(grade, week);
	}

	Section(const Section& other) : sectionName(other.sectionName), sectionTimeSlot(other.sectionTimeSlot) {
		for (size_t i = 0; i < other.sectionStudents.size(); ++i) {
			Student* copyStudent = new Student(*(other.sectionStudents[i]));
			sectionStudents.push_back(copyStudent);
		}
	}

	~Section() {
		cout << "Section " << sectionName << " is being deleted" << endl;
		for (size_t i = 0; i < sectionStudents.size(); ++i) {
			cout << "Deleting " << sectionStudents[i]->getStudentName() << endl;
			delete sectionStudents[i];
		}
	}

private:
	string sectionName;

	class TimeSlot {
	public:
		TimeSlot(const string& sD, int sT) : sectionDay(sD), sectionTime(sT) {}
		void display() const { 
			cout << "[Day: " << sectionDay << ", Start time : " << sectionTime % 12;
			if (sectionTime <= 12) {
				cout << "am]";
			}
			else {
				cout << "pm]";
			}
		}
	private:
		string sectionDay;
		unsigned int sectionTime;
	};

	TimeSlot sectionTimeSlot;

	class Student {
	public:
		Student(const string& sN) : studentName(sN), studentGrades(WEEKS, -1) {}
		void display() const {
			cout << "Name: " << studentName << ", Grades: ";
			for (size_t i = 0; i < studentGrades.size(); ++i) {
				 cout << studentGrades[i] << " ";
			}
		}
		
		void changeGrade(int grade, int week) {
			studentGrades[week] = grade;
		}
		string getStudentName() const { return studentName; }
	private:
		string studentName;
		vector<int> studentGrades;
	};
	
	vector<Student*> sectionStudents;
};

class LabWorker {
public:
	LabWorker(const string& name) : labWorkerName(name), section(nullptr) {}
	void display() const {
		if (section == nullptr) {
			cout << labWorkerName << " does not have a section" << endl;
		}
		else {
			cout << labWorkerName << " has ";
			section->display();
		}
	}
	void addSection(Section& sec) {
		section = &sec;
	}
	void addGrade(const string& studentName, int studentGrade, int week) {
		section->changeStudentGrade(studentName, studentGrade, week - 1);
	}
private:
	string labWorkerName;
	Section* section;
};


// Test code
void doNothing(Section sec) { sec.display(); }

int main() {

	cout << "Test 1: Defining a section\n";
	 Section secA2("A2", "Tuesday", 16);
	 secA2.display();

	cout << "\nTest 2: Adding students to a section\n";
	 secA2.addStudent("John");
	 secA2.addStudent("George");
	 secA2.addStudent("Paul");
	 secA2.addStudent("Ringo");
	 secA2.display();

	cout << "\nTest 3: Defining a lab worker.\n";
	 LabWorker moe( "Moe" );
	 moe.display();

	cout << "\nTest 4: Adding a section to a lab worker.\n";
	 moe.addSection( secA2 );
	 moe.display();

	cout << "\nTest 5: Adding a second section and lab worker.\n";
	 LabWorker jane( "Jane" );
	 Section secB3( "B3", "Thursday", 11 );
	 secB3.addStudent("Thorin");
	 secB3.addStudent("Dwalin");
	 secB3.addStudent("Balin");
	 secB3.addStudent("Kili");
	 secB3.addStudent("Fili");
	 secB3.addStudent("Dori");
	 secB3.addStudent("Nori");
	 secB3.addStudent("Ori");
	 secB3.addStudent("Oin");
	 secB3.addStudent("Gloin");
	 secB3.addStudent("Bifur");
	 secB3.addStudent("Bofur");
	 secB3.addStudent("Bombur");
	 jane.addSection( secB3 );
	 jane.display();

	cout << "\nTest 6: Adding some grades for week one\n";
	 moe.addGrade("John", 17, 1);  
	 moe.addGrade("Paul", 19, 1);  
	 moe.addGrade("George", 16, 1);  
	 moe.addGrade("Ringo", 7, 1);  
	 moe.display();

	cout << "\nTest 7: Adding some grades for week three (skipping week 2)\n";
	 moe.addGrade("John", 15, 3);  
	 moe.addGrade("Paul", 20, 3);  
	 moe.addGrade("Ringo", 0, 3);  
	 moe.addGrade("George", 16, 3);  
	 moe.display();

	cout << "\nTest 8: We're done (almost)! \nWhat should happen to all those students (or rather their records?)\n";

	cout << "\nTest 9: Oh, IF you have covered copy constructors in lecture, then make sure the following call works\n";
	 doNothing(secA2);
	 cout << "Back from doNothing\n\n";

} // main
