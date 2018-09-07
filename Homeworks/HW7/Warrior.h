#ifndef WARRIOR_H
#define WARRIOR_H
#include "Protector.h"
#include <string>

namespace WarriorCraft {
	class Warrior : public Protector {
	public:
		Warrior(const std::string& name, double strength);
		void display() const;
	protected:
	private:
	};
}
#endif
