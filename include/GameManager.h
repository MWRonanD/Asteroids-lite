#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "GameSpace.h"
#include <SFML/Graphics.hpp>

class GameManager
{
    public:
        /** Default constructor */
        GameManager(GameSpace& gs);
        void StartGame();
        void EndGame();
        inline bool IsInGame() const {return inGame;};
        void DrawHome(sf::RenderWindow& wind) const;

    protected:
        GameSpace& gameSpace;
        sf::Font font{};
        sf::Sprite spriteHome{};
        bool inGame{false};
    private:
};

#endif // GAMEMANAGER_H
