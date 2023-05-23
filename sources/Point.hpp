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
    Point& operator=(const Point& other);
    Point(Point&& other) noexcept;
    Point& operator=(Point&& other) noexcept;
    double getX() const;
    double getY() const;
    void setX(double var_x);
    void setY(double var_y);
    Point(double var_x, double var_y);
    Point(const Point& other);
    double distance(Point other) const;
    std::string toString() const;
    static Point moveTowards(const Point& source, const Point& destination, double distance);

};

}
#endif // CARD_HPP
