#ifndef __CURE_HPP__
#define __CURE_HPP__

#include "AMateria.hpp"

class Cure : public AMateria {

public:
    Cure();
    Cure(Cure const & src);
    virtual ~Cure();
    Cure const & operator=(Cure const & rhs);

    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);

};

#endif