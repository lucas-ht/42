#include "Zombie.hpp"

int main(void) {
    Zombie  *heap = newZombie("heap");
    heap->announce();
    delete heap;

    randomChump("stack");
}