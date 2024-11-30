
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap's Default constuctor called\n";
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap's constuctor called\n";
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap's copy constructor called\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "ScavTrap copy assignment operator called\n";
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap's destructor called\n";
}

void ScavTrap::attack(const std::string& target)
{
    if (_energyPoints <= 0 || _hitPoints <= 0)
    {
        std::cout << "ScavTrap can't attack\n";
        return ;
    }
    _energyPoints--;
    std::cout << "ScavTrap " << _name << " attacks " << target 
              << " causing " << _attackDamage << " points of damage!\n";  
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode.\n";
}