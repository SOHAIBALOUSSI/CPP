#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <iostream>
#include <ctime>
#include <cstdlib>

template<class T>
class Array
{
private:
    T* arr;
    unsigned int _size;
public:
    
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    Array& operator=(const Array& assign);
    ~Array();

    T& operator[](unsigned int idx);
    const T& operator[](unsigned int idx) const;
    unsigned int size() const;
};

template<class T>
Array<T>::Array() : arr(NULL), _size(0U) {
    arr = new T[0];
} 

template<class T>
Array<T>::Array(unsigned int n) : _size(n){
    arr = new T[n]();
}

template<class T>
Array<T>::~Array() { delete[] arr; }

template<class T>
const T& Array<T>::operator[](unsigned int idx) const {
    if (idx >= _size) throw std::out_of_range("out of bounds!");
    return arr[idx];
}

template<class T>
T& Array<T>::operator[](unsigned int idx) {
    if (idx >= _size) throw std::out_of_range("out of bounds!");
    return arr[idx];
}

template<class T>
unsigned int Array<T>::size() const { return _size; }

template<class T>
Array<T>::Array(const Array<T>& other) : _size(other.size()) {
    arr = new T[_size]();
    for (unsigned int i = 0; i < _size; i++) {
        arr[i] = other.arr[i];
    }
}

template<class T>
Array<T>& Array<T>::operator=(const Array<T>& assign){
    if (this != &assign) {
        _size = assign.size();
        delete[] arr;
        arr = new T[_size]();
        for (unsigned int i = 0; i < _size; i++) {
            arr[i] = assign.arr[i];
        }
    }
    return *this;
}

#endif
