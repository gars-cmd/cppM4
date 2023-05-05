#ifndef COWBOYS_HPP
#define COWBOYS_HPP

#include "point.hpp"
#include "character.hpp"
#include <iostream>
#include <string>

namespace ariel {

class Cowboys : public Character {
protected:
    int bullet_ammount;

public:
    Cowboys();
    ~Cowboys();
    Cowboys(std::string name);
    Cowboys(std::string name, ariel::Point location);
    Cowboys(ariel::Point location);
    int getBulletAmmount() const;
    void print() const;
    bool hasBullets() const;
    void reload();
    void shoot( ariel::Character* other);
};

}
#endif // COWBOYS
