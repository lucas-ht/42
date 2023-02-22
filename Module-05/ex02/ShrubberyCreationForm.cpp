#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137), target("default") {
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137), target(target) {
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& f) : Form("ShrubberyCreationForm", 145, 137), target(f.getTarget()) {
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm desstructor called" << std::endl;
}

ShrubberyCreationForm&  ShrubberyCreationForm::operator=(const ShrubberyCreationForm& f) {
    if (this == &f)
        return *this;
    return *this;
}

std::string ShrubberyCreationForm::getTarget() const {
    return this->target;
}

void        ShrubberyCreationForm::execute(const Bureaucrat& b) {
    this->checkExecuted(b);

    std::ofstream   f;

    f.open(this->target + "_shrubbery", std::ios::out);
    f << "      _-_        " << std::endl;
    f << "    /~~   ~~\\   " << std::endl;
    f << " /~~         ~~\\" << std::endl;
    f << "{               }" << std::endl;
    f << " \\  _-     -_  /" << std::endl;
    f << "   ~  \\\\ //  ~ " << std::endl;
    f << "_- -   | | _- _  " << std::endl;
    f << "  _ -  | |   -_  " << std::endl;
    f << "      // \\\\    " << std::endl;
    f.close();
}