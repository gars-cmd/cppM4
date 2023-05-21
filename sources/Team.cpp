#include <algorithm>
#include <cstddef>
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

static int nextId = 0 ;

ariel::Team::~Team(){
    for (ariel::Character* player : this->vectorTeam) {
        delete player;
    }
}

ariel::Team::Team( ariel::Character* leader){
    this->leader = leader;
    this->vectorTeam.reserve(10); //resize to 10 and fill everything with nullptr
    this->id = nextId++;
    this->add(leader);
    this->size = 1;
}

int ariel::Team::getSize() const{
    return  this->size;
}

std::vector<Character*> ariel::Team::getVec(){
    return this->vectorTeam;
}

void ariel::Team::add(ariel::Character* new_player){
    if (this->size >= 10) {
        throw std::runtime_error("the team is already full");
    } else if (new_player->isATeamMember()) {
        throw std::runtime_error("the member is already in a team");
    }
    else {
        new_player->setTeamMember(this->id);
        this->vectorTeam.push_back(new_player);
        this->size++;
    }
    this->sort();
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

std::size_t ariel::Team::indexOfLastSortedCowboy() {
    if (this->vectorTeam.size()== 0) {
        std::cout << "the vector is empty" << '\n';
    }
    std::size_t pos = 0;
    while ( (!this->vectorTeam.at(pos)->isNinja()) && (pos <= this->size) ) {
        pos++;
    }
    return ( pos-1 );
}

void ariel::Team::moveSaveAddOrder(std::size_t last_continues_cowboy_index, std::size_t next_cowboy_index){
    std::vector<ariel::Character*> tmpCharToMove = {};
    std::size_t index = last_continues_cowboy_index+1;
    while (this->vectorTeam.at(index)->isNinja()) {
        tmpCharToMove.push_back(this->vectorTeam.at(index));
        index++;
    }
    if (index == next_cowboy_index) {
        this->vectorTeam.at(last_continues_cowboy_index+1)=this->vectorTeam.at(next_cowboy_index);
    }
    std::copy(tmpCharToMove.begin(),tmpCharToMove.end(),this->vectorTeam.begin()
              + static_cast<std::vector<Character*>::difference_type>(last_continues_cowboy_index)+2);
}

std::size_t ariel::Team::firstNinjaIndex(){
    std::size_t size = this->vectorTeam.size();
    for (std::size_t i = 0; i< size ; i++) {
        if (this->vectorTeam.at(i)->isNinja()) {
            return i;
        }
    }
    return size;
}

bool ariel::Team::isSorted(){
    std::size_t index = firstNinjaIndex();
    while (index < this->vectorTeam.size()) {
        if (!this->vectorTeam.at(index)->isNinja()) {
            return false;
        }
        index++;
    }
    return true;
}

void ariel::Team::sort(){
    if (!this->isSorted()) {
        std::size_t lastSortedCowboy = this->indexOfLastSortedCowboy();
        for (std::size_t i = lastSortedCowboy+1 ; i<this->size ; i++) {
            if (!this->vectorTeam.at(i)->isNinja()) {
                this->moveSaveAddOrder(lastSortedCowboy, i);
            }
        }
    }
}

bool ariel::Team::isLeaderAlive(){
    return this->leader->getHealthPoint() > 0;
}

void ariel::Team::replaceLeader(){
    ariel::Point oldLeaderPos = this->leader->getLocation();
    ariel::Character* newLeader = this->getCloserFromLeaderIntern();
    this->setLeader(*newLeader);
}

ariel::Character* ariel::Team::getCloserFromLeaderIntern(){
    ariel::Character* theCloser = nullptr;
    double minDistance = std::numeric_limits<double>::max();
    for (ariel::Character* player : this->vectorTeam) {
        if ( (player->isAlive()) ) {
            double tempDistance = player->distance(this->leader);
            if (minDistance > tempDistance) {
                minDistance = tempDistance;
                theCloser = player;
            }
        }
    }
    return theCloser;
}

ariel::Character* ariel::Team::getCloserFromLeaderExtern(ariel::Team* otherTeam){
    ariel::Character* theCloser = nullptr;
    double minDistance = std::numeric_limits<double>::max();
    for (ariel::Character* player : otherTeam->vectorTeam) {
        if ( (player->isAlive()) ) {
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
    for (ariel::Character* player : this->vectorTeam) {
        if (player->getHealthPoint() > 0) {
            counter++;
        }
    }
    return counter;
}

void ariel::Team::print(){
    for (ariel::Character* player : this->vectorTeam) {
        std::cout << player->print() << '\n';
    }
}


void ariel::Team::attack(ariel::Team *ennemyTeam){
    if (ennemyTeam == nullptr) {
        throw std::invalid_argument("nullptr was given");
    }
    if (ennemyTeam->stillAlive() == 0) {
        std::cout << "there is no ennemy" << std::endl;
    }else {
        if (!ennemyTeam->isLeaderAlive()) {
            ennemyTeam->replaceLeader();
        }
        ariel::Character* new_victim = this->getCloserFromLeaderExtern(ennemyTeam);
        for (ariel::Character* player : this->vectorTeam) {
            player->attack(new_victim);
            if (new_victim->getHealthPoint() == 0) {
                new_victim = this->getCloserFromLeaderExtern(ennemyTeam);
            }
        }
    }
}










