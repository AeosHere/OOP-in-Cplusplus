//Richard Yeung
//Linked List Lab
//Insert a list in the middle of another list
//Find whether a sublist exists in a list

#include <iostream>
#include <string>
using namespace std;

struct Node {
	Node(int data = 0, Node* link = nullptr) : data(data), link(link) {}
	int data;
	Node* link;
};

void listInsertHead(int entry, Node*& headPtr) {
	headPtr = new Node(entry, headPtr);
}

void printList(Node* list) {
	if (list == nullptr) { cout << "NONE"; }
	while (list != nullptr) {
		cout << list->data << ' ';
		list = list->link;
	}
	cout << endl;
}

void spliceInto(Node*& prevNode, Node*& sublist) {
	if (sublist == nullptr) { return; }
	if (prevNode == nullptr) { 
		prevNode = sublist; 
		return;
	}
	Node* successor = prevNode->link;
	prevNode->link = sublist;
	while (sublist->link != nullptr) {
		sublist = sublist->link;
	}
	sublist->link = successor;
}

Node* isSubList(Node* list, Node* sublist) {
	if (sublist == nullptr) { return list; }
	if (list == nullptr) { return nullptr; }
	Node* listCurr = list;
	Node* sublistCurr = sublist;
	Node* idx = nullptr;
	while (listCurr) {
		if (listCurr->data != sublistCurr->data && idx != nullptr) {
			listCurr = idx;
			idx = nullptr;
			sublistCurr = sublist;
			listCurr = listCurr->link;
		}
		else if (listCurr->data != sublistCurr->data) {
			listCurr = listCurr->link;
		}
		/*
		else if (listCurr->data == sublistCurr->data && idx == nullptr) {
			idx = listCurr;
			listCurr = listCurr->link;
			sublistCurr = sublistCurr->link;
			if (sublistCurr == nullptr) {
				return idx;
			}
		}
		*/
		else if (listCurr->data == sublistCurr->data) {
			if (idx == nullptr) {
				idx = listCurr;
			}
			listCurr = listCurr->link;
			sublistCurr = sublistCurr->link;
			if (sublistCurr == nullptr) {
				return idx;
			}
		}
	}
	return nullptr;
}

