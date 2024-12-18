#include "Fixed.hpp"

const int Fixed::_fracBits = 8;

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called\n";
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

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called\n";
    this->_value = raw;
}
