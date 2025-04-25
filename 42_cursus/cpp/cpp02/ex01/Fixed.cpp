#include "Fixed.hpp"

Fixed::Fixed(): fixedPointValue(0) {
		std::cout << "Default constructor called" << std::endl;
	}

Fixed::Fixed(const Fixed &other){
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}
Fixed &Fixed::operator=(const Fixed &other){
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &other)
		this->fixedPointValue = other.getRawBits();
	return *this;
}
Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}
Fixed::Fixed(const int nb){
	fixedPointValue = nb * (1 << fractionalBits);
	std::cout << "Int constructor called" << std::endl;
}
Fixed::Fixed(const float nb)
{
	fixedPointValue = roundf(nb * (1 << fractionalBits));
	std::cout << "Float constructor called" << std::endl;
}
int Fixed::getRawBits(void) const{return this->fixedPointValue;}
float Fixed::toFloat(void) const
{
	return (float)this->fixedPointValue / (1 << fractionalBits);
}
int Fixed::toInt(void) const{
	return this->fixedPointValue / (1 << fractionalBits);
}
std::ostream &operator<<(std::ostream &out, const Fixed &fix)
{
	out << fix.toFloat();
	return out;
}