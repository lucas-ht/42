#ifndef __CLAP_TRAP_HPP__
#define __CLAP_TRAP_HPP__

#include <iostream>
#include <string>

class ClapTrap {
private:
    std::string name;
    int         hp;
    int         energy;
    int         damage;

public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& c);
    ~ClapTrap();
    ClapTrap&   operator=(const ClapTrap& c);

    void        attack(const std::string& target);
    void        takeDamage(unsigned int amount);
    void        beRepaired(unsigned int amount);
};


#endif