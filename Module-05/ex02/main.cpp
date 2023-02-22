#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {

    Bureaucrat	            b("Test", 33);
    ShrubberyCreationForm   s("test");
    RobotomyRequestForm     r("test");
    PresidentialPardonForm  p("test");

    try {
        b.signForm(s);
        b.executeForm(s);
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;
    try {
        b.signForm(r);
        b.executeForm(r);
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;
    try {
        b.signForm(p);
        b.executeForm(p);
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
}