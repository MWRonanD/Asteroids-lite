#include "MovingItem.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Vector.h"
#include "Position.h"
#include "ResourceManager.h"

MovingItem::MovingItem(std::string imgPath)
{
    name = imgPath;

  sprite.setTexture(ResourceManager<sf::Texture>::GetResource(imgPath));
  sprite.setOrigin(sprite.getLocalBounds().width/2,sprite.getLocalBounds().height/2);
  sprite.setPosition(pos.GetY(),pos.GetX());
}

void MovingItem::Update(float lastFrame)
{
    auto deplacement = speed*lastFrame;
    pos += deplacement;
    sprite.setPosition(pos.GetX(), pos.GetY());
    sprite.rotate(rotateSpeed*lastFrame);

}
void MovingItem::Draw(sf::RenderWindow &wind)
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
    return sprite.getGlobalBounds().height/2.4f;
}



void MovingItem::Collision(MovingItem& other)
{
    auto distance = pos.GetDistance(other.GetPosition());

    if(distance < GetColiderRadius() + other.GetColiderRadius())
    {
        CollisionReaction(other.type);
    }
}

