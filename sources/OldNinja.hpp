#ifndef OLDNINJA
#define OLDNINJA


#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "Point.hpp"
#include <iostream>
#include <string>


constexpr int OLD_SPEED = 8;
constexpr int OLD_HP = 150;

namespace ariel {

class OldNinja : public Ninja {
private:
    int speed;
    int healthPoint;
public:
    OldNinja(const std::string& name = "UNKNOWN", const Point& location = Point(), int speed = OLD_SPEED, int healthPoint = OLD_HP);
};

} // namespace ariel

#endif // !OLDNINJA
