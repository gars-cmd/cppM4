
#ifndef YOUNGNINJA
#define YOUNGNINJA

#include "Character.hpp"
#include "Ninja.hpp"
#include "Point.hpp"
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

#endif //YOUNGNINJA
