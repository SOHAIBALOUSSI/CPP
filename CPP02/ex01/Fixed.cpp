#include "Fixed.hpp"

const int Fixed::_fracBits = 8;

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called\n";
}
Fixed::Fixed(const int Value)
{
    std::cout << "Int constructor called\n";
   _value = Value << _fracBits;
}

Fixed::Fixed(const float fValue)
{
    std::cout << "Float constructor called\n";
    _value = roundf(fValue * (1 << _fracBits)); // value * 2 ^ 8 
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called\n";
    _value = other._value;
}
Fixed& Fixed::operator = (const Fixed &other)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &other)
        this->_value = other._value;
    return *this;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called\n";
    return _value;
}

void Fixed::setRawBits( int const rawBits )
{
    std::cout << "setRawBits member function called\n";
    _value = rawBits;
}

float Fixed::toFloat( void ) const
{
    return ((float)_value / (float)(1 << _fracBits));
}

int Fixed::toInt( void ) const
{
    return _value >> _fracBits;
}

std::ostream&    operator<<(std::ostream& out, const Fixed& fp)
{
    out << fp.toFloat();
    return out;
}
