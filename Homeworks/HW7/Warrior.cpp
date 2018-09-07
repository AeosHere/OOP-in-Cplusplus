#include "Warrior.h"
using namespace std;

namespace WarriorCraft {
	Warrior::Warrior(const string& name, double strength) : Protector(name, strength) {}
	//The warrior calls the Protector display method
	void Warrior::display() const {
		Protector::display();
	}
}