#include <algorithm>
#include <iostream>
#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"
#include "Ninja.hpp"
#include "Cowboy.hpp"
#include "Team.hpp"
#include "SmartTeam.hpp"
#include <limits>
#include <iostream>


using namespace ariel;


ariel::Character* ariel::SmartTeam::getWeakerEnnemy(Team* ennemyTeam){
    Character* target = nullptr;
    int min_ennemy_hp = std::numeric_limits<int>::max();
    for (Character* player : ennemyTeam->getVec()) {
        if (player->isAlive() && player->getHealthPoint() < min_ennemy_hp) {
            min_ennemy_hp = player->getHealthPoint();
            target = player;
        }
    }
    return target;
}




void ariel::SmartTeam::attack(Team* ennemyTeam){
    this->attackErrorHandler(ennemyTeam);
    this->liveReplacement(ennemyTeam);
    if (ennemyTeam != nullptr && ennemyTeam->stillAlive()!=0) {
        for (ariel::Character* player : this->getVec()) {
            this->liveReplacement(ennemyTeam);
            ariel::Character* new_victim = this->getWeakerEnnemy(ennemyTeam) ;
            if (new_victim!=nullptr) {
                if (player!=nullptr && player->isAlive() && new_victim->isAlive()) {
                    player->attack(new_victim);
                }
            }
        }
    }
}


