#include "Asteroids.h"
#include "MovingItem.h"
#include "Position.h"
#include <random>
#include <iostream>
#include <cstdlib>
#include <ctime>


Asteroids::Asteroids() : MovingItem("Assets/asteroide.png")
{
    static std::random_device seed;
    static std::mt19937 rdm(seed());
    auto distribPosition = std::uniform_real_distribution<float>{-150,150};
    auto distribSpeed = std::uniform_real_distribution<float>{80,120};
    auto distribAngle = std::uniform_real_distribution<float>{0, 360};
    auto distribAngularSpeed = std::uniform_real_distribution<float>{10,30};
    pos = {distribPosition(rdm),distribAngle(rdm) };
    speed = Vector::GetDirection(distribSpeed(rdm),distribSpeed(rdm));
    rotateSpeed = distribAngularSpeed(rdm);
}

void Asteroids::CollisionReaction(){

}
