//Richard Yeung
// Doubly Linked List Lab

#include <cstdlib>
#include <iostream>
using namespace std;

class List {
	struct Node;

	friend ostream& operator<<(ostream& os, const List& aList) {
		Node* headC = aList.head;
		while (headC) {
			os << headC->data << " ";
			headC = headC->next;
		}
		return os;
	}
public:
	class Iterator {
		friend class List;

		friend bool operator==(const Iterator& lhs, const Iterator& rhs) {
			return lhs.curr == rhs.curr;
		}
	public:
		Iterator() : curr(nullptr) {}
		Iterator(Node* currNode) {
			curr = currNode;
		}

		Iterator& operator++() {
			curr = curr->next;
			return *this;
		}

		Iterator& operator--() {
			curr = curr->prev;
			return *this;
		}

		int& operator*() {
			return curr->data;
		}
	private:
		Node* curr;
	};

	List() : head(nullptr), tail(nullptr), listSize(0) {}
	
	List(const List& rhs) : head(nullptr), tail(nullptr), listSize(0) {
		for (Node* p = rhs.head; p != nullptr; p = p->next) {
			push_back(p->data);
		}
		cout << "List(List)" << endl;
	}

	~List() {
		clear();
		cout << "~List()" << endl;
	}

	List& operator=(const List& rhs) {
		if (this != &rhs) {
			clear();
			for (Node* p = rhs.head; p != nullptr; p = p->next) {
				push_back(p->data);
			}
		}
		cout << "List::op=(List)" << endl;
		return *this;
	}

	void push_back(int data) {
		if (tail == nullptr) {
			tail = new Node(data);
			head = tail;
			++listSize;
			return;
		}
		tail->next = new Node(data, tail);
		tail = tail->next;
		++listSize;
	}

	void push_front(int data) {
		if (head == nullptr) {
			head = new Node(data);
			tail = head;
			++listSize;
			return;
		}
		head->prev = new Node(data, nullptr, head);
		head = head->prev;
		++listSize;
	}

	void pop_back() {
		if (head == tail) {
			delete tail;
			head = nullptr;
			tail = nullptr;
			listSize = 0;
			return;
		}
		tail = tail->prev;
		delete tail->next;
		tail->next = nullptr;
		--listSize;
	}

	void pop_front() {
		if (head == tail) {
			delete head;
			head = nullptr;
			tail = nullptr;
			listSize = 0;
			return;
		}
		head = head->next;
		delete head->prev;
		head->prev = nullptr;
		--listSize;
	}

	void clear() {
		while (listSize) {
			pop_back();
		}
	}

	int operator[](size_t idx) const {
		Node* headC = head;
		for (size_t i = 0; i < idx; ++i) {
			headC = headC->next;
		}
		return headC->data;
		cerr << "INDEX NOT FOUND" << endl;
	}

	int& operator[](size_t idx) {
		Node* headC = head;
		for (size_t i = 0; i < idx; ++i) {
			headC = headC->next;
		}
		return headC->data;
		cerr << "INDEX NOT FOUND" << endl;
	}

	int& front() const {
		return head->data;
	}

	int& back() const {
		return tail->data;
	}

	size_t size() const {
		return listSize;
	}

	Iterator begin() const {
		return Iterator(head);
	}

	Iterator end() const {
		return Iterator(nullptr);
	}

	Iterator insert(Iterator iter, int data) {
		if (head == nullptr && tail == nullptr) {
			Node* insertNode = new Node(data);
			head = insertNode;
			tail = insertNode;
			iter.curr = insertNode;
		}
		else if (iter.curr == head) {
			Node* insertNode = new Node(data, nullptr, head);
			head->prev = insertNode;
			head = head->prev;
			iter.curr = insertNode;
		}
		else if (iter.curr == nullptr) {
			Node* insertNode = new Node(data, tail);
			tail->next = insertNode;
			tail = tail->next;
			iter.curr = insertNode;
		}
		else {
			Node* insertNode = new Node(data, iter.curr->prev, iter.curr->next);
			insertNode->prev->next = insertNode;
			insertNode->next->prev = insertNode;
			iter.curr = insertNode;
		}
		++listSize;
		return iter;
	}

