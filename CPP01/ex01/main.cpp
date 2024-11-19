#include "Zombie.hpp"

int main()
{
    size_t numOfZombies = 10;
    Zombie *Zombies = zombieHorde(numOfZombies, "k3k3");
    for (size_t i = 0; i < numOfZombies; i++) {
        Zombies[i].announce();
    }
    delete[] Zombies;
}
