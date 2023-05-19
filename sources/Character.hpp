#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Point.hpp"
#include <iostream>
#include <string>

namespace ariel {


class Character {
protected:
    ariel::Point location;
    int healthPoint;
    std::string name;
    bool boolTeamMember = false;
    bool boolIsNinja = false;

public:
    Character();
    virtual ~Character();
    ariel::Point getLocation() const;
    void setLocation(ariel::Point new_location);
    int getHealthPoint() const;
    bool isATeamMember() const;
    bool isNinja() const;
    void setTeamMember();
    void setHealthPoint(int newPoint );
    std::string getName() const;
    void  setName(std::string new_name);
    bool isAlive() const;
    double distance(Character* other) const;
    void hit(int damage_points);
    virtual std::string print() const = 0;
};

}
#endif // CHARACTER
