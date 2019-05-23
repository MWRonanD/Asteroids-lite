#include "Asteroids.h"
#include "MovingItem.h"
#include "Position.h"
#include <random>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Explosion.h"

Asteroids::Asteroids(GameSpace &g_gameSpace, GameManager &gaMa, Asteroids *asteroid) : MovingItem("Assets/asteroide.png"), gameSpace{g_gameSpace}, gm{gaMa}
{
    type = TypeItem::ASTEROIDS;
    speed = Vector::GetDirection(gm.GetRand(80.f, 120.f), gm.GetRand(0.f, 360.f));
    rotateSpeed = gm.GetRand(10.f, 30.f);
    if (asteroid)
    {
        pos = asteroid->pos;
        sprite.setScale(asteroid->sprite.getScale().x / SCALE_DIVISOR, asteroid->sprite.getScale().y / SCALE_DIVISOR);
    }
    else
    {
        pos = {gm.GetRand(-150.f, 150.f), gm.GetRand(0.f, 360.f)};
    }
}

void Asteroids::CollisionReaction(TypeItem typeItem)
{
    if (typeItem == TypeItem::MISSILE)
    {
        isDestroy = true;
        gm.AddScore(sprite.getScale().x * 100);
        if (sprite.getScale().x > MIN_SCALE)
        {
            gameSpace.AddElement(std::make_unique<Asteroids>(gameSpace, gm, this));
            gameSpace.AddElement(std::make_unique<Asteroids>(gameSpace, gm, this));
        }
        gameSpace.AddElement(std::make_unique<Explosion>(pos));
    }
}
