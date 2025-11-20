#include "figure.h" 

template<typename T>
DynamicArray<T>::DynamicArray() : size(0), data(nullptr) {}

template<typename T>
DynamicArray<T>::DynamicArray(const std::initializer_list<T>& initialValues) {
    size = initialValues.size();
    data = std::shared_ptr<T[]>(new T[size], custom_deleter);
    
    size_t index = 0;
    for (const auto& value : initialValues) {
        data[index++] = value; 
    }
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& other) {
    size = other.size;
    data = std::shared_ptr<T[]>(new T[size], custom_deleter);
    
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i]; 
    }
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& other) {
    if (this != &other) {
        size = other.size;
        data = std::shared_ptr<T[]>(new T[size], custom_deleter);
        
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i]; 
        }
    }
    return *this;
}

template<typename T>
DynamicArray<T>::DynamicArray(DynamicArray<T>&& other) noexcept {
    size = other.size;
    data = other.data;

    other.size = 0;
    other.data = nullptr;
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(DynamicArray&& other) noexcept {
    if (this != &other) {
        size = other.size;
        data = other.data;
        
        other.size = 0;
        other.data = nullptr;
    }
    return *this;
}

template<typename T>
void DynamicArray<T>::add(T element) {
    std::shared_ptr<T[]> newData(new T[size + 1]);
    
    for (size_t i = 0; i < size; ++i) {
        newData[i] = std::move(data[i]);
    }
    
    newData[size] = std::move(element); 
    data = newData;
    ++size;
}

template<typename T>
void DynamicArray<T>::remove(size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    
    if (size == 1) {
        data = nullptr;
        size = 0;
        return;
    }

    std::shared_ptr<T[]> newData(new T[size - 1]);
    for (size_t i = 0; i < index; ++i) {
        newData[i] = std::move(data[i]); 
    }

    for (size_t i = index + 1; i < size; ++i) {
        newData[i - 1] = std::move(data[i]); 
    }
    
    data = newData;
    --size;
}

template<typename T>
T& DynamicArray<T>::operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template<typename T>
const T& DynamicArray<T>::operator[](size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template<typename T>
size_t DynamicArray<T>::getSize() const {
    return size;
}

template<typename T>
double DynamicArray<T>::TotalArea() const {
    double total = 0.0;
    for (size_t i = 0; i < size; ++i) {
        if (data[i]) {
            total += static_cast<double>(*data[i]);
        }
    }
    return total;
}

template<typename T>
void DynamicArray<T>::PrintFigures() {
    for (size_t i = 0; i < size; ++i) {
        if (data[i] != nullptr) {
            std::cout << *data[i] << std::endl;
            std::cout << "Center: (" << data[i]->geometric_center().get_x() << ", "
                        << data[i]->geometric_center().get_y() << ")" << std::endl;
            std::cout << "Area: " << static_cast<double>(*data[i]) << std::endl;
        }
    }
}

template <typename T>
void DynamicArray<T>::DeleteFigure(size_t idx) {
    if (idx >= size) {
        throw std::out_of_range("Error index out range");
    }
    delete data[idx]; 
    for (size_t i = idx; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    --size;
}
    
template<typename T>
DynamicArray<T>::~DynamicArray() noexcept = default;