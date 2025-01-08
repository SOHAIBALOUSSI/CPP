#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat() : _name("def"), _grade(150) {}
Bureaucrat::Bureaucrat(std::string name, int grade)  {
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    else if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    _name = name;
    _grade = grade;
}
Bureaucrat::~Bureaucrat() {}
Bureaucrat::Bureaucrat(Bureaucrat const &Bureaucrat) : _name(Bureaucrat._name), _grade(Bureaucrat._grade) {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &assing){
    if (this != &assing) {
        _name = assing._name;
        _grade = assing._grade;
    }
    return *this;
}

std::string Bureaucrat::getName() { return _name; }

int Bureaucrat::getGrade() { return _grade; }

void Bureaucrat::incrementGrade(){
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
    return "Grade Too High";
}

const char * Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade Too Low";
}

std::ostream& operator<<(std::ostream &out, Bureaucrat& b) {
    // <name>, bureaucrat grade <grade>
    out << b.getName() << ", bureaucrat grade " << b.getGrade();
    return out;
}