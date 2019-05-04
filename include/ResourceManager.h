#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H
#include <unordered_map>
#include <SFML/Graphics.hpp>

class ResourceManager
{
    public:
        /** Default constructor */
        ResourceManager() = delete;
        static sf::Texture const& GetResource(std::string imgPath);

    protected:
       static std::unordered_map<std::string, sf::Texture> resources;
    private:
};

#endif // RESOURCEMANAGER_H
