#ifndef GAMESPACE_H
#define GAMESPACE_H
#include <memory>
#include <SFML/Graphics.hpp>
#include "MovingItem.h"
#include "vector"

class GameSpace
{
    public:
        /** Default constructor */
        GameSpace();
        void AddElement(std::unique_ptr<MovingItem> item);
        void Update(bool paused);
        void Collision();
        void Draw(sf::RenderWindow& wind) const;
        void Clean();
        void Clear();
        inline bool IsEmpty()const {return elements.empty() && toAdd.empty();};

        inline int GetNbAsteroids(){
            auto nbAsteroids{0};
            for(auto& item : elements){
                if (item->type == TypeItem::ASTEROIDS)
                {
                   nbAsteroids++;
                }
            }
            for(auto& item : toAdd){
                if (item->type == TypeItem::ASTEROIDS)
                {
                   nbAsteroids++;
                }
            }
            return nbAsteroids;
        };

    protected:

        bool toClear{false};

        std::vector<std::unique_ptr<MovingItem>> elements{};
        std::vector<std::unique_ptr<MovingItem>> toAdd{};
        sf::Clock clock{};
        sf::Sprite spriteBg;


    private:
};

#endif // GAMESPACE_H
