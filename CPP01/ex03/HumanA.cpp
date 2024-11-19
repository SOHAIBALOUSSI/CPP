#include "HumanA.hpp"

HumanA::HumanA(std::string humanName, Weapon &WeaponObj)
    : name(humanName), WeaponA(WeaponObj)
{
}

void    HumanA::attack()
{
    std::cout << this->name << " attacks with their " << this->WeaponA.getType() << "\n";
}