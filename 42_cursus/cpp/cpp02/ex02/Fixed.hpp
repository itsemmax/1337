#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
	private:
		int fixedPointValue;
		static const int fractionalBits = 8;
	public:
		Fixed(void);
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;
		Fixed operator+(const Fixed &other);
		Fixed operator-(const Fixed &other);
		Fixed operator*(const Fixed &other);
		Fixed operator/(const Fixed &other);
		Fixed &operator++(void);
		Fixed operator++(int);
		Fixed &operator--(void);//--a
		Fixed operator--(int);//a--
		static const Fixed &max(const Fixed& a, const Fixed& b) ;
    	static const Fixed &min(const Fixed& a, const Fixed& b);
    	static Fixed &min(Fixed& a, Fixed& b);
    	static Fixed &max(Fixed& a, Fixed& b);
		~Fixed();
		Fixed(const int raw);
		Fixed(const float raw);
		int getRawBits(void) const;
		float toFloat(void) const;
		int toInt(void) const;

};
std::ostream &operator<<(std::ostream &out, const Fixed &fix);
#endif