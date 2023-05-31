#include <algorithm>
#include <iostream>
#include "Character.hpp"
#include "Point.hpp"
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

ariel::Character* ariel::SmartTeam::getCloserEnnemy(Character* teammate, Team* ennemyTeam){
    Character* target = nullptr;
    double min_ennemy_dist = std::numeric_limits<double>::max();
    for (Character* player : ennemyTeam->getVec()) {
        if (player->isAlive() && teammate->isAlive() && player->distance(teammate) < min_ennemy_dist) {
            min_ennemy_dist = player->distance(teammate);
            target = player;
        }
    }
    return target;
}

int ariel::SmartTeam::numOfNinjaEnnemy(ariel::Team* ennemyTeam){
    int numOfNinja = 0;
    for (Character* player : ennemyTeam->getVec()) {
        if (player->isNinja()) {
            numOfNinja++;
        }
    }
    return numOfNinja;
}

ariel::Character* ariel::SmartTeam::getCloserNinjaEnnemy(Character* Teammate, Team* ennemyTeam){
    Character* target = nullptr;
    double min_dist_ninja = std::numeric_limits<double>::max();
    for (Character* player : ennemyTeam->getVec() ) {
       if (player->isAlive() && player->isNinja() && player->distance(Teammate) < min_dist_ninja ) {
            min_dist_ninja = player->distance(Teammate);
            target = player;
       } 
    }
    return target;
}


ariel::Character* ariel::SmartTeam::getCloserToTheTeamTarget(Team* ennemyTeam){
    Character* teamTarget = ennemyTeam->getCloserFromLeaderExtern(this);
    Character* ennemyTarget = nullptr;
    double min_dist_ninja = std::numeric_limits<double>::max();
    for (Character* player : ennemyTeam->getVec() ) {
       if (player->isAlive() && player->isNinja() && player->distance(teamTarget) < min_dist_ninja ) {
            min_dist_ninja = player->distance(teamTarget);
            ennemyTarget = player;
       } 
    }
    return ennemyTarget;
}



//THE NINJA'S KILL THE CLOSER TO THEM , THE COWBOY THE WEAKER ~68% winrate
void ariel::SmartTeam::attack(Team* ennemyTeam){
    this->attackErrorHandler(ennemyTeam);
    this->liveReplacement(ennemyTeam);
    if (ennemyTeam != nullptr && ennemyTeam->stillAlive()!=0) {
        for (ariel::Character* player : this->getVec()) {
            this->liveReplacement(ennemyTeam);
            ariel::Character* new_victim = nullptr;
            if (player->isNinja()) {
                 new_victim = this->getCloserEnnemy(player, ennemyTeam) ;
            }else {
                 new_victim = this->getWeakerEnnemy(ennemyTeam) ;
            }
            if (new_victim!=nullptr) {
                if (player!=nullptr && player->isAlive() && new_victim->isAlive()) {
                    player->attack(new_victim);
                }
            }else {

            }
        }
    }
}
//
//
// void ariel::SmartTeam::attack(Team* ennemyTeam){
//     this->attackErrorHandler(ennemyTeam);
//     this->liveReplacement(ennemyTeam);
//     if (ennemyTeam != nullptr && ennemyTeam->stillAlive()!=0) {
//         for (ariel::Character* player : this->getVec()) {
//             this->liveReplacement(ennemyTeam);
//             ariel::Character* new_victim = nullptr;
//             if (this->numOfNinjaEnnemy(ennemyTeam) > 0 ) {
//                  new_victim = this->getCloserToTheTeamTarget( ennemyTeam) ;
//             }else {
//                  new_victim = this->getWeakerEnnemy(ennemyTeam) ;
//             }
//             if (new_victim!=nullptr) {
//                 if (player!=nullptr && player->isAlive() && new_victim->isAlive()) {
//                     player->attack(new_victim);
//                 }
//             }else {
//             std::cout << "nullptr" << std::endl;
//             }
//         }
//     }
// }
