#ifndef PROTECTOR_H
#define PROTECTOR_H
#include <string>
#include <iostream>

namespace WarriorCraft {

	class Lord;

	class Protector {
	public:
		Protector(const std::string& name, double strength);
		bool hasOwner() const;
		void changeOwner(Lord& aLord);
		double getStrength() const;
		void changeStrength(double ratio);
		void virtual display() const = 0;
		void dies();
		bool isDead() const;
		void quits();
	protected:
	private:
		std::string name;
		double strength;
		Lord* owner;
		bool dead;
	};
}
#endif
