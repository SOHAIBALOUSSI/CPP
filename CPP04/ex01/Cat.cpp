#include "Cat.hpp"

Cat::Cat() : Animal(), brain(NULL)
{
    std::cout << "Cat's Default constuctor called\n";
    type = "Cat";
    brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat's copy constuctor called\n";
    std::cout << this->type;
    brain = new Brain(*(other.brain));
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat's copy assignment operator called\n";

    if (this != &other) {
        Animal::operator=(other);
        if (brain)
            delete brain;
        brain = new Brain(*(other.brain));
    }   
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat's Destructor called\n";
    if (brain)
        delete brain;
}

void Cat::makeSound() const
{
    std::cout << "Meow Meow\n"; 
}

Brain* Cat::getBrain()
{
    return brain;
}