#include "Missile.h"
#include "vector.h"
#include"MovingItem.h"

Missile::Missile(Position position, float rotation) : MovingItem{"Assets/missile.png"}
{
    type = TypeItem::MISSILE;
    pos = Position{position.GetX(), position.GetY()};
    sprite.setRotation(rotation);
    speed = Vector::GetDirection(SPEED,rotation);
}

void Missile::CollisionReaction(TypeItem t_type) {
    if(t_type != TypeItem::SHIP){
        isDestroy = true;
    }
}
