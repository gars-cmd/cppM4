#include <iostream>
#include "point.hpp"
#include "character.hpp"

using namespace ariel;

ariel::Character::~Character(){}

ariel::Character::Character(){
    this->name = "UNKNOWN";
    this->healthPoint = 0;
    this->location = ariel::Point();
}

std::string ariel::Character::getName() const{return this->name;}

void ariel::Character::setName(std::string new_name){ this->name = new_name; }

int ariel::Character::getHealthPoint() const{return this->healthPoint;}

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
    return this->location.distance(this->location);
}

void ariel::Character::hit(int damage_points){
    this->healthPoint = (damage_points > this->healthPoint ? 0 : this->healthPoint - damage_points);
}





