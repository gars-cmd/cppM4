#include "character.hpp"
#include "ninja.hpp"
#include "youngninja.hpp"
#include "point.hpp"
#include <iostream>
#include <string>


#define YOUNG_SPEED 14
#define YOUNG_HP 100

ariel::YoungNinja::YoungNinja(){
    this->name = "UNKNOWN";
    this->location = ariel::Point();
    this->speed = YOUNG_SPEED;
    this->healthPoint = YOUNG_HP;
}

ariel::YoungNinja::YoungNinja(const std::string name, ariel::Point location){
    this->speed = YOUNG_SPEED;
    this->healthPoint = YOUNG_HP;
    this->location = location;
    this->name = name;
}


ariel::YoungNinja::YoungNinja(ariel::Point location){
    this->speed = YOUNG_SPEED;
    this->healthPoint = YOUNG_HP;
    this->location = location;
    this->name = "UKNOWN";
}


ariel::YoungNinja::YoungNinja(const std::string name){
    this->speed = YOUNG_SPEED;
    this->healthPoint = YOUNG_HP;
    this->location = ariel::Point();
    this->name = name;
}
