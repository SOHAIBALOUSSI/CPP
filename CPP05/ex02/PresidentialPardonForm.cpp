#include "PresidentialPardonForm.hpp"

std::string PresidentialPardonForm::getTarget() const { return target; }

PresidentialPardonForm::PresidentialPardonForm() : AForm() {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 145, 137) {
    this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& form) : target(form.getTarget()) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& form) {
    if (this != &form) {
        target = form.getTarget();
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    AForm::execute(executor);
    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox.\n";
}