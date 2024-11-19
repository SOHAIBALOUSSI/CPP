
#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *Horde = new(std::nothrow) Zombie[N];
    if (!Horde) {
        std::cout << "Memory allocation failed\n";
        exit(1);
    }
    for (int i = 0; i < N; i++) {
        Horde[i].setZombieName(name);
    }
    return Horde;
}
