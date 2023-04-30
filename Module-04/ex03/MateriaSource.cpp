#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++)
        this->inventory[i] = nullptr;
}

MateriaSource::MateriaSource(MateriaSource const & src) {
    *this = src;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        if (this->inventory[i])
            delete this->inventory[i];
    }
}

MateriaSource const & MateriaSource::operator=(MateriaSource const & rhs) {
    if (this == &rhs)
        return *this;
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

void MateriaSource::learnMateria(AMateria* m) {
    if (!m)
        return ;
    for (int i = 0; i < 4; i++) {
        if (!this->inventory[i]) {
            this->inventory[i] = m;
            return ;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (this->inventory[i] && this->inventory[i]->getType() == type)
            return this->inventory[i]->clone();
    }
    return nullptr;
}