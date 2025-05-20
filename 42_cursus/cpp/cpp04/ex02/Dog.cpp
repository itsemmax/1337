#include "Dog.hpp"

Dog::Dog(void){
	type = "Dog";
	brain = new Brain("random dog thoughts");
	std::cout << "Dog default constructor called" << std::endl;
}
Dog::Dog(const Dog &other): Animal(other), brain(new Brain(*other.brain)){
	std::cout << "Dog copy constructor called" << std::endl;
	type = other.type;
}
Dog &Dog::operator=(const Dog &other){
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other)
	{
		type = other.type;
		delete this->brain;
		brain = new Brain(*other.brain);
	}
	return *this;
}
Dog::~Dog(){
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}
void Dog::makeSound(void) const{
	std::cout << "Woof" << std::endl;
}