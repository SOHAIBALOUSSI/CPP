#include "Cure.hpp"

Cure::Cure()
{
    _type = "cure";
}

Cure::Cure(const Cure& copy)
{
    _type = copy._type;
}

Cure::~Cure()
{
}

AMateria* Cure::clone() const
{
    return new Cure();
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *\n";
}