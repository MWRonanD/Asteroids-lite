#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

int main()
{
    sf::RenderWindow wind{sf::VideoMode{800,600}, "Asteroids Lite" };
    while (wind.isOpen()){
        auto events = sf::Event{};
        while(wind.pollEvent(events)){
            if(events.type == sf::Event::Closed){
                wind.close();
            }
        }
        wind.display();
    }
    return 0;
}
