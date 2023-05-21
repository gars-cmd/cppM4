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

ariel::Point::Point(double x, double y):coord_x(x),coord_y(y){}

double ariel::Point::getX() const{return this->coord_x;}

double ariel::Point::getY() const{return this->coord_y;}

void ariel::Point::setX(double x){this->coord_x = x;}

void ariel::Point::setY(double y){this->coord_y = y;}

double ariel::Point::distance(Point other) const{
    double exact_distance =std::sqrt(std::pow(other.coord_x - this->coord_x, 2)
                         + std::pow(other.coord_y - this->coord_y, 2));
    return std::round(exact_distance * 1000) / 1000;
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
    double total_distance = source.distance(destination);
    if (total_distance <= distance) {
        return destination;
    }
    double distanceRatio = distance / total_distance;
    double new_x = source.getX() + ( (destination.getX() - source.getX()) * distanceRatio );
    double new_y = source.getY() + ( (destination.getY() - source.getY()) * distanceRatio );
    return ariel::Point(new_x, new_y);
}


//Ressources : 
//https://www.geeksforgeeks.org/program-calculate-distance-two-points/
//https://www.khanacademy.org/math/linear-algebra/vectors-and-spaces/dot-cross-products/v/vector-dot-product-and-vector-length
