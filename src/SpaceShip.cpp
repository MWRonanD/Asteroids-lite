#include "../include/spaceship.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Vector.h"
using namespace std;

SpaceShip::SpaceShip()
{
  texture.loadFromFile("Assets/spaceship.png");
  sprite.setTexture(texture);
  sprite.setOrigin(sprite.getLocalBounds().width/2,sprite.getLocalBounds().height/2);
  sprite.setPosition(50,50);
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
void SpaceShip::Update(double lastFrame)
{
    if(hasForward)
    {
        speed += Vector::GetDirection(SPEED_MODIFICATOR*lastFrame, sprite.getRotation());
    }
    speed -= speed * 1.f * lastFrame;
    auto deplacement = speed*lastFrame;
    sprite.move(deplacement.x, deplacement.y);
    if(hasLeft){
        sprite.rotate(-ROTATE_SPEED*lastFrame);
    }
    if(hasRight){
        sprite.rotate(ROTATE_SPEED*lastFrame);
    }
}
void SpaceShip::Draw(sf::RenderWindow &wind) const
{
    wind.draw(sprite);
}

