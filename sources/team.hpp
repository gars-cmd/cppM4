#ifndef TEAM_HPP
#define TEAM_HPP

#include "point.hpp"
#include "character.hpp"
#include "ninja.hpp"
#include "cowboys.hpp"
#include <iostream>
#include <string>

namespace ariel {

class Team {
protected:
    ariel::Character arrTeam[10];
    ariel::Character leader;
    int size;



public:
    Team();
    ~Team();
    Team(ariel::Character& leader);
    void add(ariel::Character& new_player);
    int getSize() const;
    int setSize(int newSize);
    ariel::Character getLeader() const;
    void setLeader(ariel::Character& leader);
};

}
#endif // TEAM
