#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat Mahjoub("Mahjoub", 1);
        Form form("form", 10, 10);
        Mahjoub.signForm(form);
        std::cout << "form info:\n" << form << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Bureaucrat Ahmed("Ahmed", 150);
        Form form("form", 10, 10);
        Ahmed.signForm(form);
        std::cout << "form info:\n" << form << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}