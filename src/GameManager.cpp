#include "GameManager.h"
#include "SpaceShip.h"
#include "Asteroids.h"
#include "font.h"
#include "ResourceManager.h"

#include <SFML/Graphics.hpp>
#include <memory>

GameManager::GameManager(GameSpace& gs) : gameSpace{gs}
{
    font.loadFromMemory(Air_Americana_ttf,Air_Americana_ttf_size);
    spriteHome.setTexture(ResourceManager::GetResource("Assets/accueil.png"));
}

void GameManager::StartGame(){
    inGame = true;
    //Creation d'un spaceship avec pointeur dynamique
    //Spaceship
    gameSpace.AddElement(std::make_unique<SpaceShip>(gameSpace, *this));
    //Asteroids
    gameSpace.AddElement(std::make_unique<Asteroids>(gameSpace));
    gameSpace.AddElement(std::make_unique<Asteroids>(gameSpace));
    gameSpace.AddElement(std::make_unique<Asteroids>(gameSpace));
    gameSpace.AddElement(std::make_unique<Asteroids>(gameSpace));
    std::cout<<"Started"<<std::endl;

}

void GameManager::EndGame(){
    inGame = false;
    gameSpace.Clear();
}

void GameManager::DrawHome(sf::RenderWindow& wind) const{
    if(!IsInGame()){
        wind.draw(spriteHome);
    }
}
