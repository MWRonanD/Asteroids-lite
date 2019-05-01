#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <MovingItem.h>
#include "Position.h"

class Explosion : public MovingItem
{
    public:
        Explosion(Position position);
        virtual void Update(float lastFrame) override;
        //DELETE ON REFACTOR
        virtual void CollisionReaction(TypeItem t_type) override;
    protected:
        float startSince{0};
        static constexpr float ANIMATION_DURATION{0.2f};
};
#endif // EXPLOSION_H
