#include "Bureaucrat.hpp"




int main()
{
    try
    {
       Bureaucrat Mahjoub("Mahjoub", 15);
       std::cout << "Mahjoub's info:\n" << Mahjoub << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
       Bureaucrat saaid("saaid", 151); // too low grade
       std::cout << "saaid's info:\n" << saaid << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
       Bureaucrat ahmed("ahmed", 0); // high grade
       std::cout << "ahmed's info:\n" << ahmed << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}