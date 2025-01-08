#include "Bureaucrat.hpp"

int main()
{

    try
    {
       Bureaucrat obj("mahjoub", -1);
       Bureaucrat obj2("sa3id", 300);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    Bureaucrat obj3("mahjoub", 20);
    std::cout << obj3 << std::endl;
}