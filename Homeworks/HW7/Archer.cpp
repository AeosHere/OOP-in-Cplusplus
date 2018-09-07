#include "Archer.h"
using namespace std;

namespace WarriorCraft {
	Archer::Archer(const string& name, double strength) : Warrior(name, strength) {}
	//If archer is not dead, it makes the sound TWANG! during fights and the sound warrior makes in fights
	void Archer::display() const {
		if (getStrength() != 0) {
			cout << "TWANG! ";
			Warrior::display();
		}
	}
}