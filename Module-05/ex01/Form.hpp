#ifndef __FORM_HPP__
#define __FORM_HPP__

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
    static const int    lowestGrade = 150;
    static const int    highestGrade = 1;

    const std::string   name;
    bool                isSigned;
    const int           gradeSign;
    const int           gradeExec;

    Form();

    void        checkGrade();

public:
    Form(std::string name, int gradeSign, int gradeExec);
    Form(const Form& f);
    ~Form();
    Form& operator=(const Form& f);

    std::string getName() const;
    int         getGradeSign() const;
    int         getGradeExec() const;
    bool        getSigned() const;
    bool        beSigned(const Bureaucrat& b);

    class GradeTooHighException : public std::exception {
    public:
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        const char *what() const throw();
    };
};

std::ostream&   operator<< (std::ostream &o, Form const &f);

#endif