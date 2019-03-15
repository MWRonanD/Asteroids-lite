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
