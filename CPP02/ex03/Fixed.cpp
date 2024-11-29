#include "Fixed.hpp"

const int Fixed::_fracBits = 8;

Fixed::Fixed() : _value(0)
{
}
Fixed::Fixed(const int Value)
{
   _value = Value << _fracBits;
}

Fixed::Fixed(const float fValue)
{
    _value = (int)roundf(fValue * (1 << _fracBits));
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &other)
{
    _value = other._value;
}

Fixed& Fixed::operator = (const Fixed &other)
{
    if (this == &other)
        return *this;
    this->_value = other._value;
    return *this;
}

int Fixed::getRawBits( void ) const
{
    return _value;
}

void Fixed::setRawBits( int const rawBits )
{
    _value = rawBits;
}

float Fixed::toFloat( void ) const
{
    return ((float)_value / (1 << _fracBits)); // value / 2 ^ 8
}
