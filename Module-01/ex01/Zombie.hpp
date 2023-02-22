#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include <iostream>
#include <string>

class Zombie {
public:
    std::string name;

    Zombie();
    Zombie(std::string name);
    ~Zombie();
    void    announce();
};

Zombie* zombieHorde(int N, std::string name);

#endif