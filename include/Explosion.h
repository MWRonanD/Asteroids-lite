#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <MovingItem.h>
#include "Position.h"

class Explosion : public MovingItem
{
    public:
        Explosion();
        void Start(Position p_position );
        virtual void Update(float lastFrame) override;
        //DELETE ON REFACTOR
        virtual void CollisionReaction() override;

        virtual ~Explosion();
    protected:
        bool hasStart{false};
        float startSince{0};
        static constexpr float ANIMATION_DURATION{0.2f};
};
#endif // EXPLOSION_H
