#include "Explosion.h"
#include "MovingItem.h"

Explosion::Explosion() : MovingItem{"Assets/explosion.png"}
{

}

Explosion::~Explosion()
{
    //dtor
}

void Explosion::Start(const Position p_position){
    pos = p_position;
    hasStart = true;
}
void Explosion::Update(float lastFrame) {
    if(hasStart){

        startSince += lastFrame;
        if(startSince < ANIMATION_DURATION){
                // std::cout<<"hi there "<< startSince/ANIMATION_DURATION <<std::endl;
            sprite.setScale(startSince/ANIMATION_DURATION,startSince/ANIMATION_DURATION);
        }else{
            hasStart = false;
        }
    }

    MovingItem::Update(lastFrame);
}
void Explosion::Draw(sf::RenderWindow& wind){

    if(startSince < ANIMATION_DURATION){
            MovingItem::Draw(wind);
    }
}
//DELETE ON REFACTOR
void Explosion::CollisionReaction() {
}
