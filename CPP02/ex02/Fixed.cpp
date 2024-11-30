
#include "Fixed.hpp"

const int Fixed::_fracBits = 8;

Fixed::Fixed() : _value(0)
{
    // std::cout << "Default constructor called\n";
}
Fixed::Fixed(const int Value)
{
    // std::cout << "Int constructor called\n";
   _value = Value << _fracBits; // v * 2 ^ _fracBits
}

Fixed::Fixed(const float fValue)
{
    // std::cout << "Float constructor called\n";
    _value = (int)roundf(fValue * (1 << _fracBits)); 
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &other)
{
    // std::cout << "Copy constructor called\n";
    _value = other._value;
}

Fixed& Fixed::operator = (const Fixed &other)
{
    // std::cout << "Copy assignment operator called\n";
    if (this != &other)
        this->_value = other._value;
    return *this;
}

int Fixed::getRawBits( void ) const
{
    // std::cout << "getRawBits member function called\n";
    return _value;
}

void Fixed::setRawBits( int const rawBits )
{
    // std::cout << "setRawBits member function called\n";
    _value = rawBits;
}

float Fixed::toFloat( void ) const
{
    return ((float)_value / (1 << _fracBits)); // value / 2 ^ 8
}

int Fixed::toInt( void ) const
{
    return _value >> _fracBits; // shift it back to its original form
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
    Fixed plus;
    plus._value = this->_value + b._value;
    return plus;
}

Fixed     Fixed::operator - (const Fixed &b)
{
    Fixed minus;
    minus._value = this->_value - b._value;
    return minus;
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
    fpoint._value = (this->_value << _fracBits) / b._value;
    return fpoint;
}

Fixed&     Fixed::operator++ () // pre-increment 
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

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a._value < b._value)
        return a;
    return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a._value < b._value)
        return a;
    return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a._value > b._value)
        return a;
    return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a._value > b._value)
        return a;
    return b;
}
