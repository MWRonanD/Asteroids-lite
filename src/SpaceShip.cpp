#include "../include/spaceship.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Vector.h"
#include "Position.h"
#include "MovingItem.h"
#include "Explosion.h"
#include "GameSpace.h"
using namespace std;

SpaceShip::SpaceShip(GameSpace& gs) : MovingItem("Assets/spaceship.png"), gameSpace{gs}
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
    if (!isDestroy){
        UpdateMove();
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
    }
    else{
        speed = {0,0};
    }
    MovingItem::Update(lastFrame);
}

void SpaceShip::CollisionReaction(){
    if(!isDestroy){
        explosion.Start(pos);
        gameSpace.AddElement(explosion);
        isDestroy = true;
    }
}
