#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void) {

    Bureaucrat	            b("Test", 33);
    Intern                  i;

    Form                    *f;

    try {
        f = i.makeForm("robotomy request", "Bender");
        b.signForm(*f);
        b.executeForm(*f);
        delete f;
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

    try {
        f = i.makeForm("hello", "hello");
        b.signForm(*f);
        b.executeForm(*f);
        delete f;
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
}