int main() {
	cout << "Part 1" << endl;
	Node* list = nullptr;
	listInsertHead(1, list);
	listInsertHead(9, list);
	listInsertHead(7, list);
	listInsertHead(5, list);
	cout << "List 1 Before Splice: ";
	printList(list);
	Node* list2 = nullptr;
	listInsertHead(2, list2);
	listInsertHead(3, list2);
	listInsertHead(6, list2);
	cout << "List 2 Before Splice: ";
	printList(list2);
	cout << "List 3 (empty) Before Splice: ";
	Node* list3 = nullptr;
	printList(list3);
	cout << "SPLICING" << endl;
	cout << "Test 1: Splicing a list into the middle of a list: ";
	spliceInto(list->link, list2);
	printList(list);
	cout << "Test 2: Splicing an empty list into the middle of a list: ";
	spliceInto(list->link, list3);
	printList(list);
	cout << "Test 3: Splicing a an empty list into an empty list: ";
	spliceInto(list3, list3);
	printList(list3);
	cout << "Test 4: Splicing a list into an empty list: ";
	spliceInto(list3, list);
	printList(list3);

	cout << endl;


	cout << "Part 2 " << endl;
	cout << "Test 1: Checking whether the sublist exists in the middle of list 1" << endl;
	cout << "List 1: ";
	Node* list4 = nullptr;
	listInsertHead(9, list4);
	listInsertHead(2, list4);
	listInsertHead(3, list4);
	listInsertHead(6, list4);
	listInsertHead(1, list4);
	listInsertHead(9, list4);
	listInsertHead(2, list4);
	listInsertHead(3, list4);
	listInsertHead(6, list4);
	listInsertHead(7, list4);
	listInsertHead(5, list4);
	printList(list4);
	cout << "Sublist 1: ";
	Node* sublist1 = nullptr;
	listInsertHead(9, sublist1);
	listInsertHead(2, sublist1);
	listInsertHead(3, sublist1);
	listInsertHead(6, sublist1);
	printList(sublist1);
	cout << "Insertion Index: ";
	Node* idx = isSubList(list4, sublist1);
	printList(idx);

	cout << "Test 2: Checking whether the sublist exist at the end of the list 2" << endl;
	cout << "List 2: ";
	Node* list5 = nullptr;
	listInsertHead(4, list5);
	listInsertHead(2, list5);
	listInsertHead(2, list5);
	listInsertHead(2, list5);
	listInsertHead(2, list5);
	listInsertHead(2, list5);
	printList(list5);
	cout << "Sublist 2: ";
	Node* sublist2 = nullptr;
	listInsertHead(4, sublist2);
	listInsertHead(2, sublist2);
	listInsertHead(2, sublist2);
	listInsertHead(2, sublist2);
	printList(sublist2);
	cout << "Insertion Index: ";
	Node* idx2 = isSubList(list5, sublist2);
	printList(idx2);

	cout << "Test 3: Checking whether the list 3 is a sublist of itself" << endl;
	cout << "List 3: ";
	Node* list6 = nullptr;
	listInsertHead(4, list6);
	listInsertHead(2, list6);
	listInsertHead(2, list6);
	printList(list6);
	cout << "Sublist 3: ";
	Node* sublist3 = nullptr;
	listInsertHead(4, sublist3);
	listInsertHead(2, sublist3);
	listInsertHead(2, sublist3);
	printList(sublist3);
	cout << "Insertion Index: ";
	Node* idx3 = isSubList(list6, sublist3);
	printList(idx3);

	cout << "Test 4: Checking whether an empty list is a sublist of list 4" << endl;
	cout << "List 4: ";
	Node* list7 = nullptr;
	listInsertHead(4, list7);
	listInsertHead(2, list7);
	listInsertHead(2, list7);
	printList(list7);
	cout << "Sublist 4: ";
	Node* sublist4 = nullptr;
	printList(sublist4);
	cout << "Insertion Index: ";
	Node* idx4 = isSubList(list7, sublist4);
	printList(idx4);

	cout << "Test 5: Checking whether an empty list is a sublist of an empty list" << endl;
	cout << "List 5: ";
	Node* list8 = nullptr;
	printList(list8);
	cout << "Sublist 5: ";
	Node* sublist5 = nullptr;
	printList(sublist5);
	cout << "Insertion Index: ";
	Node* idx5 = isSubList(list8, sublist5);
	printList(idx5);

	cout << "Test 6: Checking whether a list is a sublist of an empty list" << endl;
	cout << "List 6: ";
	Node* list9 = nullptr;
	printList(list9);
	cout << "Sublist 6: ";
	printList(sublist3);
	cout << "Insertion Index: ";
	Node* idx6 = isSubList(list9, sublist3);
	printList(idx6);

	cout << "Test 7: Checking whether the sublist does not exists in a list" << endl;
	cout << "List 7: ";
	Node* list10 = nullptr;
	listInsertHead(1, list10);
	listInsertHead(9, list10);
	listInsertHead(2, list10);
	listInsertHead(3, list10);
	listInsertHead(6, list10);
	listInsertHead(7, list10);
	listInsertHead(5, list10);
	printList(list10);
	cout << "Sublist: ";
	Node* sublist7 = nullptr;
	listInsertHead(3, sublist7);
	listInsertHead(2, sublist7);
	listInsertHead(6, sublist7);
	printList(sublist7);
	cout << "Insertion Index: ";
	Node* idx7 = isSubList(list7, sublist7);
	printList(idx7);

	cout << "Test 8: Checking whether the sublist does not exists in a list" << endl;
	cout << "List 8: ";
	Node* list11 = nullptr;
	listInsertHead(1, list11);
	listInsertHead(9, list11);
	listInsertHead(2, list11);
	listInsertHead(3, list11);
	listInsertHead(6, list11);
	listInsertHead(7, list11);
	listInsertHead(5, list11);
	printList(list11);
	cout << "Sublist: ";
	Node* sublist8 = nullptr;
	listInsertHead(4, sublist8);
	listInsertHead(1, sublist8);
	listInsertHead(9, sublist8);
	listInsertHead(2, sublist8);
	printList(sublist8);
	cout << "Insertion Index: ";
	Node* idx8 = isSubList(list11, sublist8);
	printList(idx8);
	cout << "Test 9: Checking whether size 1 sublist exists in list" << endl;
	cout << "List 9: ";
	Node* list12 = nullptr;
	listInsertHead(9, list12);
	listInsertHead(1, list12);
	printList(list12);
	cout << "Sublist: ";
	Node* sublist9 = nullptr;
	listInsertHead(9, sublist9);
	printList(sublist9);
	cout << "Insertion Index: ";
	Node* idx9 = isSubList(list12, sublist9);
	printList(idx9);

}
