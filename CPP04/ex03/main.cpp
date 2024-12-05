
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#

int main()
{
    ICharacter* me = new Character("me");
    me->equip(new Ice);
    me->equip(new Cure);
    ICharacter* target = new Character("bob");
    me->use(0, *target);
    me->use(1, *target);
    me->use(10, *target);

    me->unequip(0);
    me->unequip(1);

/// test Materia source

    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    AMateria *ptr;
    ptr = src->createMateria("ice");
    me->equip(ptr);

    me->use(2, *target);

    Character::cleanDroppedMaterias();

    delete target;
    delete me;
  
    return 0;
}


// int main()
// {
//     IMateriaSource* src = new MateriaSource();
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());
//     ICharacter* me = new Character("me");
//     AMateria* tmp;
//     tmp = src->createMateria("ice");
//     me->equip(tmp);
//     tmp = src->createMateria("cure");
//     me->equip(tmp);
//     ICharacter* bob = new Character("bob");
//     me->use(0, *bob);
//     me->use(1, *bob);
//     delete bob;
//     delete me;
//     delete src;

//     return 0;
// }