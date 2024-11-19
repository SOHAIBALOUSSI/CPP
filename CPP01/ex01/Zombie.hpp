#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <stdlib.h>

class Zombie
{
    private:
        std::string name;
    public:
        Zombie();
        Zombie(std::string name);
        ~Zombie();

        void announce( void );
        void setZombieName(std::string name);

};

Zombie* zombieHorde( int N, std::string name );

#endif
