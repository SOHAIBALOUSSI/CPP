#include "ScavTrap.hpp"

int main()
{
    ScavTrap batman("batman");
    ScavTrap alien("alien");

    std::cout  << std::endl;
    batman.attack("alien");
    alien.takeDamage(20);
    alien.attack("batman");
    batman.takeDamage(20);
    alien.beRepaired(10);

    std::cout  << std::endl;

    batman.guardGate();

    std::cout  << std::endl;
}