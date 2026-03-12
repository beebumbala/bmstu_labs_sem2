#pragma once

template <class T>
class vector {
private:
    T* _data;
    size_t _size;
    size_t _capacity;

public:
    vector();
    vector(const vector& v);
    vector(size_t len, const T& value);
    ~vector();

    vector& operator=(const vector& v);

    T& operator[](size_t index);

    T& at(size_t index);
    T& front();
    T& back();
    T* data();

    bool empty() const;
    size_t size() const;
    size_t capacity() const;
    void reserve(size_t newcap);

    void clear();
    void insert(size_t index, const T& value);
    void push_back(const T& value);
    void pop_back();
    void swap(vector& v);
};
