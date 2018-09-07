#ifndef PERSONWITHSTRENGTHTOFIGHT_H
#define PERSONWITHSTRENGTHTOFIGHT_H
#include "Noble.h"
#include <string>
#include <vector>

namespace WarriorCraft {
	class PersonWithStrengthToFight : public Noble {
	public:
		PersonWithStrengthToFight(const std::string& name, double strength);
		void display() const;
		double getStrength() const;
		void changeStrength(double ratio);
		void changeArmyDeathStatus();
	protected:
	private:
		double strength;
	};
}
#endif
