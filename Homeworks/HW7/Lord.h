#ifndef LORD_H
#define LORD_H
#include "Noble.h"
#include <string>
#include <vector>

namespace WarriorCraft {

	class Lord : public Noble {
	public:
		Lord(const std::string& name);
		const std::string& getName() const;
		void display() const;
		void hires(Protector& aProtector);
		double getStrength() const;
		void changeStrength(double ratio);
		void changeArmyDeathStatus();
		void remove(Protector& aProtector);
		bool exists(const Protector& aProtector) const;
	protected:
	private:
		std::vector<Protector*> protectors;
	};
}
#endif
