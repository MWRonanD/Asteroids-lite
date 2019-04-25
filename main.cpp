#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>
using namespace std;
#include "Position.h"
#include "SpaceShip.h"
#include "Asteroids.h"
#include "MovingItem.h"
#include <array>

constexpr int screenWidth{800};
constexpr int screenHeight{600};

int main()
{
    auto i = true;
    sf::RenderWindow wind{sf::VideoMode{screenWidth,screenHeight}, "Asteroids Lite" };
    Position::InitScreenSize(screenWidth,screenHeight);

    SpaceShip ship{};
    Asteroids asteroid1{};
    Asteroids asteroid2{};
    Asteroids asteroid3{};
    Asteroids asteroid4{};
    auto elements = array<MovingItem*, 5>{&asteroid1,
                                                &asteroid2,
                                                &asteroid3,
                                                &asteroid4,
                                                &ship};
    sf::Clock clock{};
    while (wind.isOpen()){
        auto events = sf::Event{};
        while(wind.pollEvent(events)){

            if(events.type == sf::Event::Closed){
                wind.close();
            }
        }
        auto lastFrame = clock.restart().asSeconds();
        for(auto* element : elements){
            for(auto* element2 : elements){
                if(element != &ship)
                {
                    element->Collision(ship);
                }
            }
        }
        for(MovingItem* element : elements){
            element->Update(lastFrame);
        }

        wind.clear();
        for(MovingItem* element : elements){
            element->Draw(wind);
        }
        wind.display();
    }
    return 0;
}
