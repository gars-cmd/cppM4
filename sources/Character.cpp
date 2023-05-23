#include <iostream>
#include <stdexcept>
#include "Point.hpp"
#include "Character.hpp"

using namespace ariel;

ariel::Character::~Character(){}

ariel::Character::Character(const std::string& name, const Point& location, int healthPoint)
: name{name}, location{location}, healthPoint{healthPoint}{}

ariel::Character::Character(const Character& other)
: location(other.location), healthPoint(other.healthPoint), name(other.name),
  TeamId(other.TeamId), boolIsNinja(other.boolIsNinja) {}

ariel::Character& ariel::Character::operator=(const Character& other) {
    if (this != &other) {
        location = other.location;
        healthPoint = other.healthPoint;
        name = other.name;
        TeamId = other.TeamId;
        boolIsNinja = other.boolIsNinja;
    }
    return *this;
}

ariel::Character::Character(Character&& other) noexcept
: location(std::move(other.location)), healthPoint(other.healthPoint),
  name(std::move(other.name)), TeamId(other.TeamId), boolIsNinja(other.boolIsNinja) {
    other.healthPoint = 0;
    other.TeamId = -1;
    other.boolIsNinja = false;
}

ariel::Character& ariel::Character::operator=(Character&& other) noexcept{
    if (this != &other) {
        location = std::move(other.location);
        healthPoint = other.healthPoint;
        name = std::move(other.name);
        TeamId = other.TeamId;
        boolIsNinja = other.boolIsNinja;

        other.healthPoint = 0;
        other.TeamId = -1;
        other.boolIsNinja = false;
    }
    return *this;
}

int ariel::Character::getTeamID() const{
    return this->TeamId;
}

std::string ariel::Character::getName() const{
    return this->name;
}

void ariel::Character::setName(const std::string& new_name){
    this->name = new_name; 
}

int ariel::Character::getHealthPoint() const{
    return this->healthPoint;
}

bool ariel::Character::isATeamMember() const{
    return this->TeamId != -1;
}

void ariel::Character::setTeamMember(int new_id){
    this->TeamId = new_id;
}

bool ariel::Character::isNinja() const{
    return this->boolIsNinja;
}

void ariel::Character::setHealthPoint(int newPoint){
    this->healthPoint = newPoint;
}

ariel::Point ariel::Character::getLocation() const{
    return this->location;
}

void ariel::Character::setNinja(){
    this->boolIsNinja = true;
}

void ariel::Character::setLocation(ariel::Point new_location){
    this->location = new_location;
}

bool ariel::Character::isAlive() const{
    return this->getHealthPoint() > 0;
}
void ariel::Character::charErrorHandler(){
    if (!this->isAlive()) {
        throw std::runtime_error("the cowboy is dead");
    }
}

void ariel::Character::charErrorHandler(ariel::Character* other){
    if (!other->isAlive()) {
        throw std::runtime_error("the ennemy is already dead");
    }
    if (this == other) {
        throw std::runtime_error("self-harm");
    }
    this->charErrorHandler();
}

double ariel::Character::distance(Character *other) const{
    return this->location.distance(other->location);
}

void ariel::Character::hit(int damage_points){
    if (damage_points < 0) {
        throw std::invalid_argument("no negative dammage point allowed");
    }else {
        if ((this->getHealthPoint() - damage_points) <= 0) {
            this->setHealthPoint(0);
        }else {
            this->setHealthPoint(this->getHealthPoint()-damage_points);
        }
    }
}



