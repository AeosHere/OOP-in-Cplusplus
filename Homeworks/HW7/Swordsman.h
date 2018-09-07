#ifndef SWORDSMAN_H
#define SWORDSMAN_H
#include "Warrior.h"
#include <string>

namespace WarriorCraft {
	class Swordsman : public Warrior {
	public:
		Swordsman(const std::string& name, double strength);
		void display() const;
	protected:
	private:
	};
}
#endif

