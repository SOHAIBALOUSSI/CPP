#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : _name("Default")
{
    std::cout << "DiamondTrap's Default constuctor called\n";
}

DiamondTrap::DiamondTrap(std::string name) : _name(name)
{
    std::cout << "DiamondTrap's constuctor called\n";
    ClapTrap::_name = name + "_clap_name";
    this->_hitPoints = FragTrap::_hitPoints;
    this-> _energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
}
DiamondTrap::DiamondTrap(const DiamondTrap& other) : FragTrap(other), ScavTrap(other), ClapTrap(other)
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