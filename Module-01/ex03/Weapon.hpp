#ifndef __WEAPON_H__
#define __WEAPON_H__

#include <string>

class Weapon {
private:
    std::string type;

public:
    Weapon(std::string);

    std::string getType();
    void        setType(std::string);
};

#endif