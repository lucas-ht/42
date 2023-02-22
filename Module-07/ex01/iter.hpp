#include <iostream>

template <typename T, typename F>
void    iter(T *a, int size, F f) {
    for (int i = 0; i < size; i++) {
        f(a[i]);
    }
}

template <typename T>
void    print(T a) {
    std::cout << a << std::endl;
}