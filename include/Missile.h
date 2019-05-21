#ifndef MISSILE_H
#define MISSILE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Position.h"
#include <MovingItem.h>


class Missile : public MovingItem
{
    public:
        /** Default constructor */
        Missile(Position position, float rotation);
        virtual void CollisionReaction(TypeItem t_type) override;
        virtual void Update(float lastFrame) override;

    protected:
        sf::Sound sound{};
        sf::Clock timeSinceCreate{};
        static constexpr float SPEED{2000.f};
        static constexpr float LIFETIME{1.5f};
    private:
};

#endif // MISSILE_H
