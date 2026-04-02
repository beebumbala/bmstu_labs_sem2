#pragma once

#include <iostream>

class Point {
protected:
    double x, y;

public:
    Point(const double x, const double y) : x(x), y(y) {}

    // virtual version
    virtual void print() const {
        std::cout << "Your 2D point : " << x << " " << y << std::endl;
    }

    // static version
    void print_st() const {
        std::cout << "X and Y of your point (I assume its 2D...): " << x << " " << y << std::endl;
    }

    virtual ~Point() {}
};


class Point3D : public Point {
private:
    double z;

public:
    Point3D(const double x, const double y, const double z) : Point(x, y), z(z) {}

    // dynamic polymorphism
    void print() const override {
        std::cout << "Your 3D point : " << x << " " << y << " " << z << std::endl;
    }

    // static polymorphism
    void print_st() const {
        std::cout << "X, Y and Z of your point (3D IM SURE!): " << x << " " << y << " " << z << std::endl;
    }
};

