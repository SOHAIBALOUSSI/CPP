#include "Zombie.hpp"

int main()
{
    Zombie *Zombie1 = newZombie("Zombie1");
    Zombie1->announce();
    randomChump("ka3ko3");
    delete Zombie1;
}