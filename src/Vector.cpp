#include <iostream>
#include <cmath>
#include "Vector.h"


    void Vector::operator +=(Vector const &v)
    {
        x += v.x;
        y += v.y;
    }
    void Vector::operator -=(Vector const &v)
    {
        x -= v.x;
        y -= v.y;
    }

    Vector Vector::operator *(double const &coef) const
    {
        return {x * coef, y * coef};
    }
    Vector Vector::GetDirection(double speed, double rotation)
    {

        return {speed * cos(rotation/180 * 3.1415926535897), speed * sin(rotation/180 * 3.1415926535897)};
    }
