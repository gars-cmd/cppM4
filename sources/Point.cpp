#include <cstring>
#include <iostream>
#include "point.hpp"
#include <bits/stdc++.h>

using namespace ariel;

ariel::Point::~Point(){}

ariel::Point::Point():coord_x(0),coord_y(0){}

ariel::Point::Point(const Point& other){
    std::memcpy(this, &other, sizeof(ariel::Point));
}

ariel::Point::Point(double x, double y):coord_x(x),coord_y(y){}

double ariel::Point::getX() const{return this->coord_x;}

double ariel::Point::getY() const{return this->coord_y;}

void ariel::Point::setX(double x){this->coord_x = x;}

void ariel::Point::setY(double y){this->coord_y = y;}

double ariel::Point::distance(Point other){
    return std::sqrt(std::pow(other.coord_x - this->coord_x, 2)
                     + std::pow(other.coord_y - this->coord_y, 2));
}

void ariel::Point::toString() const{ std::cout << this->coord_x << "," << this->coord_y << '\n'; }


//Ressources : 
//https://www.geeksforgeeks.org/program-calculate-distance-two-points/
