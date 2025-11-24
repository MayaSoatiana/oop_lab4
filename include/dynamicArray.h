#pragma once

#include <iostream>
#include <memory>
#include <initializer_list>

template<typename T>
class DynamicArray {
public:
    DynamicArray();
    DynamicArray(const std::initializer_list<T>& initialValues);  
    DynamicArray(const DynamicArray& other);
    DynamicArray& operator=(const DynamicArray& other);
    DynamicArray(DynamicArray&& other) noexcept;
    DynamicArray& operator=(DynamicArray&& other) noexcept;

    void add(T element);
    void remove(size_t index);
    size_t getSize() const;
    
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    
    double TotalArea() const;
    void DeleteFigure(size_t idx);
    void  PrintFigures();
    ~DynamicArray() noexcept;

private:   
    size_t size;           
    std::shared_ptr<T[]> data;
    inline static auto custom_deleter = [](T* ptr) {
        delete[] ptr;
    };
};

#include "dynamicArray.ipp"