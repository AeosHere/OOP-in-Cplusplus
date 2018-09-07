#include "Swordsman.h"
using namespace std;

namespace WarriorCraft {
	Swordsman::Swordsman(const string& name, double strength) : Warrior(name, strength) {}
	//If swordsman is not dead, it makes the sound CLANG! in fights and the sound warrior makes in fights
	void Swordsman::display() const {
		if (getStrength() != 0) {
			cout << "CLANG! ";
			Warrior::display();
		}
	}
}