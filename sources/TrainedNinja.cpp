#include "character.hpp"
#include "ninja.hpp"
#include "trainedninja.hpp"
#include "point.hpp"
#include <iostream>
#include <string>


#define TRAINED_SPEED 12
#define TRAINED_HP 120

ariel::TrainedNinja::TrainedNinja(){
    this->name = "UNKNOWN";
    this->location = ariel::Point();
    this->speed = TRAINED_SPEED;
    this->healthPoint = TRAINED_HP;
}

ariel::TrainedNinja::TrainedNinja(const std::string name, ariel::Point location){
    this->speed = TRAINED_SPEED;
    this->healthPoint = TRAINED_HP;
    this->location = location;
    this->name = name;
}


ariel::TrainedNinja::TrainedNinja(ariel::Point location){
    this->speed = TRAINED_SPEED;
    this->healthPoint = TRAINED_HP;
    this->location = location;
    this->name = "UKNOWN";
}


ariel::TrainedNinja::TrainedNinja(const std::string name){
    this->speed = TRAINED_SPEED;
    this->healthPoint = TRAINED_HP;
    this->location = ariel::Point();
    this->name = name;
}
