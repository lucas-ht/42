#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern& i) {
    std::cout << "Intern copy constructor called" << std::endl;
    *this = i;
}

Intern::~Intern() {
    std::cout << "Intern destructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& i) {
    if (this == &i)
        return *this;
    return *this;
}

Form    *Intern::makeForm(std::string name, std::string target) {

    Form    *listForm[3] = {
        new ShrubberyCreationForm(target),
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target),
    };
    std::string listName[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon",
    };

    Form    *f = nullptr;

    for (int i = 0; i < 3; i++) {
        if (listName[i] == name)
            f = listForm[i];
        else
            delete listForm[i];
    }

    if (f == nullptr) {
        std::cout << "Intern didn't find " << name << std::endl;
        throw Intern::FormNotFound();
    }
    else
        std::cout << "Intern creates " << name << std::endl;

    return f;
}

const char  *Intern::FormNotFound::what() const throw() {
    return "Form not found";
}