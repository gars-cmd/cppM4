#include "doctest.h"

#include "sources/Character.hpp"
#include "sources/Cowboy.hpp"
#include "sources/Ninja.hpp"
#include "sources/OldNinja.hpp"
#include "sources/Point.hpp"
#include "sources/YoungNinja.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/Team.hpp"
#include "sources/Team2.hpp"
#include "sources/SmartTeam.hpp"
#include <iostream>
#include <random>
#include <chrono>

using namespace ariel;

TEST_CASE("Constructor, Getter"){
    Point p0; 
    Point p1(1.0,1.0);
    Point p2(1.1,2.2);
    Point p3(3.1,5.2);

    CHECK_EQ(p0.getX(),0.0);
    CHECK_EQ(p0.getY(),0.0);
    CHECK_EQ(p1.getX(),1.0);
    CHECK_EQ(p1.getY(),1.0);
    CHECK_EQ(p2.getX(),1.1);
    CHECK_EQ(p2.getY(),2.2);
    CHECK_EQ(p3.getX(),3.1);
    CHECK_EQ(p3.getY(),5.2);

    Cowboy *c0 = new Cowboy();
    Cowboy *c1 = new Cowboy("Hariba", p2);
    Cowboy *c2 = new Cowboy("Buffalo");
    Cowboy *c3 = new Cowboy("Billy",p3);

    CHECK_EQ(c0->getName(),"UNKNOWN");
    CHECK_EQ(c0->getLocation().getX(),p0.getX());
    CHECK_EQ(c0->getLocation().getY(),p0.getY());
    CHECK_EQ(c0->getHealthPoint(),110);
    CHECK_EQ(c0->getBulletAmmount(),6);


    CHECK_EQ(c1->getName(),"Hariba");
    CHECK_EQ(c1->getLocation().getX(),p2.getX());
    CHECK_EQ(c1->getLocation().getY(),p2.getY());
    CHECK_EQ(c1->getHealthPoint(),110);
    CHECK_EQ(c1->getBulletAmmount(),6);


    CHECK_EQ(c2->getName(),"Buffalo");
    CHECK_EQ(c2->getLocation().getX(),0.0);
    CHECK_EQ(c2->getLocation().getY(),0.0);
    CHECK_EQ(c2->getHealthPoint(),110);
    CHECK_EQ(c2->getBulletAmmount(),6);


    CHECK_EQ(c3->getName(),"Billy");
    CHECK_EQ(c3->getLocation().getX(),p3.getX());
    CHECK_EQ(c3->getLocation().getY(),p3.getY());
    CHECK_EQ(c3->getHealthPoint(),110);
    CHECK_EQ(c3->getBulletAmmount(),6);

    YoungNinja *yn0 = new YoungNinja();
    YoungNinja *yn1 = new YoungNinja("Naruto",p3);

    CHECK_EQ(yn0->getName(),"UNKNOWN");
    CHECK_EQ(yn0->getLocation().getX(),0.0);
    CHECK_EQ(yn0->getLocation().getY(),0.0);
    CHECK_EQ(yn0->getHealthPoint(),100);
    CHECK_EQ(yn0->getSpeed(),14);


    CHECK_EQ(yn1->getName(),"Naruto");
    CHECK_EQ(yn1->getLocation().getX(),p3.getX());
    CHECK_EQ(yn1->getLocation().getY(),p3.getY());
    CHECK_EQ(yn1->getHealthPoint(),100);
    CHECK_EQ(yn1->getSpeed(),14);

    TrainedNinja *tn0 = new TrainedNinja();
    TrainedNinja *tn1 = new TrainedNinja("Itachi",p2);


    CHECK_EQ(tn0->getName(),"UNKNOWN");
    CHECK_EQ(tn0->getLocation().getX(),0.0);
    CHECK_EQ(tn0->getLocation().getY(),0.0);
    CHECK_EQ(tn0->getHealthPoint(),120);
    CHECK_EQ(tn0->getSpeed(),12);


    CHECK_EQ(tn1->getName(),"Itachi");
    CHECK_EQ(tn1->getLocation().getX(),p2.getX());
    CHECK_EQ(tn1->getLocation().getY(),p2.getY());
    CHECK_EQ(tn1->getHealthPoint(),120);
    CHECK_EQ(tn1->getSpeed(),12);


    OldNinja *on0 = new OldNinja;
    OldNinja *on1 = new OldNinja("Okage",p1);


    CHECK_EQ(on0->getName(),"UNKNOWN");
    CHECK_EQ(on0->getLocation().getX(),0.0);
    CHECK_EQ(on0->getLocation().getY(),0.0);
    CHECK_EQ(on0->getHealthPoint(),150);
    CHECK_EQ(on0->getSpeed(),8);


    CHECK_EQ(on1->getName(),"Okage");
    CHECK_EQ(on1->getLocation().getX(),p1.getX());
    CHECK_EQ(on1->getLocation().getY(),p1.getY());
    CHECK_EQ(on1->getHealthPoint(),150);
    CHECK_EQ(on1->getSpeed(),8);

    Team t0(c0);

    CHECK_EQ(t0.getLeader(),c0);
    CHECK_EQ(t0.getSize(),1);

    t0.add(yn0);

    CHECK_EQ(t0.getSize(),2);

    Team t20(c1);

    CHECK_EQ(t20.getLeader(),c1);
    CHECK_EQ(t20.getSize(),1);

    t20.add(yn1);

    CHECK_EQ(t20.getSize(),2);


    Team st0(on0);

    CHECK_EQ(st0.getLeader(),on0);
    CHECK_EQ(st0.getSize(),1);


    CHECK_EQ(st0.getSize(),1);
}


