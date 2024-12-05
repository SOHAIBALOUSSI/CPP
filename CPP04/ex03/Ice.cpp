#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice& copy) : AMateria(copy) {}

Ice::~Ice() {}

Ice& Ice::operator=(const Ice& assign)
{
    if (this != &assign) {
        _type = assign._type;
    }
    return *this;
}


AMateria* Ice::clone() const
{
    return new Ice();
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " <<  target.getName() << " *\n";
}
