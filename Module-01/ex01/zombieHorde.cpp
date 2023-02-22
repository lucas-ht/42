#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    Zombie *z = new Zombie[N];
    for (int i = 0; i < N; i++)
        z[i].name = name;
    return z;
}