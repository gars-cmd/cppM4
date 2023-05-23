#include <cmath>
#include <cstring>
#include <iostream>
#include "Point.hpp"
#include <bits/stdc++.h>
#include <stdexcept>
#include <string>

using namespace ariel;

ariel::Point::~Point(){}

ariel::Point::Point():coord_x(0),coord_y(0){}

ariel::Point::Point(const Point& other){
    std::memcpy(this, &other, sizeof(ariel::Point));
}

// copy assignment constructor
Point& Point::operator=(const Point& other) {
    if (this != &other) {
        coord_x = other.coord_x;
        coord_y = other.coord_y;
    }
    return *this;
}

//move constructor
Point::Point(Point&& other) noexcept {
    coord_x = std::exchange(other.coord_x, 0);
    coord_y = std::exchange(other.coord_y, 0);
}

//move assignment operator
Point& Point::operator=(Point&& other) noexcept {
    if (this != &other) {
        coord_x = std::exchange(other.coord_x, 0);
        coord_y = std::exchange(other.coord_y, 0);
    }
    return *this;
}

ariel::Point::Point(double var_x, double var_y):coord_x(var_x),coord_y(var_y){}

double ariel::Point::getX() const{return this->coord_x;}

double ariel::Point::getY() const{return this->coord_y;}

void ariel::Point::setX(double var_x){this->coord_x = var_x;}

void ariel::Point::setY(double var_y){this->coord_y = var_y;}

double ariel::Point::distance(Point other) const{
    return std::sqrt(std::pow(other.getX() - this->getX(), 2) + std::pow(other.getY() - this->getY(), 2));
}

std::string ariel::Point::toString() const{
    return std::to_string(this->coord_x) 
               + "," 
               + std::to_string( this->coord_y);
}

ariel::Point ariel::Point::moveTowards(const ariel::Point& source, const ariel::Point& destination, double distance){
    if (distance < 0 ) {
        throw std::invalid_argument("distance cannot be negative");
    }
    double distanceFromTo = source.distance(destination);
    if (distanceFromTo <= distance) {
        return destination;
    }
    else {
    double distanceRatio = distance / distanceFromTo;
    double diff_x = destination.getX() - source.getX();
    double diff_y = destination.getY() - source.getY();
    ariel::Point point = ariel::Point(source.getX() + distanceRatio * diff_x, source.getY() + distanceRatio * diff_y);
    return point;
    }
}


//Ressources : 
//https://www.geeksforgeeks.org/program-calculate-distance-two-points/
//https://www.khanacademy.org/math/linear-algebra/vectors-and-spaces/dot-cross-products/v/vector-dot-product-and-vector-length
