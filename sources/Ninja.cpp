#include "cowboys.hpp"
#include "character.hpp"
#include "ninja.hpp"
#include "point.hpp"
#include <iostream>
#include <string>


ariel::Ninja::~Ninja() {}


void ariel::Ninja::slash(Character *other){
    if (this->isAlive() && this->distance(other) <= 1) {
        other->hit(31);
    }
}

void ariel::Ninja::move(Character *other){
    //TODO implementation
}

void ariel::Ninja::print() const{
    if (this->isAlive()) { 
        std::cout << "N-" <<  this->name << ","
                << this->healthPoint << ","
                << (this->location.toString()) << "." << "\n";
    }
}





