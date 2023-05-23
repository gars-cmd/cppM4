#ifndef TRAINEDNINJA
#define TRAINEDNINJA


#include "Character.hpp"
#include "Ninja.hpp"
#include "Point.hpp"
#include <iostream>
#include <string>


constexpr int  TRAINED_SPEED =  12;
constexpr int  TRAINED_HP = 120;

namespace ariel {

class TrainedNinja : public ariel::Ninja {
private:
    int speed;
    int healthPoint;
public:
    TrainedNinja(const std::string& name = "UNKNOWN", const Point& location = Point(), int speed = TRAINED_SPEED, int healthPoint = TRAINED_HP);
    // TrainedNinja();
    // TrainedNinja(std::string name, ariel::Point location);
    // TrainedNinja(std::string name);
    // TrainedNinja(ariel::Point location);
};

} // namespace ariel
#endif //TRAINEDNINJA
