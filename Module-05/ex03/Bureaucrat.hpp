#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <iostream>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat {
private:
    static const int    lowestGrade = 150;
    static const int    highestGrade = 1;

    std::string name;
    int         grade;

    Bureaucrat();

    void    checkGrade();

public:
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat& b);
    ~Bureaucrat();
    Bureaucrat& operator=(const Bureaucrat& b);

    std::string getName() const;
    int         getGrade() const;
    void        promote();
    void        demote();

    void        signForm(Form& f) const;
    void        executeForm(Form& form);

    class GradeTooHighException : public std::exception {
    public:
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        const char *what() const throw();
    };


};

std::ostream&   operator<< (std::ostream &o, Bureaucrat const &b);

#endif