#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(Intern const &intern)
{
    *this = intern;
}

Intern &Intern::operator=(Intern const &intern)
{
    (void)intern;
    return *this;
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
    static std::string formNames[3] = {
        "robotomy request",
        "presidential pardon",
        "shrubbery creation"
    };

    static CreateFormFunction createForms[3] = {
                &RobotomyRequestForm::createForm,
                &PresidentialPardonForm::createForm,
                &ShrubberyCreationForm::createForm
            };

    for (int i = 0; i < 3; i++) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << "\n";
            return createForms[i](target);
        }
    }
    throw FormNotFoundException();
}

const char *Intern::FormNotFoundException::what() const throw() {
    return "Form type not found";
}