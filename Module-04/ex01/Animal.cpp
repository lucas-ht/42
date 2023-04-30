#include <Animal.hpp>

Animal::Animal() : type("Animal") {
    std::cout << this->type << " constructor called" << std::endl;
}

Animal::Animal(const Animal& a) {
    *this = a;
    std::cout << this->type << " copy constructor called" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& a) {
    if (this == &a)
        return *this;
    this->type = a.getType();
    return *this;
}

std::string Animal::getType() const {
    return this->type;
}

void    Animal::makeSound() const {
    std::cout << "Animal Sound" << std::endl;
}