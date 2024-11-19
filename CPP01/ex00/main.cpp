#include "Zombie.hpp"

int main()
{
    Zombie *Zombie1 = newZombie("Zombie1");
    Zombie *Zombie2 = newZombie("Zombie2");
    Zombie *Zombie3 = newZombie("Zombie3");
   
    Zombie1->announce();
    Zombie2->announce();
    Zombie3->announce();
   
    randomChump("ka3ko3");
    randomChump("Batman");

    delete Zombie1;
    delete Zombie2;
    delete Zombie3;
}