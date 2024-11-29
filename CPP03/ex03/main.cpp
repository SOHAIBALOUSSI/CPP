#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    // ClapTrap player1("bot");
    // ScavTrap batman("batman");
    DiamondTrap X("alien");

    std::cout  << std::endl;
    
    // batman.attack("alien");
    X.takeDamage(20);
    X.attack("batman");
    // batman.takeDamage(30);
    X.beRepaired(10);
    X.attack("batman");
    // batman.takeDamage(30);
    std::cout  << std::endl;

    X.whoAmI();

    std::cout  << std::endl;

}