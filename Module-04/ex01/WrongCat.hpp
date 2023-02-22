#ifndef __WRONG_CAT_HPP__
#define __WRONG_CAT_HPP__

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
    WrongCat();
    WrongCat(const WrongCat& c);
    ~WrongCat();
    WrongCat&    operator=(const WrongCat& c);

    void    makeSound() const;
};

#endif