#ifndef DIPLOMACY_GAME_HPP
#define DIPLOMACY_GAME_HPP

#include <SFML/Config.hpp>

#include "map.hpp"
#include "nation.hpp"


class Game {
    public:
    Map *map;
    Nation *nations;
};

#endif