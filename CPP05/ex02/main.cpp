#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
int main()
{
    try {
        ShrubberyCreationForm obj("form1");
        Bureaucrat obj2("mahjoub", 150);
        obj2.signForm(obj);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}