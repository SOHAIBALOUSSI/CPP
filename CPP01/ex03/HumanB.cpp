#include "HumanB.hpp"

HumanB::HumanB(std::string humanName) : WeaponB(0), name(humanName)
{
}

HumanB::~HumanB()
{
}

void    HumanB::setWeapon(Weapon &nWeapon)
{
    this->WeaponB = &nWeapon;
}

void    HumanB::attack()
{
    if (WeaponB) {
        std::cout << this->name << " attacks with their " << WeaponB->getType() << "\n";
    } else {
        std::cout << this->name << " has no weapon to attack with!\n";
    }
}

