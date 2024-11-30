#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : _name("Default")
{
    std::cout << "DiamondTrap's Default constuctor called\n";
    ClapTrap::_name = "Default_clap_name";
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), FragTrap(name), ScavTrap(name)
{
    std::cout << "DiamondTrap's constuctor called\n";

    _name = name;
    ClapTrap::_name = name + "_clap_name";
    _hitPoints = FragTrap::_hitPoints;
     _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other), ScavTrap(other)
{
    std::cout << "DiamondTrap copy constuctor called\n";
    this->_name = other._name;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    std::cout << "DiamondTrap copy assignment operator called\n";
    if (this != &other)
    {
        ClapTrap::operator=(other);
        this->_name = other._name;
    }
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called\n";
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << _name 
              << ", ClapTrap name: " << ClapTrap::_name << std::endl;
}