TEST_CASE("Cowboys"){
    Point p1(1.2,3.4);
    Cowboy *c1     = new Cowboy("Buffalo, ");
    YoungNinja *n1 = new YoungNinja();
    CHECK_EQ(c1->getBulletAmmount(),6);
    c1->shoot(n1);
    CHECK_EQ(c1->getBulletAmmount(),5);
    while (c1->getBulletAmmount()>0) {
        c1->shoot(n1);
    }
    CHECK_EQ(c1->getBulletAmmount(),0);
    CHECK_EQ(c1->hasboolets(),false);
    c1->reload();
    CHECK_EQ(c1->getBulletAmmount(),6);
    c1->shoot(n1);
    c1->reload();
    CHECK_EQ(c1->getBulletAmmount(),6);
}

TEST_CASE("Ninja"){
    Cowboy *c1        = new Cowboy("Buffalo", Point(9.0,9.0));
    YoungNinja *yn0   = new YoungNinja();
    TrainedNinja *tn0 = new TrainedNinja();
    OldNinja *on0     = new OldNinja;

    yn0->move(c1);
    tn0->move(c1);
    on0->move(c1);
    CHECK_EQ(on0->getLocation().getX(), doctest::Approx(5.656854249492381).epsilon(0.001));
    CHECK_EQ(on0->getLocation().getY(), doctest::Approx(5.656854249492381).epsilon(0.001));
    CHECK_EQ(tn0->getLocation().getX(), doctest::Approx(8.48528137423857).epsilon(0.001)); //speed 12
    CHECK_EQ(tn0->getLocation().getY(), doctest::Approx(8.48528137423857).epsilon(0.001));
    CHECK_EQ(yn0->getLocation().getX(), doctest::Approx(9.0).epsilon(0.001)); // speed 14
    CHECK_EQ(yn0->getLocation().getY(), doctest::Approx(9.0).epsilon(0.001));

    on0->slash(c1);
    CHECK_EQ(c1->getHealthPoint(), 110);

    tn0->slash(c1);
    CHECK_EQ(c1->getHealthPoint(), 70);

    yn0->slash(c1);
    CHECK_EQ(c1->getHealthPoint(),30);
}

