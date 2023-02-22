#include "ClapTrap.hpp"

int main(void) {
    ClapTrap    c("Clap");

    for (int i = 0; i < 11; i++)
        c.attack("Target");

    c = ClapTrap("Clap2");
    c.takeDamage(5);
    c.beRepaired(10);
    c.takeDamage(15);

    return 0;
}