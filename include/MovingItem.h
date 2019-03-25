#ifndef MOVINGITEM_H
#define MOVINGITEM_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Vector.h"
#include "Position.h"

class MovingItem
{
    public:
        MovingItem(std::string);
        void Update(float lastFrame);
        void Draw(sf::RenderWindow &wind)const;

    protected:
        sf::Sprite sprite{};
        sf::Texture texture{};

        Vector speed{0.f};
        Position pos{};

    private:
};

#endif // MOVINGITEM_H
