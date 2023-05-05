#include "character.hpp"
#include "cowboys.hpp"
#include "ninja.hpp"
#include "oldninja.hpp"
#include "point.hpp"
#include <iostream>
#include <string>

#define OLD_SPEED 8
#define OLD_HP 150

ariel::OldNinja::OldNinja(){
    this->name = "UNKNOWN";
    this->location = ariel::Point();
    this->speed = OLD_SPEED;
    this->healthPoint = OLD_HP;
}

ariel::OldNinja::OldNinja(std::string name, ariel::Point location){
    this->speed = OLD_SPEED;
    this->healthPoint = OLD_HP;
    this->location = location;
    this->name = name;
}


ariel::OldNinja::OldNinja(ariel::Point location){
    this->speed = OLD_SPEED;
    this->healthPoint = OLD_HP;
    this->location = location;
    this->name = "UKNOWN";
}


ariel::OldNinja::OldNinja(std::string name){
    this->speed = OLD_SPEED;
    this->healthPoint = OLD_HP;
    this->location = ariel::Point();
    this->name = name;
}
