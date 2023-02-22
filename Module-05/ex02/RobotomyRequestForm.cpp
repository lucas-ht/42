#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45), target("default") {
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45), target(target) {
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& f) : Form("RobotomyRequestForm", 72, 45), target(f.getTarget()) {
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm desstructor called" << std::endl;
}

RobotomyRequestForm&  RobotomyRequestForm::operator=(const RobotomyRequestForm& f) {
    if (this == &f)
        return *this;
    return *this;
}

std::string RobotomyRequestForm::getTarget() const {
    return this->target;
}

void        RobotomyRequestForm::execute(const Bureaucrat& b) {
    this->checkExecuted(b);

    std::srand(std::time(nullptr));
    std::cout << "Drilling noises" << std::endl;
    std::cout << "The robotomization on " << this->target << " has been " << (std::rand() % 2 ? "" : "not ") << "successfull" << std::endl;
}