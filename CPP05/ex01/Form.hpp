#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Form
{
private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;

public:
    Form();
    Form(const Form& form);
    Form& operator=(const Form& form);
    ~Form();

    const std::string getName() const;
    bool getIsSigned() const;
    const int getGradeToSign() const;
    const int getGradeToExecute() const;

    void beSigned(Bureaucrat& bureaucrat);
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


#endif