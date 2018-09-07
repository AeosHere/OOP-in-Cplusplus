#include "Wizard.h"
using namespace std;

namespace WarriorCraft {
	Wizard::Wizard(const string& name, double strength) : Protector(name, strength) {}
	//If wizard is not dead, it makes the sound POOF! in fights
	void Wizard::display() const {
		if (getStrength() != 0) {
			cout << "POOF!" << endl;
		}
	}
}