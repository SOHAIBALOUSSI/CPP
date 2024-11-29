#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    FragTrap batman("batman");
    FragTrap alien("alien");

    std::cout << std::endl;
    
    batman.attack("alien");
    alien.takeDamage(20);
    alien.attack("batman");
    batman.takeDamage(20);
    alien.beRepaired(10);
    alien.attack("batman");
    batman.takeDamage(20);

    std::cout  << std::endl;

    alien.highFivesGuys();

    std::cout  << std::endl;

}