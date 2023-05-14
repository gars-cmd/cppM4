#include "Cowboy.hpp"
#include "Character.hpp"
#include "Point.hpp"
#include <iostream>
#include <string>

#define MAGAZINE_CAPACITY 6
#define COWBOY_HP 110

using namespace ariel;

ariel::Cowboy::~Cowboy() {}

ariel::Cowboy::Cowboy() {
  this->name = "UNKNOWN";
  this->healthPoint = COWBOY_HP;
  this->bullet_ammount = MAGAZINE_CAPACITY;
  this->location = ariel::Point();
}

ariel::Cowboy::Cowboy(const std::string name, ariel::Point location) {
    this->name = name;
    this->healthPoint = COWBOY_HP;
    this->bullet_ammount = MAGAZINE_CAPACITY;
    this->location = location;
}

ariel::Cowboy::Cowboy(const std::string name){
    this->name = name;
    this->healthPoint = COWBOY_HP;
    this->bullet_ammount = MAGAZINE_CAPACITY;
    this->location = ariel::Point();
}

ariel::Cowboy::Cowboy(ariel::Point location){
    this->name = "UNKNOWN";
    this->healthPoint = COWBOY_HP;
    this->bullet_ammount = MAGAZINE_CAPACITY;
    this->location = location;
}

int ariel::Cowboy::getBulletAmmount() const{ return this->bullet_ammount; }

void ariel::Cowboy::reload(){this->bullet_ammount = MAGAZINE_CAPACITY;}

bool ariel::Cowboy::hasBullets() const{return (this->bullet_ammount > 0 ? true : false);}

void ariel::Cowboy::shoot(ariel::Character *other){
    if (this->isAlive() && this->hasBullets()) {
        other->hit(10);
        this->bullet_ammount --;
    }
}

std::string ariel::Cowboy::print() const{
    if (this->isAlive()) { 
        return  "C-"+ this->name + ","
            + std::to_string(this->healthPoint)
            + ","
            + (this->location.toString())
            + "." ;
    }else{
        return "";
    }
}


