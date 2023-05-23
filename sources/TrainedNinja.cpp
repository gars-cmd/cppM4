#include "Character.hpp"
#include "Ninja.hpp"
#include "TrainedNinja.hpp"
#include "Point.hpp"
#include <iostream>
#include <string>



ariel::TrainedNinja::TrainedNinja(const std::string& name , const Point& location, int speed, int healthPoint)
: ariel::Ninja(name, location, speed, healthPoint){}
