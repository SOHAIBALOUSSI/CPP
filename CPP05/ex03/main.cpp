#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    try
    {
        Intern i;
        Bureaucrat Bureaucrat1("Ahmed", 1);
        AForm *a;
        AForm *b;
        AForm *c;

        a = i.makeForm("robotomy request", "robot");
        b = i.makeForm("presidential pardon", "samir");
        c = i.makeForm("shrubbery creation", "home");
    
        std::cout << "\n";
        Bureaucrat1.signForm(*a);
        Bureaucrat1.signForm(*b);
        Bureaucrat1.signForm(*c);
        std::cout << "\n";

        Bureaucrat1.executeForm(*a);
        std::cout << "\n";

        Bureaucrat1.executeForm(*b);
        std::cout << "\n";

        Bureaucrat1.executeForm(*c);
        std::cout << "\n";
        delete a;
        delete b;
        delete c;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // try
    // {
    //     Intern i;
    //     Bureaucrat Bureaucrat1("Ahmed", 1);
    //     AForm *a;
    //     AForm *b;
    //     AForm *c;

    //     a = i.makeForm("robotomy request", "robot");
    //     b = i.makeForm("presidential pardon", "samir");
    //     c = i.makeForm("shrubbery creation", "home");
    
    //     std::cout << "\n";

    //     std::cout << "\n";

    //     Bureaucrat1.executeForm(*a);
    //     std::cout << "\n";

    //     Bureaucrat1.executeForm(*b);
    //     std::cout << "\n";

    //     Bureaucrat1.executeForm(*c);
    //     std::cout << "\n";
    //     delete a;
    //     delete b;
    //     delete c;
    // }
    // catch (std::exception &e) {
    //     std::cout << e.what() << std::endl;
    // }

}
