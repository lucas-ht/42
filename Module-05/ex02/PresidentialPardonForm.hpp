#ifndef __PRESIDENTIAL_PARDON_FORM_HPP__
#define __PRESIDENTIAL_PARDON_FORM_HPP__

#include <iostream>
#include <string>
#include <fstream>
#include "Form.hpp"

class PresidentialPardonForm : public Form {
private:
    const std::string     target;

    PresidentialPardonForm();

public:
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm& f);
    ~PresidentialPardonForm();
    PresidentialPardonForm&  operator=(const PresidentialPardonForm& f);

    std::string	    getTarget() const;
    void            execute(Bureaucrat const & executor);
};

#endif