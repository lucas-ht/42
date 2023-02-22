#ifndef __INTERN_HPP__
#define __INTERN_HPP__

#include <iostream>
#include <string>

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
public:
    Intern();
    Intern(const Intern& i);
    ~Intern();
    Intern& operator=(const Intern& i);

    Form    *makeForm(std::string name, std::string target);

    class FormNotFound : public std::exception {
    public:
        const char *what() const throw();
    };
};

#endif