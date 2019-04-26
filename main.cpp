#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>
using namespace std;
#include "Position.h"
#include "SpaceShip.h"
#include "Asteroids.h"
#include "MovingItem.h"
#include <array>
#include "GameSpace.h"
constexpr int screenWidth{800};
constexpr int screenHeight{600};

int main()
{
    auto i = true;
    sf::RenderWindow wind{sf::VideoMode{screenWidth,screenHeight}, "Asteroids Lite" };
    Position::InitScreenSize(screenWidth,screenHeight);
    auto gameSpace = GameSpace{};
    SpaceShip ship{gameSpace};

    Asteroids asteroid1{};
    Asteroids asteroid2{};
    Asteroids asteroid3{};
    Asteroids asteroid4{};

    while (wind.isOpen()){
        auto events = sf::Event{};
        while(wind.pollEvent(events)){
            if(events.type == sf::Event::Closed){
                wind.close();
            }
            if(events.type == sf::Event::KeyPressed && !gameSpace.GameState()){
                gameSpace.StatGame();
                gameSpace.AddElement(asteroid1);
                gameSpace.AddElement(asteroid2);
                gameSpace.AddElement(asteroid3);
                gameSpace.AddElement(asteroid4);
                gameSpace.AddElement(ship);
            }
        }
        gameSpace.Clean();
        gameSpace.Update();
        gameSpace.Collision();
        wind.clear();
        gameSpace.Draw(wind);
        wind.display();
    }
    return 0;
}
