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
        virtual ~MovingItem() { }
        virtual void Update(float lastFrame);
        virtual void Draw(sf::RenderWindow &wind);
        void Collision(MovingItem& other);
        Position GetPosition(){
            return pos;
        }
        float GetColiderRadius() const;
        void Hit();
        virtual void CollisionReaction() = 0;

    protected:
        sf::Sprite sprite{};
        sf::Texture texture{};

        Vector speed{0.f};
        Position pos{};
        float rotateSpeed{};

    private:
};

#endif // MOVINGITEM_H
