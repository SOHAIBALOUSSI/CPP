#include "HumanB.hpp"

HumanB::HumanB(std::string humanName) : name(humanName), WeaponB(NULL)
{
}

void    HumanB::setWeapon(Weapon &nWeapon)
{
    this->WeaponB = &nWeapon;
}

void    HumanB::attack()
{
    if (WeaponB)
        std::cout << this->name << " attacks with their " << WeaponB->getType() << "\n";
    else
        std::cout << this->name << " has no weapon to attack with!\n";
}
