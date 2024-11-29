#include "ClapTrap.hpp"

int main()
{
    ClapTrap A("Alex");
    ClapTrap B("Batman");
    
    std::cout << std::endl;
    A.attack("Batman");
    B.takeDamage(0);
    B.beRepaired(5);
    std::cout << std::endl;
}