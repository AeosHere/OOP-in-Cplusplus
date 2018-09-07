#ifndef NOBLE_H
#define NOBLE_H
#include "Protector.h"
#include <string>
#include <iostream>

namespace WarriorCraft {

	class Protector;

	class Noble {
	public:
		Noble(const std::string& name);
		const std::string& getName() const;
		void battle(Noble& aNoble);
		double virtual getStrength() const = 0;
		void virtual changeStrength(double ratio) = 0;
		void virtual display() const = 0;
		void virtual changeArmyDeathStatus() = 0;
	protected:
		bool isDead() const;
	private:
		std::string name;
		bool dead;
	};
}

#endif