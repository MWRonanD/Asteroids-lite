#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <MovingItem.h>
#include "Position.h"

class Explosion : public MovingItem
{
    public:
        Explosion();
        virtual ~Explosion();
        void Start(const Position p_position);
        virtual void Update(float lastFrame) override;
        virtual void Draw(sf::RenderWindow& wind) override;
        //DELETE ON REFACTOR
        virtual void CollisionReaction() override;

    protected:
        bool hasStart{false};
        float startSince{0};
        static constexpr float ANIMATION_DURATION{0.5f};
};
#endif // EXPLOSION_H
