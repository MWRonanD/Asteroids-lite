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
        void AddScore(int s);
        inline bool IsInGame() const {return inGame;};
        void DrawHome(sf::RenderWindow& wind) const;
        void CheckForAsteroids();
        inline float GetRand(float M,float N)
        {
            return float(M + (rand() / ( RAND_MAX / (N-M) ) )) ;  
        }
    protected:
        void UpdateScore();
        void UpdateBestScore();

        GameSpace& gameSpace;
        sf::Font font{};
        sf::Sprite spriteHome{};
        sf::Text displayScore{};
        sf::Text displayBestScore{};

        bool inGame{false};
        int score{0};
        int bestScore{0};

        static constexpr int NB_ASTEROIDS{4};

    private:
};

#endif // GAMEMANAGER_H
