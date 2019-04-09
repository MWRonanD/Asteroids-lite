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

    Vector Vector::operator *(float const &coef) const
    {
        return {x * coef, y * coef};
    }
    Vector Vector::GetDirection(float speed, float rotation)
    {
        return {(float)(speed * cos(rotation/180 * 3.14159265)), float(speed * sin(rotation/180 * 3.14159265))};
    }
