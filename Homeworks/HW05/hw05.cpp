//by Richard Yeung

//This program simulates a medieval warfare between nobles
//Nobles can hire, fire, and battle other nobles

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Warrior {
public:
	//Warrior constructor that creates a Warrior object given a name and strength
	Warrior(const string& warriorName, int warriorStrength) : name(warriorName), strength(warriorStrength) {}

	//Returns the name of this warrior
	const string& getName() const { return name; }

	//Returns the strength of this warrior
	int getStrength() const { return strength; }

	//Displays this warrior's name and strength
	void display() const {
		cout << name << ": " << strength << endl;
	}

	//Changes this warrior's strength by a certain ratio
	void changeStrength(double armyRatio) {
		strength *= armyRatio;
	}

private:
	string name;
	int strength;
};

class Noble {
public:
	//Creates a Noble object given a name
	Noble(const string& nobleName) : name(nobleName) {}
	
	//Noble destructor that deletes this noble's warrior pointers
	~Noble() {
		for (size_t i = 0; i < warriors.size(); ++i) {
			delete warriors[i];
		}
		warriors.clear();
	}
	
	//Returns this noble's name
	const string& getName() const { return name; }

	//Displays this noble's name and the warriors that this noble has
	void display() const {
		cout << name << " has an army of " << warriors.size() << endl;
		for (size_t i = 0; i < warriors.size(); ++i) {
			cout << "        ";
			warriors[i]->display();
		}
	}

	//takes a Warrior and puts it in the warrior vector of this noble
	void hire(Warrior* warrior) {
		warriors.push_back(warrior);
	}
	
	//Fires a warrior from this noble's army of warriors
	//Finds the warrior in this noble's vector of warriors by looking for the parameter name
	//Returns a warrior pointer so that the warrior can be put back into the unemployed warriors vector
	//Otherwise returns nullptr if that specific warrior pointer does not exist
	Warrior* fire(const string& warriorName) {
		for (size_t i = 0; i < warriors.size(); ++i) {
			if (warriors[i]->getName() == warriorName) {
				Warrior* firedWarrior = warriors[i];
				warriors[i] = warriors.back();
				warriors.pop_back();
				cout << "You don't work for me anymore " << warriorName << "! -- " << name << "." << endl;
				cout << endl;
				return firedWarrior;
			}
		}
		cout << endl;
		return nullptr;
	}

	//Returns this noble's army strength by adding up each warrior's strength
	int getArmyStrength() {
		int armyStrength = 0;
		for (size_t i = 0; i < warriors.size(); ++i) {
			armyStrength += warriors[i]->getStrength();
		}
		return armyStrength;
	}

	//Changes this noble's army strength by changing each warrior in it
	//by a given ratio amount
	void changeArmyStrength(double ratio) {
		for (size_t i = 0; i < warriors.size(); ++i) {
			warriors[i]->changeStrength(ratio);
		}
	}

	//This noble's army of warriors versus the parameter's noble army of warriors
	//Their army strengths are compared and changed based on whoever wins the battle
	void battle(Noble* aNoble) {
		double army1Strength = this->getArmyStrength();
		double army2Strength = aNoble->getArmyStrength();
		double ratio;

		cout << name << " battles " << aNoble->name << endl;

		if (army1Strength == 0 && army2Strength == 0) {
			cout << "Oh, NO! They're both dead! Yuck!" << endl;
		}
		else if (army1Strength == 0) {
			cout << "He's dead " << aNoble->name << endl;
		}
		else if (army2Strength == 0) {
			cout << "He's dead " << name << endl;
		}
		else if (army1Strength > army2Strength) {
			cout << name << " defeats " << aNoble->name << endl;
			ratio = army2Strength / army1Strength;
			aNoble->changeArmyStrength(0);
			this->changeArmyStrength(1 - ratio);
		}
		else if (army2Strength > army1Strength) {
			cout << aNoble->name << " defeats " << name << endl;
			ratio = army1Strength / army2Strength;
			aNoble->changeArmyStrength(1 - ratio);
			this->changeArmyStrength(0);
			
		}
		else if (army1Strength == army2Strength) {
			cout << "Mutual Annihilation: " << name << " and " << aNoble->name << " die at each other's hands" << endl;
			aNoble->changeArmyStrength(0);
			this->changeArmyStrength(0);
		}
		cout << endl;
	}

private:
	string name;
	vector<Warrior*> warriors;
};

//finds and returns a noble's index in a given vector with noble pointers
//returns the size of the vector if no such noble exists
size_t findNobleIndex(const vector<Noble*>& nobles, const string& nobleName) {
	for (size_t i = 0; i < nobles.size(); ++i) {
		if (nobles[i]->getName() == nobleName) {
			return i;
		}
	}
	return nobles.size();
}

//finds and returns a warrior's index in a given vector with warrior pointers
//returns the size of the vector if no such warrior exists
size_t findWarriorIndex(const vector<Warrior*>& warriors, const string& warriorName) {
	for (size_t i = 0; i < warriors.size(); ++i) {
		if (warriors[i]->getName() == warriorName) {
			return i;
		}
	}
	return warriors.size();
}

