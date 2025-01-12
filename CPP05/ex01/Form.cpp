#include "Form.hpp"
#include "Bureaucrat.hpp"


const std::string   Form::getName() const { return name; }
int           Form::getGradeToSign() const { return gradeToSign; }
int           Form::getGradeToExecute() const { return gradeToExecute; }
bool                Form::getIsSigned() const { return isSigned; }


Form::Form()
  : name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {}

Form::Form(std::string FormName, int _gradeToSign, int _gradeToExecute)
  : name(FormName), isSigned(false) , gradeToSign(_gradeToSign), gradeToExecute(_gradeToExecute)
{
    if (gradeToExecute > 150 || gradeToSign > 150)
        throw Form::GradeTooLowException();
    else if (gradeToExecute < 1 || gradeToSign < 1)
        throw Form::GradeTooHighException();
}

Form::Form(const Form& form)
  : name(form.getName()) , isSigned(form.getIsSigned()), gradeToSign(form.getGradeToSign()), gradeToExecute(form.getGradeToExecute()) {}

Form& Form::operator=(const Form& form) {
    if (this != &form) {
        isSigned = form.getIsSigned();
    }
    return *this;
}

Form::~Form() {}

void Form::beSigned(Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > gradeToSign) {
        throw Form::GradeTooLowException();
    }
    isSigned = true;
}

const char * Form::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char * Form::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

std::ostream &operator << (std::ostream &out, Form& form){
    out << "Form name : " << form.getName() << "\n"
        << "is Signed : "  << (form.getIsSigned() == true ? "true" : "false") << "\n"
        << "Grade to sign : " << form.getGradeToSign() << "\n"
        << "Grade to execute : " << form.getGradeToExecute() << "\n";
    return out;
}
