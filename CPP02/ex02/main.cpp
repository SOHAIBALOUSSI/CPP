#include <iostream>
#include "Fixed.hpp"

#include <iostream>
int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}

// int main( void ) {
//     Fixed a;

//     std::cout <<"init value: "<< a << std::endl;
//     std::cout <<"++a: "<< ++a << std::endl;
//     std::cout <<"++a result: "<< a << std::endl;
//     std::cout << "a++ "<< a++ << std::endl;
//     std::cout << "a++ result: " << a << std::endl;

//     std::cout <<"value: "<< a << std::endl;
//     std::cout <<"--a: "<< --a << std::endl;
//     std::cout <<"--a result: "<< a << std::endl;
//     std::cout << "a--: "<< a-- << std::endl;
//     std::cout << "a-- result: " << a << std::endl;

//     Fixed  b( Fixed( 5.05f ) * Fixed( 2 ) );
//     std::cout << "init value of b : "<< b << std::endl;
//     std::cout << " / : "<< b / (Fixed(2)) << std::endl;
//     std::cout << " * : "<< b * (Fixed(2)) << std::endl;
//     std::cout << " - : "<< b - (Fixed(2.0f)) << std::endl;
//     std::cout << " + : "<< b + (Fixed(2)) << std::endl;

//     std::cout << " > : "<< (b > (Fixed(2))) << std::endl;
//     std::cout << " >= : "<< (b >= (Fixed(2))) << std::endl;
//     std::cout << " < : "<< (b < (Fixed(2))) << std::endl;
//     std::cout << " <= : "<< (b <= (Fixed(2))) << std::endl;
//     std::cout << " == : "<< (b == (Fixed(2))) << std::endl;
//     std::cout << " != : "<< (b != (Fixed(2))) << std::endl;
    
//     std::cout <<"max() :" << Fixed::max( a, b ) << std::endl;
//     std::cout << "min() :" << Fixed::min( a, b ) << std::endl;

//     return 0;
// }