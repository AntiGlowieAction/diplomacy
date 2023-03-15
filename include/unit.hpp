#ifndef DIPLOMACY_UNIT_HPP
#define DIPLOMACY_UNIT_HPP

#include <SFML/Config.hpp>

#include "province.hpp"
#include "nation.hpp"

class Unit {
    public:
        Province *province = nullptr;
        Nation *nation = nullptr;
        /**
         * @brief True if army, false if navy.
         * 
         */
        bool land;


};

#endif