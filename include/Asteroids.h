#ifndef ASTEROIDS_H
#define ASTEROIDS_H
#include <random>
#include <iostream>
#include "MovingItem.h"
#include "GameSpace.h"
#include "GameManager.h"


class Asteroids : public MovingItem
{
    public:
        Asteroids(GameSpace& g_gameSpace, GameManager& gaMa, Asteroids* asteroid = nullptr);
        virtual void CollisionReaction(TypeItem typeItem) override;

    protected:
        GameSpace& gameSpace;
        GameManager& gm;
        static constexpr float MIN_SCALE{0.25f};
        static constexpr float SCALE_DIVISOR{1.75};
    private:
};

#endif // ASTEROIDS_H
