//Richard Yeung
//A program to simulate fights between nobles with an army of warriors
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Warrior {
public:
	Warrior(const string& warriorName, int warriorStrength) : name(warriorName), strength(warriorStrength) {}
	string getName() const { return name; }
	int getStrength() const { return strength; }

	//Shows the warrior's name and strength
	void display() const {
		cout << "        " << name << ": " << strength << endl;
	}

	//Changes the warrior's strength by multiplying it by the ratio obtained from the losing army's strength over the winning army's strength
	void changeStrength(double armyRatio) {
		strength *= armyRatio;
	}
private:
	string name;
	double strength;
};

class Noble {
public:
	Noble(const string& nobleName) : name(nobleName) {}
	void hire(Warrior& aWarrior) {
		army.push_back(&aWarrior);
	}
	
	//Shows the status of the noble's 
	//Loops through army vector and shows the warriors
	void display() const {
		cout << name << " has an army of " << army.size() << endl;
		for (size_t i = 0; i < army.size(); ++i) {
			army[i]->display();
		}
	}
	
	//Gets rid of a warrior from a noble's army
	//Loops through the army vector, swaps the last pointer with the pointer that refers to the passed in warrior and pops that warrior out
	void fire(const Warrior& aWarrior) {
		cout << aWarrior.getName() << ", you're fired! -- " << name << endl;
		for (size_t i = 0; i < army.size(); ++i) {
			if (army[i]->getName() == aWarrior.getName()) {
				Warrior* warriorPointerHolder = army[army.size() - 1];
				army[army.size() - 1] = army[i];
				army[i] = warriorPointerHolder;
				army.pop_back();
			}
		}
	}

	//Returns the total strength of a noble's army
	//Loops through the army vector and sums up each warrior's strength and returns the sum
	double getArmyStrength(const vector<Warrior*>& army) {
		int armyStrength = 0;
		for (size_t i = 0; i < army.size(); ++i) {
			armyStrength += army[i]->getStrength();
		}
		return armyStrength;
	}

	//Displays the outcome of the battle between nobles
	//Compares noble's army strengths and updates the warriors strength by looping through the army vector
	void battle(Noble& aNoble) {
		double army1Strength = getArmyStrength(army);
		double army2Strength = getArmyStrength(aNoble.army);
		double ratio;

		cout << name << " battles " << aNoble.name << endl;

		if (army1Strength == 0 && army2Strength == 0) {
			cout << "Oh, NO! They're both dead! Yuck!" << endl;
		}
		else if (army1Strength == 0) {
			cout << "He's dead " << aNoble.name << endl;
		}
		else if (army2Strength == 0) {
			cout << "He's dead " << name << endl;
		}
		else if (army1Strength > army2Strength) {
			cout << name << " defeats " << aNoble.name << endl;
			for (size_t i = 0; i < aNoble.army.size(); ++i) {
				aNoble.army[i]->changeStrength(0);
			}
			for (size_t i = 0; i < army.size(); ++i) {
				ratio = army2Strength / army1Strength;
				army[i]->changeStrength(1 - ratio);
			}
		}
		else if (army2Strength > army1Strength) {
			cout << aNoble.name << " defeats " << name << endl;
			for (size_t i = 0; i < aNoble.army.size(); ++i) {
				ratio = army1Strength / army2Strength;
				aNoble.army[i]->changeStrength(1 - ratio);
			}
			for (size_t i = 0; i < army.size(); ++i) {
				army[i]->changeStrength(0);
			}
		}
		else if (army1Strength == army2Strength) {
			cout << "Mutual Annihilation: " << name << " and " << aNoble.name << " die at each other's hands" << endl;
			for (size_t i = 0; i < aNoble.army.size(); ++i) {
				aNoble.army[i]->changeStrength(0);
			}
			for (size_t i = 0; i < army.size(); ++i) {
				army[i]->changeStrength(0);
			}
		}
	}
private:
	string name;
	vector<Warrior*> army;
};

int main() {
	Noble art("King Arthur");
	Noble lance("Lancelot du Lac");
	Noble jim("Jim");
	Noble linus("Linus Torvalds");
	Noble billie("Bill Gates");

	Warrior cheetah("Tarzan", 10);
	Warrior wizard("Merlin", 15);
	Warrior theGovernator("Conan", 12);
	Warrior nimoy("Spock", 15);
	Warrior lawless("Xena", 20);
	Warrior mrGreen("Hulk", 8);
	Warrior dylan("Hercules", 3);
	
	jim.hire(nimoy);
	lance.hire(theGovernator);
	art.hire(wizard);
	lance.hire(dylan);
	linus.hire(lawless);
	billie.hire(mrGreen);
	art.hire(cheetah);

	jim.display();
	lance.display();
	art.display();
	linus.display();
	billie.display();
	
	art.fire(cheetah);
	art.display();

	art.battle(lance);
	jim.battle(lance);
	linus.battle(billie);
	billie.battle(lance);
	/*
	jim.display(); //15
	lance.display(); //0
	art.display(); //0
	linus.display(); //12
	billie.display(); //0
	*/
}

