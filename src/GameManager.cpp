#include "GameManager.h"
#include "SpaceShip.h"
#include "Asteroids.h"
#include "font.h"
#include "ResourceManager.h"

#include <string>
#include <SFML/Graphics.hpp>
#include <memory>
#include <fstream>

using namespace std::string_literals;

GameManager::GameManager(GameSpace &gs) : gameSpace{gs}
{
    auto file = std::ifstream{".save"};
    if (file.is_open())
    {
        file >> bestScore;
    }
    else
    {
        std::cout << "failed to load : .save" << std::endl;
    }
    file.close();
    if (!font.loadFromMemory(Air_Americana_ttf, Air_Americana_ttf_size))
    {
        std::cout << "failed to load : font" << std::endl;
    }
    else
    {
        std::cout << "success to load : font" << std::endl;
        displayScore.setFont(font);
        displayScore.move(0, 30);
        displayBestScore.setFont(font);
        UpdateBestScore();
    }

    spriteHome.setTexture(ResourceManager<sf::Texture>::GetResource("Assets/accueil.png"));
    spritePause.setTexture(ResourceManager<sf::Texture>::GetResource("Assets/pause.png"));
}

void GameManager::StartGame()
{
    inGame = true;
    score = 0;
    UpdateScore();
    //Creation d'un spaceship avec pointeur dynamique
    //Spaceship
    gameSpace.AddElement(std::make_unique<SpaceShip>(gameSpace, *this));
    //Asteroids
    // gameSpace.AddElement(std::make_unique<Asteroids>(gameSpace, *this));
    // gameSpace.AddElement(std::make_unique<Asteroids>(gameSpace, *this));
    // gameSpace.AddElement(std::make_unique<Asteroids>(gameSpace, *this));
    // gameSpace.AddElement(std::make_unique<Asteroids>(gameSpace, *this));

    std::cout << "Started" << std::endl;
}

void GameManager::EndGame()
{
    inGame = false;
    if (score > bestScore)
    {
        bestScore = score;
        UpdateBestScore();
        auto file = std::ofstream{".save"};
        if (file.is_open())
        {
            file << score;
        }
        file.close();
    }
    gameSpace.Clear();
}

void GameManager::DrawHome(sf::RenderWindow &wind) const
{
    if (!IsInGame() && gameSpace.IsEmpty())
    {
        wind.draw(spriteHome);
    }
    else
    {
        wind.draw(displayScore);
    }
    wind.draw(displayBestScore);
}

void GameManager::DrawPause(sf::RenderWindow &wind) const 
{
if (paused)
{
   wind.draw(spritePause);
}

}

void GameManager::AddScore(int s)
{
    score += s;
    UpdateScore();
}

void GameManager::UpdateScore()
{
    displayScore.setString("Score : "s + std::to_string(score));
}

void GameManager::UpdateBestScore()
{
    displayBestScore.setString("Best score : "s + std::to_string(bestScore));
}

void GameManager::CheckForAsteroids()
{
    if (NB_ASTEROIDS > gameSpace.GetNbAsteroids() && inGame)
    {
        for (auto i{0}; i < NB_ASTEROIDS; i++)
        {
            gameSpace.AddElement(std::make_unique<Asteroids>(gameSpace, *this));
        }
    }
}
