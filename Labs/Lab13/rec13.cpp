//Richard Yeung
//STL Practice Recitation

#include <iostream>
#include <fstream>
#include <string>
#include <vector>      // task 1
#include <list>        // task 2
#include <algorithm>   // task 3
#include <set>         // task 19
#include <map>         // task 21
using namespace std;

//Task 9
void printList(const list<int>& aList) {
	for (list<int>::const_iterator i = aList.begin(); i != aList.end(); ++i) {
		cout << *i << " ";
	}
	cout << endl;
}

//Task 10
void printListRangedFor(const list<int>& aList) {
	for (const int& i : aList) {
		cout << i << " ";
	}
	cout << endl;
}

//Task 11
void printEveryOtherInList(const list<int>& aList) {
	bool everyOther = true;
	for (auto i = aList.begin(); i != aList.end(); ++i) {
		if (everyOther) {
			cout << *i << " ";
			everyOther = false;
		}
		else {
			everyOther = true;
		}
	}
	cout << endl;
}

//Task 12
list<int>::const_iterator findItem(const list<int>& aList, int val) {
	for (list<int>::const_iterator i = aList.begin(); i != aList.end(); ++i) {
		if (*i == val) {
			return i;
		}
	}
	return aList.end();
}

//Task 13
auto findItemUsingAuto(const list<int>& aList, int val) {
	for (auto i = aList.begin(); i != aList.end(); ++i) {
		if (*i == val) {
			return i;
		}
	}
	return aList.end();
}

//Task 15 - find_if
bool isEven(int val) {
	return (val & 1) == 0;
}

//Task 16 - functor
class Even {
public:
	bool operator() (int val) const {
		return (val & 1) == 0;
	}
};

//Task 18 - ourFind function without template
list<int>::const_iterator ourFind(const list<int>::const_iterator start, const list<int>::const_iterator stop, int val) {
	cout << "This is ourFind function!" << endl;
	for (list<int>::const_iterator i = start; i != stop; ++i) {
		if (*i == val) {
			return i;
		}
	}
	return stop;
}

//Task 19 - ourFind function with template
template <typename T, typename I>
T ourFind(T start, T stop, I target) {
	cout << "We are in the template ourFind function!" << endl;
	for (T i = start; i != stop; ++i) {
		if (*i == target) {
			return i;
		}
	}
	return stop;
}


