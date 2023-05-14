#ifndef TRAINEDNINJA
#define TRAINEDNINJA


#include "Character.hpp"
#include "Ninja.hpp"
#include "Point.hpp"
#include <iostream>
#include <string>



namespace ariel {

class TrainedNinja : public ariel::Ninja {
public:
    TrainedNinja();
    TrainedNinja(std::string name, ariel::Point location);
    TrainedNinja(std::string name);
    TrainedNinja(ariel::Point location);
};

} // namespace ariel
#endif //TRAINEDNINJA
