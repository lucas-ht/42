#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{

    Cat *cat = new Cat();
    std::cout << std::endl;
    Cat *cat2 = new Cat(*cat);
    std::cout << std::endl;
    *cat2 = *cat;
    std::cout << std::endl;
    delete cat;
    std::cout << std::endl;
    delete cat2;
    std::cout << std::endl;

    Animal  *animals[10];
    for (int i = 0; i < 10; i++) {
        if (i % 2)  { animals[i] = new Cat(); }
        else        { animals[i] = new Dog(); }
        std::cout << i << std::endl << std::endl;
    }

    for(unsigned int i = 0; i < sizeof(animals) / sizeof(*animals); i++) {
       animals[i]->makeSound();
        std::cout << i << std::endl << std::endl;
    }

    for(unsigned int i = 0; i < sizeof(animals) / sizeof(*animals); i++) {
        delete animals[i];
        std::cout << i << std::endl << std::endl;
    }

    return 0;
}