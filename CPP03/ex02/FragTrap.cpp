#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap's Default constructor called\n";
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap's constructor called\n";
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap's copy constructor called\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout << "FragTrap's copy assignment operator called\n";
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap's destructor called\n";
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "🙌 Let's celebrate this win!\n";
}
