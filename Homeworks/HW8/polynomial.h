#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <vector>
#include <iostream>

struct Node {
	Node(int data = 0, Node* next = nullptr);
	int data;
	Node* next;
};

void listInsertHead(Node*& head, int data);
void listRemoveHead(Node*& head);
void listRemoveTail(Node*& head);
Node* listDuplicate(Node* head);
void clear(Node*& head);

class Polynomial {
	friend std::ostream& operator<<(std::ostream& os, const Polynomial& rhs);
	friend bool operator==(const Polynomial& lhs, const Polynomial& rhs);
public:
	Polynomial();
	Polynomial(const std::vector<int>& coeffs);
	Polynomial(const Polynomial& rhs);
	~Polynomial();
	Polynomial& operator=(const Polynomial& rhs);
	void deleteHighestDegreeZero();
	Polynomial& operator+=(const Polynomial& rhs);
	double evaluate(int xVal);

private:
	int degree;
	Node* head;
};

Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs);
bool operator!=(const Polynomial& lhs, const Polynomial& rhs);

#endif
