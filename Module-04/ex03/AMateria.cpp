#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : type("default") {}

AMateria::AMateria(AMateria const & src) {
    *this = src;
}

AMateria::AMateria(std::string const & type) : type(type) {}

AMateria::~AMateria() {}

AMateria const & AMateria::operator=(AMateria const & rhs) {
    if (this == &rhs)
        return *this;
    this->type = rhs.getType();
    return *this;
}

std::string const & AMateria::getType() const {
    return this->type;
}

void    AMateria::use(ICharacter& target) {
    std::cout << "AMateria use on " << target.getName() << std::endl;
}