//Richard Yeung
//This program is written to mimic the game Warrior

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//Creates the basis of a Warrior object
struct Warrior {
	string name;
	int strength;
};

//Codes what happens when two warriors fight each other
//Compares warriors strengths and the weaker one dies while the stronger one's strength weakens by the amount of the weaker one
//Equal strengths both dies and their strength becomes 0
//Replaces the warrior in the warriors to override the existing strengths
void battle(Warrior& warrior1, Warrior& warrior2, vector<Warrior>& warriors) {
	if (warrior1.strength > warrior2.strength) {
		cout << warrior1.name << " battles " << warrior2.name << endl;
		if (warrior2.strength == 0) {
			cout << "He's dead, " << warrior1.name << endl;
		}
		else {
			warrior1.strength -= warrior2.strength;
			warrior2.strength = 0;
			cout << warrior1.name << " defeats " << warrior2.name << endl;
		}
	}
	else if (warrior2.strength > warrior1.strength) {
		cout << warrior1.name << " battles " << warrior2.name << endl;
		if (warrior1.strength == 0) {
			cout << "He's dead, " << warrior2.name << endl;
		}
		else {
			warrior2.strength -= warrior1.strength;
			warrior1.strength = 0;
			cout << warrior1.name << " has died!" << endl;
		}
	}
	else if (warrior1.strength == 0 && warrior2.strength == 0) {
		cout << warrior1.name << " battles " << warrior2.name << endl;
		cout << "Oh, NO! They're both dead! Yuck!" << endl;
	}
	else {
		cout << warrior1.name << " battles " << warrior2.name << endl;
		warrior1.strength = 0;
		warrior2.strength = 0;
		cout << "Mutual Annihiliation: " << warrior1.name << " and " << warrior2.name << " die at each other's hands" << endl;
	}
	cout << "----------------" << endl;

	for (size_t i = 0; i < warriors.size(); ++i) {
		if (warriors[i].name == warrior1.name) {
			warriors[i] = warrior1;
		}
		if (warriors[i].name == warrior2.name) {
			warriors[i] = warrior2;
		}
	}
}

//Find the warrior with the same name in the collection of warriors
Warrior findWarrior(const vector<Warrior>& warriors, const string& warriorName) {
	for (size_t i = 0; i < warriors.size(); ++i) {
		if (warriors[i].name == warriorName) {
			return warriors[i];
		}
	}
	cerr << "Warrior cannot be found" << endl;
}

//Creates a warrior with a certain name and strength
void createWarrior(vector<Warrior>& warriors, const string& warriorName, int warriorStrength) {
	Warrior aWarrior;
	aWarrior.name = warriorName;
	aWarrior.strength = warriorStrength;
	warriors.push_back(aWarrior);
}

//Displays the status of the warriors 
void showWarriorStatus(const vector<Warrior>& warriors) {
	cout << "There are: " << warriors.size() << " warriors" << endl;
	for (size_t i = 0; i < warriors.size(); ++i) {
		cout << "Warrior: " << warriors[i].name << ", strength: " << warriors[i].strength << endl;
	}
	cout << "----------------" << endl;
}

//Runs the whole Warrior simulation by looping through the vector that stores the input file words
int main()
{
	ifstream warriorFile("warriors.txt");

	if (!warriorFile) {
		cerr << "Warrior File is not found" << endl;
		exit(0);
	}

	vector<Warrior> warriors;
	string ignoreText;
	string name;
	int strength;
	string opponent1;
	string opponent2;
	while (warriorFile >> ignoreText) {
		if (ignoreText == "Warrior") {
			warriorFile >> name >> strength;
			createWarrior(warriors, name, strength);
		}
		else if (ignoreText == "Status") {
			showWarriorStatus(warriors);
		}
		else if (ignoreText == "Battle") {
			warriorFile >> opponent1 >> opponent2;
			Warrior w1 = findWarrior(warriors, opponent1);
			Warrior w2 = findWarrior(warriors, opponent2);
			battle(w1, w2, warriors);
		}
	}
}

