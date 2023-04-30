#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(Ice const & src) : AMateria("ice") {
    *this = src;
}

Ice::~Ice() {}

Ice const & Ice::operator=(Ice const & rhs) {
    if (this == &rhs)
        return *this;
    this->type = rhs.getType();
    return *this;
}

AMateria* Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
