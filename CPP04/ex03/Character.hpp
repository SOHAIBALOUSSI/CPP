#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

typedef struct droppedMaterias
{
    AMateria                *dropped;
    struct droppedMaterias  *next;
}               dMaterias;

class Character : public ICharacter
{
    private:
        std::string         _name;
        AMateria*           _materias[4];
        size_t              _size;
        static dMaterias    *head;

        void addDroppedMateria(AMateria* materia);
    public:
        Character();
        Character(std::string name);
        Character(const Character& copy);
        Character& operator=(const Character& assign);
        ~Character();

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
        static void cleanDroppedMaterias();
};


#endif