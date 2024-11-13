#include "HumanA.hpp"

HumanA::HumanA(std::string humanName, Weapon &WeaponObj)
    : name(humanName), WeaponA(WeaponObj)
{
}

HumanA::~HumanA()
{
}

void    HumanA::attack()
{
    std::cout << this->name << " attacks with their " << this->WeaponA.getType() << "\n";
}