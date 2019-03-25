#ifndef SPACESHIP_H
#define SPACESHIP_H
#include <SFML/Graphics.hpp>

#include "Position.h"
#include "Vector.h"
#include "MovingItem.h"

class SpaceShip : public MovingItem
{
    public:
        SpaceShip();
        virtual ~SpaceShip();
        void Update(float lastFrame);
        void UpdateMove();

    protected:
        static constexpr double SLOWDOWN{2};
        static constexpr double ROTATE_SPEED{200};
        static constexpr double SPEED_MODIFICATOR{700};

        bool hasForward{false};
        bool hasLeft{false};
        bool hasRight{false};

    private:
};

#endif // SPACESHIP_H
