#include "character.hpp"
#include "cowboys.hpp"
#include "ninja.hpp"
#include "point.hpp"
#include <iostream>
#include <string>



namespace ariel {

class OldNinja : public Ninja {
public:
    OldNinja();
    OldNinja(std::string name, ariel::Point location);
    OldNinja(std::string name);
    OldNinja(ariel::Point location);
};

} // namespace ariel

