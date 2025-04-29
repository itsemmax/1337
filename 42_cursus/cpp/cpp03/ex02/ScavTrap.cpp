#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("Default"){
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap " << this->name << " constructor called" << std::endl;
}
ScavTrap::ScavTrap(std::string name){
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap " << this->name << " constructor called" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other){
	std::cout << "ScavTrap copy constructor called" << std::endl;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &other){
	if(this != &other){
		ClapTrap::operator=(other);
		std::cout << "ScavTrap copy assignment operator called" << std::endl;
	}
	return *this;
}
ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap destructor called" << std::endl;
}
void ScavTrap::attack(const std::string& target){
	if(hitPoints <= 0 || energyPoints <= 0)
	{
		std::cout << "ScavTrap " << this->name << " can't attack!" << std::endl;
		return;
	}
	energyPoints -= 1;
	std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}
void ScavTrap::guardGate(void){
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode!" << std::endl;
}