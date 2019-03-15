#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

#include "SpaceShip.h"

int main()
{
    sf::RenderWindow wind{sf::VideoMode{800,600}, "Asteroids Lite" };
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
