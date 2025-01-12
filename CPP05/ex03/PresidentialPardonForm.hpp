#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP


#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    std::string target;

public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm& form);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& form);
    ~PresidentialPardonForm();


    void  execute(Bureaucrat const & executor) const;
    std::string getTarget() const;
    static AForm *createForm(std::string target);
};

#endif