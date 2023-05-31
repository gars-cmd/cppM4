#include "sources/Character.hpp"
#include "sources/OldNinja.hpp"
#include "sources/Point.hpp"
#include "sources/YoungNinja.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/Cowboy.hpp"
#include "sources/Team.hpp"
#include "sources/SmartTeam.hpp"
#include "sources/Team2.hpp"
#include <random>
#include <chrono>
#include <iostream>

using namespace ariel;
using namespace std;

static int counter = 0;
//<--------------------Helper Functions-------------------->
//https://www.geeksforgeeks.org/generate-a-random-float-number-in-cpp/
double random_float(double min = -100, double max = 100) {
    std::default_random_engine generator(static_cast<unsigned long>(std::chrono::system_clock::now().time_since_epoch().count()));
    std::uniform_real_distribution<double> distribution(min, max);

    return distribution(generator);
}


    auto multi_attack = [](int n, Team &attacker, Team &defender) {
        for (int i = 0; i < n; i++) {
            if (defender.stillAlive()) {
                attacker.attack(&defender);
            }
        }
    };



auto create_yninja = [](double x = random_float(), double y = random_float()) {
    return new YoungNinja{"Bob", Point{x, y}};
};

auto create_tninja = [](double x = random_float(), double y = random_float()) {
    return new TrainedNinja{"Bob", Point{x, y}};
};

auto create_oninja = [](double x = random_float(), double y = random_float()) {
    return new OldNinja{"Bob", Point{x, y}};
};

auto create_cowboy = [](double x = random_float(), double y = random_float()) {
    return new Cowboy{"Bob", Point{x, y}};
};

auto random_char(double x = random_float(), double y = random_float()) -> Character * {
    int flag = static_cast<int>(random_float()) % 4;

    if (flag == 0) return create_cowboy(x, y);

    if (flag == 1) return create_yninja(x, y);

    if (flag == 2) return create_tninja(x, y);

    return create_oninja(x, y);
}

auto simulate_battle = [](Team &team, Team &team2) {
    int i = 0;
    while (team.stillAlive() && team2.stillAlive()) {
        if (i % 2 == 0) {
            team.attack(&team2);
        } else {
            team2.attack(&team);
        }
        i++;
    }
    if (team.stillAlive() == 0) {
        counter++;
    }
};
//<-------------------------------------------------->

const int MAX_TEAM = 10;

