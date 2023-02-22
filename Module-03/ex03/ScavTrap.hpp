#ifndef __SCAV_TRAP_HPP__
#define __SCAV_TRAP_HPP__

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap& s);
    ~ScavTrap();
    ScavTrap&   operator=(const ScavTrap& s);

    void guardGate();
};

#endif