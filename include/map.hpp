#ifndef DIPLOMACY_MAP_HPP
#define DIPLOMACY_MAP_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>
#include <string>

#include "province.hpp"

class Map {
    public:
    Province *provinces = nullptr;
    sf::Uint8 *pixels = nullptr;
    size_t height = 0;
    size_t width = 0;

    bool load (const std::string filename);

    Province province (size_t x, size_t y);
};

#endif