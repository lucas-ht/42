#include "Cat.hpp"

Cat::Cat() {
    this->type = "Cat";
    std::cout << this->type << " constructor called" << std::endl;
    this->brain = new Brain;
}

Cat::Cat(const Cat& c) {
    std::cout << "Cat copy constructor called" << std::endl;
    *this = c;
}

Cat::~Cat() {
    std::cout << this->type << " destructor called" << std::endl;
    delete this->brain;
}

Cat& Cat::operator=(const Cat& c) {
    if (this == &c)
        return *this;
    this->type = c.type;
    delete this->brain;
    this->brain = new Brain(*c.brain);
    return *this;
}

void    Cat::makeSound() const {
    std::cout << "Meow" << std::endl;
}
