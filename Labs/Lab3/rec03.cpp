#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Task 1 (Making a sandwich class and sandwich object)
class Sandwich1 {
	int numBread;
	int numCheese;
	double numMayo;
	int numTomato;
	double numMustard;
};

//Task 2 (Making a sandwich object display method)
class Sandwich2 {
public:
	void display() const {
		cout << "Slices of Bread: " << numBread << endl;
		cout << "Slices of Cheese: " << numCheese << endl;
		cout << "Ounces of Mayo: " << numMayo << endl;
		cout << "Slices of Tomato: " << numTomato << endl;
		cout << "Ounces of Mustard: " << numMustard << endl;
		cout << endl;
	}
private:
	int numBread;
	int numCheese;
	double numMayo;
	int numTomato;
	double numMustard;
};

//Task 3 (bad way to initialize the mayo amount to 1)
class Sandwich3 {
public:
	void display() const {
		cout << "Slices of Bread: " << numBread << endl;
		cout << "Slices of Cheese: " << numCheese << endl;
		cout << "Ounces of Mayo: " << numMayo << endl;
		cout << "Slices of Tomato: " << numTomato << endl;
		cout << "Ounces of Mustard: " << numMustard << endl;
		cout << endl;
	}
private:
	int numBread;
	int numCheese;
	double numMayo = 1;
	int numTomato;
	double numMustard;
};

//Task 4 (Using initialization list to set mayo amount to 0.1)
class Sandwich4 {
public:
	Sandwich4() : numMayo(0.1) {};
	void display() const {
		cout << "Slices of Bread: " << numBread << endl;
		cout << "Slices of Cheese: " << numCheese << endl;
		cout << "Ounces of Mayo: " << numMayo << endl;
		cout << "Slices of Tomato: " << numTomato << endl;
		cout << "Ounces of Mustard: " << numMustard << endl;
		cout << endl;
	}
private:
	int numBread;
	int numCheese;
	double numMayo;
	int numTomato;
	double numMustard;
};

//Task 5 (Having values for default sandwich/custom sandwich)
class Sandwich5 {
public:
	Sandwich5(int reqTomato = 2, int reqCheese = 1, double reqMustard = 0.05, double reqMayo = 0.1) : 
		numBread(2), numCheese(reqCheese), numMayo(reqMayo), numTomato(reqTomato), numMustard(reqMayo) {};
	void display() const {
		cout << "Slices of Bread: " << numBread << endl;
		cout << "Slices of Cheese: " << numCheese << endl;
		cout << "Ounces of Mayo: " << numMayo << endl;
		cout << "Slices of Tomato: " << numTomato << endl;
		cout << "Ounces of Mustard: " << numMustard << endl;
		cout << endl;
	}
private:
	int numBread;
	int numCheese;
	double numMayo;
	int numTomato;
	double numMustard;
};

//Task 6 (Creating accessor methods to get ingredient amount)
class Sandwich6 {
public:
	Sandwich6(int reqTomato = 2, int reqCheese = 1, double reqMustard = 0.05, double reqMayo = 0.1) :
		numBread(2), numCheese(reqCheese), numMayo(reqMayo), numTomato(reqTomato), numMustard(reqMayo) {};
	void display() const {
		cout << "Slices of Bread: " << numBread << endl;
		cout << "Slices of Cheese: " << numCheese << endl;
		cout << "Ounces of Mayo: " << numMayo << endl;
		cout << "Slices of Tomato: " << numTomato << endl;
		cout << "Ounces of Mustard: " << numMustard << endl;
		cout << endl;
	}

	int getNumBread() const { return numBread; }
	int getNumCheese() const { return numCheese; }
	double getNumMayo() const { return numMayo; }
	int getNumTomato() const { return numTomato; }
	double getNumMustard() const { return numMustard; }

private:
	int numBread;
	int numCheese;
	double numMayo;
	int numTomato;
	double numMustard;
};

//Task 7 (Creating mutators to change ingredient amount)
class Sandwich7 {
public:
	Sandwich7(int reqTomato = 2, int reqCheese = 1, double reqMustard = 0.05, double reqMayo = 0.1) :
		numBread(2), numCheese(reqCheese), numMayo(reqMayo), numTomato(reqTomato), numMustard(reqMayo) {};
	void display() const {
		cout << "Slices of Bread: " << numBread << endl;
		cout << "Slices of Cheese: " << numCheese << endl;
		cout << "Ounces of Mayo: " << numMayo << endl;
		cout << "Slices of Tomato: " << numTomato << endl;
		cout << "Ounces of Mustard: " << numMustard << endl;
		cout << endl;
	}

	int getNumBread() const { return numBread; }
	int getNumCheese() const { return numCheese; }
	double getNumMayo() const { return numMayo; }
	int getNumTomato() const { return numTomato; }
	double getNumMustard() const { return numMustard; }

