#ifndef __SHRUBBERY_CREATION_FORM_HPP__
#define __SHRUBBERY_CREATION_FORM_HPP__

#include <iostream>
#include <string>
#include <fstream>
#include "Form.hpp"

class ShrubberyCreationForm : public Form {
private:
    const std::string     target;

    ShrubberyCreationForm();

public:
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm& f);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm&  operator=(const ShrubberyCreationForm& f);

    std::string	    getTarget() const;
    void            execute(Bureaucrat const & executor);
};

#endif