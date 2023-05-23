#include "Cowboy.hpp"
#include "Character.hpp"
#include "Ninja.hpp"
#include "Point.hpp"
#include <iostream>
#include <stdexcept>
#include <string>



ariel::Ninja::Ninja(const std::string& name, const Point& location, int speed, int healthPoint) 
: ariel::Character(name, location, healthPoint), speed(speed){this->setNinja();}

void ariel::Ninja::slash(Character *other){
    this->charErrorHandler(other);
    if (this->distance(other) <=1 ) {
        other->hit(40);
    }
}

int ariel::Ninja::getSpeed()const{
    return this->speed;
}

void ariel::Ninja::setSpeed(int speed){
     this->speed = speed;
}

void ariel::Ninja::move(Character *other){
    ariel::Point new_location = ariel::Point::moveTowards(this->getLocation(), other->getLocation(), this->getSpeed());
    this->setLocation(new_location);
}

void ariel::Ninja::attack(ariel::Character* other){
    if (this->distance(other) <= 1) {
        this->slash(other);
    }else {
    this->move(other);
    }
}

std::string ariel::Ninja::print() const{
    if (this->isAlive()) { 
        return  "N-" 
        +  this->getName()
        + ","
        + std::to_string(this->getHealthPoint())
        + ","
        + (this->getLocation().toString()) 
        + "." ;
    }else {
        return "";
    }
}





