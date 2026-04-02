#include <iostream>
#include "some_points.h"


int main() {
    Point point_2d(10, 52);
    Point3D point_3d(12, 2.4, -12.2);

    {
        std::cout << "DEFAULT (no pointers, all is good):" << std::endl;
        std::cout << "point_2d.print(): ";
        point_2d.print();
        std::cout << std::endl;

        std::cout << "point_3d.print(): ";
        point_3d.print();
        std::cout << std::endl;

        std::cout << "point_2d.print_st(): ";
        point_2d.print_st();
        std::cout << std::endl;

        std::cout << "point_3d.print_st(): ";
        point_3d.print_st();
        std::cout << std::endl;
    }

    // Base type pointer, derived entity
    Point* p = &point_3d;

    {
        // Dynamic polymorphism demonstration (cpp's sure its 3D)
        std::cout << "\nSTATIC:" << std::endl;
        std::cout << "p->print_st(): "; p->print_st();
        std::cout << std::endl;
    }
    {
        // Dynamic polymorphism demonstration (cpp's sure its 3D)
        std::cout << "\nDYNAMIC:" << std::endl;
        std::cout << "p->print(): "; p->print();
        std::cout << std::endl;
    }

    return 0;
}