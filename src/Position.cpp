#include "Position.h"
#include <iostream>
int Position::screenWidth = 0;
int Position::screenHeight = 0;

void Position::InitScreenSize(int width, int height)
{
   std::cout << width << std::endl;
   std::cout << height << std::endl;
   Position::screenWidth = width;
   Position::screenHeight = height;
}

Position::Position()
{
    x = Position::screenWidth /2;
    y = Position::screenHeight / 2;
}

void Position::operator+=(Vector const &v)
{
    if(y > Position::screenWidth)
    {
        y = 0;
    }
    else if (y < 0)
    {
        y = Position::screenWidth;
    }
    else
    {
        y += v.y;
    }

    if(x > Position::screenHeight)
    {
        x = 0;
    }
    else if (x < 0)
    {
        x = Position::screenHeight;
    }
    else
    {
        x += v.x;
    }
}
