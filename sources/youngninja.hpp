#include "character.hpp"
#include "ninja.hpp"
#include "point.hpp"
#include <iostream>
#include <string>



namespace ariel {

class YoungNinja : public Ninja {
public:
    YoungNinja();
    YoungNinja(std::string name, ariel::Point location);
    YoungNinja(std::string name);
    YoungNinja(ariel::Point location);
};

} // namespace ariel

