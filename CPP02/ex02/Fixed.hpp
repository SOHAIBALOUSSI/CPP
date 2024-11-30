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
        Fixed(const Fixed &other);
        Fixed& operator = (const Fixed &other);
        ~Fixed();


        bool   operator > (const Fixed &b);
        bool   operator < (const Fixed &b);
        bool   operator >= (const Fixed &b);
        bool   operator <= (const Fixed &b);
        bool   operator == (const Fixed &b);
        bool   operator != (const Fixed &b);

        Fixed     operator + (const Fixed &b);   
        Fixed     operator - (const Fixed &b);   
        Fixed     operator * (const Fixed &b);   
        Fixed     operator / (const Fixed &b);

        Fixed&  operator++ ();      // pre-increment    ++b;
        Fixed   operator++ (int);   // post increment   b++;
        Fixed&  operator-- ();      // pre-decrement    --b;
        Fixed   operator-- (int);   // post-increment   b--;
        
        float toFloat( void ) const;
        int toInt( void ) const;
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        static Fixed& min(Fixed& a, Fixed&b);
        const static Fixed& min(const Fixed& a, const Fixed&b);
        static Fixed& max(Fixed& a, Fixed&b);
        const static Fixed& max(const Fixed& a, const Fixed&b);
};

std::ostream&    operator << (std::ostream& out, const Fixed& fp);


#endif /* FIXED_HPP */