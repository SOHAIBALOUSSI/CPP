#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : ICharacter
{
    private:
        std::string     _name;
        AMateria*       _materias[4];
        size_t          _size;

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
};


#endif