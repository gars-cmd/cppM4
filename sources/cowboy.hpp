#ifndef COWBOY_HPP
#define COWBOY_HPP

#include "point.hpp"
#include "character.hpp"
#include <iostream>
#include <string>

namespace ariel {

class Cowboy : public Character {
protected:
    int bullet_ammount;

public:
    Cowboy();
    ~Cowboy();
    Cowboy(std::string name);
    Cowboy(std::string name, ariel::Point location);
    Cowboy(ariel::Point location);
    int getBulletAmmount() const;
    void print() const;
    bool hasBullets() const;
    void reload();
    void shoot( ariel::Character* other);
};

}
#endif // COWBOY
