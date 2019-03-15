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
    cout<< lastFrame;
    if(hasForward)
    {
        speed += {SPEED_MODIFICATOR*lastFrame, 0.f};
    }
    if(hasLeft){
        sprite.rotate(-ROTATE_SPEED*lastFrame);
    }
    if(hasRight){
        sprite.rotate(ROTATE_SPEED*lastFrame);
    }
    speed -= speed * (COEF_SLOWDOWN * lastFrame);

    sprite.move(speed.x, speed.y*ROTATE_SPEED*lastFrame);
}
void SpaceShip::Rotation(float rotate)
{
    sprite.rotate(rotate);
}
void SpaceShip::Draw(sf::RenderWindow &wind) const
{
    wind.draw(sprite);
}

