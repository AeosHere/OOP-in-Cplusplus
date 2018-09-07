#ifndef ARCHER_H
#define ARCHER_H
#include "Warrior.h"
#include <string>

namespace WarriorCraft {
	class Archer : public Warrior {
	public:
		Archer(const std::string& name, double strength);
		void display() const;
	protected:
	private:
	};
}
#endif
