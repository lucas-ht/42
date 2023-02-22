#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include <iostream>
#include <string>

class Zombie {
private:
    std::string name;

public:
    Zombie(std::string name);
    ~Zombie();
    void    announce();
};

Zombie* newZombie(std::string name);
void    randomChump(std::string name);

#endif