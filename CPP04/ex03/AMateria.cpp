#include "AMateria.hpp"

AMateria::AMateria() : _type("default")
{
}

AMateria::AMateria(std::string const & type) : _type(type)
{
}

AMateria::AMateria(const AMateria& copy)
{
    _type = copy._type;
}
AMateria& AMateria::operator=(const AMateria& assign)
{
    if (this != &assign) {
        _type = assign._type;
    }
    return *this;
}


AMateria::~AMateria()
{
}


std::string const & AMateria::getType() const {
    return _type;
}

void    AMateria::use(ICharacter& target)
{
    std::cout << "im just a base class\n";
}