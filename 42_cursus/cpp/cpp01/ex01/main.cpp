#include "Zombie.hpp"

int main(){
	Zombie *zmb = zombieHorde(n,"allal");
	for(int i=0;i<n;i++)
	{
		zmb[i].announce();
	}
	delete []zmb;
}
