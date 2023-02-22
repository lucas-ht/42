#include <iostream>
#include "Bureaucrat.hpp"

int main(void) {

    Bureaucrat	b("Test", 80);
    Form        f("Form", 80, 80);

    try {
        b.signForm(f);
        b.signForm(f);
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    Form        f2("Form2", 1, 1);
    std::cout << f2 << std::endl;

    try {
        b.signForm(f2);
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Form    f3("form3", 200, 200);
        std::cout << f3 << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}