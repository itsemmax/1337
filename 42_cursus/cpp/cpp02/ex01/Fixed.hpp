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
		~Fixed();
		Fixed(const int raw);
		Fixed(const float raw);
		int getRawBits(void) const;
		float toFloat(void) const;
		int toInt(void) const;
};
std::ostream &operator<<(std::ostream &out, const Fixed &fix);
#endif