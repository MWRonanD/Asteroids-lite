#include "ResourceManager.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
template<>
std::unordered_map<std::string, sf::Texture> ResourceManager<sf::Texture>::resources{};

template<>
std::unordered_map<std::string, sf::SoundBuffer> ResourceManager<sf::SoundBuffer>::resources{};

