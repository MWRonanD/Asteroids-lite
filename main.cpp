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
    auto keyReleased{false};
    sf::Image icon;
    if(!icon.loadFromFile("Assets/asteroide.png"))
        EXIT_FAILURE;
    sf::RenderWindow wind{sf::VideoMode{screenWidth,screenHeight}, "Asteroids Lite" };
    wind.setIcon(200,200,icon.getPixelsPtr());
    Position::InitScreenSize(screenWidth,screenHeight);
    auto gameSpace = GameSpace{};
    auto gm = GameManager{gameSpace};
    while (wind.isOpen()){
        auto events = sf::Event{};
        while(wind.pollEvent(events)){
            if(events.type == sf::Event::Closed){
                wind.close();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !gm.IsInGame()){
                std::cout<<"Let's play !"<<std::endl;
                gm.StartGame();
                keyReleased = false;
            }
        }
        gm.CheckForAsteroids();
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
