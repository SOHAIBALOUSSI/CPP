#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal's Default constuctor called\n";
}

Animal::Animal(const Animal& other)
{
    std::cout << "Animal's copy constuctor called\n";
    type = other.type;
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Animal's copy assignment operator called\n";
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal's destuctor called\n";
}

void Animal::makeSound() const
{
    std::cout << "$%!&$%!^%$!\n";
}

std::string Animal::getType() const{
    return type;
}