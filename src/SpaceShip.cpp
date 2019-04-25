#include "../include/spaceship.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Vector.h"
#include "Position.h"
#include "MovingItem.h"
#include "Explosion.h"
using namespace std;

SpaceShip::SpaceShip() : MovingItem("Assets/spaceship.png")
{
  sprite.setPosition(pos.GetY(),pos.GetX());
}

SpaceShip::~SpaceShip()
{
    //dtor
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
           rotateSpeed =  -ROTATE_SPEED;
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
    explosion.Update(lastFrame);
}

void SpaceShip::Draw(sf::RenderWindow &wind){
    if(!isDestroy){
        MovingItem::Draw(wind);
    }
    else
    {
        explosion.Draw(wind);
    }
}

void SpaceShip::CollisionReaction(){
    if(!isDestroy){
        isDestroy = true;
    explosion.Start(pos);
    }
}
