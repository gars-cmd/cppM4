#ifndef NINJA_HPP
#define NINJA_HPP

#include "point.hpp"
#include "character.hpp"
#include <iostream>
#include <string>

namespace ariel {

class Ninja : public Character {
protected:
    int speed;

public:
    Ninja();
    ~Ninja();
    Ninja(std::string name);
    Ninja(std::string name, ariel::Point location);
    Ninja(ariel::Point location);
    int getSpeed() const;
    void print() const;
    void move(Character* other);
    void slash(Character* other);
};

}
#endif // NINJA
