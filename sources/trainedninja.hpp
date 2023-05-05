#include "character.hpp"
#include "ninja.hpp"
#include "point.hpp"
#include <iostream>
#include <string>



namespace ariel {

class TrainedNinja : public Ninja {
public:
    TrainedNinja();
    TrainedNinja(std::string name, ariel::Point location);
    TrainedNinja(std::string name);
    TrainedNinja(ariel::Point location);
};

} // namespace ariel

