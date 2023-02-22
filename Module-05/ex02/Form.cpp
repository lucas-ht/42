#include "Form.hpp"

Form::Form() : name("default"), gradeSign(Form::lowestGrade), gradeExec(Form::lowestGrade) {
    std::cout << "Form constructor called" << std::endl;
}

Form::Form(std::string name, int gradeSign, int gradeExec) : name(name), gradeSign(gradeSign), gradeExec(gradeExec) {
    std::cout << "Form constructor called" << std::endl;
    this->isSigned = false;
    this->checkGrade();
}

Form::Form(const Form& f) : name(f.name), gradeSign(f.gradeSign), gradeExec(f.gradeExec) {
    std::cout << "Form copy constructor called" << std::endl;
    *this = f;
    this->checkGrade();
}

Form::~Form() {
    std::cout << "Form destructor called" << std::endl;
}

std::ostream&   operator<< (std::ostream &o, Form const &b) {
    return o << "form; name " << b.getName() << "; gradeSign " << b.getGradeSign() << "; gradeExec " << b.getGradeExec();
}

Form& Form::operator=(const Form& b) {
    if (this == &b)
        return *this;
    this->isSigned = b.isSigned;
    return *this;
}

void        Form::checkGrade() {
    if (this->gradeSign < 1 || this->gradeExec < 1)
        throw Form::GradeTooHighException();
    if (this->gradeSign > 150 || this->gradeExec > 150)
        throw Form::GradeTooLowException();
}

std::string Form::getName() const {
    return this->name;
}

int         Form::getGradeSign() const {
    return this->gradeSign;
}

int         Form::getGradeExec() const {
    return this->gradeExec;
}

bool        Form::getSigned() const {
    return this->isSigned;
}

bool        Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > this->gradeSign)
        throw Form::GradeTooLowException();
    this->isSigned = true;
    return true;
}

bool        Form::checkExecuted(const Bureaucrat& b) {
    if (b.getGrade() > this->gradeExec)
        throw Form::GradeTooLowException();
    return true;
}

const char  *Form::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char  *Form::GradeTooLowException::what() const throw() {
    return "Grade too low";
}