#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : FragTrap() {
    ClapTrap::name = "default_clap_name";
    this->name = "default";
    this->hp = FragTrap::hp;
    this->energy = ScavTrap::energy;
    this->damage = FragTrap::damage;
    std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) {
	ClapTrap::name = name + "_clap_name";
    this->name = name;
    this->hp = FragTrap::hp;
    this->energy = ScavTrap::energy;
    this->damage = FragTrap::damage;
    std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& d) {
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    *this = d;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap&   DiamondTrap::operator=(const DiamondTrap& d) {
    if (this == &d)
        return *this;
    this->name = d.name;
    this->hp = d.energy;
    this->energy = d.energy;
    this->damage = d.damage;
    return *this;
}

void    DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name : " << this->name << "; ClapTrap name : " << ClapTrap::name << std::endl;
}