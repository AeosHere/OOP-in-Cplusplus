#include <iostream>
#include <vector>
using namespace std;

class PrintedMaterial {
public:
	PrintedMaterial(unsigned numOfPages) : numberOfPages(numOfPages) {}
	virtual void displayNumPages(ostream& os = cout) const = 0;
protected:
private:
	unsigned numberOfPages;
};
void PrintedMaterial::displayNumPages(ostream& os) const {
	os << numberOfPages << " pages";
}

class Magazine : public PrintedMaterial {
public:
	Magazine(unsigned numOfPages) : PrintedMaterial(numOfPages) {}
	void displayNumPages(ostream& os = cout) const {
		os << "I am a Magazine with ";
		PrintedMaterial::displayNumPages(os);
		os << endl;
	}
protected:
private:
};

class Book : public PrintedMaterial {
public:
	Book(unsigned numOfPages) : PrintedMaterial(numOfPages) {}
	void displayNumPages(ostream& os = cout) const {
		os << "I am a Book with ";
		PrintedMaterial::displayNumPages(os);
		os << endl;
	}
protected:
private:
};

class TextBook : public Book {
public:
	TextBook(unsigned numPages, unsigned numIndxPgs) : Book(numPages), numOfIndexPages(numIndxPgs) {}
	void displayNumPages(ostream& os = cout) const {
		os << "I am a Textbook with ";
		PrintedMaterial::displayNumPages(os);
		os << " and " << numOfIndexPages << " index pages" << endl;
	}
protected:
private:
	unsigned numOfIndexPages;
};

class Novel : public Book {
public:
	Novel(unsigned numPages) : Book(numPages) {}
	void displayNumPages(ostream& os = cout) const {
		os << "I am a Novel with ";
		PrintedMaterial::displayNumPages(os);
		os << endl;
	}
protected:
private:
};

void displayNumberOfPages(const PrintedMaterial& aPM) {
	aPM.displayNumPages();
}

ostream& operator<<(ostream& os, const PrintedMaterial& aPM) {
	aPM.displayNumPages(os);
	return os;
}

// tester/modeler code
int main()
{
	//Task 1 2 3 4 5 6
	//TextBook t;
	//Novel n;
	//Magazine m;

	//t.displayNumPages();
	//n.displayNumPages();
	//m.displayNumPages();

	//Task 7 8
	TextBook t(5430, 234);
	Novel n(213);
	Magazine m(6);
	Book b(123456789);

	cout << "Calling the member's displayNumPages()" << endl;
	t.displayNumPages();
	n.displayNumPages();
	m.displayNumPages();
	b.displayNumPages();
	cout << "Using output operator" << endl;
	cout << t;
	cout << n;
	cout << m; 
	cout << b << endl;

	//Task 9
	//PrintedMaterial pm = t; // like putting a t into a vector of PrintedMaterials
	//pm.displayNumPages();

	//Task 10
	cout << "Using a PrintedMaterial pointer" << endl;
	PrintedMaterial* pmPtr;
	pmPtr = &t;
	// instead of putting an actual PrintedMaterial
	// object into the vector, we put a pointer to
	// a PrintedMaterial object (t) into a vector
	// of pointers-to-PrintedMaterial
	// (that is, pointers to the Base class)
	// we'll be "managing" our objects by using
	// pointers to PrintedMaterial values.
	pmPtr->displayNumPages();
	cout << "Using output operator" << endl;
	cout << *pmPtr << endl;

	cout << "Passing by constant reference" << endl;
	displayNumberOfPages(t);
	displayNumberOfPages(n);
	displayNumberOfPages(m);
	displayNumberOfPages(b);
	cout << "Using output operator" << endl;
	cout << t;
	cout << n;
	cout << m; 
	cout << b << endl;

	//Task 15
	cout << "Vector of PrintedMaterial pointers and displaying" << endl;
	vector<PrintedMaterial*> pmPointers;
	pmPointers.push_back(&t);
	pmPointers.push_back(&n);
	pmPointers.push_back(&m);
	pmPointers.push_back(&b);
	for (size_t i = 0; i < pmPointers.size(); ++i) {
		pmPointers[i]->displayNumPages();
	}
	cout << "Using output operator" << endl;
	for (size_t i = 0; i < pmPointers.size(); ++i) {
		cout << *pmPointers[i];
	}
}
