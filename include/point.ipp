template <Scalar T>
Point<T>::Point() : x(0), y(0) {}

template <Scalar T>
Point<T>::Point(T x, T y) : x(x), y(y) {}

template <Scalar T>
T Point<T>::get_x() const { 
    return x; 
}

template <Scalar T>
T Point<T>::get_y() const {
     return y; 
    }

template <Scalar T>
void Point<T>::set_x(T x_value) { 
    x = x_value; 
}

template <Scalar T>
void Point<T>::set_y(T y_value) {
     y = y_value; 
}

template <Scalar T>
bool Point<T>::operator==(const Point<T>& other) const {
    return x == other.x && y == other.y;
}