#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

namespace ariel {

class Point {
private:
    double coord_x;
    double coord_y;


public:
    Point();
    ~Point();
    double getX() const;
    double getY() const;
    void setX(double x);
    void setY(double y);
    Point(double x, double y);
    Point(const Point& other);
    double distance(Point other) const;
    std::string toString() const;
    Point moveTowards(Point source, Point destination, double distance);

};

}
#endif // CARD_HPP
