#ifndef ASTEROIDS_H
#define ASTEROIDS_H
#include <random>
#include <iostream>
#include "MovingItem.h"
#include "GameSpace.h"


class Asteroids : public MovingItem
{
    public:
        Asteroids(GameSpace& g_gameSpace, Asteroids* asteroid = nullptr);
        virtual void CollisionReaction(TypeItem typeItem) override;

    protected:
        GameSpace& gameSpace;
        static constexpr float MIN_SCALE{0.5f};
    private:
};

#endif // ASTEROIDS_H
