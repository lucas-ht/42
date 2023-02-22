#include "Dog.hpp"

Dog::Dog() {
    this->type = "Dog";
    std::cout << this->type << " constructor called" << std::endl;
}

Dog::Dog(const Dog& c) {
    *this = c;
    std::cout << this->type << " copy constructor called" << std::endl;
}

Dog::~Dog() {
    std::cout << this->type << " destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& c) {
    if (this == &c)
        return *this;
    this->type = c.type;
    return *this;
}

void    Dog::makeSound() const {
    std::cout << "Wouf" << std::endl;
}