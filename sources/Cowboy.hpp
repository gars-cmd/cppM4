#ifndef COWBOY_HPP
#define COWBOY_HPP

#include "Point.hpp"
#include "Character.hpp"
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
    std::string print() const override;
    bool hasboolets() const;
    void reload();
    void shoot( ariel::Character* other) ;
    void attack( ariel::Character* other) override;
};

}
#endif // COWBOY
