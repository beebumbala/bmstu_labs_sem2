#include "vector.hpp"
#include <stdexcept>

template <class T>
vector<T>::vector() : _data(nullptr), _size(0), _capacity(0) {}

template <class T>
vector<T>::vector(const vector& v) : _data(nullptr), _size(0), _capacity(0) {
    if (v._size > 0) {
        _capacity = v._size;
        _size = v._size;
        _data = new T[_capacity];

        for (size_t i = 0; i < v._size; ++i) _data[i] = v._data[i];
    }
}

template <class T>
vector<T>::vector(const size_t len, const T& value) : _data(nullptr), _size(0), _capacity(0) {
    if (len > 0) {
        _capacity = len;
        _size = len;
        _data = new T[len];

        for (size_t i = 0; i < len; ++i) _data[i] = value;
    }
}

template <class T>
vector<T>::~vector() {
    delete[] _data;
}

template <class T>
vector<T>& vector<T>::operator=(const vector& v) {
    if (this != &v) {
        delete[] _data;
        _capacity = v.size();
        _size = v.size();
        _data = nullptr;

        if (_size > 0) {
            _data = new T[_size];
            for (size_t i = 0; i < v._size; ++i) _data[i] = v._data[i];
        }
    }
    return *this;
}

template <class T>
T& vector<T>::operator[](size_t index) {
    return _data[index];
}

template <class T>
T& vector<T>::at(size_t index) {
    if (index >= _size) throw std::out_of_range("out of range");

    return _data[index];
}

template <class T>
T& vector<T>::front() {
    if (_size == 0) throw std::out_of_range("out of range");

    return _data[0];
}

template <class T>
T& vector<T>::back() {
    if (_size == 0) throw std::out_of_range("out of range");

    return _data[_size - 1];
}

template <class T>
T* vector<T>::data() {
    return _data;
}

template <class T>
bool vector<T>::empty() const {
    return _size == 0;
}

template <class T>
size_t vector<T>::size() const {
    return _size;
}

template <class T>
size_t vector<T>::capacity() const {
    return _capacity;
}

template <class T>
void vector<T>::reserve(size_t newcap) {
    if (newcap <= _capacity) return;

    T* new_data = new T[newcap];
    for (size_t i = 0; i < _size; ++i) new_data[i] = _data[i];

    delete[] _data;
    _data = new_data;
    _capacity = newcap;
}

template <class T>
void vector<T>::clear() {
    _size = 0;
}

template <class T>
void vector<T>::insert(size_t index, const T& value) {
    if (index > _size) throw std::out_of_range("out of range");

    if (_size == _capacity) {
        size_t newcap = _capacity == 0 ? 1 : _capacity * 2;
        reserve(newcap);
    }
    for (size_t i = _size; i > index; --i) {
        _data[i] = _data[i - 1];
    }
    _data[index] = value;
    ++_size;
}

template <class T>
void vector<T>::push_back(const T& value) {
    if (_size == _capacity) {
        size_t newcap = _capacity == 0 ? 1 : _capacity * 2;
        reserve(newcap);
    }
    ++_size;
    _data[_size] = value;
}

template <class T>
void vector<T>::pop_back() {
    if (_size == 0) throw std::out_of_range("out_of_range");
    --_size;
}

template <class T>
void vector<T>::swap(vector& v) {
    T* temp_data = _data;
    size_t temp_size = _size;
    size_t temp_capacity = _capacity;

    _data = v._data;
    _size = v._size;
    _capacity = v._capacity;

    v._data = temp_data;
    v._size = temp_size;
    v._capacity = temp_capacity;
}
