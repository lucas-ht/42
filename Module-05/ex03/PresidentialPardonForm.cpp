#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5), target("default") {
    std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5), target(target) {
    std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& f) : Form("PresidentialPardonForm", 25, 5), target(f.getTarget()) {
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm desstructor called" << std::endl;
}

PresidentialPardonForm&  PresidentialPardonForm::operator=(const PresidentialPardonForm& f) {
    if (this == &f)
        return *this;
    return *this;
}

std::string PresidentialPardonForm::getTarget() const {
    return this->target;
}

void        PresidentialPardonForm::execute(const Bureaucrat& b) {
    this->checkExecuted(b);

    std::cout << this->target << " was pardoned by Zaphod Beeblebrox" << std::endl;
}