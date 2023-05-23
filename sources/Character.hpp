#pragma once
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Point.hpp"
#include <iostream>
#include <string>

namespace ariel {


class Character {
private:
    ariel::Point location;
    int healthPoint;
    std::string name;
    int TeamId = -1;
    bool boolIsNinja = false;

public:
    Character(const std::string& name = "UNKNOWN", const Point& location = Point(), int healthPoint = 0);
    virtual ~Character();
    Character(const Character& other);
    Character& operator=(const Character& other);
    Character(Character&& other) noexcept;
    Character& operator=(Character&& other) noexcept; 
    ariel::Point getLocation() const;
    void setLocation(ariel::Point new_location);
    void setHealthPoint(int newPoint );
    void setTeamMember(int new_id);
    int getTeamID() const;
    void setName(const std::string& new_name);
    void setNinja();
    int getHealthPoint() const;
    bool isATeamMember() const;
    bool isNinja() const;
    virtual void attack(Character* victim) = 0;
    std::string getName() const;
    bool isAlive() const;
    double distance(Character* other) const;
    void charErrorHandler(Character* other);
    void charErrorHandler();
    void hit(int damage_points);
    virtual std::string print() const = 0;
};

}
#endif // CHARACTER
