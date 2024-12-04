#include "Character.hpp"


Character::Character() : _name("DEFAULT"), _size(0)
{
    for (size_t i = 0; i < 4; i++){
        _materias[i] = NULL;
    }
}

Character::Character(std::string name) : _name(name) , _size(0)
{
    for (size_t i = 0; i < 4; i++){
        _materias[i] = NULL;
    }
}

Character::~Character()
{

}

Character::Character(const Character& copy)
{
    _name = copy._name;
    _size = copy._size;
    for (size_t i = 0; i < 4; i++) {
        if (copy._materias[i])
            _materias[i] = copy._materias[i]->clone();
        else
            _materias[i] = NULL;
    }

}

Character& Character::operator=(const Character& assign)
{
    if (this != &assign)
    {
        for (size_t i = 0; i < 4; i++)
        {
            if (_materias[i])
                delete _materias[i];
        }
        for (size_t i = 0; i < 4; i++) {
            if (assign._materias[i])
                _materias[i] = assign._materias[i]->clone();
            else
                _materias[i] = NULL;
        }
    }
    return *this;
}

std::string const & Character::getName() const
{
    return _name;
}

void Character::equip(AMateria* m)
{
    if (_size == 4)
        return;
    _materias[_size++] = m;
}

void    Character::unequip(int idx)
{
    if (idx > 3 || idx < 0)
        return ;
    if (_materias[idx] == NULL)
        return ;
        // 
    _materias[idx] = NULL;
    _size--;
}

void    Character::use(int idx, ICharacter& target)
{
    _materias[idx]->use(target);
}