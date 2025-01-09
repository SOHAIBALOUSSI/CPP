#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137) {
    std::ofstream ofile(target + "_shrubbery");
    ofile << "       ### \n      #o### \n    #####o### \n   #o#^#|#/### \n    ###^|/#o# \n     # }|{  # \n       }|{";
    ofile.close();
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& form) {
    *this = ShrubberyCreationForm(form);
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& form) {
    (void)form;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}
