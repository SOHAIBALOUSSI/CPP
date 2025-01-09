#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP


#include "AForm.hpp"
#include "fstream"

class ShrubberyCreationForm : public AForm
{
private:
    
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm& form);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& form);
    ~ShrubberyCreationForm();
};

#endif