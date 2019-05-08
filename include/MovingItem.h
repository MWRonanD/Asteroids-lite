#ifndef MOVINGITEM_H
#define MOVINGITEM_H

#include <memory>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Vector.h"
#include "Position.h"

enum class TypeItem{SHIP, ASTEROIDS, MISSILE, OTHER};

class MovingItem
{
    public:
        MovingItem(std::string);
        MovingItem(MovingItem const& autre) = delete;
        virtual void Update(float lastFrame);
        virtual void Draw(sf::RenderWindow &wind);
        void Collision(MovingItem& other);
        Position GetPosition(){
            return pos;
        }
        float GetColiderRadius() const;
        virtual void CollisionReaction(TypeItem typeItem) = 0;

        static inline bool IsDestroy(std::unique_ptr<MovingItem>& item)
        {
            return item->isDestroy;
        };

        std::string name{};
        TypeItem type{TypeItem::OTHER};

        Position pos{};
    protected:
        sf::Sprite sprite{};
        sf::Texture texture{};


        Vector speed{0.f};
        float rotateSpeed{};
        bool isDestroy{false};
    private:
};

#endif // MOVINGITEM_H
