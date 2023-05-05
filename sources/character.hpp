#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "point.hpp"
#include <iostream>
#include <string>

namespace ariel {

class Character {
protected:
    ariel::Point location;
    int healthPoint;
    std::string name;

public:
    Character();
    ~Character();
    ariel::Point getLocation() const;
    void setLocation(ariel::Point new_location);
    int getHealthPoint() const;
    void setHealthPoint(int newPoint );
    std::string getName() const;
    void  setName(std::string new_name);
    bool isAlive() const;
    double distance(Character* other) const;
    void hit(int damage_points);
    void print() const;


};

}
#endif // CHARACTER
