#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{

    Animal *arr[10];

    for (int i = 0; i < 10; i++) {
        if (i < 5)
        {
            arr[i] = new Dog();
            std::cout << std::endl;
        }
        else
        {
            arr[i] = new Cat();
            std::cout << std::endl;
        }
    }

    for (size_t i = 0; i < 10; i++) {
        delete arr[i];
        std::cout << std::endl;
    }
}

// DEEP COPY CHECK

// int main()
// {
//     Dog dog;
    
//     dog.getBrain()->setBrainIdeas("bone", 5);
//     dog.getBrain()->printIdeas(5);

//     std::cout << std::endl;

//     Dog  box(dog);

//     box.getBrain()->setBrainIdeas("changed", 5);
//     std::cout << std::endl;
//     box.getBrain()->printIdeas(5);
//     std::cout << std::endl;

//     std::cout << "u can see that dog's brain remain unchanged\n";
//     dog.getBrain()->printIdeas(5);

//     Cat cat;
//     cat.getBrain()->setBrainIdeas("fish", 50);
//     cat.getBrain()->printIdeas(10);
// }