#include "Noble.h"
using namespace std;

namespace WarriorCraft {
	Noble::Noble(const string& name) : name(name), dead(false) {}
	const string& Noble::getName() const {
		return name;
	}
	bool Noble::isDead() const {
		return dead;
	}
	void Noble::battle(Noble& aNoble) {
		//Gets the two noble's strengths in order to compare the battle result
		double noble1Strength = this->getStrength();
		double noble2Strength = aNoble.getStrength();
		double ratio;

		//cout << noble1Strength << " " << noble2Strength << endl;
		cout << name << " battles " << aNoble.name << endl;

		if (noble1Strength == 0 && noble2Strength == 0) {
			cout << "Oh NO! They're both dead! Yuck!" << endl;
		}
		else if (noble1Strength == 0 && this->isDead() == true) {
			cout << "He's dead, " << aNoble.name << endl;
		}
		else if (noble2Strength == 0 && aNoble.isDead() == true) {
			cout << "He's dead, " << name << endl;
		}
		//Calls the different nobles display methods
		//Calculates the ratio to change the protectors strengths
		//Defeated noble's strength becomes 0 and dies and so does every protector in his army
		//Winning noble's strength is multipled by ratio
		else if (noble1Strength > noble2Strength) {
			this->display();
			aNoble.display();
			cout << name << " defeats " << aNoble.name << endl;
			ratio = noble2Strength / noble1Strength;
			aNoble.changeStrength(0);
			aNoble.changeArmyDeathStatus();
			aNoble.dead = true;
			this->changeStrength(1 - ratio);
		}
		else if (noble1Strength < noble2Strength) {
			this->display();
			aNoble.display();
			cout << aNoble.name << " defeats " << name << endl;
			ratio = noble1Strength / noble2Strength;
			aNoble.changeStrength(1 - ratio);
			this->changeStrength(0);
			this->dead = true;
			this->changeArmyDeathStatus();
		}
		else if (noble1Strength == noble2Strength) {
			this->display();
			aNoble.display();
			cout << "Mutual Annihalation: " << name << " and " << aNoble.name << " die at each other's hands" << endl;
			aNoble.changeStrength(0);
			aNoble.dead = true;
			aNoble.changeArmyDeathStatus();
			this->changeStrength(0);
			this->dead = true;
			this->changeArmyDeathStatus();
		}
		cout << endl;
	}
}