#include "Point.hpp"

float   fabs(float value)
{
    if (value < 0)
        value *= -1;
    return value;
}

// area of ABC = | x1(y2 – y3) + x2(y3 – y1) + x3(y1-y2) | / 2
float   calculateArea(Point A, Point  B, Point C)
{
    float x1 = A.getX() * (B.getY() - C.getY());
    float x2 = B.getX() * (C.getY() - A.getY());
    float x3 = C.getX() * (A.getY() - B.getY());

    return (fabs(x1 + x2 + x3) / 2.0f);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    float   abcArea = calculateArea(a,b,c);    
    float   pabArea = calculateArea(point,a,b);   
    float   pacArea = calculateArea(point,a,c);    
    float   pcbArea = calculateArea(point,c,b);

    if (!pabArea || !pacArea || !pcbArea)
        return false;
    return ((pabArea + pacArea + pcbArea) == abcArea);    
}