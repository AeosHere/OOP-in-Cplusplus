/*
Recitation 06
CS2124
Richard Yeung
Focus: Dynamic arrays and copy control.
*/

#include <string>
#include <iostream>
using namespace std;

class Position {
public:
	Position(const string& aTitle, double aSalary)
		: title(aTitle), salary(aSalary) {}
	const string& getTitle() const { return title; }
	double getSalary() const { return salary; }
	void changeSalaryTo(double d) { salary = d; }
	void display(ostream& os = cout) const {
		os << '[' << title << ',' << salary << ']';
	}
private:
	string title;
	double salary;
}; // class Position

class Entry {
public:
	Entry(const string& aName, unsigned aRoom, unsigned aPhone,
		Position& aPosition)
		: name(aName), room(aRoom), phone(aPhone), pos(&aPosition) {
	}
	void display(ostream& os = cout) const {
		os << name << ' ' << room << ' ' << phone << ", ";
		pos->display(os);
	}

	string getName() const { return name; }
	unsigned getPhone() const { return phone; }

private:
	string name;
	unsigned room;
	unsigned phone;
	Position* pos;
}; // class Entry

class Directory {
public:
	Directory() {}
	
	Directory(const Directory& rhs) : size(rhs.size), capacity(rhs.capacity), entries(new Entry*[rhs.capacity]) {
		cout << "Using Copy Constructor" << endl;
		for (size_t i = 0; i < rhs.size; ++i) {
			entries[i] = new Entry(*rhs.entries[i]);
		}
		cout << "Copy Constructor Works" << endl;
	}
	
	~Directory() {
		cout << "Using Destructor" << endl;
		for (size_t i = 0; i < size; ++i) {
			delete entries[i];
		}
		delete[] entries;
		cout << "Destructor Works" << endl;
	}

	Directory& operator=(const Directory& rhs) {
		cout << "Using Assignment Operator" << endl;
		if (this != &rhs) {
			for (size_t i = 0; i < size; ++i) {
				delete entries[i];
			}
			delete[] entries;
			size = rhs.size;
			capacity = rhs.capacity;
			entries = new Entry*[rhs.capacity];
			for (size_t i = 0; i < size; ++i) {
				entries[i] = new Entry(*rhs.entries[i]);
			}
		}
		cout << "Assignment Operator Works" << endl << endl;;
		return *this;
	}
	
	unsigned operator[](const string& name) const { 
		for (size_t i = 0; i < size; ++i) {
			if (entries[i]->getName() == name) {
				return entries[i]->getPhone();
			}
		}
		return 0;
	}
	
	void add(const string& name, unsigned room, unsigned ph, Position& pos) {
		if (capacity == 0) {
			entries = new Entry*[1];
			++capacity;
		}
		if (size == capacity) {
			// something is missing!!!  Add it!
			Entry** oldEntry = entries;
			capacity *= 2;
			entries = new Entry*[capacity];
			for (size_t i = 0; i < size; ++i) {
				entries[i] = oldEntry[i];
			}
			delete[] oldEntry;
		} // if
		entries[size] = new Entry(name, room, ph, pos);
		++size;
	} // add

	void display(ostream& os = cout) const {
		for (size_t i = 0; i < size; ++i) {
			entries[i]->display(os);
			os << endl;
		}
	}
private:
	Entry** entries = nullptr;
	size_t size = 0;
	size_t capacity = 0;
}; // class Directory

void doNothing(Directory dir) { dir.display(); }

int main() {

	// Note that the Postion objects are NOT on the heap.
	Position boss("Boss", 3141.59);
	Position pointyHair("Pointy Hair", 271.83);
	Position techie("Techie", 14142.13);
	Position peon("Peonissimo", 34.79);

	// Create a Directory
	Directory d;
	d.add("Marilyn", 123, 4567, boss);
	d.display();
	
	Directory d2 = d;	// What function is being used??
	d2.add("Gallagher", 111, 2222, techie);
	d2.add("Carmack", 314, 1592, techie);
	d2.display();
	
	cout << "Calling doNothing\n";
	doNothing(d2);
	cout << "Back from doNothing\n";

	Directory d3;
	d3 = d2;
	
	// Should display 1592
	cout << d2["Carmack"] << endl;
	
} // main
