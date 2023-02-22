#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
    ClapTrap    c("ClapTrap");
    ScavTrap    s("ScavTrap");

    for (int i = 0; i < 11; i++) {
        c.attack("Target");
    }
    s.guardGate();

    return 0;
}