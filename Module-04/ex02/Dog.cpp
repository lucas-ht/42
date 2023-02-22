#include "Dog.hpp"

Dog::Dog() {
    this->type = "Dog";
    std::cout << this->type << " constructor called" << std::endl;
    this->brain = new Brain;
}

Dog::Dog(const Dog& d) {
    std::cout << "Dog copy constructor called" << std::endl;
    *this = d;
}

Dog::~Dog() {
    std::cout << this->type << " destructor called" << std::endl;
    delete this->brain;
}

Dog& Dog::operator=(const Dog& c) {
    if (this == &c)
        return *this;
    this->type = c.type;
    this->brain = new Brain(*c.brain);
    return *this;
}

void    Dog::makeSound() const {
    std::cout << "Wouf" << std::endl;
}