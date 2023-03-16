#include "../include/map.hpp"

bool Map::load(const std::string filename) {
    sf::Image pi;
    
    if (!pi.loadFromFile("res/provinces.tga")) {
        return false;
    }

    const sf::Uint8* pixels = pi.getPixelsPtr();
    sf::Vector2u size = pi.getSize();

    this->height = size.y;
    this->width = size.x;
    
    this->provinces = new Province[sizeof(sf::Uint8)];
    this->pixels = new sf::Uint8[size.x * size.y];

    if (!this->provinces || !this->pixels) {
        return false;
    }

    // Copy R channel from RGBA data of image.
    for (size_t i = 0; i < size.x * size.y; i++) {
        this->pixels[i] = pixels[4*i];
    }

    // TODO: Load in provincial data
    for (int i = 0; i < 255; i++) {
        this->provinces[i] = Province();
        this->provinces[i].id = i;
    }

    return true;
}

Province Map::province(size_t x, size_t y) {
    sf::Uint8 id = this->pixels[this->width*y + x];
    return this->provinces[id];
}