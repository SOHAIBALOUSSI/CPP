#include "Ice.hpp"

Ice::Ice()
{
    _type = "ice";
}

Ice::Ice(const Ice& copy)
{
    
}

Ice& Ice::operator=(const Ice& assign)
{
    
}

Ice::~Ice()
{
    
}

AMateria* Ice::clone() const
{
    return new Ice();
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " <<  target.getName() << "*";
}
