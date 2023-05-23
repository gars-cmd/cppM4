#ifndef TEAM_HPP
#define TEAM_HPP

#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

namespace ariel {

class Team {
private:
    std::vector<ariel::Character*> vectorTeam;
    ariel::Character* leader;
    int size = 0;
    int id = 0;

public:
    Team(ariel::Character* leader);
    virtual ~Team();
    void add(ariel::Character* new_player);
    int getSize() const;
    Team& operator=(const Team& other); // Copy assignment operator
    Team(Team&& other) noexcept; // Move constructor
    Team& operator=(Team&& other) noexcept;// Move assignment operator
    Team(const Team& other);
    void setSize(int newSize);
    std::vector<Character*> getVec();
    virtual void sort();
    ariel::Character* getLeader() const;
    void setLeader(ariel::Character& leader);
    std::size_t indexOfLastSortedCowboy() ;
    int stillAlive();
    void attack(ariel::Team* ennemyTeam);
    virtual void print();
    bool isLeaderAlive();
    void replaceLeader();
    bool isSorted();
    std::size_t firstNinjaIndex();
    ariel::Character* getCloserFromLeaderIntern();
    ariel::Character* getCloserFromLeaderExtern(ariel::Team* otherTeam);
    void addErrorHandler(ariel::Character* new_player);
    void moveSaveAddOrder(std::size_t last_continues_cowboy_index, std::size_t cowboy_index);
    void attackErrorHandler(ariel::Team *ennemyTeam);
    void liveReplacement(ariel::Team *ennemyTeam);
};

}
#endif // TEAM

//Ressources: https://stackoverflow.com/questions/33123371/how-to-create-array-of-an-abstract-class-in-c
