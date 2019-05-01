#ifndef MISSILE_H
#define MISSILE_H

#include <SFML/Graphics.hpp>
#include "Position.h"
#include <MovingItem.h>


class Missile : public MovingItem
{
    public:
        /** Default constructor */
        Missile(Position position, float rotation);
        virtual void CollisionReaction(TypeItem t_type) override;

    protected:
        static constexpr float SPEED{2000.f};
    private:
};

#endif // MISSILE_H
