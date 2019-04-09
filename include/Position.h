#ifndef POSITION_H
#define POSITION_H
#include "vector.h"
class Position
{
    public:
        Position();
        Position(float _x, float _y);
        float GetDistance(Position const& other) const;
        float GetX()
        {
            return x;
        }
        float GetY()
        {
            return y;
        }
        void operator+=(Vector const &v);

       void static InitScreenSize(int width, int height);
        static int screenWidth;
        static int screenHeight;

    protected:
        float x;
        float y;

    private:
};
#endif // POSITION_H
