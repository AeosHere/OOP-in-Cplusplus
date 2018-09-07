#include "Lord.h"
using namespace std;

namespace WarriorCraft {
	Lord::Lord(const string& name) : Noble(name) {}
	const string& Lord::getName() const {
		return Noble::getName();
	}
	void Lord::display() const {
		for (size_t i = 0; i < protectors.size(); ++i) {
			//each protector has its own way of display
			protectors[i]->display();
		}
	}
	void Lord::hires(Protector& aProtector) {
		//conditions to hire: protector does not have owner, lord hiring is not dead, and the protector is not dead
		if (aProtector.hasOwner() == false && isDead() == false && aProtector.isDead() == false) {
			protectors.push_back(&aProtector);
			aProtector.changeOwner(*this);
		}
		else {
			cout << getName() << " cannot hire because of these reasons:" << endl;
			if (aProtector.hasOwner() == true) {
				cout << "	This protector has an owner already!" << endl;
			}
			if (isDead() == true) {
				cout << "	This noble is dead!" << endl;
			}
			if (aProtector.isDead() == true) {
				cout << "	This protector is dead!" << endl;
			}
			cout << endl;
		}
	}
	double Lord::getStrength() const {
		double strength = 0;
		for (size_t i = 0; i < protectors.size(); ++i) {
			strength += protectors[i]->getStrength();
		}
		return strength;
	}
	void Lord::changeStrength(double ratio) {
		for (size_t i = 0; i < protectors.size(); ++i) {
			protectors[i]->changeStrength(ratio);
		}
	}
	void Lord::changeArmyDeathStatus() {
		for (size_t i = 0; i < protectors.size(); ++i) {
			protectors[i]->dies();
		}
	}
	void Lord::remove(Protector& aProtector) {
		for (size_t i = 0; i < protectors.size(); ++i) {
			if (protectors[i] == &aProtector) {
				protectors[i] = protectors.back();
				protectors.pop_back();
			}
		}
	}
	bool Lord::exists(const Protector& aProtector) const {
		for (size_t i = 0; i < protectors.size(); ++i) {
			if (protectors[i] == &aProtector) {
				return true;
			}
		}
		return false;
	}
}