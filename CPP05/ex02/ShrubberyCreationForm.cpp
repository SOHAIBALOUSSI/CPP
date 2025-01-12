#include "ShrubberyCreationForm.hpp"

std::string ShrubberyCreationForm::getTarget() const { return target; }

ShrubberyCreationForm::ShrubberyCreationForm() : AForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137) {
    this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& form) : target(form.getTarget()) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& form) {
    if (this != &form) {
        target = form.getTarget();
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    AForm::execute(executor);
    std::string filename = getTarget() + "_shrubbery";
    std::ofstream ofile(filename.c_str());
    if (ofile.is_open()) {
        ofile << ASCII_TREE;
        ofile.close();
    }
    else {
        throw std::runtime_error("cannot open file");
    }
}