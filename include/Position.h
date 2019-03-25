#ifndef POSITION_H
#define POSITION_H
#include "vector.h"
class Position
{
    public:
        Position();
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

    protected:
        float x;
        float y;

        static int screenWidth;
        static int screenHeight;
    private:
};
#endif // POSITION_H
