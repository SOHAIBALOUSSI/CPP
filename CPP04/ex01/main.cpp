#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
    Animal *arr[10];

    for (int i = 0; i < 10; i++) {
        if (i < 5) {
            arr[i] = new Dog();
            std::cout << std::endl;
        }
        else {
            arr[i] = new Cat();
            std::cout << std::endl;
        }
    }

    for (size_t i = 0; i < 10; i++)
    {
        std::cout << arr[i]->getType() << ": ";
        arr[i]->makeSound();
    }
    
    std::cout << std::endl;

    for (size_t i = 0; i < 10; i++) {
        delete arr[i];
        std::cout << std::endl;
    }
}

// DEEP COPY CHECK

// int main()
// {
//     Dog dog;
    
//     std::cout << std::endl;
//     dog.getBrain()->setBrainIdeas("BONE", 5);
//     std::cout << "Dog's ideas:\n";
//     dog.getBrain()->printIdeas(5);

//     std::cout << std::endl;

//     Dog  CopyDog = dog;

//     CopyDog.getBrain()->setBrainIdeas("COPY", 5);
//     std::cout << "\nCopyDog's ideas:\n";
//     CopyDog.getBrain()->printIdeas(5);

//     std::cout << "\nYou can see that Dog's brain remain unchanged:\n";
//     dog.getBrain()->printIdeas(5);
//     std::cout << std::endl;

//     Cat cat;
//     std::cout << std::endl;
//     Cat CopyCat;
//     std::cout << std::endl;

//     cat.getBrain()->setBrainIdeas("fish", 5);
//     std::cout << "cat ideas:"<< std::endl;
//     cat.getBrain()->printIdeas(5);
//     std::cout << std::endl;
//     CopyCat = cat;
//     std::cout << "\nCopyCat ideas:"<< std::endl;
//     CopyCat.getBrain()->printIdeas(5);
//     std::cout << std::endl;

// }