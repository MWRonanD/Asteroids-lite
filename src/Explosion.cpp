#include "Explosion.h"
#include "MovingItem.h"

Explosion::Explosion(Position position) : MovingItem{"Assets/explosion.png"}
{
    pos = Position{position.GetX(), position.GetY()};
}


void Explosion::Update(float lastFrame) {

   // std::cout<< "hasStart : "<< hasStart <<std::endl;
    startSince += lastFrame;
    if(startSince < ANIMATION_DURATION){
       //  std::cout<<"hi there "<< startSince/ANIMATION_DURATION <<std::endl;
        sprite.setScale(startSince/ANIMATION_DURATION,startSince/ANIMATION_DURATION);
    }else{
        isDestroy = true;
    }
    MovingItem::Update(lastFrame);
}
//DELETE ON REFACTORS
void Explosion::CollisionReaction(TypeItem t_type) {
}
