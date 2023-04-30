#include <iostream>
#include <string>

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

#include "ICharacter.hpp"
#include "Character.hpp"

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main() {
    IMateriaSource* src = new MateriaSource();

    src->learnMateria(new Ice);
    src->learnMateria(new Cure);

    ICharacter* me = new Character("me");

    AMateria* ice = src->createMateria("ice");
    me->equip(ice);
    me->unequip(0);
    delete ice;

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;

    return 0;
}