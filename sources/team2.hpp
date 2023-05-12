#ifndef TEAM2_HPP
#define TEAM2_HPP

#include "point.hpp"
#include "character.hpp"
#include "ninja.hpp"
#include "cowboy.hpp"
#include "Team.hpp"
#include <iostream>
#include <string>

namespace ariel {

class Team2 : public ariel::Team {
    using ariel::Team::Team;

public:
    void sort() override;
};

}
#endif // TEAM2

