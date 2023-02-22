#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* cat = new Cat();
    const Animal* dog = new Dog();
    const Animal* meta = new Animal();
    std::cout << std::endl;

    std::cout << cat->getType() << " " << std::endl;
    std::cout << dog->getType() << " " << std::endl;
    std::cout << meta->getType() << " " << std::endl;
    std::cout << std::endl;

    cat->makeSound();
    dog->makeSound();
    meta->makeSound();
    std::cout << std::endl;

    delete meta;
    delete cat;
    delete dog;
    std::cout << std::endl;

    const WrongAnimal* wrongCat = new WrongCat();
    const WrongAnimal* wrongMeta = new WrongAnimal();
    std::cout << std::endl;

    std::cout << wrongCat->getType() << std::endl;
    std::cout << wrongMeta->getType() << std::endl;
    std::cout << std::endl;

    wrongCat->makeSound();
    wrongMeta->makeSound();
    std::cout << std::endl;

    delete wrongCat;
    delete wrongMeta;

    return 0;
}