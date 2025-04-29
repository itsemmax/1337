#include "ScavTrap.hpp"

int main() {
    ScavTrap scav("a");
    ScavTrap scav1("b");
    ScavTrap a(scav1);
    ScavTrap c;
    c = scav;
    scav.attack("b");
    scav.guardGate();
    scav1.attack("a");
    scav.beRepaired(10);

    return 0;
}

