#include "polynomial.h"
#include <cmath>
using namespace std;

Node::Node(int data, Node* next) : data(data), next(next) {}

void listInsertHead(Node*& head, int data) {
	head = new Node(data, head);
}

void listRemoveHead(Node*& head) {
	if (head) {
		Node* victim = head;
		head = head->next;
		delete victim;
	}
}

void listRemoveTail(Node*& head) {
	if (head == nullptr) return;
	if (head->next == nullptr) {
		delete head;
		head = nullptr;
		return;
	}
	Node* p = head;
	while (p->next->next != nullptr) {
		p = p->next;
	}
	delete p->next;
	p->next = nullptr;
}

Node* listDuplicate(Node* head) {
	if (head == nullptr) { return nullptr; }
	Node* result = new Node(head->data);
	Node* p = head->next;
	Node* last = result;

	while (p != nullptr) {
		last->next = new Node(p->data);
		p = p->next;
		last = last->next;
	}
	return result;
}

void clear(Node*& head) {
	while (head) { listRemoveHead(head); }
}

//Prints out a polynomial from its highest degree to lowest degree
ostream& operator<<(ostream& os, const Polynomial& rhs) {
	if (rhs.head == nullptr && rhs.degree == 0) {
		os << "";
		return os;
	}
	if (rhs.head != nullptr && rhs.degree == 0) {
		os << rhs.head->data;
		return os;
	}
	int degreeC = rhs.degree;

	vector<int> coeffs;
	//Stores the coefficients in the linked list into a vector from highest to lowest degree
	for (Node* p = rhs.head; p != nullptr; p = p->next) {
		coeffs.insert(coeffs.begin(), p->data);
	}
	os << coeffs[0] << "x^" << degreeC;
	degreeC -= 1;

	for (size_t i = 1; i < coeffs.size(); ++i) {
		if (coeffs[i] == 0) {
			os << "";
		}
		else if (degreeC == 0) {
			if (coeffs[i] < 0) {
				os << " " << coeffs[i];
			}
			else {
				os << " + " << coeffs[i];
			}
		}
		else if (coeffs[i] < 0) {
			os << " " << coeffs[i] << "x^" << degreeC;
		}
		else if (coeffs[i] > 0) {
			os << " + " << coeffs[i] << "x^" << degreeC;
		}
		degreeC -= 1;
	}
	return os;
}
//Returns whether two polynomials are equal
bool operator==(const Polynomial& lhs, const Polynomial& rhs) {
	//Both polynomial need to have same degree first
	if (lhs.degree == rhs.degree) {
		Node* lhsCurr = lhs.head;
		Node* rhsCurr = rhs.head;
		//Traverses both linked lists and checks if both have the same coeffiecients
		while (lhsCurr && rhsCurr) {
			if (lhsCurr->data != rhsCurr->data) {
				return false;
			}
			lhsCurr = lhsCurr->next;
			rhsCurr = rhsCurr->next;
		}
		return true;
	}
	return false;
}

//Default constructor - sets degree and head to 0
Polynomial::Polynomial() : degree(0), head(0) {}

//Constructor that takes in a vector of coefficients
Polynomial::Polynomial(const vector<int>& coeffs) : degree(coeffs.size() - 1), head(nullptr) {
	//The coeffs are stored in reverse in the linked lists by placing at the head every time
	for (size_t i = 0; i < coeffs.size(); ++i) {
		listInsertHead(head, coeffs[i]);
	}
	//If the highest degree coeff is 0, gets rid of it
	deleteHighestDegreeZero();
}

//Copy constructor - takes the content of rhs, makes new copy of it, and sets this to it
Polynomial::Polynomial(const Polynomial& rhs) {
	degree = rhs.degree;
	head = listDuplicate(rhs.head);
}

//Destructor - deletes every node in the linked lists 
Polynomial::~Polynomial() {
	clear(head);
}

//Equals operator - clears the contents of this and takes the content of rhs, 
//	makes new copy of it, and sets this to it
Polynomial& Polynomial::operator=(const Polynomial& rhs) {
	if (this != &rhs) {
		clear(head);
		degree = rhs.degree;
		head = listDuplicate(rhs.head);
	}
	return *this;
}

//Fixes the cases where the coefficient of the highest degree is 0
//Or when the consecutive highest degree coeffiecients are all 0
void Polynomial::deleteHighestDegreeZero() {
	vector<int> coeffs;
	for (Node* p = head; p != nullptr; p = p->next) {
		coeffs.insert(coeffs.begin(), p->data);
	}

	//Remove the highest degree coeffs that are 0 and decrease degree
	unsigned idx = 0;
	while (coeffs[idx] == 0 && idx < coeffs.size() - 1) {
		listRemoveTail(head);
		degree -= 1;
		idx += 1;
	}
}

//Adds two polynomials together and returns the value
Polynomial& Polynomial::operator+=(const Polynomial& rhs) {
	Node* headC = head;
	Node* rhsHeadC = rhs.head;
	Node* tail = nullptr;

	//Case 1 : Both polynomial degrees are the same or rhs degree is less than this degree
	//Go through both linked lists, add the value from the second to the first
	while (headC && rhsHeadC) {
		//If the case is that rhs degree is greater than this degree
		//Have a pointer continue where headC left off
		if (headC->next == nullptr) {
			tail = headC;
		}
		headC->data += rhsHeadC->data;
		headC = headC->next;
		rhsHeadC = rhsHeadC->next;
	}
	//Case 2 : rhs degree is greater than this degree
	//Create a new node and have the data equal to where the rhs coeff left off
	//Continue going through both linked lists until the end
	if (rhsHeadC) {
		while (rhsHeadC) {
			tail->next = new Node(rhsHeadC->data);
			tail = tail->next;
			rhsHeadC = rhsHeadC->next;
			degree += 1;
		}
	}
	deleteHighestDegreeZero();
	return *this;
}

//Evaluates a polynomial expression by a given x-value
//If polynomial is only a constant, return that constant value
//Else go through the linked list, evaluate the terms and add to the sum
//At the end return the sum
//Made it double return type because of a double to int conversion loss warning
double Polynomial::evaluate(int xVal) {
	if (degree == 0) {
		return head->data;
	}
	double sum = head->data;
	int degreeC = 1;
	Node* curr = head->next;
	while (curr) {
		sum += curr->data * pow(xVal, degreeC);
		curr = curr->next;
		++degreeC;
	}
	return sum;
}

//Returns the copied value of adding two polynomials
Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs) {
	Polynomial result = lhs;
	result += rhs;
	return result;
}

//Returns whether two polynomials are not equal
bool operator!=(const Polynomial& lhs, const Polynomial& rhs) {
	return !(lhs == rhs);
}
