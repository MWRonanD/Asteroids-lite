#ifndef VECTOR_H
#define VECTOR_H


struct Vector
{
    double x{0.f};
    double y{0.f};

    void operator+=(Vector const &v);
    void operator-=(Vector const &v);
    Vector operator *(double const &coef) const;

    //Rotation est un angle en °
    static Vector GetDirection(double speed, double rotation);
};

#endif // VECTOR_H
