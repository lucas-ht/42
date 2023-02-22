#include "Array.hpp"

template <typename T>
Array<T>::Array() {
    this->array = new T[0];
    this->len = 0;
}

template <typename T>
Array<T>::Array(unsigned int n) {
    this->array = new T[n];
    this->len = n;
}

template <typename T>
Array<T>::Array(const Array<T>& a) {
    *this = a;
}

template <typename T>
Array<T>::~Array() {
    delete [] this->array;
}

template <typename T>
Array<T>&  Array<T>::operator=(const Array<T>& a) {
    if (this == &a)
        return *this;

    this->len = a.len;
    this->array = new T[this->len];

    for (unsigned int i = 0; i < this->len; i++) {
        this->array[i] = a.array[i];
    }
    return *this;
}

template <typename T>
T&      Array<T>::operator[](const unsigned int i) {
    if (i < 0 || i >= this->len)
        throw Array::InvalidIndex();
    return this->array[i];
}

template <typename T>
unsigned int  Array<T>::size() const {
    return this->len;
}

template <typename T>
const char  *Array<T>::InvalidIndex::what() const throw() {
    return "Invalid index";
}