#pragma once

#include <iostream>
#include <memory>
#include "figure.h"
#include "dynamicArray.h"

template <Scalar T> 
class Hexagon final : public Figure<T> {
public:
    using value_type = T;
    static constexpr size_t VERTICES_COUNT = 6;
    size_t vertices_count() const override{return VERTICES_COUNT;};
    
    Hexagon();
    Hexagon(const DynamicArray<Point<T>>& points);
    Hexagon(DynamicArray<Point<T>>&& points); 
    Hexagon& operator=(const Hexagon& other);
    Hexagon& operator=(Hexagon&& other) noexcept;
    
    ~Hexagon() = default;
};

#include "hexagon.ipp"