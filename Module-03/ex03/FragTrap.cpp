#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    this->hp = 100;
    this->energy = 100;
    this->damage = 30;
    std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->hp = 100;
    this->energy = 100;
    this->damage = 30;
    std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& s) {
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = s;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap&   FragTrap::operator=(const FragTrap& s) {
    if (this == &s)
        return *this;
    this->name = s.name;
    this->hp = s.energy;
    this->energy = s.energy;
    this->damage = s.damage;
    return *this;
}

void    FragTrap::highFivesGuys() {
    std::cout << "FragTrap is asking for high fives !" << std::endl;
}