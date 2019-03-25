#include "MovingItem.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Vector.h"
#include "Position.h"

using namespace std;

MovingItem::MovingItem(std::string imgPath)
{
  texture.loadFromFile(imgPath.data());
  sprite.setTexture(texture);
  sprite.setOrigin(sprite.getLocalBounds().width/2,sprite.getLocalBounds().height/2);
  sprite.setPosition(pos.GetY(),pos.GetX());
}

void MovingItem::Update(float lastFrame)
{
    pos += speed*lastFrame;
    sprite.setPosition(pos.GetX(), pos.GetY());
}
void MovingItem::Draw(sf::RenderWindow &wind) const
{
    wind.draw(sprite);
}

