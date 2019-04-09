#include "MovingItem.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Vector.h"
#include "Position.h"


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
    sprite.rotate(rotateSpeed*lastFrame);
}
void MovingItem::Draw(sf::RenderWindow &wind) const
{
    auto drawing = std::array<Vector, 9>{
        Vector{-1,-1},Vector{0, -1},Vector{1,-1},
        Vector{-1,0},Vector{0,0},Vector{1,0},
        Vector{-1,1},Vector{0,1},Vector{1,1}
        };
        for(auto& draw : drawing){
        auto transfor = sf::Transform{};
        transfor.translate(draw.x*Position::screenWidth, draw.y*Position::screenHeight);
         wind.draw(sprite,transfor);
      }
}
float MovingItem::GetColiderRadius() const
{
    return sprite.getLocalBounds().height/2.f;
}

void MovingItem::Hit()
{
    sprite.setColor(sf::Color::Red);
}

void MovingItem::Collision(MovingItem& other)
{
    auto distance = pos.GetDistance(other.GetPosition());

    if(distance < GetColiderRadius() + other.GetColiderRadius())
    {
        other.Hit();
        Hit();
    }
}

