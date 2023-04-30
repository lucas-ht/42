#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(Cure const & src) : AMateria("cure") {
    *this = src;
}

Cure::~Cure() {}

Cure const & Cure::operator=(Cure const & rhs) {
    if (this == &rhs)
        return *this;
    this->type = rhs.getType();
    return *this;
}

AMateria* Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}