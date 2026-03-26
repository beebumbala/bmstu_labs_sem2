#pragma once

#include <stdexcept>

template<typename T>
class MyShared {
private:
    T* p;
    int* count;

public:
    explicit MyShared(T* ptr = nullptr) : p(ptr) {
        if (p) count = new int(1);
    }

    ~MyShared() {
        if (count && --*count == 0) {
            delete p;
            delete count;
        }
    }

    // copy constr
    MyShared(const MyShared& oth) : p(oth.p), count(oth.count) {
        if (count) (*count)++;
    }
    // move constr
    MyShared(MyShared&& oth) noexcept : p(oth.p), count(oth.count) {
        oth.p = nullptr;
        oth.count = nullptr;
    }

    // copy ass
    MyShared& operator=(const MyShared& oth) {
        if (p != oth.p) {
            if (count && --*count == 0) {
                delete p;
                delete count;
            }
            p = oth.p;
            count = oth.count;
            if (count) (*count)++;
        }
        return *this;
    }
    // move ass
    MyShared& operator=(MyShared&& oth) noexcept {
        if (p != oth.p) {
            if (count && --*count == 0) {
                delete p;
                delete count;
            }
            p = oth.p;
            count = oth.count;
            oth.p = nullptr;
            oth.count = nullptr;
        }
        return *this;
    }

    // get count
    int use_count() {
        if (!count) return 0;
        return *count;
    }

    T* get() {return p;}

    T& operator*() {
        if (p == nullptr) throw std::runtime_error("no ptr here");
        return *p;
    }
    T* operator->() {return p;}
};