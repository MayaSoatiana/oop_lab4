#pragma once

#include <concepts>
#include <iostream>

template <typename T>
concept Scalar = std::is_arithmetic_v<T>;

template <Scalar T>
class Point {
private:
    T x, y;

public:
    Point();
    Point(T x, T y) ;
    
    T get_x() const ;
    T get_y() const ;
    
    void set_x(T x_value);
    void set_y(T y_value);
    
    bool operator==(const Point<T>& other) const ;

};

template <Scalar T>
std::ostream& operator<<(std::ostream& os, const Point<T>& p) {
    os << "(" << p.get_x() << ", " << p.get_y() << ")";
    return os;
}

template <Scalar T>
std::istream& operator>>(std::istream& in, Point<T>& p) {
    T x, y;
    if (in >> x >> y) {
        p.set_x(x);
        p.set_y(y);
    }
    return in;
}

#include "point.ipp"