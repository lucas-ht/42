#ifndef __WRONG_ANIMAL_HPP__
#define __WRONG_ANIMAL_HPP__

#include <iostream>
#include <string>

class WrongAnimal {
protected:
    std::string type;

public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& a);
    ~WrongAnimal();
    WrongAnimal& operator=  (const WrongAnimal& a);

    std::string     getType() const;
    void            makeSound() const;
};

#endif