#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

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
    Form(std::string FormName, int _gradeToSign, int _gradeToExecute);
    Form& operator=(const Form& form);
    ~Form();

    const std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

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

std::ostream &operator << (std::ostream &out, Form& form);


#endif