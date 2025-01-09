#include "ShrubberyCreationForm.hpp"

std::string ShrubberyCreationForm::getTarget() const { return target; }

ShrubberyCreationForm::ShrubberyCreationForm() : AForm() {}
/*
    std::string filename = target + "_shrubbery";
    std::ofstream ofile(filename.c_str());
    ofile << "\n       ### \n      #o### \n    #####o### \n   #o#^#|#/### \n    ###^|/#o# \n     # }|{  # \n       }|{";
    ofile.close();
*/

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137) {

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& form) {
    // *this = ShrubberyCreationForm(form);
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& form) {
    (void)form;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}


void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const {

}