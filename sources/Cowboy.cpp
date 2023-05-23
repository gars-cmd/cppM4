#include "Cowboy.hpp"
#include "Character.hpp"
#include "Point.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

constexpr int MAGAZINE_CAPACITY = 6;


ariel::Cowboy::Cowboy(const std::string& name, const Point& location, int healthPoint) 
: ariel::Character(name, location, healthPoint), bullet_ammount(MAGAZINE_CAPACITY){}


int ariel::Cowboy::getBulletAmmount() const{ return this->bullet_ammount; }

void ariel::Cowboy::reload(){
    this->charErrorHandler();
    this->bullet_ammount = MAGAZINE_CAPACITY;
}

bool ariel::Cowboy::hasboolets() const{return (this->bullet_ammount > 0 ? true : false);}


void ariel::Cowboy::shoot(ariel::Character *other){
    this->charErrorHandler(other);
    if ( this->hasboolets()) {
        other->hit(10);
        this->bullet_ammount --;
    }
}

std::string ariel::Cowboy::print() const{
    if (this->isAlive()) { 
        return  "C-"+ this->getName() + ","
            + std::to_string(this->getHealthPoint())
            + ","
            + (this->getLocation().toString())
            + "." ;
    }else{
        return "";
    }
}

void ariel::Cowboy::attack(Character* other){
    if (this->hasboolets()) {
        this->shoot(other);
    }else {
        this->reload();
    }
}


