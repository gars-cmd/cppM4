#include <algorithm>
#include <iostream>
#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"
#include "Ninja.hpp"
#include "Cowboy.hpp"
#include "Team.hpp"
#include <limits>
#include <iostream>
#include <stdexcept>
#include <vector>


using namespace ariel;

ariel::Team::~Team(){
    for (ariel::Character* player : this->vectorTeam()) {
        delete player;
    }
}

ariel::Team::Team( ariel::Character* leader){
    this->leader = leader;
    this->vectorTeam().resize(10,nullptr); //resize to 10 and fill everything with nullptr
    this->vectorTeam().push_back(leader);
    this->size = 1;
}

int ariel::Team::getSize() const{
    return  this->size;
}

std::vector<Character*> ariel::Team::getVec(){
    return this->vectorTeam();
}

void ariel::Team::add(ariel::Character* new_player){
    if (this->size > 10) {
        throw std::runtime_error("the team is already full");
    } else if (new_player->isATeamMember()) {
        throw std::invalid_argument("the member is already in a team");
    }
    else {
        new_player->setTeamMember();
        this->vectorTeam().push_back(new_player);
        this->size++;
    }
}

void ariel::Team::setSize(int newSize){
    this->size = newSize;
}

ariel::Character* ariel::Team::getLeader() const{
    return this->leader;
}

void ariel::Team::setLeader(ariel::Character &leader){
    this->leader = &leader;
}

int ariel::Team::indexOfLastSortedCowboy() {
    int pos = 0;
    while ( (!this->vectorTeam()[pos]->isNinja()) && (pos < this->size) ) {
        pos++;
    }
    return pos;
}

void ariel::Team::sort(){
    int lastSortedCowboy = this->indexOfLastSortedCowboy();
    for (int i = lastSortedCowboy ; i<this->size ; i++) {
        if (!player->isNinja()) {
            this->vectorTeam().insert()
        }
    
    }

}

bool ariel::Team::isLeaderAlive(){
    return this->leader->getHealthPoint() > 0;
}

void ariel::Team::replaceLeader(){
    ariel::Point oldLeaderPos = this->leader->getLocation();
    ariel::Character* newLeader = this->getCloserFromLeader();
    this->setLeader(*newLeader);
}

ariel::Character* ariel::Team::getCloserFromLeader(){
    ariel::Character* theCloser = nullptr;
    double minDistance = std::numeric_limits<double>::max();
    for (ariel::Character* player : this->vectorTeam()) {
        if ( (this->leader != player) && (player->isAlive()) ) {
            double tempDistance = player->distance(this->leader);
            if (minDistance > tempDistance) {
                minDistance = tempDistance;
                theCloser = player;
            }
        }
    }
    return theCloser;
}

int ariel::Team::stillAlive(){
    int counter = 0;
    for (ariel::Character* player : this->vectorTeam()) {
        if (player->getHealthPoint() > 0) {
            counter++;
        }
    }
    return counter;
}

void ariel::Team::print(){
    for (ariel::Character* player : this->vectorTeam()) {
        player->print();
    }
}

void ariel::Team::attack(ariel::Team *ennemyTeam){
    if (!ennemyTeam->isLeaderAlive()) {
        ennemyTeam->replaceLeader();
    }
    //TODO need to implement the rest
}










