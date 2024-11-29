
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap's Default constructor called\n";
}
ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap's constructor called\n";
}
ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "ClapTrap's copy constructor called\n";
    _name = other._name; 
    _hitPoints = other._hitPoints; 
    _energyPoints = other._energyPoints; 
    _attackDamage = other._attackDamage;
}
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "ClapTrap's copy assignment operator called\n";
    if (this == &other)
        return (*this);
    _name = other._name; 
    _hitPoints = other._hitPoints; 
    _energyPoints = other._energyPoints; 
    _attackDamage = other._attackDamage;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap's Destructor called\n";
}


void ClapTrap::attack(const std::string& target)
{
    if (_energyPoints <= 0 || _hitPoints <= 0)
    {
        std::cout << "ClapTrap can't attack\n";
        return ;
    }
    _energyPoints--;
    std::cout << "ClapTrap " << _name << " attacks " << target 
              << " causing " << _attackDamage << " points of damage!\n";  
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints <= 0 || _hitPoints <= 0)
    {
        std::cout << "ClapTrap can't be reperaid\n";
        return ;
    }
    _energyPoints--;
    _hitPoints += amount;
    std::cout << "ClapTrap " << _name << " repaired with " << amount << " hit points"<< "\n"; 
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount > _hitPoints)
        amount = _hitPoints;
    _hitPoints -= amount;
    std::cout << "ClapTrap " << _name << " lost " << amount << " hit points\n";
}