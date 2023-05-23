#ifndef NINJA_HPP
#define NINJA_HPP

#include "Point.hpp"
#include "Character.hpp"
#include <iostream>
#include <string>

namespace ariel {

class Ninja : public ariel::Character {
private:
    int healthPoint;
    int speed;
public:
    Ninja(const std::string& name = "UNKNOWN", const Point& location = Point(), int speed = 0, int healthPoint = 0);
    int getSpeed() const;
    std::string print() const override;
    void setSpeed(int speed);
    void move(Character* other);
    void slash(Character* other);
    void attack(Character* other) override;
};

}
#endif // NINJA
