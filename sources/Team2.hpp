#pragma once
#ifndef TEAM2_HPP
#define TEAM2_HPP

#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"
#include "Cowboy.hpp"
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

