#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("default"), hp(100), energy(50), damage(10) {
    std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hp(100), energy(50), damage(10) {
    std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& c) {
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = c;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap&   ClapTrap::operator=(const ClapTrap& c) {
    if (this == &c)
        return *this;
    this->name = c.name;
    this->hp = c.energy;
    this->energy = c.energy;
    this->damage = c.damage;
    return *this;
}

void        ClapTrap::attack(const std::string& target) {
    if (!this->hp) {
        std::cout << "ClapTrap can't attack ! (He has 0 hp)" << std::endl;
        return;
    }
    if (!this->energy) {
        std::cout << "ClapTrap can't attack ! (He has 0 energy)" << std::endl;
        return;
    }
    std::cout << "ClapTrap attacked " << target << " causing " << this->damage << " damage" << std::endl;
    this->energy--;
}

void        ClapTrap::takeDamage(unsigned int amount) {
    if (!this->hp) {
        std::cout << "ClapTrap is already dead !" << std::endl;
        return;
    }

    this->hp = (this->hp - amount > 0) ? this->hp - amount : 0;
    std::cout << "ClapTrap took " << amount << " damage, he has " << this->hp << " hp" << std::endl;
    if (!this->hp)
        std::cout << "ClapTrap died" << std::endl;
}

void        ClapTrap::beRepaired(unsigned int amount) {
    if (!this->hp) {
        std::cout << "ClapTrap can't be repaired ! (He has 0 hp)" << std::endl;
        return;
    }
    if (!this->energy) {
        std::cout << "ClapTrap can't be repaired ! (He has 0 energy)" << std::endl;
        return;
    }
    this->hp += amount;
    std::cout << "ClapTrap repaired itself, he now has " << this->hp << " hp" << std::endl;
    this->energy--;
}