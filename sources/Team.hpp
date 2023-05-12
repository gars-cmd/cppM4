#ifndef TEAM_HPP
#define TEAM_HPP

#include "point.hpp"
#include "character.hpp"
#include "ninja.hpp"
#include "cowboy.hpp"
#include <iostream>
#include <string>

namespace ariel {

class Team {
protected:
    ariel::Character* arrTeam[10];
    ariel::Character* leader;
    int size;



public:
    Team(ariel::Character* leader);
    ~Team();
    void add(ariel::Character& new_player);
    int getSize() const;
    void setSize(int newSize);
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
