#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    // const Animal* meta = new Animal();
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();

    // std::cout << i->getType() << " " << std::endl;
    // i->makeSound(); //will output the cat sound!
    // std::cout << j->getType() << " " << std::endl;
    // j->makeSound();
    // meta->makeSound();

    //

    WrongAnimal* badAnimal = new WrongAnimal();
    WrongAnimal* badCat = new WrongCat();

    std::cout << badAnimal->getType() << std::endl;
    badAnimal->makeSound();

    std::cout << badCat->getType() << std::endl;
    badCat->makeSound(); // wrong sound 

    return 0;
}