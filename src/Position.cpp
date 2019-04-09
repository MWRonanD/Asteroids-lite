#include "Position.h"
#include <iostream>
#include <cmath>
#include <algorithm>
int Position::screenWidth = 0;
int Position::screenHeight = 0;

void Position::InitScreenSize(int width, int height)
{
   Position::screenWidth = width;
   Position::screenHeight = height;
}

Position::Position()
{
    x = Position::screenWidth /2;
    y = Position::screenHeight / 2;
}
Position::Position(float _x, float _y)
{
    x = _x;
    y = _y;
}

void Position::operator+=(Vector const &v)
{
    if(x > Position::screenWidth)
    {
        x = 0;
    }
    else if (x < 0)
    {
        x = Position::screenWidth;
    }
    else
    {
        x += v.x;
    }

    if(y > Position::screenHeight)
    {
        y = 0;
    }
    else if (y < 0)
    {
        y = Position::screenHeight;
    }
    else
    {
        y += v.y;
    }
}
float Position::GetDistance(Position const& other) const
{
    auto tmpX = (float)(std::min({abs(x - other.x), abs(x-other.x-screenWidth), abs(x-other.x+screenWidth) }));
    auto tmpY = (float)(std::min({abs(y - other.y), abs(y-other.y-screenHeight), abs(y-other.y+screenHeight) }));
    auto delta = Vector{tmpX , tmpY};
    std::cout << sqrt(delta.x*delta.x+delta.y*delta.y) << std::endl;
    return sqrt(delta.x*delta.x+delta.y*delta.y);
}

