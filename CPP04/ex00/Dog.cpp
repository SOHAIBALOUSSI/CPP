#include "Dog.hpp"

Dog::Dog() : Animal()
{
    type = "Dog";
    std::cout << "Dog's Default constuctor called\n";
}

Dog::Dog(const Dog& other)
{
    std::cout << "Dog's copy constuctor called\n";
    type = other.type;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog's copy assignment operator called\n";

    if (this != &other) {
        type = other.type;
    }   
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog's Destructor called\n";
}

void Dog::makeSound() const
{
    std::cout << "3aw 3aw\n";
}