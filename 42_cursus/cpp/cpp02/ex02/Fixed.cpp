#include "Fixed.hpp"

Fixed::Fixed(void) : fixedPointValue(0){}
Fixed::Fixed(const Fixed &other){
	this->fixedPointValue = other.getRawBits();
}
Fixed &Fixed::operator=(const Fixed &other){
	if(this != &other){
		this->fixedPointValue = other.getRawBits();
	}
	return *this;
}
bool Fixed::operator>(const Fixed &other)const{
	return this->fixedPointValue > other.getRawBits();
}
bool Fixed::operator<(const Fixed &other)const{
	return this->fixedPointValue < other.getRawBits();
}
bool Fixed::operator>=(const Fixed &other)const{
	return this->fixedPointValue >= other.getRawBits();
}
bool Fixed::operator<=(const Fixed &other)const{
	return this->fixedPointValue <= other.getRawBits();
}
bool Fixed::operator==(const Fixed &other)const{
	return this->fixedPointValue == other.getRawBits();
}
bool Fixed::operator!=(const Fixed &other)const{
	return this->fixedPointValue != other.getRawBits();
}
Fixed Fixed::operator+(const Fixed &other){
	return Fixed(this->toFloat() + other.toFloat());
}
Fixed Fixed::operator-(const Fixed &other){
	return Fixed(this->toFloat() - other.toFloat());
}
Fixed Fixed::operator*(const Fixed &other){
	return Fixed(this->toFloat() * other.toFloat());
}
Fixed Fixed::operator/(const Fixed &other){
	if(other.getRawBits() == 0){
		std::cerr << "Error: Division by zero" << std::endl;
		return Fixed(0);
	}
	return Fixed(this->toFloat() / other.toFloat());
}
Fixed &Fixed::operator++(void){
	this->fixedPointValue++;
	return *this;
}
Fixed Fixed::operator++(int){
	Fixed temp = *this;
	this->fixedPointValue++;
	return temp;
}
Fixed &Fixed::operator--(void){//--a
	this->fixedPointValue--;
	return *this;
}
Fixed Fixed::operator--(int){//a--
	Fixed temp = *this;
	this->fixedPointValue--;
	return temp;
}
const Fixed &Fixed::max(const Fixed& a, const Fixed& b){
	if(a > b)
		return a;
	return b;
}
const Fixed &Fixed::min(const Fixed& a, const Fixed& b){
	if(a < b)
		return a;
	return b;
}
Fixed &Fixed::min(Fixed& a, Fixed& b){
	if(a < b)
		return a;
	return b;
}
Fixed &Fixed::max(Fixed& a, Fixed& b){
	if(a > b)
		return a;
	return b;
}
Fixed::~Fixed(){}
Fixed::Fixed(const int raw){
	fixedPointValue = raw * (1 << fractionalBits);
}
Fixed::Fixed(const float raw){
	fixedPointValue = roundf(raw * (1 << fractionalBits));
}
int Fixed::getRawBits(void) const{
	return this->fixedPointValue;
}
float Fixed::toFloat(void) const{
	return (float)this->fixedPointValue / (1 << fractionalBits);
}
int Fixed::toInt(void) const{
	return this->fixedPointValue / (1 << fractionalBits);
}
std::ostream &operator<<(std::ostream &out, const Fixed &fix){
	out << fix.toFloat();
	return out;
}