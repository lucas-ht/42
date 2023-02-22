#include <iostream>
#include "Bureaucrat.hpp"

int main(void) {
    try {
        Bureaucrat	b("Test", 150);
        b.promote();
        std::cout << b << std::endl;
        b.demote();
        std::cout << b << std::endl;
        b.demote();
        std::cout << b << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}