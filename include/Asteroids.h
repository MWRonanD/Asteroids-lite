#ifndef ASTEROIDS_H
#define ASTEROIDS_H
#include <random>
#include <iostream>
#include "MovingItem.h"


class Asteroids : public MovingItem
{
    public:
        Asteroids();
        virtual void CollisionReaction();

    protected:

    private:
};

#endif // ASTEROIDS_H