//shows the noble's name and the warriors that he enlisted and their strengths
//shows the warriors that are not hired and their strengths
void status(const vector<Noble*>& nobles, const vector<Warrior*>& unemployedWarriors) {
	cout << "Status" << endl;
	cout << "======" << endl;
	cout << "Nobles:" << endl;
	if (nobles.size() == 0) {
		cout << "NONE" << endl;
	}
	else {
		for (size_t i = 0; i < nobles.size(); ++i) {
			nobles[i]->display();
		}
	}
	cout << "Unemployed Warriors:" << endl;
	if (unemployedWarriors.size() == 0) {
		cout << "NONE" << endl;
	}
	else {
		for (size_t i = 0; i < unemployedWarriors.size(); ++i) {
			unemployedWarriors[i]->display();
		}
	}
	cout << endl;
}

//clears the pointers in the vector of noble pointers and the vector of warrior pointers
void clear(vector<Noble*>& nobles, vector<Warrior*>& unemployedWarriors) {
	for (size_t i = 0; i < unemployedWarriors.size(); ++i) {
		delete unemployedWarriors[i];
	}
	unemployedWarriors.clear();
	for (size_t i = 0; i < nobles.size(); ++i) {
		delete nobles[i];
	}
	nobles.clear();
}

int main()
{
	ifstream ifs("nobleWarriors.txt");

	if (!ifs) {
		cerr << "Cannot find/open file" << endl;
		exit(1);
	}

	vector<Warrior*> unemployedWarriors;
	vector<Noble*> nobles;

	string curr, noble1Name, noble2Name, warriorName;
	size_t nobleIndex, noble2Index, warriorIndex;
	int strength;

	while (ifs >> curr) {
		//Creates a Noble with a given name
		//Checks if the Noble already exists by seraching for its index in the nobles vector
		if (curr == "Noble") {
			ifs >> noble1Name;
			nobleIndex = findNobleIndex(nobles, noble1Name);
			if (nobleIndex == nobles.size()) {
				Noble* aNoble = new Noble(noble1Name);
				nobles.push_back(aNoble);
			}
			else {
				cerr << "Noble " << noble1Name << " already exists." << endl;
			}
		}
		//Creates a Warrior with a given name and strength
		//Checks if the Warrior already exists by searching for its index in the unemployed warrior vector
		if (curr == "Warrior") {
			ifs >> warriorName >> strength;
			warriorIndex = findWarriorIndex(unemployedWarriors, warriorName);
			if (warriorIndex == unemployedWarriors.size()) {
				Warrior* aWarrior = new Warrior(warriorName, strength);
				unemployedWarriors.push_back(aWarrior);
			}
			else {
				cerr << "Warrior " << warriorName << " already exists." << endl;
			}
		}
		//Finds the specific warrior and noble by finding its indexes
		//Checks if the warrior and noble exists by their indexes
		//The specific Noble hires the specific Warrior
		//The specific warrior is popped off the unemployed warrior vector
		if (curr == "Hire") {
			ifs >> noble1Name >> warriorName;
			nobleIndex = findNobleIndex(nobles, noble1Name);
			warriorIndex = findWarriorIndex(unemployedWarriors, warriorName);
			if (nobleIndex == nobles.size()) {
				cerr << "Noble " << noble1Name << " does not exist." << endl;
			}
			else if (warriorIndex == unemployedWarriors.size()) {
				cerr << "Warrior " << warriorName << " does not exist." << endl;
			}
			else {
				nobles[nobleIndex]->hire(unemployedWarriors[warriorIndex]);
				unemployedWarriors[warriorIndex] = unemployedWarriors.back();
				unemployedWarriors.pop_back();
			}
		}
		if (curr == "Status") {
			status(nobles, unemployedWarriors);
		}
		//Finds the noble by finding its index
		//Checks whether the noble exist by its index
		//The specific Noble fires the Warrior
		//The fire method returns the now unemployed Warrior
		//Puts him back into the unemployed warrior vector
		if (curr == "Fire") {
			ifs >> noble1Name >> warriorName;
			nobleIndex = findNobleIndex(nobles, noble1Name);
			if (nobleIndex == nobles.size()) {
				cerr << "Noble " << noble1Name << " does not exist." << endl;
			}
			else {
				Warrior* unemployedWarrior = nobles[nobleIndex]->fire(warriorName);
				if (unemployedWarrior != nullptr) {
					unemployedWarriors.push_back(unemployedWarrior);
				}
				else {
					cerr << "Warrior " << warriorName << " does not exist." << endl;
				}
			}
		}
		//Two nobles battle each other 
		//Checks if a noble exists by its index
		if (curr == "Battle") {
			ifs >> noble1Name >> noble2Name;
			nobleIndex = findNobleIndex(nobles, noble1Name);
			noble2Index = findNobleIndex(nobles, noble2Name);
			if (nobleIndex == nobles.size()) {
				cerr << "Noble " << noble1Name << " does not exist." << endl;
			}
			else if (noble2Index == nobles.size()) {
				cerr << "Noble " << noble2Name << " does not exist." << endl;
			}
			else {
				nobles[nobleIndex]->battle(nobles[noble2Index]);
			}
		}
		if (curr == "Clear") {
			clear(nobles, unemployedWarriors);
		}
	}
	ifs.close();
}
