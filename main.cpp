#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
#include "Position.h"
//#include "SpaceShip.h"
#include "SpaceShip.h"

constexpr int screenWidth{600};
constexpr int screenHeight{800};
int main()
{
    sf::RenderWindow wind{sf::VideoMode{screenHeight,screenWidth}, "Asteroids Lite" };
    Position::InitScreenSize(screenWidth,screenHeight);

    SpaceShip ship{};
    sf::Clock clock{};
    while (wind.isOpen()){
        auto events = sf::Event{};
        while(wind.pollEvent(events)){

            if(events.type == sf::Event::Closed){
                wind.close();
            }

        }
        ship.UpdateMove();
        ship.Update(clock.restart().asSeconds());

        wind.clear();
        ship.Draw(wind);

        wind.display();
    }
    return 0;
}
