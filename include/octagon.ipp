template <Scalar T>
Octagon<T>::Octagon() 
    : Figure<T>(VERTICES_COUNT) {}

template <Scalar T>
Octagon<T>::Octagon(const DynamicArray<Point<T>>& points) 
    : Figure<T>(points, VERTICES_COUNT) {}

template <Scalar T>
Octagon<T>::Octagon(DynamicArray<Point<T>>&& points) 
    : Figure<T>(std::move(points), VERTICES_COUNT) {}

template <Scalar T>
Octagon<T>& Octagon<T>::operator=(const Octagon& other) {
    if (this != &other) {
        this->vertices.reset(new Point<T>[VERTICES_COUNT]);
        for (size_t i = 0; i < VERTICES_COUNT; ++i) {
            this->vertices[i] = other.vertices[i];
        }
    }
    return *this;
}

template <Scalar T>
Octagon<T>& Octagon<T>::operator=(Octagon&& other) noexcept {
    if (this != &other) {
        this->vertices = std::move(other.vertices);
    }
    return *this;
}