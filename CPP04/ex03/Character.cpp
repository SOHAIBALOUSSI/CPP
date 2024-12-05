#include "Character.hpp"

dMaterias   *Character::head = NULL;

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
    for (size_t i = 0; i < 4; i++) {
        if (_materias[i])
            delete _materias[i];
    }
}

Character::Character(const Character& copy) : _name(copy._name), _size(copy._size)
{
    for (size_t i = 0; i < 4; i++)
    {
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
        for (size_t i = 0; i < 4; i++)
        {
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

void    Character::addDroppedMateria(AMateria* materia)
{
    dMaterias   *node = new dMaterias;
    node->dropped = materia;
    node->next = head;
    head = node;
}

void Character::equip(AMateria* m)
{
    if (!m)
        return ;
    for (size_t i = 0; i < 4; i++) {
        if (_materias[i] == NULL)
        {
            _materias[i] = m;
            return ;
        }
    }
    delete m;
}

void    Character::unequip(int idx)
{
    if (idx > 3 || idx < 0)
        return ;
    if (_materias[idx] == NULL)
        return ;
    addDroppedMateria(_materias[idx]);
    _materias[idx] = NULL;
}

void    Character::use(int idx, ICharacter& target)
{
    if (idx > 3 || idx < 0)
        return ;
    if (_materias[idx] == NULL)
        return ;
    _materias[idx]->use(target);
}



void Character::cleanDroppedMaterias()
{
    while (head)
    {
        dMaterias* temp = head;
        if (!temp)
            return;
        head = head->next;
        if (temp->dropped != NULL)
            delete temp->dropped;
        delete temp;
    }
}