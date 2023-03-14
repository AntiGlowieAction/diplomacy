#ifndef DIPLOMACY_PROVINCE_HPP
#define DIPLOMACY_PROVINCE_HPP

#include <SFML/Config.hpp>

class Province {
    sf::Uint8 id;
    sf::Uint8 controller;
    bool occupied;
    bool naval;
};

#endif