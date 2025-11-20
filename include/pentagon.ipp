template <Scalar T>
Pentagon<T>::Pentagon() 
    : Figure<T>(VERTICES_COUNT) {}

template <Scalar T>
Pentagon<T>::Pentagon(const DynamicArray<Point<T>>& points) 
    : Figure<T>(points, VERTICES_COUNT) {}

template <Scalar T>
Pentagon<T>::Pentagon(DynamicArray<Point<T>>&& points) 
    : Figure<T>(std::move(points), VERTICES_COUNT) {}

template <Scalar T>
Pentagon<T>& Pentagon<T>::operator=(const Pentagon& other) {
    if (this != &other) {
        this->vertices.reset(new Point<T>[VERTICES_COUNT]);
        for (size_t i = 0; i < VERTICES_COUNT; ++i) {
            this->vertices[i] = other.vertices[i];
        }
    }
    return *this;
}

template <Scalar T>
Pentagon<T>& Pentagon<T>::operator=(Pentagon&& other) noexcept {
    if (this != &other) {
        this->vertices = std::move(other.vertices);
    }
    return *this;
}