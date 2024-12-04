#include "Cat.hpp"

Cat::Cat() : Animal()
{
    type = "Cat";
    std::cout << "Cat's Default constuctor called\n";
}

Cat::Cat(const Cat& other)
{
    std::cout << "Cat's copy constuctor called\n";
    type = other.type;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat's copy assignment operator called\n";

    if (this != &other) {
        type = other.type;
    }   
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat's Destructor called\n";
}

void Cat::makeSound() const
{
    std::cout << "Meow Meow\n"; 
}