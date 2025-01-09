#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm() {}

const char* loadTree() {
    const char * tree = "       ### \n      #o### \n    #####o### \n   #o#^#|#/### \n    ###^|/#o# \n     # }|{  # \n       }|{";
    return tree;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137) {
    const char* tree = loadTree();
    std::ofstream ofile(target + "_shrubbery");
    ofile << tree;
    ofile.close();
    std::cout << tree << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& form) {
    *this = ShrubberyCreationForm(form);
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& form) {
    (void)form;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}
