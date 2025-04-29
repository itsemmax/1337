#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap("Default"){
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap " << this->name << " constructor called" << std::endl;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap " << this->name << " constructor called" << std::endl;
}
FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other){
	std::cout << "FragTrap copy constructor called" << std::endl;
}
FragTrap &FragTrap::operator=(const FragTrap &other){
	if(this != &other) {
		ClapTrap::operator=(other);
		std::cout << "FragTrap copy assignment operator called" << std::endl;
	}
	return *this;
}
FragTrap::~FragTrap(){
	std::cout << "FragTrap destructor called" << std::endl;
}
void FragTrap::highFivesGuys(void){
	std::cout << "FragTrap gave a HIGH FIVE!" << std::endl;
}