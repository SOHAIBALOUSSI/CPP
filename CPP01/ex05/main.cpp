#include "Harl.hpp"


int main()
{
    Harl obj;
    std::cout << "DEBUG LEVEL :";
    obj.complain("DEBUG");
    std::cout << "INFO LEVEL :";
    obj.complain("INFO");
    std::cout << "WARNING LEVEL :";
    obj.complain("WARNING");
    std::cout << "ERROR LEVEL :";
    obj.complain("ERROR"); 
}