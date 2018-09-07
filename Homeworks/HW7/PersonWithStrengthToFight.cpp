#include "PersonWithStrengthToFight.h"
using namespace std;

namespace WarriorCraft {
	PersonWithStrengthToFight::PersonWithStrengthToFight(const string& name, double strength) : Noble(name), strength(strength) {}
	double PersonWithStrengthToFight::getStrength() const {
		return strength;
	}
	void PersonWithStrengthToFight::changeStrength(double ratio) {
		strength *= ratio;
	}
	//This has no code inside because a PersonWithStrengthToFight has no warcry during fights
	void PersonWithStrengthToFight::display() const {}
	//This has no code inside because a PersonWithStrengthToFight does not have an army
	void PersonWithStrengthToFight::changeArmyDeathStatus() {}
}