#include "doctest.h"

#include "sources/Character.hpp"
#include "sources/Ninja.hpp"
#include "sources/OldNinja.hpp"
#include "sources/Point.hpp"
#include "sources/YoungNinja.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/Cowboy.hpp"
#include "sources/Team.hpp"
#include "sources/Team2.hpp"
#include "sources/SmartTeam.hpp"
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
    Cowboy *c3 = new Cowboy(p3);

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


    CHECK_EQ(c3->getName(),"UNKNOWN");
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

    st0.add(yn0);

    CHECK_EQ(st0.getSize(),1);
}


TEST_CASE("Cowboys"){
    Point p1(1.2,3.4);
    Cowboy *c1 = new Cowboy("Buffalo, ");

}


