#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include <iostream>
#include <string>

class Animal {
protected:
    std::string type;

    Animal();
    Animal(const Animal& a);

public:
    virtual ~Animal();
    Animal& operator=   (const Animal& a);

    std::string     getType() const;
    virtual void    makeSound() const = 0;
};

#endif