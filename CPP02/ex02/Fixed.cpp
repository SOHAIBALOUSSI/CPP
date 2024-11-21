
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
    this->_value = rawBits;
}

float Fixed::toFloat( void ) const
{
    return ((float)_value / (1 << _fracBits));
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

bool   Fixed::operator > (const Fixed &b)
{
    return this->_value > b._value;
}

bool   Fixed::operator < (const Fixed &b)
{
    return this->_value < b._value;
}

bool   Fixed::operator >= (const Fixed &b)
{
    return this->_value >= b._value;
}

bool   Fixed::operator <= (const Fixed &b)
{
    return this->_value <= b._value;
}

bool   Fixed::operator == (const Fixed &b)
{
    return this->_value == b._value;
}
bool   Fixed::operator != (const Fixed &b)
{
    return this->_value != b._value;
}

// Arithmitic operators

Fixed     Fixed::operator + (const Fixed &b)
{
    return Fixed(this->_value + b._value);
}

Fixed     Fixed::operator - (const Fixed &b)
{
    Fixed fpoint;
    fpoint._value = this->_value - b._value;
    return fpoint;
}

Fixed     Fixed::operator * (const Fixed &b)
{
    Fixed fpoint;
    fpoint._value = (this->_value * b._value ) >> _fracBits;
    return fpoint;
}

Fixed     Fixed::operator / (const Fixed &b)
{
    Fixed fpoint;
    fpoint._value = (this->_value >> _fracBits) / b._value;
    return fpoint;
}

Fixed&     Fixed::operator++ ()
{
    this->_value += 1;
    return *this;
}

Fixed     Fixed::operator++ (int)
{
    Fixed copy(*this);
    this->_value += 1;
    return copy;
}

Fixed&  Fixed::operator-- ()
{
    _value -= 1;
    return *this;
}

Fixed  Fixed::operator-- (int)
{
    Fixed copy(*this);
    _value -= 1;
    return copy;
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