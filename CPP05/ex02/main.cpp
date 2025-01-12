#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try {
        ShrubberyCreationForm form1("home");
        PresidentialPardonForm form2("sabir");
        RobotomyRequestForm form3("robot");

        Bureaucrat  b("ahmed", 1);
        b.signForm(form1);
        b.signForm(form2);
        b.signForm(form3);
        std::cout << std::endl;
        b.executeForm(form1);
        std::cout << std::endl;
        b.executeForm(form2);
        std::cout << std::endl;
        b.executeForm(form3);
        std::cout << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    try {
        ShrubberyCreationForm form1("home");
        PresidentialPardonForm form2("sabir");
        RobotomyRequestForm form3("robot");

        Bureaucrat  b("ahmed", 1);
        b.signForm(form1);
        // b.signForm(form2);
        // b.signForm(form3);
        std::cout << std::endl;
        b.executeForm(form1);
        std::cout << std::endl;
        b.executeForm(form2);
        std::cout << std::endl;
        b.executeForm(form3);
        std::cout << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

}
