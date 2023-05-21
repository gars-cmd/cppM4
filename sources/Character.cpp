#include <iostream>
#include <stdexcept>
#include "Point.hpp"
#include "Character.hpp"

using namespace ariel;

ariel::Character::~Character(){}

ariel::Character::Character(){
    this->name = "UNKNOWN";
    this->healthPoint = 0;
    this->location = ariel::Point();
}

std::string ariel::Character::getName() const{return this->name;}

void ariel::Character::setName(const std::string new_name){ this->name = new_name; }

int ariel::Character::getHealthPoint() const{return this->healthPoint;}

bool ariel::Character::isATeamMember() const{return this->TeamId != -1;}

void ariel::Character::setTeamMember(int new_id){this->TeamId = new_id;}

bool ariel::Character::isNinja() const{
    return this->boolIsNinja;
}

void ariel::Character::setHealthPoint(int newPoint){
    this->healthPoint = newPoint;
}

ariel::Point ariel::Character::getLocation() const{return this->location;}

void ariel::Character::setLocation(ariel::Point new_location){
    this->location = new_location;
}

bool ariel::Character::isAlive() const{
    return (this->healthPoint > 0 ? true : false);
}

double ariel::Character::distance(Character *other) const{
    return this->location.distance(other->location);
}

void ariel::Character::hit(int damage_points){
    if (damage_points < 0) {
        throw std::invalid_argument("no negative dammage point allowed");
    }else {
        this->healthPoint = (damage_points > this->healthPoint ? 0 : this->healthPoint - damage_points);
    }
}



