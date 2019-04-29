#include "../include/spaceship.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Vector.h"
#include "Position.h"
#include "MovingItem.h"
#include "Explosion.h"
#include "GameSpace.h"
using namespace std;

SpaceShip::SpaceShip(GameSpace& g_gameSpace) : MovingItem{"Assets/spaceship.png"}, gameSpace{g_gameSpace}
{
    sprite.setPosition(pos.GetY(),pos.GetX());
}

SpaceShip::~SpaceShip()
{
}
void SpaceShip::UpdateMove()
{
    hasForward = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    hasLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    hasRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);


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

void SpaceShip::CollisionReaction(){
    if(!isDestroy){
        isDestroy = true;
        explosion.Start(GetPosition());
        gameSpace.AddElement(explosion);

    }
}
