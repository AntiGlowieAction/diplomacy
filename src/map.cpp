#include "../include/map.hpp"
#include <iostream>


bool Map::load () {
    sf::Image mapImg;
    
    if (!mapImg.loadFromFile("res/provinces.tga")) {
        return false;
    }

    const sf::Uint8* mapRGBA = mapImg.getPixelsPtr();
    sf::Vector2u mapDim = mapImg.getSize();

    sf::Uint8* mapR = new sf::Uint8[mapDim.x * mapDim.y];
    
    // Get R channel.
    for (size_t i = 0; i < mapDim.x * mapDim.y; i++) {
        mapR[i] = mapRGBA[4*i];
    }

    // TODO: This belongs in a different function.
    this->provinces = new Province[256];

    for (size_t i = 0; i < mapDim.x * mapDim.y; i++) {
        sf::Uint8 id = mapR[i];

        size_t x = i % mapDim.x;
        size_t y = i / mapDim.x;

        Province* prov = provinces + id;

        if (x > prov->max.x) {
            prov->max.x = x;
        }
        if (y > prov->max.y) {
            prov->max.y = y;
        }
        if (x < prov->min.x) {
            prov->min.x = x;
        }
        if (y < prov->min.y) {
            prov->min.y = y;
        }
    }

    // Allocate space for province textures.
    sf::Uint32* provinceRGBA[256];
    size_t width[256];
    size_t height[256];

    for (size_t i = 0; i < 256; i++) {
        Province* prov = this->provinces + i;
        if (prov->min.x == UINT32_MAX) {
            continue;
        }

        width[i] = prov->max.x - prov->min.x + 1;
        height[i] = prov->max.y - prov->min.y + 1;

        provinceRGBA[i] = new sf::Uint32[width[i] * height[i]];
    }

    // Fill in textures;
    for (size_t x = 0; x < mapDim.x; x++) {
        for (size_t y = 0; y < mapDim.y; y++) {
            sf::Uint8 id = mapR[y*mapDim.x + x];
            Province* prov = this->provinces + id;
            size_t xRel = x - prov->min.x;
            size_t yRel = y - prov->min.y;
            provinceRGBA[id][yRel * width[id] + xRel] = 0xffffffffU;
        }
    }

    // Generate images
    for (size_t i = 0; i < 256; i++) {
        Province* prov = this->provinces + i;
        if (prov->min.x == UINT32_MAX) {
            continue;
        }

        sf::Image provImg;
        provImg.create(width[i], height[i], (sf::Uint8*) provinceRGBA[i]);

        this->provinces[i].texture.loadFromImage(provImg);

        delete provinceRGBA[i];
    }

    this->pixels = mapR;

    return true;
}