bool isCowboy(Character* person){
    std::string str = person->print();
    if (str[0] == 'C') {
        return true;
    }else{
        return false;
    }
}

bool isNinja(Character* person){
    std::string str = person->print();
    if (str[0] == 'N') {
        return true;
    }else{
        return false;
    }
}

TEST_CASE("Point Distance"){
    Point p1(1,1);
    Point p2(2,2);
    Point p3(3,3);
    Point p9(9,9);

    CHECK_EQ(p1.distance(p2),doctest::Approx(1.41421).epsilon(0.001));
    CHECK_EQ(p2.distance(p3),doctest::Approx(1.41421).epsilon(0.001));
    CHECK_EQ(p3.distance(p9),doctest::Approx(8.48728).epsilon(0.001));
    CHECK_THROWS(p1.moveTowards(p1, p2, -1));

    p1.moveTowards(p1, p2, 2); //res : 2.000000, 2.000000
    p2.moveTowards(p2, p3, 0); //res : 2.000000, 2.000000
    p3.moveTowards(p3, p9, 4); //res : 5.828427, 5.828427 
    

    CHECK_EQ(p1.moveTowards(p1, p2, 2).getX(), doctest::Approx(2.000000).epsilon(0.001));
    CHECK_EQ(p1.moveTowards(p1, p2, 2).getY(), doctest::Approx(2.000000).epsilon(0.001));
    CHECK_EQ(p2.moveTowards(p2, p3, 0).getX(), doctest::Approx(2.000000).epsilon(0.001));
    CHECK_EQ(p2.moveTowards(p2, p3, 0).getX(), doctest::Approx(2.000000).epsilon(0.001));
    CHECK_EQ(p3.moveTowards(p3, p9, 4).getX(), doctest::Approx(5.828427).epsilon(0.001));
    CHECK_EQ(p3.moveTowards(p3, p9, 4).getX(), doctest::Approx(5.828427).epsilon(0.001));

}

TEST_CASE("dead don't attack"){
    OldNinja o1{"Bob", Point{0, 0}};
    YoungNinja y1{"Bob", Point{0, 0}};
    Cowboy c1{"Bob", Point{0, 0}};
    YoungNinja y2{"Bob", Point{0, 0}};

    while (c1.isAlive()) {
        y1.slash(&c1);
    }
    while (y2.isAlive()) {
        y1.slash(&y2);
    }
    while (o1.isAlive()) {
        y1.slash(&o1);
    }

    CHECK_THROWS(y1.slash(&c1));
    CHECK_THROWS(y1.slash(&y2));
    CHECK_THROWS(y1.slash(&o1));
    CHECK_THROWS(c1.shoot(&y1));
    CHECK_THROWS(y2.slash(&y1));
    CHECK_THROWS(o1.slash(&y1));
}

TEST_CASE("negative hit"){
    Cowboy cowboy("bob", Point(1,1));
    CHECK_THROWS(cowboy.hit(-1));
    CHECK_THROWS(cowboy.hit(-24));
    CHECK_THROWS(cowboy.hit(-67));
    CHECK_THROWS(cowboy.hit(-100));
}

TEST_CASE("attack a friend"){
    Cowboy c1("Billy");
    YoungNinja y1("Naruto");
    OldNinja o1("Hokage");
    TrainedNinja t1("Hokage");

    CHECK_THROWS(c1.shoot(&c1));
    CHECK_THROWS(y1.slash(&y1));
    CHECK_THROWS(o1.slash(&o1));
    CHECK_THROWS(t1.slash(&t1));


}


