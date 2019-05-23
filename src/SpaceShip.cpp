#include "../include/spaceship.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Vector.h"
#include "Position.h"
#include "MovingItem.h"
#include "Explosion.h"
#include "GameSpace.h"
#include "Missile.h"
using namespace std;

SpaceShip::SpaceShip(GameSpace& g_gameSpace, GameManager& gaMa) : MovingItem{"Assets/spaceship.png"}, gameSpace{g_gameSpace}, gm{gaMa}
{
    type = TypeItem::SHIP;
    sprite.setPosition(pos.GetY(),pos.GetX());
}


void SpaceShip::UpdateMove()
{
    hasForward = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    hasLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    hasRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && lastShoot.getElapsedTime().asSeconds() > COOLDOWN_SHOOT){
        gameSpace.AddElement(std::make_unique<Missile>(GetPosition(), sprite.getRotation()));
        lastShoot.restart();
    }


}
void SpaceShip::Update(float lastFrame)
{
        UpdateMove();
    if (!isDestroy){
        if(hasForward)
        {
            speed += Vector::GetDirection(SPEED_MODIFICATOR*lastFrame, sprite.getRotation());
        }
        speed -= speed * 1.f * lastFrame;

        if(hasLeft){
           rotateSpeed =-ROTATE_SPEED;
        }
        else if(hasRight){
            rotateSpeed = ROTATE_SPEED;
        }else{
            rotateSpeed =0;
        }
        MovingItem::Update(lastFrame);
    }

}

void SpaceShip::CollisionReaction(TypeItem t_type){
    if(t_type == TypeItem::ASTEROIDS){
        isDestroy = true;
        gm.EndGame();
        gameSpace.AddElement(std::make_unique<Explosion>(GetPosition()));

    }
}