	Iterator erase(Iterator iter) {
		if (head == nullptr) {
			iter = nullptr;
		}
		else if (head == tail) {
			++iter;
			delete iter.curr;
			head = nullptr;
			tail = nullptr;
		}
		else if (iter.curr == head) {
			++iter;
			head = head->next;
			delete head->prev;
			head->prev = nullptr;
		}
		else if (iter.curr == tail) {
			++iter;
			tail = tail->prev;
			delete tail->next;
			tail->next = nullptr;
		}
		else {
			Node* deleteNode = iter.curr;
			++iter;
			deleteNode->prev->next = deleteNode->next;
			deleteNode->next->prev = deleteNode->prev;
			delete deleteNode;
		}
		--listSize;
		return iter;
	}
private:
	struct Node {
		Node(int data = 0, Node* prev = nullptr, Node* next = nullptr) : data(data), prev(prev), next(next) {}
		int data;
		Node* prev;
		Node* next;
	};

	Node* head;
	Node* tail;
	size_t listSize;
};

bool operator!=(const List::Iterator& lhs, const List::Iterator& rhs) {
	return !(lhs == rhs);
}

void printListInfo(List& myList) {
        cout << "size: " << myList.size()
             << ", front: " << myList.front()
             << ", back(): " << myList.back()
             << ", list: " << myList << endl;
}

// Task 8
void doNothing(List aList) {
    cout << "In doNothing\n";
    printListInfo(aList);
    cout << endl;
    cout << "Leaving doNothing\n";
}    

int main() {

    // Task 1
    cout << "\n------Task One------\n";
    List myList;
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        cout << "myList.push_back(" << i*i << ");\n";
        myList.push_back(i*i);
        printListInfo(myList);
    }
    cout << "===================\n";
    cout << "Remove the items with pop_back\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.pop_back();
    }
    cout << "===================\n";
	
    // Task2
    cout << "\n------Task Two------\n";
    cout << "Fill empty list with push_front: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        cout << "myList2.push_front(" << i*i << ");\n";
        myList.push_front(i*i);
        printListInfo(myList);
    }
    cout << "===================\n";
    cout << "Remove the items with pop_front\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.pop_front();
    }
    cout << "===================\n";
	
    // Task3
    cout << "\n------Task Three------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        myList.push_back(i*i);
    }
    printListInfo(myList);
    cout << "Now clear\n";
    myList.clear();
    cout << "Size: " << myList.size() << ", list: " << myList << endl;
    cout << "===================\n";
	
    // Task4
    cout << "\n------Task Four------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
    cout << "Display elements with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
    cout << endl;
    cout << "Add one to each element with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) myList[i] += 1;
    cout << "And print it out again with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
    cout << endl;
	
    // Task 5
    cout << "\n------Task Five------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
    printListInfo(myList);
    cout << "Now display the elements in a ranged for\n";
    for (int x : myList) cout << x << ' ';
    cout << endl;
    cout << "And again using the iterator type directly:\n";
    for (List::Iterator iter = myList.begin(); iter != myList.end(); ++iter) {
        cout << *iter << ' ';
    }
    cout << endl;
    cout << "WOW!!! (I thought it was cool.)\n";
    
    // Task 6
    cout << "\n------Task Six------\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    printListInfo(myList);
    cout << "Filling an empty list with insert at begin(): "
         << "i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.begin(), i*i);
    printListInfo(myList);
    // ***Need test for insert other than begin/end***
    cout << "===================\n";
	
    // Task 7
    cout << "\n------Task Seven------\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    cout << "Erasing the elements in the list, starting from the beginning\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.erase(myList.begin());
    }
	//myList.erase(myList.begin());
    // ***Need test for erase other than begin/end***
    cout << "===================\n";
	
    // Task 8
    cout << "\n------Task Eight------\n";
    cout << "Copy control\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    printListInfo(myList);
    cout << "Calling doNothing(myList)\n";
    doNothing(myList);
    cout << "Back from doNothing(myList)\n";
    printListInfo(myList);

    cout << "Filling listTwo with insert at begin: i*i for i from 0 to 9\n";
    List listTwo;
    for (int i = 0; i < 10; ++i) listTwo.insert(listTwo.begin(), i*i);
    printListInfo(listTwo);
    cout << "listTwo = myList\n";
    listTwo = myList;
    cout << "myList: ";
    printListInfo(myList);
    cout << "listTwo: ";
    printListInfo(listTwo);
    cout << "===================\n";
}
