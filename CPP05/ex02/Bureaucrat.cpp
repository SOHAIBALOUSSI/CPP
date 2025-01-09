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
Bureaucrat::Bureaucrat(Bureaucrat const &Bureaucrat) : _name(Bureaucrat._name), _grade(Bureaucrat._grade) {}
Bureaucrat::~Bureaucrat() {}

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
    return "Bureaucrat : Grade Too High";
}

const char * Bureaucrat::GradeTooLowException::what() const throw() {
    return "Bureaucrat : Grade Too Low";
}

void    Bureaucrat::signForm(AForm& form) {
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