#include "AForm.hpp"


const std::string AForm::getName() const { return name; }
int AForm::getGradeToSign() const { return gradeToSign; }
int AForm::getGradeToExecute() const { return gradeToExecute; }
bool AForm::getIsSigned() const { return isSigned; }

AForm::~AForm() {}

AForm::AForm()
  : name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {}

AForm::AForm(std::string FormName, int _gradeToSign, int _gradeToExecute)
  : name(FormName), isSigned(false) , gradeToSign(_gradeToSign), gradeToExecute(_gradeToExecute)
{
    if (gradeToExecute > 150 || gradeToSign > 150)
        throw AForm::GradeTooLowException();
    else if (gradeToExecute < 1 || gradeToSign < 1)
        throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm& form)
  : name(form.getName()) , isSigned(form.getIsSigned()), gradeToSign(form.getGradeToSign()), gradeToExecute(form.getGradeToExecute()) {}

AForm& AForm::operator=(const AForm& form) {
    if (this != &form) {
        isSigned = form.getIsSigned();
    }
    return *this;
}

void AForm::beSigned(Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > gradeToSign) {
        throw AForm::GradeTooLowException();
    }
    isSigned = true;
}

const char * AForm::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char * AForm::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

const char * AForm::NotSignedExeption::what() const throw() {
    return "Form not signed";
}

void  AForm::execute(Bureaucrat const & executor) const {
    if (getIsSigned() == false)
        throw AForm::NotSignedExeption();
    else if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();
}

std::ostream &operator << (std::ostream &out, AForm& form){
    out << "Form name : " << form.getName() << "\n"
        << "is Signed : "  << (form.getIsSigned() == true ? "true" : "false") << "\n"
        << "Grade to sign : " << form.getGradeToSign() << "\n"
        << "Grade to execute : " << form.getGradeToExecute() << "\n";
    return out;
}
