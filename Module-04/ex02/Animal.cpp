#include <Animal.hpp>

Animal::Animal() : type("Animal") {
    std::cout << this->type << " constructor called" << std::endl;
}

Animal::Animal(const Animal& a) : type(a.getType()) {
    std::cout << this->type << " copy constructor called" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& a) {
    this->type = a.getType();
    return *this;
}

std::string Animal::getType() const {
    return this->type;
}
