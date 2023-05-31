#include <algorithm>
#include <cstddef>
#include <cstdlib>
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
    this->vectorTeam.reserve(10);
    this->id = nextId++;
    this->add(leader);
    this->size = 1;
}

//Copy constructor
Team::Team(const Team& other) {
    leader = nullptr;
    *this = other;
}

// Copy assignment operator
Team& Team::operator=(const Team& other) {
    if (this == &other) {
        return *this;
    }
    for (ariel::Character* player : vectorTeam) {
        delete player;
    }
    vectorTeam.clear();

    for (ariel::Character* player : other.vectorTeam) {
        if (player->isNinja()) {
            vectorTeam.push_back(new ariel::Ninja(*dynamic_cast<Ninja*>(player)));
        }else {
            vectorTeam.push_back(new ariel::Cowboy(*dynamic_cast<Cowboy*>(player)));
        }
    }
    leader = nullptr;
    for (Character* player : vectorTeam) {
        if (player->getTeamID() == other.leader->getTeamID()) {
            leader = player;
        }
        player->setTeamMember(id);
    }
    size = other.size;
    return *this;
}

// Move constructor
Team::Team(Team&& other) noexcept
: vectorTeam(std::move(other.vectorTeam)), leader(other.leader), id(other.id), size(other.size) {
    other.leader = nullptr;
    other.id = 0;
    other.size = 0;
}

// Move assignment operator
Team& Team::operator=(Team&& other) noexcept {
    if (this == &other) {
        return *this;
    }
    for (Character* player : vectorTeam) {
        delete player;
    }
    vectorTeam.clear();
    vectorTeam = std::move(other.vectorTeam);
    leader = other.leader;
    for (Character* player : vectorTeam) {
        player->setTeamMember(id);
    }
    other.leader = nullptr;
    other.id = 0;
    other.size = 0;
    return *this;
}


int ariel::Team::getSize() const{
    return  this->size;
}

std::vector<Character*> ariel::Team::getVec(){
    return this->vectorTeam;
}

void ariel::Team::addErrorHandler(ariel::Character* new_player){
    if (this->size >= 10) {
        throw std::runtime_error("the team is already full");
    }else if(new_player->isATeamMember()){
        throw std::runtime_error("the member is already in a team");
    }else {}
}

void ariel::Team::add(ariel::Character* new_player){
    this->addErrorHandler(new_player);
    new_player->setTeamMember(this->id);
    this->vectorTeam.push_back(new_player);
    this->size++;
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
        return std::numeric_limits<std::size_t>::max();
    }else {
        std::size_t pos = 0;
        while ( (!this->vectorTeam.at(pos)->isNinja()) && (pos <= this->size) ) {
            pos++;
        }
        return ( pos-1 );
    }
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
        if (lastSortedCowboy < 10) {
            for (std::size_t i = lastSortedCowboy+1 ; i<this->size ; i++) {
                if (!this->vectorTeam.at(i)->isNinja()) {
                    this->moveSaveAddOrder(lastSortedCowboy, i);
                }
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
        if ( player->isAlive() ) {
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

void ariel::Team::attackErrorHandler(ariel::Team *ennemyTeam){
    if (ennemyTeam == nullptr) {
        throw std::invalid_argument("ennemy team = nullptr");
    }else if (ennemyTeam->stillAlive() == 0) {
        throw std::runtime_error("ennemyTeam is dead");
    }
}

void ariel::Team::liveReplacement(ariel::Team *ennemyTeam){
    if (!this->isLeaderAlive() && (this->getCloserFromLeaderIntern() != nullptr) ) {
        this->replaceLeader();
    }
    if (!ennemyTeam->isLeaderAlive() && ennemyTeam->getCloserFromLeaderIntern()!=nullptr) {
        ennemyTeam->replaceLeader();
    }
}


void ariel::Team::attack(ariel::Team *ennemyTeam){
    this->attackErrorHandler(ennemyTeam);
    this->liveReplacement(ennemyTeam);
    if (ennemyTeam != nullptr && ennemyTeam->stillAlive()!=0) {
        for (ariel::Character* player : this->vectorTeam) {
            this->liveReplacement(ennemyTeam);
            ariel::Character* new_victim = this->getCloserFromLeaderExtern(ennemyTeam);
            if (new_victim!=nullptr) {
                if (player!=nullptr && player->isAlive() && new_victim->isAlive()) {
                    player->attack(new_victim);
                }
            }else {
            }
        }
    }
}










