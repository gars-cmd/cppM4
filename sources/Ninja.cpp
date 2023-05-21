#include "Cowboy.hpp"
#include "Character.hpp"
#include "Ninja.hpp"
#include "Point.hpp"
#include <iostream>
#include <stdexcept>
#include <string>


ariel::Ninja::~Ninja() {}

ariel::Ninja::Ninja() {
    this->name = "UNKNOWN";
    this->location = ariel::Point();
    this->boolIsNinja = true;
    this->speed = 0;
    this->healthPoint = 0;
}

void ariel::Ninja::slash(Character *other){
    if (!(this->isAlive() && other->isAlive() && this!=other)) {
        throw std::runtime_error("the ninja or the target is already dead");
    }
    if (this->distance(other) < 1) {
        other->hit(40);
    }
}

int ariel::Ninja::getSpeed()const{
    return this->speed;
}

void ariel::Ninja::move(Character *other){
    ariel::Point new_location = ariel::Point::moveTowards(this->getLocation(), other->getLocation(), this->getSpeed());
    this->setLocation(new_location);
}

void ariel::Ninja::attack(ariel::Character* other){
    this->slash(other);
}

std::string ariel::Ninja::print() const{
    if (this->isAlive()) { 
        return  "N-" 
            +  this->name 
            + ","
            + std::to_string(this->healthPoint)
            + ","
            + (this->location.toString()) 
            + "." ;
    }else {
        return "";
    }
}





