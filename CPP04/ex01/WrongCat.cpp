#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    type = "WrongCat";
    std::cout << "WrongCat's Default constuctor called\n";
}

WrongCat::WrongCat(const WrongCat& other)
{
    std::cout << "WrongCat's copy constuctor called\n";
    type = other.type;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    std::cout << "WrongCat's copy assignment operator called\n";

    if (this != &other) {
        type = other.type;
    }   
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat's Destructor called\n";
}

void WrongCat::makeSound()
{
    std::cout << "Meow Meow\n"; 
}

