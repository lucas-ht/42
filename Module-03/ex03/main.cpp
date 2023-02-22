#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void) {
    ClapTrap    c("ClapTrap");
    std::cout << std::endl;
    ScavTrap    s("ScavTrap");
    std::cout << std::endl;
    FragTrap    f("FragTrap");
    std::cout << std::endl;
    DiamondTrap d("DiamondTrap");
    std::cout << std::endl;

    for (int i = 0; i < 11; i++) {
        c.attack("Target");
    }
    std::cout << std::endl;
    s.guardGate();
    std::cout << std::endl;
    f.highFivesGuys();
    std::cout << std::endl;
    d.whoAmI();
    std::cout << std::endl;

    return 0;
}