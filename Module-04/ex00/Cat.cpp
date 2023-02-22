#include "Cat.hpp"

Cat::Cat() {
    this->type = "Cat";
    std::cout << this->type << " constructor called" << std::endl;
}

Cat::Cat(const Cat& c) {
    *this = c;
    std::cout << this->type << " copy constructor called" << std::endl;
}

Cat::~Cat() {
    std::cout << this->type << " destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& c) {
    if (this == &c)
        return *this;
    this->type = c.type;
    return *this;
}

void    Cat::makeSound() const {
    std::cout << "Meow" << std::endl;
}