int main() {
	// 1. Create a vector with some values and display using ranged for
	cout << "Task 1:\n";
	vector<int> v1{ 5, 3, 8, 1, 9, 10 };

	for (const int& i : v1) {
		cout << i << " ";
	}

	cout << "\n=======\n";

	// 2. Initalize a list as a copy of values from the vector
	cout << "Task 2:\n";
	list<int> l1(v1.begin(), v1.end());
	for (const int& i : l1) {
		cout << i << " ";
	}

	cout << "\n=======\n";

	// 3. Sort the original vector.  Display both the vector and the list
	cout << "Task 3:\n";
	sort(v1.begin(), v1.end());

	for (const int& i : v1) {
		cout << i << " ";
	}
	cout << endl;
	for (const int& i : l1) {
		cout << i << " ";
	}

	cout << "\n=======\n";

	// 4. print every other element of the vector.
	cout << "Task 4:\n";
	for (size_t i = 0; i < v1.size(); i += 2) {
		cout << v1[i] << " ";
	}
	cout << "\n=======\n";

	// 5. Attempt to print every other element of the list using the
	// same technique.
	cout << "Task 5:\n";
	for (size_t i = 0; i < l1.size(); i += 2) {
		//cout << v2[i] << " ";
	}

	cout << "\n=======\n";

	// 6. Repeat task 4 using iterators.  Do not use auto;
	cout << "Task 6:\n";
	for (vector<int>::iterator iter = v1.begin(); iter != v1.end(); iter += 2) {
		cout << *iter << " ";
	}
	cout << "\n=======\n";

	// 7. Repeat the previous task using the list.  Again, do not use auto.
	//    Note that you cannot use the same simple mechanism to bump
	//    the iterator as in task 6.
	cout << "Task 7:\n";
	bool everyOther = true;
	for (list<int>::iterator iter = l1.begin(); iter != l1.end(); iter++) {
		if (everyOther) {
			cout << *iter << " ";
			everyOther = false;
		}
		else {
			everyOther = true;
		}
	}
	cout << "\n=======\n";

	// 8. Calling the function to print the list
	cout << "Task 8:\n";
	l1.sort();
	printList(l1);
	cout << "=======\n";

	// 9. Calling the function that uses a ranged-for to print the list, 
	cout << "Task 9:\n";
	printListRangedFor(l1);
	cout << "=======\n";

	// 10. Calling the function that, using auto,
	//     prints alterate items in the list
	cout << "Task 10:\n";
	printEveryOtherInList(l1);
	cout << "=======\n";


	// 11.  Write a function find that takes a list and value to search for.
	//      What should we return if not found
	cout << "Task 11:\n";
	list<int>::const_iterator i = findItem(l1, 3);
	cout << *i << endl;
	list<int>::const_iterator i2 = findItem(l1, 88);
	if (i2 != l1.end()) {
		cout << *i2 << endl;
	}
	else {
		cerr << "Cannot dereference the end" << endl;
	}

	cout << "=======\n";

	// 12.  Write a function find that takes a list and value to search for.
	//      What should we return if not found
	cout << "Task 11, 12:\n";
	i = findItemUsingAuto(l1, 5);
	i2 = findItemUsingAuto(l1, 78);
	cout << *i << endl;
	if (i2 != l1.end()) {
		cout << *i2 << endl;
	}
	else {
		cerr << "Cannot dereference the end" << endl;
	}
	cout << "=======\n";

	// 13. Generic algorithms: find
	cout << "Task 13:\n";
	i = find(l1.begin(), l1.end(), 5);
	cout << *i << endl;
	i2 = find(l1.begin(), l1.end(), 89);
	if (i2 != l1.end()) {
		cout << *i2 << endl;
	}
	else {
		cerr << "Cannot dereference the end" << endl;
	}
	cout << "=======\n";

	// 14. Generic algorithms: find_if
	cout << "Task 14:\n";
	i = find_if(l1.begin(), l1.end(), isEven);
	cout << *i << endl;
	
	list<int> noEven = { 3, 5, 7, 9, 11, 13 };
	i2 = find_if(noEven.begin(), noEven.end(), isEven);
	if (i2 != noEven.end()) {
		cout << *i2 << endl;
	}
	else {
		cerr << "There is no even number" << endl;
	}
	cout << "=======\n";

	// 15. Lambda and Functor
	cout << "Task 15:\n";
	Even isThisEven;
	i = find_if(l1.begin(), l1.end(), isThisEven);
	if (i != l1.end()) {
		cout << *i << endl;
	}
	else {
		cerr << "Cannot dereference the end" << endl;
	}
	cout << "=======\n";

	// 16. Generic algorithms: copy to an array
	cout << "Task 16:\n";
	int arr[6];
	copy(l1.begin(), l1.end(), arr);
	for (const int& val : arr) {
		cout << val << " ";
	}
	cout << endl;
	auto i3 = find(begin(arr), end(arr), 5);
	if (i3 != end(arr)) {
		cout << *i3 << endl;
	}
	else {
		cerr << "Cannot dereference the end" << endl;
	}
    cout << "=======\n";

    // 17
    cout << "Task 17:\n";
	i = ourFind(l1.begin(), l1.end(), 5);
	cout << *i << endl;
	i2 = ourFind(l1.begin(), l1.end(), 99);
	if (i2 != l1.end()) {
		cout << *i2 << endl;
	}
	else {
		cerr << "Cannot dereference the end" << endl;
	}
    cout << "=======\n";
    
    // 18
    cout << "Task 18:\n";
	i = ourFind(l1.begin(), l1.end(), 5);
	cout << *i << endl;
	i2 = ourFind(l1.begin(), l1.end(), 99);
	if (i2 != l1.end()) {
		cout << *i2 << endl;
	}
	else {
		cout << "Cannot dereference the end" << endl;
	}
    cout << "=======\n";

    // 19. Using a vector of strings, print a line showing 
    cout << "Task 19:\n";
	ifstream ifs("pooh-nopunc.txt");
	if (!ifs) {
		cerr << "File cannot be found" << endl;
		exit(1);
	}

	string curr;
	vector<string> distinctStrings;
	bool notIn = true;
	while (ifs >> curr) {
		for (size_t i = 0; i < distinctStrings.size(); ++i) {
			if (distinctStrings[i] == curr) {
				notIn = false;
				break;
			}
			else {
				notIn = true;
			}
		}
		if (notIn) {
			distinctStrings.push_back(curr);
			notIn = true;
		}
	}
	for (const string& str : distinctStrings) {
		cout << str << " ";
	}
	cout << endl;
	cout << "Size: " << distinctStrings.size() << endl;
	ifs.clear();
	ifs.seekg(0);	
	cout << "\n=======\n";
	
    // 20.
    cout << "Task 20:\n";
	set<string> distinctStringsSet;
	while (ifs >> curr) {
		distinctStringsSet.insert(curr);
	}
	for (const string& str : distinctStringsSet){
		cout << str << " ";
	}
	cout << endl;
	cout << "Size: " << distinctStringsSet.size() << endl;
	ifs.clear();
	ifs.seekg(0);

    cout << "=======\n";
	
    // 21. word coocurrence
    cout << "Task 21:\n";
	int idx = 0;
	map<string, vector<int>> distinctStringsMap;
	while (ifs >> curr) {
		distinctStringsMap[curr].push_back(idx);
		idx += 1;
	}
	for (auto i : distinctStringsMap) {
		cout << i.first << ": ";
		for (size_t idx = 0; idx < i.second.size(); ++idx) {
			cout << i.second[idx] << " ";
		}
		cout << endl;
	}
	cout << "Size: " << distinctStringsMap.size() << endl;
	cout << "=======\n";
	ifs.close();
}
