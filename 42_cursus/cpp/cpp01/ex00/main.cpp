#include "Zombie.hpp"

int main(){
	Zombie zmb("allal");
	zmb.announce();
	
	Zombie *zmb1;
	zmb1 = newZombie("sam");
	zmb1->announce();

	randomChump("stan");	
	delete zmb1;
}
