#ifndef __HUMANB_H__
#define __HUMANB_H__

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB {
private:
    std::string name;
    Weapon      *weapon;

public:
    HumanB(std::string);
    void        setWeapon(Weapon &);
    void        attack();
};

#endif