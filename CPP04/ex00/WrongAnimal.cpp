#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "WrongAnimal's Default constuctor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    std::cout << "WrongAnimal's copy constuctor called\n";
    type = other.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    std::cout << "WrongAnimal's copy assignment operator called\n";
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal's destuctor called\n";
}

void WrongAnimal::makeSound()
{
    std::cout << "$%!&$%!^%$^@!^%#@!\n";
}

std::string WrongAnimal::getType(){
    return type;
}