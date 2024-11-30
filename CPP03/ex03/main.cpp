#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap X("alien");
    DiamondTrap Y("BATMAN");

    std::cout  << std::endl;
    
    X.attack("BATMAN");
    Y.takeDamage(30);
    Y.beRepaired(20);

    std::cout  << std::endl;

    X.whoAmI();

    std::cout  << std::endl;
    X.guardGate(); // inherited 
    std::cout  << std::endl;
    X.highFivesGuys(); // inherited 
    std::cout  << std::endl;
}