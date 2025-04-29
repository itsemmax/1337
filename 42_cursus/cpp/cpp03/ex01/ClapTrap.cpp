#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0){
	std::cout << "ClapTrap Default constructor called" << std::endl;
}
ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0){
	std::cout <<"ClapTrap "<< name << " constructor called" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap& other)
    : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage) {
    std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other){
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	if(this != &other)
	{
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return *this;
}
ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap Destructor called" << std::endl;
}
void ClapTrap::attack(const std::string& target){
	if(this->hitPoints <= 0 || this->energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name << " can't attack!" << std::endl;
		return;
	}
	this->energyPoints--;
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount){
	if(this->hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " is already dead!" << std::endl;
		return;
	}
    hitPoints -= amount;
	if(hitPoints < 0)
		hitPoints = 0;
	std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage! Hit points left: " << this->hitPoints << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount){
	if(this->hitPoints <= 0 || this->energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " can't repair!" << std::endl;
		return;
	}
	this->hitPoints += amount;
	this->energyPoints--;
	std::cout << "ClapTrap " << this->name << " repairs itself for " << amount << " points! Hit points: " << this->hitPoints << std::endl;
}
