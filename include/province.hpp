#ifndef DIPLOMACY_PROVINCE_HPP
#define DIPLOMACY_PROVINCE_HPP

#include <SFML/Graphics.hpp>

class Province {
    public:
    sf::Uint8 id;
    sf::Uint8 controller;
    bool supplyCentre;
    bool occupied;
    bool naval;
    sf::Texture texture;
    sf::Vector2u min = { UINT32_MAX, UINT32_MAX };
    sf::Vector2u max = { 0, 0 };
};

#endif