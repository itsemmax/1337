#include "Cat.hpp"

Cat::Cat(void){
	type = "Cat";
	brain = new Brain("random cat thoughts");
	std::cout << "Cat default constructor called" << std::endl;
}
Cat::Cat(const Cat &other) :Animal(other), brain(new Brain(*other.brain)){
	std::cout << "Cat copy constructor called" << std::endl;
	type = other.type;
}
Cat &Cat::operator=(const Cat &other){
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		type = other.type;
		delete this->brain;
		brain = new Brain(*other.brain);
	}
	return *this;
}
Cat::~Cat(){
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}
void Cat::makeSound(void) const{
	std::cout << "Meow" << std::endl;
}