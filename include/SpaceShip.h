#ifndef SPACESHIP_H
#define SPACESHIP_H
#include <SFML/Graphics.hpp>

#include "Position.h"
#include "Vector.h"

class SpaceShip
{
    public:
        SpaceShip();
        virtual ~SpaceShip();
        void UpdateMove();
        void Update(double lastFrame);
        void Draw(sf::RenderWindow &wind)const;

    protected:
        static constexpr double SLOWDOWN{2};
        static constexpr double ROTATE_SPEED{200};
        static constexpr double SPEED_MODIFICATOR{700};

        sf::Sprite sprite{};
        sf::Texture texture{};
        //sf::Vector2f speed();
        Vector speed{0.f};
        Position pos{};

        bool hasForward{false};
        bool hasLeft{false};
        bool hasRight{false};

    private:
};

#endif // SPACESHIP_H
