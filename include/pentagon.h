#pragma once

#include <iostream>
#include <memory>
#include "figure.h"
#include "dynamicArray.h"

template <Scalar T> 
class Pentagon final : public Figure<T> {
public:
    using value_type = T;
    static constexpr size_t VERTICES_COUNT = 5;
    size_t vertices_count() const override{return VERTICES_COUNT;};
    
    Pentagon();
    Pentagon(const DynamicArray<Point<T>>& points);
    Pentagon(DynamicArray<Point<T>>&& points);
    Pentagon& operator=(const Pentagon& other);
    Pentagon& operator=(Pentagon&& other) noexcept;
    
    ~Pentagon() = default;
};

#include "pentagon.ipp"