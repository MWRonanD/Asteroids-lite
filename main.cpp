#include <SFML/Graphics.hpp>
using namespace std;
#include "Position.h"
#include "MovingItem.h"
#include "GameSpace.h"
#include "GameManager.h"
constexpr int screenWidth{800};
constexpr int screenHeight{600};

int main()
{
    sf::RenderWindow wind{sf::VideoMode{screenWidth,screenHeight}, "Asteroids Lite" };
    Position::InitScreenSize(screenWidth,screenHeight);
    auto gameSpace = GameSpace{};
    auto gm = GameManager{gameSpace};
    while (wind.isOpen()){
        auto events = sf::Event{};
        while(wind.pollEvent(events)){
            if(events.type == sf::Event::Closed){
                wind.close();
            }
            if(events.type == sf::Event::KeyPressed && !gm.IsInGame()){
                std::cout<<"Let's play !"<<std::endl;
                gm.StartGame();
            }
        }
        gameSpace.Update();
        gameSpace.Collision();

        wind.clear();
        gameSpace.Draw(wind);
        gm.DrawHome(wind);
        wind.display();

        gameSpace.Clean();
    }
    return 0;
}
