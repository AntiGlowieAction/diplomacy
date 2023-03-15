#ifndef DIPLOMACY_NATION_HPP
#define DIPLOMACY_NATION_HPP

#include <SFML/Config.hpp>
#include <string>

class Nation {
    public:
    std::string name;
    sf::Uint32 color;
    sf::Uint8 centers;

};

#endif