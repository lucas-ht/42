#ifndef __MATRIASOURCE_HPP__
#define __MATRIASOURCE_HPP__

#include <iostream>
#include <string>

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

private:
    AMateria *inventory[4];

public:
    MateriaSource();
    MateriaSource(MateriaSource const & src);
    ~MateriaSource();
    MateriaSource const & operator=(MateriaSource const & rhs);

    void learnMateria(AMateria*);
    AMateria* createMateria(std::string const & type);

};

#endif