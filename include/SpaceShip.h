#ifndef SPACESHIP_H
#define SPACESHIP_H
#include <SFML/Graphics.hpp>

#include "Position.h"
#include "Vector.h"
#include "MovingItem.h"
#include "Explosion.h"

class SpaceShip : public MovingItem
{
    public:
        SpaceShip();
        virtual ~SpaceShip();
        virtual void Update(float lastFrame) override;
        void UpdateMove();
        virtual void CollisionReaction();
        virtual void Draw(sf::RenderWindow &wind) override;


    protected:
        static constexpr double SLOWDOWN{2};
        static constexpr double ROTATE_SPEED{200};
        static constexpr double SPEED_MODIFICATOR{700};

        Explosion explosion{};

        bool hasForward{false};
        bool hasLeft{false};
        bool hasRight{false};
        bool isDestroy{false};

    private:
};

#endif // SPACESHIP_H
