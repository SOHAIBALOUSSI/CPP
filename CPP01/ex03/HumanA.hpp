#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
    private:
        std::string name;
        Weapon      &WeaponA;
    
    public:
        HumanA(std::string humanName, Weapon &WeaponObj);
    
        void    attack();
};

#endif