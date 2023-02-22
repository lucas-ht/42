#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(Bureaucrat::lowestGrade) {
    std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {
    std::cout << "Bureaucrat constructor called" << std::endl;
    this->grade = grade;
    this->checkGrade();
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& b) {
    std::cout << "Bureaucrat copy constructor called" << std::endl;
    *this = b;
}

std::ostream&   operator<< (std::ostream &o, Bureaucrat const &b) {
    return o << b.getName() << ", bureaucrat grade " << b.getGrade();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b) {
    if (this == &b)
        return *this;
    this->name = b.name;
    this->grade = b.grade;
    this->checkGrade();
    return *this;
}

void        Bureaucrat::checkGrade() {
    if (this->grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (this->grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

std::string Bureaucrat::getName() const {
    return this->name;
}

int         Bureaucrat::getGrade() const {
    return this->grade;
}

void        Bureaucrat::promote() {
    this->grade--;
    this->checkGrade();
}

void        Bureaucrat::demote() {
    this->grade++;
    this->checkGrade();
}

const char  *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char  *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low";
}