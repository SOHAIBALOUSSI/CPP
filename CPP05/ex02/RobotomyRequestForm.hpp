#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP


#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
    std::string target;

public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm& form);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& form);
    ~RobotomyRequestForm();


    void  execute(Bureaucrat const & executor) const;
    std::string getTarget() const;
};

#endif