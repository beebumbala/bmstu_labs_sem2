#pragma once

#include <stdexcept>

template<typename T>
class MyUnique {
private:
    T* p;

public:
    explicit MyUnique(T* ptr = nullptr) : p(ptr) {}
    ~MyUnique() {delete p;}

    // copy constr
    MyUnique(const MyUnique& oth) = delete;
    // move constr
    MyUnique(MyUnique&& oth) noexcept {
        p = oth.p;
        oth.p = nullptr;
    }

    // copy ass
    MyUnique& operator=(const MyUnique& oth) = delete;
    // move ass
    MyUnique& operator=(MyUnique&& oth) noexcept {
        if (p != oth.p) {
            p = oth.p;
            oth.p = nullptr;
        }
        return *this;
    }

    T* get() {return p;}

    T& operator*() {
        if (p == nullptr) throw std::runtime_error("no ptr here");
        return *p;
    }
    T* operator->() {return p;}
};
