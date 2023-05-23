
#ifndef YOUNGNINJA
#define YOUNGNINJA

#include "Character.hpp"
#include "Ninja.hpp"
#include "Point.hpp"
#include <iostream>
#include <string>


constexpr int YOUNG_SPEED = 14;
constexpr int YOUNG_HP =  100;

namespace ariel {

class YoungNinja : public Ninja {
private:
    int speed;
    int healthPoint;
public:
    YoungNinja(const std::string& name = "UNKNOWN", const Point& location = Point(), int speed = YOUNG_SPEED, int healthPoint = YOUNG_HP);
};

} // namespace ariel

#endif //YOUNGNINJA
