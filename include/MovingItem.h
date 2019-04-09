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
        virtual void Update(float lastFrame);
        void Draw(sf::RenderWindow &wind)const;
        void Collision(MovingItem& other);
        Position GetPosition(){
            return pos;
        }
        float GetColiderRadius() const;
        void Hit();

    protected:
        sf::Sprite sprite{};
        sf::Texture texture{};

        Vector speed{0.f};
        Position pos{};
        float rotateSpeed{};

    private:
};

#endif // MOVINGITEM_H
