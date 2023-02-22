#ifndef __FRAG_TRAP_HPP__
#define __FRAG_TRAP_HPP__

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(const FragTrap& s);
    ~FragTrap();
    FragTrap&   operator=(const FragTrap& s);

    void highFivesGuys();
};

#endif