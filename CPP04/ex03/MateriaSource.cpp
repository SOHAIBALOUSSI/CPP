#include "MateriaSource.hpp"

MateriaSource::MateriaSource() 
{
    for (size_t i = 0; i < 4; i++) {
        _MSource[i] = NULL;
    }
}

MateriaSource::~MateriaSource()
{
    for (size_t i = 0; i < 4; i++) {
        if (_MSource[i])
            delete _MSource[i];
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    for (size_t i = 0; i < 4; i++) {
        if (NULL == _MSource[i]) {
            _MSource[i] =  m;
            return ;
        }  
    }
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (size_t i = 0; i < 4; i++) {
        if (_MSource[i]->getType() == type)
            return _MSource[i]->clone();
    }
    return 0;
}