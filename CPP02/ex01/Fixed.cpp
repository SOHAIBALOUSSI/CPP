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
    _value = roundf(fValue * (1 << _fracBits));
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
    if (this == &other)
        return *this;
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
    this->_value = rawBits;
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

/*
Default constructor called
Int constructor called
Float constructor called
Copy constructor called
Copy assignment operator called
Float constructor called
Copy assignment operator called
Destructor called
a is 1234.43
b is 10
c is 42.4219
d is 10
a is 1234 as integer
b is 10 as integer
c is 42 as integer
d is 10 as integer
Destructor called
Destructor called
Destructor called
Destructor called
$>
*/