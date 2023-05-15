#ifndef TEAM_HPP
#define TEAM_HPP

#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include <iostream>
#include <string>

namespace ariel {

class Team {
protected:
    ariel::Character* arrTeam[10] = {};
    ariel::Character* leader;
    int size;
    // need to add an id to hanfle self arm between members



public:
    Team(ariel::Character* leader);
    ~Team();
    void add(ariel::Character* new_player);
    int getSize() const;
    void setSize(int newSize);
    ariel::Character** getArr();
    virtual void sort();
    ariel::Character* getLeader() const;
    void setLeader(ariel::Character& leader);
    int stillAlive();
    void attack(ariel::Team* ennemyTeam);
    virtual void print();
    bool isLeaderAlive();
    void replaceLeader();
    ariel::Character* getCloserFromLeader();
};

}
#endif // TEAM

//Ressources: https://stackoverflow.com/questions/33123371/how-to-create-array-of-an-abstract-class-in-c
