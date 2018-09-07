#include "Protector.h"
#include "Lord.h"
using namespace std;

namespace WarriorCraft {
	Protector::Protector(const std::string& name, double strength) : name(name), strength(strength), owner(nullptr), dead(false) {}
	bool Protector::hasOwner() const {
		return owner != nullptr;
	}
	void Protector::changeOwner(Lord& aLord) {
		owner = &aLord;
	}
	double Protector::getStrength() const {
		return strength;
	}
	void Protector::changeStrength(double ratio) {
		strength *= ratio;
	}
	void Protector::display() const {
		cout << name << " says: Take that in the name of my lord, " << owner->getName() << endl;
	}
	void Protector::dies() {
		dead = true;
	}
	bool Protector::isDead() const {
		return dead;
	}
	void Protector::quits() {
		owner->remove(*this);
		owner = nullptr;
		cout << "RUNAWAY SUCCESS!" << endl;
	}
}