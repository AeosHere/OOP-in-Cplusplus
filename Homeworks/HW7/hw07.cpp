//Richard Yeung
//This program simulates battle between different types of nobles
//Two types of Nobles: Lord and PersonWithStrengthToFight
//Lord can fight by hiring protectors(composed of different warriors(swordsman, warrior, wizard, archer))
//PersonWithStrengthToFight can fight by themselves because they have strengths not made up by protectors

#include "Archer.h"
#include "Lord.h"
#include "Noble.h"
#include "PersonWithStrengthToFight.h"
#include "Protector.h"
#include "Swordsman.h"
#include "Warrior.h"
#include "Wizard.h"
using namespace WarriorCraft;
using namespace std;

int main() {
	Lord sam("Sam");
	Archer samantha("Samantha", 200);
	sam.hires(samantha);
	Lord joe("Joe");
	PersonWithStrengthToFight randy("Randolf the Elder", 250);
	joe.battle(randy);
	joe.battle(sam);
	Lord janet("Janet");
	Swordsman hardy("TuckTuckTheHardy", 100);
	Swordsman stout("TuckTuckTheStout", 80);
	janet.hires(hardy);
	janet.hires(stout);
	PersonWithStrengthToFight barclay("Barclay the Bold", 300);
	janet.battle(barclay);
	janet.hires(samantha);
	Archer pethora("Pethora", 50);
	Archer thora("Thorapleth", 60);
	Wizard merlin("Merlin", 150);
	janet.hires(pethora);
	janet.hires(thora);
	sam.hires(merlin);
	janet.battle(barclay);
	sam.battle(barclay);
	joe.battle(barclay);

	cout << endl;
	
	cout << "Testing: Protector wants to run away:" << endl;
	samantha.quits();
	cout << "Is Samantha in Janet's army anymore? " << janet.exists(samantha) << endl;
}