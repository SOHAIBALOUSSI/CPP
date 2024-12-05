#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    Animal* meta = new Animal();
    Animal* i = new Cat();
    Animal* j = new Dog();

    std::cout << std::endl;
    std::cout << i->getType() << ": ";
    i->makeSound();
    
    std::cout << j->getType() << ": ";
    j->makeSound();

    std::cout << meta->getType() << ": ";
    meta->makeSound();

    std::cout << "\nTest wrong Animal sound\n\n";

    WrongAnimal* badAnimal = new WrongAnimal();
    WrongAnimal* badCat = new WrongCat();
    WrongCat    Cat;

    std::cout << std::endl;

    std::cout << badAnimal->getType() << ": ";
    badAnimal->makeSound();

    std::cout << badCat->getType() << ": ";
    badCat->makeSound();


    std::cout << Cat.getType() << ": ";
    Cat.makeSound();

    std::cout << std::endl;
    
    delete meta;
    delete i;
    delete j;
    delete badAnimal;
    delete badCat;
    return 0;
}