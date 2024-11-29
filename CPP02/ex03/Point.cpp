#include "Point.hpp"

Point::Point() : x(0.0f), y(0.0f)
{
}

Point::Point(float xvalue, float yvalue) : x(xvalue), y(yvalue)
{
}

Point::~Point(){
    // std::cout << "destructor called\n";
}

Point::Point(const Point& other) : x(other.x), y(other.y)
{
}

Point&   Point::operator=(const Point& other)
{
    (void)other;
    return *this;
}

float Point::getX()
{
    return x.toFloat();
}

float Point::getY()
{
    return y.toFloat();
}