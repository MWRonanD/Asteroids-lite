#ifndef SPACESHIP_H
#define SPACESHIP_H
#include <SFML/Graphics.hpp>

#include "Position.h"
#include "Vector.h"
#include "MovingItem.h"
#include "Explosion.h"
#include "GameSpace.h"

class SpaceShip : public MovingItem
{
    public:
        explicit SpaceShip(GameSpace& g_gameSpace);
        virtual ~SpaceShip();
        virtual void Update(float lastFrame) override;
        void UpdateMove();
        virtual void CollisionReaction();

    protected:
        static constexpr double SLOWDOWN{2};
        static constexpr double ROTATE_SPEED{200};
        static constexpr double SPEED_MODIFICATOR{700};

        GameSpace& gameSpace;
        Explosion explosion{};
        bool hasForward{false};
        bool hasLeft{false};
        bool hasRight{false};

    private:
};

#endif // SPACESHIP_H
