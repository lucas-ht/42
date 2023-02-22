#include <iostream>
#include <exception>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void) {
    switch (std::rand() % 3) {
        case 0: {
            std::cout << "new A" << std::endl;
            return dynamic_cast<Base *>(new A);
        }
        case 1: {
            std::cout << "new B" << std::endl;
            return dynamic_cast<Base *>(new B);
        }
        case 2: {
            std::cout << "new C" << std::endl;
            return dynamic_cast<Base *>(new C);
        }
    }
    return nullptr;
}

void identify(Base* p) {

    if (dynamic_cast<A *>(p))
        std::cout << "A identified" << std::endl;
    if (dynamic_cast<B *>(p))
        std::cout << "B identified" << std::endl;
    if (dynamic_cast<C *>(p))
        std::cout << "C identified" << std::endl;
}

void identify(Base& p) {
    try {
        A   a = dynamic_cast<A&>(p);
        std::cout << "A identified" << std::endl;
    }
    catch(const std::exception& e) {
        (void) e;
    }

    try {
        B   b = dynamic_cast<B&>(p);
        std::cout << "B identified" << std::endl;
    }
    catch(const std::exception& e) {
        (void) e;
    }

    try {
        C   c = dynamic_cast<C&>(p);
        std::cout << "C identified" << std::endl;
    }
    catch(const std::exception& e) {
        (void) e;
    }
}

int main() {
    std::srand(std::time(nullptr));

    Base    *b;
    for (int i = 0; i < 10; i++) {
        b = generate();
        identify(b);
        identify(*b);
        delete b;
        std::cout << std::endl;
    }
}
