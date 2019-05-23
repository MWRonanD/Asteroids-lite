#include "Missile.h"
#include "vector.h"
#include "MovingItem.h"
#include "ResourceManager.h"

Missile::Missile(Position position, float rotation) : MovingItem{"Assets/missile.png"}
{
    type = TypeItem::MISSILE;
    pos = Position{position.GetX(), position.GetY()};
    sprite.setRotation(rotation);
    speed = Vector::GetDirection(SPEED,rotation);
    sound.setBuffer(ResourceManager<sf::SoundBuffer>::GetResource("Assets/laser.wav"));
    sound.play();
}

void Missile::CollisionReaction(TypeItem t_type) {
    if(t_type != TypeItem::SHIP && t_type != TypeItem::MISSILE){
        isDestroy = true;
    }
}

void Missile::Update(float lastFrame)
{
    if (timeSinceCreate.getElapsedTime().asSeconds() > LIFETIME)
    {
       isDestroy = true;
    }
    timeSinceCreate.restart();
    MovingItem::Update(lastFrame);
}