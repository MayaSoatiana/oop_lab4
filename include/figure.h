#pragma once 
#include <iostream>
#include <memory>
#include <cmath>
#include "point.h"
#include "dynamicArray.h"

template <Scalar T>
class Figure {
public:
    virtual ~Figure() = default;
    virtual size_t vertices_count() const = 0;

    virtual Point<T> geometric_center() const;
    virtual void print_vertices(std::ostream& out) const; 
    virtual void read_vertices(std::istream& in);
    virtual operator double() const;
    virtual T distance(const Point<T>& p1, const Point<T>& p2) const;
    
    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const Figure<U>& fig) {
        fig.print_vertices(os);
        return os;
    }
    
    template<typename U>
    friend std::istream& operator>>(std::istream& is, Figure<U>& fig) {
        fig.read_vertices(is);
        return is;
    }

protected:
    std::unique_ptr<Point<T>[], void(*)(Point<T>*)> vertices;  
    
    Figure(size_t count);
    Figure(const DynamicArray<Point<T>>& points, size_t count);
    Figure(DynamicArray<Point<T>>&& points, size_t count);
    
    static void deleter(Point<T>* ptr) {
        delete[] ptr;
    }
};

#include "figure.ipp"