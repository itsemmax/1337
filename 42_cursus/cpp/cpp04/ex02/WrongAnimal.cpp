#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal") {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &other){
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = other;
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other){
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}
WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal destructor called" << std::endl;
}
void WrongAnimal::makeSound(void) const{
	std::cout << "WrongAnimal sound" << std::endl;
}
std::string WrongAnimal::getType(void) const{
	return this->type;
}