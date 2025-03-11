#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
}
void HumanB::attack()
{
	if(weapon->getType() != "")
		std::cout << name << " attacks with their " << weapon->getType() << "\n";
	else
		std::cout << name << " don't have a weapon to attack \n";
}
void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
HumanB::~HumanB(){}