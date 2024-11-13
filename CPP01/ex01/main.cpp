#include "Zombie.hpp"


int main()
{
    Zombie *arr = zombieHorde(10, "BAMTAN");
    for (size_t i = 0; i < 10; i++)
    {
        arr[i].announce();
    }
    delete[] arr;
}