#include "Asteroids.h"
#include "MovingItem.h"

Asteroids::Asteroids() : MovingItem("Assets/asteroide.png")
{
    speed = {10.f,30.f};
}
