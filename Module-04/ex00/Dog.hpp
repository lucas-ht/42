#ifndef __DOG_HPP__
#define __DOG_HPP__

#include "Animal.hpp"

class Dog : public Animal {
public:
    Dog();
    Dog(const Dog& c);
    ~Dog();
    Dog&    operator=(const Dog& c);

    void    makeSound() const;
};

#endif