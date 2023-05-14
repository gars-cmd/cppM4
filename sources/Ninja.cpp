#include "Cowboy.hpp"
#include "Character.hpp"
#include "Ninja.hpp"
#include "Point.hpp"
#include <iostream>
#include <string>


ariel::Ninja::~Ninja() {}

ariel::Ninja::Ninja() {
    this->name = "UNKNOWN";
    this->location = ariel::Point();
    this->speed = 0;
    this->healthPoint = 0;
}

void ariel::Ninja::slash(Character *other){
    if (this->isAlive() && this->distance(other) < 1) {
        other->hit(40);
    }
}

int ariel::Ninja::getSpeed()const{
    return this->speed;
}

void ariel::Ninja::move(Character *other){
    //TODO implementation
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





