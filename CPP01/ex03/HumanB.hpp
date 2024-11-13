#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
private:
    std::string name;
    Weapon      *WeaponB;

public:
    HumanB(std::string humanName);
    ~HumanB();

    void    setWeapon(Weapon& nWeapon);
    void    attack();
};




#endif