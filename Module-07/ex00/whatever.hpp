template <typename T>
void    swap(T &a, T &b) {
    T c = a;
    a = b;
    b = c;
}

template <typename T>
T       min(T a, T b) {
    return a < b ? a : b;
}

template <typename T>
T       max(T a, T b) {
    return a > b ? a : b;
}