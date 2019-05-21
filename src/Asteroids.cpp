#include "Asteroids.h"
#include "MovingItem.h"
#include "Position.h"
#include <random>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Explosion.h"

Asteroids::Asteroids(GameSpace& g_gameSpace, GameManager& gaMa, Asteroids* asteroid) : MovingItem("Assets/asteroide.png"), gameSpace{g_gameSpace}, gm{gaMa}
{
    type = TypeItem::ASTEROIDS;
    static std::random_device seed;
    static std::mt19937 rdm(seed());
    auto distribPosition = std::uniform_real_distribution<float>{-150,150};
    auto distribSpeed = std::uniform_real_distribution<float>{80,120};
    auto distribAngle = std::uniform_real_distribution<float>{0, 360};
    auto distribAngularSpeed = std::uniform_real_distribution<float>{10,30};
    speed = Vector::GetDirection(distribSpeed(rdm),distribSpeed(rdm));
    rotateSpeed = distribAngularSpeed(rdm);
    if (asteroid){
        pos = asteroid->pos;
        sprite.setScale(asteroid->sprite.getScale().x / SCALE_DIVISOR, asteroid->sprite.getScale().y / SCALE_DIVISOR );
    }else{
        pos = {distribPosition(rdm),distribAngle(rdm)};
    }
}

void Asteroids::CollisionReaction(TypeItem typeItem){
    if(typeItem == TypeItem::MISSILE){
        isDestroy = true;
        gm.AddScore(sprite.getScale().x*100);
        if(sprite.getScale().x > MIN_SCALE){
            gameSpace.AddElement(std::make_unique<Asteroids>(gameSpace,gm,this));
            gameSpace.AddElement(std::make_unique<Asteroids>(gameSpace,gm,this));
        }
        gameSpace.AddElement(std::make_unique<Explosion>(pos));
    }
}
