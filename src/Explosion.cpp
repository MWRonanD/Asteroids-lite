#include "Explosion.h"
#include "MovingItem.h"

Explosion::Explosion() : MovingItem{"Assets/explosion.png"}
{

}

Explosion::~Explosion()
{
    //dtor
}

void Explosion::Start(Position p_position){
    std::cout<< "pos.x : "<< pos.GetX()<< " - pos.y : "<< pos.GetY()<<std::endl;
    pos = Position{p_position.GetX(), p_position.GetY()};
    std::cout<< "pos.x : "<< pos.GetX()<< " - pos.y : "<< pos.GetY()<<std::endl;
    hasStart = true;
}
void Explosion::Update(float lastFrame) {

   // std::cout<< "hasStart : "<< hasStart <<std::endl;
    if(hasStart){
        startSince += lastFrame;
    }
    if(startSince < ANIMATION_DURATION){
       //  std::cout<<"hi there "<< startSince/ANIMATION_DURATION <<std::endl;
        sprite.setScale(startSince/ANIMATION_DURATION,startSince/ANIMATION_DURATION);
    }else{
        isDestroy = true;
    }
    MovingItem::Update(lastFrame);
}
//DELETE ON REFACTOR
void Explosion::CollisionReaction() {
}