	void changeNumBread(int breadAmt) { numBread = breadAmt; }
	void changeNumCheese(int cheeseAmt) { numCheese = cheeseAmt; }
	void changeNumMayo(int mayoAmt) { numMayo = mayoAmt; }
	void changeNumTomato(int tomatoAmt) { numTomato = tomatoAmt; }
	void changeNumMustard(int mustardAmt) { numMustard = mustardAmt; }

private:
	int numBread;
	int numCheese;
	double numMayo;
	int numTomato;
	double numMustard;
};

//Task 8 (Making bread a CONSTANT value)
class Sandwich8 {
public:
	Sandwich8(int reqTomato = 2, int reqCheese = 1, double reqMustard = 0.05, double reqMayo = 0.1) :
		numBread(2), numCheese(reqCheese), numMayo(reqMayo), numTomato(reqTomato), numMustard(reqMayo) {};
	void display() const {
		cout << "Slices of Bread: " << numBread << endl;
		cout << "Slices of Cheese: " << numCheese << endl;
		cout << "Ounces of Mayo: " << numMayo << endl;
		cout << "Slices of Tomato: " << numTomato << endl;
		cout << "Ounces of Mustard: " << numMustard << endl;
		cout << endl;
	}

	int getNumBread() const { return numBread; }
	int getNumCheese() const { return numCheese; }
	double getNumMayo() const { return numMayo; }
	int getNumTomato() const { return numTomato; }
	double getNumMustard() const { return numMustard; }

	void changeNumCheese(int cheeseAmt) { numCheese = cheeseAmt; }
	void changeNumMayo(int mayoAmt) { numMayo = mayoAmt; }
	void changeNumTomato(int tomatoAmt) { numTomato = tomatoAmt; }
	void changeNumMustard(int mustardAmt) { numMustard = mustardAmt; }

private:
	const int numBread;
	int numCheese;
	double numMayo;
	int numTomato;
	double numMustard;
};

//Task 10 (Creating the SandwichTruck class)
class SandwichTruck1 {
public:
	void checkBeforeLeaving() {
		for (size_t i = 0; i < sandwiches.size(); ++i) {
			cout << "Customer " << i + 1 << " Sandwich Ingredients: " << endl;
			sandwiches[i].display();
		}
	}
	void insertSandwich(const Sandwich8& s) {
		sandwiches.push_back(s);
	}
private:
	vector<Sandwich8> sandwiches;
};

int main()
{
	//Task 1 (Create Sandwich class and make a Sandwich object)
	Sandwich1 s1;

	//Task 2 (Create a Sandwich object display method
	Sandwich2 s2;
	cout << "Task 2: " << endl;
	s2.display();

	//Task 3 (Bad way of intializing the mayo amount to 1)
	Sandwich3 s3;
	cout << "Task 3: " << endl;
	s3.display();

	//Task 4 (Using initialization list to set mayo to 0.1)
	Sandwich4 s4;
	cout << "Task 4: " << endl;
	s4.display();

	//Task 5 (Having values for default sandwich/custom sandwich)
	Sandwich5 s51;
	Sandwich5 s52(9, 9, 9, 9);
	cout << "Task 5: " << endl;
	s51.display();
	s52.display();

	//Task 6 (Creating accessors to get ingredient amount)
	Sandwich6 s6;
	cout << "Task 6" << endl;
	cout << "Bread: " << s6.getNumBread() << endl;
	cout << "Cheese: " << s6.getNumCheese() << endl;
	cout << "Mayo: " << s6.getNumMayo() << endl;
	cout << "Tomato: " << s6.getNumTomato() << endl;
	cout << "Mustard: " << s6.getNumMustard() << endl;
	cout << endl;

	//Task 7 (Creating mutators to change ingredient amount)
	Sandwich7 s7;
	cout << "Task 7: " << endl;
	s7.display();
	s7.changeNumBread(900);
	s7.changeNumCheese(900);
	s7.changeNumMayo(900);
	s7.changeNumMustard(900);
	s7.changeNumTomato(900);
	s7.display();

	//Task 8 (Making slices of bread amount CONSTANT)
	vector<Sandwich8> s8sandwiches;
	Sandwich8 s8;
	s8sandwiches.push_back(s8);

	//Task 10 (Making a SandwichTruck class)
	SandwichTruck1 sT1;
	Sandwich8 s101;
	Sandwich8 s102(28, 37, 29, 10);
	cout << "Task 10: " << endl;
	sT1.insertSandwich(s101);
	sT1.insertSandwich(s102);
	sT1.checkBeforeLeaving();

	//Task 11 (Simulating customer's sandwich requests)
	SandwichTruck1 sT2;
	Sandwich8 c1;
	Sandwich8 c2;
	c2.changeNumMustard(0);
	Sandwich8 c3(2, 2);
	Sandwich8 c4;
	sT2.insertSandwich(c1);
	sT2.insertSandwich(c2);
	sT2.insertSandwich(c3);
	sT2.insertSandwich(c4);
	cout << "Task 11: " << endl;
	sT2.checkBeforeLeaving();
	cout << "Customer 2's Sandwich Mustard Amount: " << c2.getNumMustard() << endl;
}

