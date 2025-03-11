#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iomanip>
#include <iostream>
#define n 4

class Zombie {
	private:
		std::string name;
	public:
		Zombie();
		void announce(void);
		void setname(std::string str);
		~Zombie();
};

Zombie* zombieHorde( int N, std::string name );

#endif