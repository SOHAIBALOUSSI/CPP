#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int              _value;
        static const int _fracBits;

    public:
        Fixed();
        Fixed(const int Value);
        Fixed(const float fValue);
        Fixed(const Fixed &other); // copy constractor
        Fixed& operator = (const Fixed &other); // copy assignment operator
        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
};

#endif /* FIXED_HPP */