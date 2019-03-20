#include "Position.h"

Position::Position()
{
    x = Position::screenWidth /2;
    y = Position::screenHeight / 2;
}

void Position::operator+=(Vector const &v)
{
    x += v.x;
    y += v.y;
}
