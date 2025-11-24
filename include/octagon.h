#pragma once

#include <iostream>
#include <memory>
#include "figure.h"
#include "dynamicArray.h"

template <Scalar T> 
class Octagon final : public Figure<T> {
public:
    using value_type = T;
    static constexpr size_t VERTICES_COUNT = 8;
    size_t vertices_count() const override{return VERTICES_COUNT;};

    Octagon();
    Octagon(const DynamicArray<Point<T>>& points);
    Octagon(DynamicArray<Point<T>>&& points);
    Octagon& operator=(const Octagon& other);
    Octagon& operator=(Octagon&& other) noexcept;
    
    ~Octagon() = default;
};

#include "octagon.ipp"