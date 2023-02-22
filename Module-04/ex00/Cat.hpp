#ifndef __CAT_HPP__
#define __CAT_HPP__

#include "Animal.hpp"

class Cat : public Animal {
public:
    Cat();
    Cat(const Cat& c);
    ~Cat();
    Cat&    operator=(const Cat& c);

    void    makeSound() const;
};

#endif