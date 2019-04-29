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
        MovingItem(MovingItem const& autre) = delete;
        virtual ~MovingItem() { }
        virtual void Update(float lastFrame);
        virtual void Draw(sf::RenderWindow &wind);
        void Collision(MovingItem& other);
        Position GetPosition(){
            return pos;
        }
        float GetColiderRadius() const;
        virtual void CollisionReaction() = 0;

        static inline bool IsDestroy(MovingItem* item)
        {
            return item->isDestroy;
        };

        std::string name{};

    protected:
        sf::Sprite sprite{};
        sf::Texture texture{};

        Vector speed{0.f};
        Position pos{};
        float rotateSpeed{};
        bool isDestroy{false};
    private:
};

#endif // MOVINGITEM_H
