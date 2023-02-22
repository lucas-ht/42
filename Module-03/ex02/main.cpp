#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {
    ClapTrap    c("ClapTrap");
    ScavTrap    s("ScavTrap");
    FragTrap    f("FragTrap");

    for (int i = 0; i < 11; i++) {
        c.attack("Target");
    }
    s.guardGate();
    f.highFivesGuys();

    return 0;
}