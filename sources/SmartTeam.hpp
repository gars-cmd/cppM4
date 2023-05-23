#pragma once
#ifndef SMARTTEAM_HPP
#define SMARTTEAM_HPP

#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"
#include "Cowboy.hpp"
#include "Team.hpp"
#include <iostream>
#include <string>

namespace ariel {

class SmartTeam : public ariel::Team {
    using ariel::Team::Team;

public:
    void attack(Team* ennemyTeam) override;
    Character* getWeakerEnnemy(Team* ennemyTeam);
    Character* getCloserEnnemy(Character* teammate, Team* ennemyTeam);
};

}
#endif // SAMRTTEAM

