#include "WrongCat.hpp"

WrongCat::WrongCat() {
    this->type = "WrongCat";
    std::cout << this->type << " constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& c) {
    *this = c;
    std::cout << this->type << " copy constructor called" << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << this->type << " destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& c) {
    if (this == &c)
        return *this;
    this->type = c.type;
    return *this;
}

void    WrongCat::makeSound() const {
    std::cout << "Meow" << std::endl;
}