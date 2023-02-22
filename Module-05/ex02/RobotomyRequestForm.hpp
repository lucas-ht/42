#ifndef __ROBOTOMY_REQUEST_FORM_HPP__
#define __ROBOTOMY_REQUEST_FORM_HPP__

#include <iostream>
#include <string>
#include <fstream>
#include "Form.hpp"

class RobotomyRequestForm : public Form {
private:
    const std::string     target;

    RobotomyRequestForm();

public:
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm& f);
    ~RobotomyRequestForm();
    RobotomyRequestForm&  operator=(const RobotomyRequestForm& f);

    std::string	    getTarget() const;
    void            execute(Bureaucrat const & executor);
};

#endif