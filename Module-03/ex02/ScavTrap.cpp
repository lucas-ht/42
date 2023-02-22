#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& s) {
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = s;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap&   ScavTrap::operator=(const ScavTrap& s) {
    if (this == &s)
        return *this;
    this->name = s.name;
    this->hp = s.energy;
    this->energy = s.energy;
    this->damage = s.damage;
    return *this;
}

void    ScavTrap::guardGate() {
    std::cout << "ScavTrap is in gate keeper mode" << std::endl;
}