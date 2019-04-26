#ifndef GAMESPACE_H
#define GAMESPACE_H
#include <SFML/Graphics.hpp>
#include "MovingItem.h"
#include "vector"

class GameSpace
{
    public:
        /** Default constructor */
        GameSpace();
        void AddElement(MovingItem& item);
        void Update();
        void Collision();
        void Draw(sf::RenderWindow& wind) const;
        void Clean();

        void StatGame();
        void EndGale();
        bool GameState();

    protected:
        bool gameStarted{false};
        std::vector<MovingItem*> elements{};
        sf::Clock clock{};

    private:
};

#endif // GAMESPACE_H
