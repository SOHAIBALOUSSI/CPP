#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
int main()
{
    try {
        ShrubberyCreationForm obj("file");
        Bureaucrat obj2("mahjoub", 20);
        // obj2.signForm(obj);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    
}