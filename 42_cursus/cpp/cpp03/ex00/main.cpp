#include "ClapTrap.hpp"

#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("a");
	ClapTrap b("b");
	ClapTrap c("c");
	ClapTrap d;
	d = b;

	a.attack("b");
	b.attack("a");
	a.takeDamage(3);
	b.takeDamage(5);
	a.takeDamage(10);
	a.attack("b");
	b.beRepaired(4);
	a.beRepaired(10);
	return 0;
}
