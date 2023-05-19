#include "Character.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "Point.hpp"
#include <iostream>
#include <string>


#define YOUNG_SPEED 14
#define YOUNG_HP 100

ariel::YoungNinja::YoungNinja(){
    this->name = "UNKNOWN";
    this->location = ariel::Point();
    this->speed = YOUNG_SPEED;
    this->healthPoint = YOUNG_HP;
    this->isNinja = true;
}

ariel::YoungNinja::YoungNinja(const std::string name, ariel::Point location){
    this->speed = YOUNG_SPEED;
    this->healthPoint = YOUNG_HP;
    this->location = location;
    this->name = name;
    this->isNinja = true;
}


ariel::YoungNinja::YoungNinja(ariel::Point location){
    this->speed = YOUNG_SPEED;
    this->healthPoint = YOUNG_HP;
    this->location = location;
    this->name = "UNKNOWN";
    this->isNinja = true;
}


ariel::YoungNinja::YoungNinja(const std::string name){
    this->speed = YOUNG_SPEED;
    this->healthPoint = YOUNG_HP;
    this->location = ariel::Point();
    this->name = name;
    this->isNinja = true;
}
