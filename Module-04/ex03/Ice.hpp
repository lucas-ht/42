#ifndef __ICE_HPP__
#define __ICE_HPP__

#include "AMateria.hpp"

class Ice : public AMateria {

public:
    Ice();
    Ice(Ice const & src);
    virtual ~Ice();
    Ice const & operator=(Ice const & rhs);

    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);

};

#endif