TEST_CASE("Team"){
    Cowboy *c1         = new Cowboy("Buffalo", Point(9.0,9.0));
    auto young_ninja   = new YoungNinja("new_player2",Point(0,  0));
    auto trained_ninja = new TrainedNinja("new_player3",Point(1,  1));
    auto old_ninja     = new OldNinja("new_player4",Point(2,  2));
    auto young_ninja2  = new YoungNinja("new_player5",Point(3,  3));
    auto cowboy        = new Cowboy("new_player6",Point(-6, -6));
    auto cowboy2       = new Cowboy("new_player7",Point(-7, -7));
    auto cowboy3       = new Cowboy("new_player8",Point(-8, -8));
    Team t1(c1);
    t1.add(young_ninja);
    t1.add(trained_ninja);
    t1.add(old_ninja);
    t1.add(young_ninja2);
    t1.add(cowboy);
    t1.add(cowboy2);
    t1.add(cowboy3);
    CHECK_EQ(t1.stillAlive(),8);
    CHECK_EQ( isCowboy(t1.getVec()[0]),true);
    CHECK_EQ( isNinja(t1.getVec()[1]),false);
    CHECK_EQ( isCowboy(t1.getVec()[1]),true);
    CHECK_EQ( isCowboy(t1.getVec()[2]),true);
    CHECK_EQ( isCowboy(t1.getVec()[3]),true);
    CHECK_EQ( isNinja(t1.getVec()[4]),true);
    CHECK_EQ( isNinja(t1.getVec()[5]),true);
    CHECK_EQ( isNinja(t1.getVec()[6]),true);
    CHECK_EQ( isNinja(t1.getVec()[7]),true);
    
}

void continuesAttack(int n, Team &attack, Team &victim){
    for (int i = 0; i < n; i++) {
            if (victim.stillAlive()) {
                attack.attack(&victim);
            }
        }
    }



TEST_CASE("Battle Activity"){
    Team team(new Cowboy(" new_player1",Point(0, 0)));
    team.add(new YoungNinja(" new_player2",Point(1, 1)));
    team.add(new OldNinja(" new_player3",Point(0.5, 0.5)));
    team.add(new TrainedNinja(" new_player4",Point(1.5, 1.5)));
    team.add(new Cowboy());

    CHECK_EQ(team.stillAlive(), 5);

    auto young_ninja   = new YoungNinja(" new_player5",Point(1, 1));
    auto trained_ninja = new TrainedNinja("new_player6",Point(2, 2));
    auto old_ninja     = new OldNinja(" new_player7",Point(3, 3));
    auto young_ninja2  = new YoungNinja(" new_player8",Point(4, 4));
    auto cowboy        = new Cowboy(" new_player9",Point(-5, -5));
    auto cowboy2       = new Cowboy(" new_player10",Point(-6, -6));
    auto cowboy3       = new Cowboy(" new_player11",Point(-7, -7));
    Team team2{young_ninja};
    team2.add(trained_ninja);
    team2.add(old_ninja);
    team2.add(young_ninja2);
    team2.add(cowboy);
    team2.add(cowboy2);
    team2.add(cowboy3);

        CHECK_EQ(team2.stillAlive(), 7);

        continuesAttack(2, team, team2);
        CHECK_FALSE(young_ninja->isAlive()); 
        CHECK((trained_ninja->isAlive() && old_ninja->isAlive() &&
               young_ninja2->isAlive())); 

        team.attack(&team2);
        CHECK((!trained_ninja->isAlive() && old_ninja->isAlive() &&
               young_ninja2->isAlive())); 

        continuesAttack(2, team, team2);
        CHECK_FALSE(trained_ninja->isAlive()); 
        CHECK((!old_ninja->isAlive() && young_ninja2->isAlive()));

        continuesAttack(4, team, team2);
        CHECK_FALSE(old_ninja->isAlive()); 
        CHECK(!young_ninja2->isAlive());

        continuesAttack(2, team, team2);
        CHECK_NOTHROW(team.attack(
                &team2)); 
        CHECK_FALSE(young_ninja2->isAlive()); 
        CHECK_THROWS_AS(team.attack(&team2), std::runtime_error);
}

TEST_CASE("Full Battle"){

}

//Ressources : 
//https://stackoverflow.com/questions/351845/finding-the-type-of-an-object-in-c



