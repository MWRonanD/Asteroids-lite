#ifndef VECTOR_H
#define VECTOR_H


struct Vector
{
    float x{0.f};
    float y{0.f};

    void operator+=(Vector const &v);
    void operator-=(Vector const &v);
    Vector operator *(float const &coef) const;

    //Rotation est un angle en �
    static Vector GetDirection(float speed, float rotation);
};

#endif // VECTOR_H
