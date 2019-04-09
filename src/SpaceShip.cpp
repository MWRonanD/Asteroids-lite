#include "../include/spaceship.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Vector.h"
#include "Position.h"
#include "MovingItem.h"
using namespace std;

SpaceShip::SpaceShip() : MovingItem("Assets/spaceship.png")
{
        std::cout << sprite.getLocalBounds().height/2.f << std::endl;
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
    MovingItem::Update(lastFrame);
}

