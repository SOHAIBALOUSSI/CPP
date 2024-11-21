#ifndef POINT_HPP
    #define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point
{
    private:
        const Fixed x;        
        const Fixed y;

    public:
        Point();
        Point(const Point& other);
        Point   operator=(const Point& other);
        ~Point();
};



#endif