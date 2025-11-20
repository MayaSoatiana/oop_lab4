template <Scalar T>
Figure<T>::Figure(size_t count) 
    : vertices(new Point<T>[count], deleter) {
    for (size_t i = 0; i < count; ++i) {
        vertices[i] = Point<T>(0, 0);
    }
}

template <Scalar T>
Figure<T>::Figure(const DynamicArray<Point<T>>& points, size_t count) 
    : vertices(new Point<T>[count], deleter) {
    if (points.getSize() != count) {
        throw std::invalid_argument("Invalid number of points");
    }
    for (size_t i = 0; i < count; ++i) {
        vertices[i] = points[i];
    }
}

template <Scalar T>
Figure<T>::Figure(DynamicArray<Point<T>>&& points, size_t count) 
    : vertices(new Point<T>[count], deleter) {
    if (points.getSize() != count) {
        throw std::invalid_argument("Invalid number of points");
    }
    for (size_t i = 0; i < count; ++i) {
        vertices[i] = std::move(points[i]);
    }
}

template <Scalar T>
Point<T> Figure<T>::geometric_center() const {
    T center_x = 0;
    T center_y = 0;
    size_t count = vertices_count();
    
    for (size_t i = 0; i < count; ++i) {
        center_x += vertices[i].get_x();
        center_y += vertices[i].get_y();
    }
    
    return Point<T>(center_x / count, center_y / count);
}

template <Scalar T>
void Figure<T>::print_vertices(std::ostream& out) const {
    out << "Vertices :";
    size_t count = vertices_count();
    for (size_t i = 0; i < count; ++i) {
        out << vertices[i];
        if (i < count - 1) out << " ";
    }
}

template <Scalar T>
void Figure<T>::read_vertices(std::istream& in) {
    DynamicArray<Point<T>> points;
    size_t count = vertices_count();
    
    for (size_t i = 0; i < count; ++i) {
        T x, y;
        if (!(in >> x >> y)) {
            throw std::runtime_error("Failed to read vertices");
        }
        points.add(Point<T>(x, y));
    }
    
    for (size_t i = 0; i < count; ++i) {
        this->vertices[i] = points[i];
    }
}

template <Scalar T>
Figure<T>::operator double() const {
    T area = 0;
    size_t count = vertices_count();
    
    for (size_t i = 0; i < count; ++i) {
        int j = (i + 1) % count;
        area += vertices[i].get_x() * vertices[j].get_y();
        area -= vertices[j].get_x() * vertices[i].get_y();
    }
    return std::abs(area) / 2.0;
}

template <Scalar T>
T Figure<T>::distance(const Point<T>& p1, const Point<T>& p2) const {
    T dx = p2.get_x() - p1.get_x();
    T dy = p2.get_y() - p1.get_y();
    return std::sqrt(dx * dx + dy * dy);
}