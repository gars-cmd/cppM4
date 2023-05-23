#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "Point.hpp"
#include <iostream>
#include <string>


ariel::OldNinja::OldNinja(const std::string& name, const Point& location, int speed, int healthPoint)
: ariel::Ninja(name, location, speed, healthPoint){}

