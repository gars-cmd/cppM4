#include "Character.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "Point.hpp"
#include <iostream>
#include <string>



ariel::YoungNinja::YoungNinja(const std::string& name , const Point& location , int speed , int healthPoint)
: ariel::Ninja(name, location, speed, healthPoint){}
