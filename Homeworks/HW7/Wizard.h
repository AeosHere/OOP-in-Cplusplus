#ifndef WIZARD_H
#define WIZARD_H
#include "Protector.h"
#include <string>

namespace WarriorCraft {
	class Wizard : public Protector {
	public:
		Wizard(const std::string& name, double strength);
		void display() const;
	protected:
	private:
	};
}
#endif
