#ifndef __CAT_HPP__
#define __CAT_HPP__

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
    Brain   *brain;

public:
    Cat();
    Cat(const Cat& c);
    ~Cat();
    Cat& operator=(const Cat& c);

    void    makeSound() const;
};

#endif