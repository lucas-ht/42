#ifndef __DIAMOND_TRAP_HPP__
#define __DIAMOND_TRAP_HPP__

#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
private:
    std::string name;

public:
    DiamondTrap();
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap& d);
    ~DiamondTrap();
    DiamondTrap&   operator=(const DiamondTrap& d);

    void	whoAmI();
};

#endif