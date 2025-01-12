#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP


#include "AForm.hpp"

#define  ASCII_TREE  "\n       ### \n      #o### \n    #####o### \n   #o#^#|#/### \n    ###^|/#o# \n     # }|{  # \n       }|{\n"

class ShrubberyCreationForm : public AForm
{
private:
    std::string target;

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm& form);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& form);
    ~ShrubberyCreationForm();


    void  execute(Bureaucrat const & executor) const;
    std::string getTarget() const;
    static AForm *createForm(std::string target);
};

#endif