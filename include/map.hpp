#ifndef DIPLOMACY_MAP_HPP
#define DIPLOMACY_MAP_HPP

#include <SFML/Config.hpp>

#include "province.hpp"

class Map {
    public:
    sf::Uint8 *pixels;
    Province *provinces;
};

#endif