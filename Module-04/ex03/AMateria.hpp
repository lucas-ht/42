#ifndef __AMATERIA_HPP__
#define __AMATERIA_HPP__

#include <iostream>
#include <string>

class ICharacter;

class AMateria {
private:
    AMateria();

protected:
    std::string type;

public:
    AMateria(AMateria const & src);
    AMateria(std::string const & type);
    virtual ~AMateria();
    AMateria const & operator=(AMateria const & rhs);

    std::string const & getType() const;

    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif