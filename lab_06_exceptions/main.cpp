#include <iostream>
#include "date.h"


int main() {
    bool failed = false;
    
     std::cout << "test 1: valid date" <<  std::endl;
    try {
        Date d(15, 5, 2023);
         std::cout << "Object: " << d <<  std::endl;
         std::cout << "[SUCCESS] Test passed" <<  std::endl;
    } catch (const DateException& e) {
         std::cout << "[FAIL] Unexpected exception" <<  std::endl;
        failed = true;
        e.print();
    }
     std::cout <<  std::endl;

    
     std::cout << "test 2: invalid day" <<  std::endl;
    try {
        Date d(32, 1, 2023);
         std::cout << "Object: " << d <<  std::endl;
         std::cout << "[FAIL] Exception was supposed" <<  std::endl;
        failed = true;
    } catch (const DateException& e) {
         std::cout << "[SUCCESS] Test passed" <<  std::endl;
        e.print();
    }
     std::cout <<  std::endl;

    
     std::cout << "test 3: invalid month" <<  std::endl;
    try {
        Date d(15, 13, 2023);
         std::cout << "Object: " << d <<  std::endl;
         std::cout << "[FAIL] Exception was supposed" <<  std::endl;
        failed = true;
    } catch (const DateException& e) {
         std::cout << "[SUCCESS] Test passed" <<  std::endl;
        e.print();
    }
     std::cout <<  std::endl;

    
     std::cout << "test 4: setter + invalid day (31/30)" <<  std::endl;
    try {
        Date d(1, 4, 2023);
         std::cout << "Object: " << d <<  std::endl;
         std::cout << "Setting day 31" <<  std::endl;
        d.setDay(31);
         std::cout << "New object: " << d <<  std::endl;
         std::cout << "[FAIL] Exception was supposed" <<  std::endl;
        failed = true;
    } catch (const DateException& e) {
         std::cout << "[SUCCESS] Test passed" <<  std::endl;
        e.print();
    }
     std::cout <<  std::endl;

    if (failed) {
         std::cout << "SOME TESTS FAILED, RECHECK!" <<  std::endl;
    } else {
         std::cout << "ALL GOOD, YOU'RE ON FIRE!" <<  std::endl;
    }
    return 0;
}