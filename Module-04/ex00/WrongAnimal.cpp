#include <WrongAnimal.hpp>

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << this->type << " constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& a) {
    *this = a;
    std::cout << this->type << " copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& a) {
    if (this == &a)
        return *this;
    this->type = a.type;
    return *this;
}

std::string WrongAnimal::getType() const {
    return this->type;
}

void    WrongAnimal::makeSound() const {
    std::cout << "Animal Sound" << std::endl;
}