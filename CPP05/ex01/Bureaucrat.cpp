#include "Bureaucrat.hpp"

const std::string   Bureaucrat::getName() const { return _name; }
int                 Bureaucrat::getGrade() const { return _grade; }

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    else if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
}

Bureaucrat::Bureaucrat(Bureaucrat const &bureaucrat) : _name(bureaucrat.getName()), _grade(bureaucrat.getGrade()) {}


Bureaucrat &Bureaucrat::operator=(Bureaucrat const &assing){
    if (this != &assing) {
        _grade = assing.getGrade();
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

void Bureaucrat::incrementGrade() {
    if (_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade() {
    if (_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}

const char * Bureaucrat::GradeTooHighException::what() const throw() {
    return "Bureaucrat : Grade Too High";
}

const char * Bureaucrat::GradeTooLowException::what() const throw() {
    return "Bureaucrat : Grade Too Low";
}

void    Bureaucrat::signForm(Form& form) {
    try {
        form.beSigned(*this);
    }
    catch (const std::exception& e) {
        std::cerr << _name << " couldn't sign "<< form.getName() << " because " << e.what() << "\n";
        return ;
    }
    std::cout << _name << " signed " << form.getName() << "\n"; 
}


std::ostream& operator<<(std::ostream &out, Bureaucrat& b) {
    out << b.getName() << ", bureaucrat grade " << b.getGrade();
    return out;
}