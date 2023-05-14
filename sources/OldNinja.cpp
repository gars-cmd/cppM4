#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "Point.hpp"
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

ariel::OldNinja::OldNinja(const std::string name, ariel::Point location){
    this->speed = OLD_SPEED;
    this->healthPoint = OLD_HP;
    this->location = location;
    this->name = name;
}


ariel::OldNinja::OldNinja(ariel::Point location){
    this->speed = OLD_SPEED;
    this->healthPoint = OLD_HP;
    this->location = location;
    this->name = "UNKNOWN";
}


ariel::OldNinja::OldNinja( const std::string name){
    this->speed = OLD_SPEED;
    this->healthPoint = OLD_HP;
    this->location = ariel::Point();
    this->name = name;
}
