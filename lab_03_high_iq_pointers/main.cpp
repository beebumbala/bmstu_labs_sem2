#include <iostream>
#include "unique_ptr.h"
#include "shared_ptr.h"

using namespace std;

int main() {
    cout << "tests 4 unique" << endl;

    MyUnique u1(new int(42));
    cout << "*u1 = " << *u1 << endl;

    MyUnique u2(std::move(u1));
    cout << "*u2 = " << *u2 << endl;
    cout << "u1 is " << (u1.get() ? "not null" : "null") << endl;

    MyUnique<int> u3;
    u3 = std::move(u2);
    cout << "*u3 = " << *u3 << endl;
    cout << "u2 is " << (u2.get() ? "not null" : "null") << endl;
    
    cout << "\ntests 4 shared" << endl;

    MyShared s1(new int(100));
    cout << "*s1 = " << *s1 << endl;
    cout << "s1 use_count: " << s1.use_count() << endl;

    MyShared s2(s1);
    cout << "after copy, *s2 = " << *s2 << endl;
    cout << "use_count: " << s1.use_count() << endl;

    *s1 = 200;
    cout << "*s1 = " << *s1 << endl;
    cout << "*s2 = " << *s2 << endl;

    MyShared<int> s3;
    s3 = s2;
    cout << "after assign, use_count: " << s1.use_count() << endl;

    MyShared s4(std::move(s3));
    cout << "*s4 = " << *s4 << endl;
    cout << "s3 is " << (s3.get() ? "not null" : "null") << endl;
    cout << "use_count: " << s1.use_count() << endl;
    
    return 0;
}