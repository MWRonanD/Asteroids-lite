#ifndef POSITION_H
#define POSITION_H
#include "vector.h"
class Position
{
    public:
        Position();
        double GetX()
        {
            return x;
        }
        double GetY()
        {
            return y;
        }
        void operator+=(Vector const &v);

       void static InitScreenSize(int width, int height)
       {
            Position::screenWidth = width;
           Position::screenHeight = height;
       }

    protected:
        double x;
        double y;

        static int screenWidth;
        static int screenHeight;
    private:
};
#endif // POSITION_H
