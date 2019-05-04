#ifndef ASTEROIDS_H
#define ASTEROIDS_H
#include <random>
#include <iostream>
#include "MovingItem.h"
#include "GameSpace.h"


class Asteroids : public MovingItem
{
    public:
        Asteroids(GameSpace& g_gameSpace);
        virtual void CollisionReaction(TypeItem typeItem) override;

    protected:
        GameSpace& gameSpace;
    private:
};

#endif // ASTEROIDS_H
