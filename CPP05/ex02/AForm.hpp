#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm
{
private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;

public:
    AForm();
    AForm(const AForm& form);
    AForm(std::string FormName, int _gradeToSign, int _gradeToExecute);
    AForm& operator=(const AForm& form);
    virtual ~AForm(){};

    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void          beSigned(Bureaucrat& bureaucrat);
    virtual void  execute(Bureaucrat const & executor) const = 0;
    
    class GradeTooHighException : public std::exception
    {
        public:
            const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        public:
            const char *what() const throw();
    };

};

std::ostream &operator << (std::ostream &out, AForm& form);

#endif
