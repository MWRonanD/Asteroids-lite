#include "ResourceManager.h"
#include <iostream>
std::unordered_map<std::string, sf::Texture> ResourceManager::resources{};
sf::Texture const& ResourceManager::GetResource(std::string imgPath){
    auto result = resources.find(imgPath);
    if(result == std::end(resources))
    {
        if(!resources[imgPath].loadFromFile(imgPath.data()))
        {
            std::cerr<<"failed to load : " << imgPath << std::endl;
        }
        else
        {
            std::cerr<<"success to load " << imgPath << std::endl;
        }

    }
    return resources[imgPath];
}
