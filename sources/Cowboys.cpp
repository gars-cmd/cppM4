#include "cowboys.hpp"
#include "character.hpp"
#include "point.hpp"
#include <iostream>
#include <string>

#define MAGAZINE_CAPACITY 6

using namespace ariel;

ariel::Cowboys::~Cowboys() {}

ariel::Cowboys::Cowboys() {
  this->name = "UKNOWN";
  this->healthPoint = 11;
  this->bullet_ammount = MAGAZINE_CAPACITY;
  this->location = ariel::Point();
}

ariel::Cowboys::Cowboys(std::string name, ariel::Point location) {
    this->name = name;
    this->healthPoint = 11;
    this->bullet_ammount = MAGAZINE_CAPACITY;
    this->location = location;
}

ariel::Cowboys::Cowboys(std::string name){
    this->name = name;
    this->healthPoint = 11;
    this->bullet_ammount = MAGAZINE_CAPACITY;
    this->location = ariel::Point();
}

ariel::Cowboys::Cowboys(ariel::Point location){
    this->name = "UNKNOWN";
    this->healthPoint = 11;
    this->bullet_ammount = MAGAZINE_CAPACITY;
    this->location = location;
}

int ariel::Cowboys::getBulletAmmount() const{ return this->bullet_ammount; }

void ariel::Cowboys::reload(){this->bullet_ammount = MAGAZINE_CAPACITY;}

bool ariel::Cowboys::hasBullets() const{return (this->bullet_ammount > 0 ? true : false);}

void ariel::Cowboys::shoot(ariel::Character *other){
    if (this->isAlive() && this->hasBullets()) {
        other->setHealthPoint(this->healthPoint-=1);
        this->bullet_ammount --;
    }
}

void ariel::Cowboys::print() const{
    if (this->isAlive()) { 
        std::cout << "C-"<< this->name << ","
                << this->healthPoint << ","
                << (this->location.toString()) << "." << "\n";
    }
}


