#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : name("default") {
    for (int i = 0; i < 4; i++)
        this->inventory[i] = nullptr;
}

Character::Character(std::string const & name) : name(name) {
    for (int i = 0; i < 4; i++)
        this->inventory[i] = nullptr;
}

Character::Character(Character const & src) {
    *this = src;
}

Character::~Character() {
    for (int i = 0; i < 4; i++) {
        delete this->inventory[i];
    }
}

Character const & Character::operator=(Character const & rhs) {
    if (this == &rhs)
        return *this;
    this->name = rhs.getName();
    for (int i = 0; i < 4; i++) {
        if (this->inventory[i])
            delete this->inventory[i];
    }
    for (int i = 0; i < 4; i++) {
        if (rhs.inventory[i])
            this->inventory[i] = rhs.inventory[i]->clone();
    }
    return *this;
}

std::string const & Character::getName() const {
    return this->name;
}

void Character::equip(AMateria* m) {
    if (!m)
        return ;
    for (int i = 0; i < 4; i++) {
        if (!this->inventory[i]) {
            this->inventory[i] = m;
            return ;
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4 && this->inventory[idx])
        this->inventory[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && this->inventory[idx])
        this->inventory[idx]->use(target);
}