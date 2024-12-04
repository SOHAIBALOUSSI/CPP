#include "MateriaSource.hpp"

MateriaSource::MateriaSource() 
{
   size = 0;
}

MateriaSource::~MateriaSource()
{
    for (size_t i = 0; i < size; i++)
    {
        if (_MSource[i])
            delete _MSource[i];
    }
}


void MateriaSource::learnMateria(AMateria* m)
{
    if (size == 4)
        return ;
    _MSource[size++] = m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (size_t i = 0; i < size; i++)
    {
        if (_MSource[i]->getType() == type)
            return _MSource[i]->clone();
    }
    return 0;
}