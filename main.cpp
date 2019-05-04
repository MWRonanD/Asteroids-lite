#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>
#include <memory>
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
    sf::RenderWindow wind{sf::VideoMode{screenWidth,screenHeight}, "Asteroids Lite" };
    Position::InitScreenSize(screenWidth,screenHeight);
    auto gameSpace = GameSpace{};
    while (wind.isOpen()){
        auto events = sf::Event{};
        while(wind.pollEvent(events)){
            if(events.type == sf::Event::Closed){
                wind.close();
            }
            if(events.type == sf::Event::KeyPressed && !gameSpace.GameState()){
                gameSpace.StatGame();
                //Creation d'un spaceship avec pointeur dynamique
                gameSpace.AddElement(std::make_unique<SpaceShip>(gameSpace));
                gameSpace.AddElement(std::make_unique<Asteroids>(gameSpace));
            }
        }
        gameSpace.Update();
        gameSpace.Collision();

        wind.clear();
        gameSpace.Draw(wind);
        wind.display();


        gameSpace.Clean();
    }
    return 0;
}
