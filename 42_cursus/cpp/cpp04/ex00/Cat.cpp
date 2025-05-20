#include "Cat.hpp"

Cat::Cat(void){
	type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}
Cat::Cat(const Cat &other) :Animal(other){
	std::cout << "Cat copy constructor called" << std::endl;
	type = other.type;
}
Cat &Cat::operator=(const Cat &other){
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}
Cat::~Cat(){
	std::cout << "Cat destructor called" << std::endl;
}
void Cat::makeSound(void) const{
	std::cout << "Meow" << std::endl;
}