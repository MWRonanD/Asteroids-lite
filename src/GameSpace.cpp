#include "GameSpace.h"
#include "MovingItem.h"
#include <memory>
GameSpace::GameSpace()
{
    //ctor
}
void GameSpace::AddElement(std::unique_ptr<MovingItem> item){
    elements.push_back(std::move(item));
    //std::cout<<item.name << " : "<<elements.size() <<std::endl;

}

void GameSpace::Update(){
    auto lastFrame = clock.restart().asSeconds();
    for(auto i{0}; i<elements.size(); ++i){
        elements[i]->Update(lastFrame);
    }

}
void GameSpace::Collision(){
    for(auto i{0}; i<elements.size(); ++i){
        for(auto j{0}; j<elements.size(); ++j){
            if(i != j)
            {
                elements[i]->Collision(*elements[j]);
            }
        }
    }
}
void GameSpace::Draw(sf::RenderWindow& wind) const{
    for(auto& element : elements){
        element->Draw(wind);
    }
}

void GameSpace::Clean(){
    auto newEnd = std::remove_if(std::begin(elements),std::end(elements),MovingItem::IsDestroy);
    elements.erase(newEnd, std::end(elements));

}


void GameSpace::StatGame(){
    gameStarted = true;
}

void GameSpace::EndGale(){
    gameStarted = false;
}

bool GameSpace::GameState(){
    return gameStarted;
}

