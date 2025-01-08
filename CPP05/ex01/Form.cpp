#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {}

Form::~Form() {}

const std::string Form::getName() const { return name; }

const int Form::getGradeToSign() const { return gradeToSign; }

const int Form::getGradeToExecute() const { return gradeToExecute; }

bool Form::getIsSigned() const { return isSigned; }


Form::Form(const Form& form)
 : name(form.getName()) , isSigned(form.getIsSigned()), gradeToSign(form.getGradeToSign()), gradeToExecute(form.getGradeToExecute()) {}

Form& Form::operator=(const Form& form) { // m3rt lach dayrin had l3jb
    if (this != &form) {
        isSigned = form.isSigned;
    }
    return *this;
}

void Form::beSigned(Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > gradeToSign) {
        throw Form::GradeTooLowException();
    }
    isSigned = true;
}
