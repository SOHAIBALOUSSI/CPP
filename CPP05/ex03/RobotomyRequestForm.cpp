#include "RobotomyRequestForm.hpp"

std::string RobotomyRequestForm::getTarget() const { return target; }

RobotomyRequestForm::RobotomyRequestForm() : AForm() {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45) {
    this->target = target;
}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& form) : target(form.getTarget()) {
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& form) {
    if (this != &form) {
        target = form.getTarget();
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    srand(time(0));
    AForm::execute(executor);
    std::cout << "* zZZzZRRRRR ZRRRRRRRRzRRR...*\n";

    if (rand() % 2) {
        std::cout << getTarget() << " has been robotomized successfully\n";
    }
    else {
        std::cout << "Robotomy failed for " << getTarget() << "\n";
    }
}

AForm *RobotomyRequestForm::createForm(std::string target) {
    return new RobotomyRequestForm(target);
}