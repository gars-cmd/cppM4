#pragma once
#ifndef COWBOY_HPP
#define COWBOY_HPP

#include "Point.hpp"
#include "Character.hpp"
#include <iostream>
#include <string>

constexpr int COWBOY_HP = 110;

namespace ariel {

class Cowboy : public Character {
private:
    int bullet_ammount;

public:
    Cowboy(const std::string& name = "UNKNOWN", const Point& location = Point(), int healthPoint = COWBOY_HP);

    int getBulletAmmount() const;
    std::string print() const override;
    bool hasboolets() const;
    void reload();
    void shoot( ariel::Character* other) ;
    void attack( ariel::Character* other) override;
};

}
#endif // COWBOY
