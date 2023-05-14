#ifndef OLDNINJA
#define OLDNINJA


#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "Point.hpp"
#include <iostream>
#include <string>



namespace ariel {

class OldNinja : public ariel::Ninja {
public:
    OldNinja();
    OldNinja(std::string name, ariel::Point location);
    OldNinja(std::string name);
    OldNinja(ariel::Point location);
};

} // namespace ariel

#endif // !OLDNINJA
