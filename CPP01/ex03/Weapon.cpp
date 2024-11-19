#include "Weapon.hpp"

Weapon::Weapon(std::string WeaponType)
{
    this->setType(WeaponType);
}

const std::string& Weapon::getType(void)
{
    return this->type;
}

void  Weapon::setType(std::string newType)
{
    this->type = newType;
}