int main (int argc, char *argv[]) {
    //     auto t13 = create_tninja(random_float(3.5, 3.6), random_float(3.5, 3.6));
    //     auto t23 = create_yninja(random_float(-3.5, -3.6), random_float(-3.5, -3.6));
    //     std::cout << "t13 = " << t13->print() << std::endl;
    //     std::cout << "t23 = " << t23->print() << std::endl;
    //     std::cout << t13->distance(t23) << std::endl;
    //     std::cout << t23->distance(t13) << std::endl;
    //
    //     auto t14 = create_tninja(random_float(0.0, 0.5), random_float(0.5, 0.0));
    //     auto t24 = create_yninja(random_float(-0.5, -0.0), random_float(-0.0, -0.5));
    // while (t14->isAlive() && t24->isAlive()) {
    //     t14->attack(t24);
    //     std::cout << "t24 Health: " << t24->getHealthPoint() << std::endl;
    // }
    //
    // auto c1 = new Cowboy("Roger",ariel::Point(random_float(0, 0), random_float(0, 0)));
    // auto c2 = new Cowboy("Roger2",ariel::Point(random_float(1, 1), random_float(1, 1)));
    // auto c3 = new Cowboy("Roger3",ariel::Point(random_float(2, 2), random_float(2, 2)));
    // auto c4 = new Cowboy("Roger4",ariel::Point(random_float(3, 3), random_float(3, 3)));
    // auto c5 = new Cowboy("Roger5",ariel::Point(random_float(4, 4), random_float(4, 4)));
    // auto c6 = new Cowboy("Roger6",ariel::Point(random_float(5, 5), random_float(5, 5)));
    // auto c7 = new Cowboy("Roger7",ariel::Point(random_float(6, 6), random_float(6, 6)));
    // auto c8 = new Cowboy("Roger8",ariel::Point(random_float(7, 7), random_float(7, 7)));
    // auto c9 = new Cowboy("Roger9",ariel::Point(random_float(8, 8), random_float(8, 8)));
    // Team team(c1); team.add(c2); team.add(c3); team.add(c4); team.add(c5); team.add(c6); team.add(c7); team.add(c8); team.add(c9);
    // auto cB = create_cowboy(random_float(0,1), random_float(0,1));
    // Team team2(cB);
    // while (team.stillAlive() > 0) {
    //     team2.attack(&team);
    //     // std::cout <<"team leader is : " << team.getLeader()->getName() << std::endl;
    // }
    //

    // auto n1 = new TrainedNinja("Yosu",ariel::Point(random_float(4, 4), random_float(4, 4)));
    // auto n2 = new OldNinja("Yosu2",ariel::Point(random_float(5, 5), random_float(5, 5)));
    // auto n3 = new OldNinja("Yosu3",ariel::Point(random_float(6, 6), random_float(6, 6)));
    // auto n4 = new YoungNinja("Yosu4",ariel::Point(random_float(7, 7), random_float(7, 7)));
    // auto n5 = new YoungNinja("Yosu5",ariel::Point(random_float(8, 8), random_float(8, 8)));
    //
    // Team2 team2(c1);
    // team2.add(n2);
    // team2.add(n3);
    // team2.add(n4);
    // team2.add(n5);
    // team2.add(c6);
    // team2.add(c7);
    // team2.add(c8);
    // team2.add(c9);
    // team2.print();
    
    //
    // Team team{create_cowboy(-1, -1)};
    // team.add(create_yninja(0, 0));
    // team.add(create_oninja(-0.5, -0.5));
    // team.add(create_tninja(0.5, 0.5));
    // team.add(create_cowboy());
    // auto young_ninja = create_yninja(0, 0);
    // auto trained_ninja = create_tninja(1, 1);
    // auto old_ninja = create_oninja(2, 2);
    // auto young_ninja2 = create_yninja(3, 3);
    // auto cowboy = create_cowboy(-6, -6);
    // auto cowboy2 = create_cowboy(-7, -7);
    // auto cowboy3 = create_cowboy(-8, -8);
    // Team team2{young_ninja};
    // team2.add(trained_ninja);
    // team2.add(old_ninja);
    // team2.add(young_ninja2);
    // team2.add(cowboy);
    // team2.add(cowboy2);
    // team2.add(cowboy3);
    // multi_attack(2, team, team2);

    // auto yn = (create_yninja(10, 0));
    // auto on(create_oninja(5, 0));
    // team.add(create_tninja(0, 0));

    // OldNinja old{"Bob", Point{0, 0}};
    // TrainedNinja trained{"Kung fu panda", Point{0, 0}};
    // YoungNinja young{"Karate kid", Point{0.5, 0.5}};
    // Cowboy cowboy{"Clint", Point{0.5, 0.5}};
    //
    // for (int i = 0; i < 1; i++) {
    //     std::cout << "distance between old & cowboy" << old.distance(&cowboy) << std::endl;
    //     old.slash(&cowboy);
    //     young.slash(&cowboy);
    // }
    //
    //
//     auto yn = YoungNinja();
//     auto yn1 = YoungNinja("YN1", ariel::Point(0,1));
//     auto yn2 = YoungNinja("YN2", ariel::Point(0,2));
//     auto yn3 = YoungNinja("YN3", ariel::Point(0,3));
//
//     auto tn =  TrainedNinja();
//     auto tn1 = TrainedNinja("TN1", ariel::Point(0,1));
//     auto tn2 = TrainedNinja("TN2", ariel::Point(0,2));
//     auto tn3 = TrainedNinja("TN3", ariel::Point(0,3));
//
//     auto on =  OldNinja();
//     auto on1 = OldNinja("ON1", ariel::Point(0,1));
//     auto on2 = OldNinja("ON2", ariel::Point(0,2));
//     auto on3 = OldNinja("ON3", ariel::Point(0,3));
//
//     auto on4 = OldNinja("ON4", ariel::Point(0,4), 100);
//     auto n1 = Ninja("N1", ariel::Point(0,5), 12, 100);
//
// std::cout << yn.print() << std::endl;
// std::cout << yn1.print() << std::endl;
// std::cout << n1.print() << std::endl;
// std::cout << yn2.print() << std::endl;
// std::cout << yn3.print() << std::endl;
//
// std::cout << tn.print() << std::endl;
// std::cout << tn1.print() << std::endl;
// std::cout << tn2.print() << std::endl;
// std::cout << tn3.print() << std::endl;
//
// std::cout << on.print() << std::endl;
// std::cout << on1.print() << std::endl;
// std::cout << on2.print() << std::endl;
// std::cout << on3.print() << std::endl;
// std::cout << on4.print() << std::endl;
//
//
// std::cout <<  yn.getName() << std::endl;
// std::cout << yn1.getName() << std::endl;
// std::cout << n1.getName() << std::endl;
// std::cout << yn2.getName() << std::endl;
// std::cout << yn3.getName() << std::endl;
//
// std::cout <<  tn.getName() << std::endl;
// std::cout << tn1.getName() << std::endl;
// std::cout << tn2.getName() << std::endl;
// std::cout << tn3.getName() << std::endl;
//
// std::cout <<  on.getName() << std::endl;
// std::cout << on1.getName() << std::endl;
// std::cout << on2.getName() << std::endl;
// std::cout << on3.getName() << std::endl;
// std::cout << on4.getName() << std::endl;
//

    Point p1(1,1);
    Point p2(2,2);
    Point p3(3,3);
    Point p9(9,9);

    std::cout << "p1 dist p2 " << p1.distance(p2) << std::endl;
    std::cout << "p2 dist p3 " << p2.distance(p3) << std::endl;
    std::cout << "p3 dist p4 " << p3.distance(p9) << std::endl;

    std::cout << "move toward p1 -> p2 " << p1.moveTowards(p1, p2, 2).toString() << std::endl;
    std::cout << "move toward p2 -> p3 " << p2.moveTowards(p2, p3, 0).toString() << std::endl;
    std::cout << "move toward p3 -> p9 " << p3.moveTowards(p3, p9, 4).toString() << std::endl;


int w = 0;
while (w < 1000) {
    auto leader1 = random_char();
    auto leader2 = random_char();
    Team team(leader1);
    SmartTeam smart(leader2);
    for (size_t i = 0; i < 18; i++) {
        auto new_player = random_char();
        if (i%2 ==0 ) {
            team.add(new_player);
        }else{
            smart.add(new_player);
        }
    }
    simulate_battle(team , smart);
    w++;
}
std::cout << "win-rate for smartTeam on 1000 battles : " << (((double)counter/1000))*100 <<"%" << std::endl;



}

