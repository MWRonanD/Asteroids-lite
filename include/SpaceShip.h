#ifndef SPACESHIP_H
#define SPACESHIP_H
#include <SFML/Graphics.hpp>

#include "Vector.h"

class SpaceShip
{
    public:
        SpaceShip();
        virtual ~SpaceShip();
        void UpdateMove();
        void Update(float lastFrame);
        void Draw(sf::RenderWindow &wind)const;
        void Rotation(float rotate);

    protected:
        static constexpr float MAX_SPEED{10.f};
        static constexpr float MIN_SPEED{0.f};
        static constexpr float ROTATE_SPEED{100.f};
        static constexpr float SPEED_MODIFICATOR{1.f};
        static constexpr float COEF_SLOWDOWN{2.f};
        sf::Sprite sprite{};
        sf::Texture texture{};
        //sf::Vector2f speed();
        Vector speed{0.f};
        bool hasForward{false};
        bool hasLeft{false};
        bool hasRight{false};

    private:
};

#endif // SPACESHIP_H
