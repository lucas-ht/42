#ifndef __CHARACTER_HPP__
#define __CHARACTER_HPP__

#include <iostream>
#include <string>

#include "ICharacter.hpp"

class Character : public ICharacter {
private:
    std::string name;
    AMateria *inventory[4];

    Character();

public:
    Character(std::string const & name);
    Character(Character const & src);
    ~Character();
    Character const & operator=(Character const & rhs);

    std::string const & getName() const;

    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);

};

#endif