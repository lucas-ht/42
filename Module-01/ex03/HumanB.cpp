#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name) {
    this->weapon = nullptr;
};

void    HumanB::setWeapon(Weapon &weapon) {
    this->weapon = &weapon;
};

void    HumanB::attack() {
    if (this->weapon == nullptr)
        return;
    std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
};