#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <random>
#include <chrono>

using namespace std;

void thread_1(const string& name, int n, const vector<double>& a, const vector<double>& b, int delay = 0) {
    for (int i = 0; i < n; ++i) {
        cout << "\n" << name << ": ";
        if (delay > 0) this_thread::sleep_for(chrono::milliseconds(delay));
        cout << a[i] << " * " << b[i] << " = " << a[i] * b[i];
    }
    cout << endl;
}

void thread_2(const string& name, int n, const vector<double>& a, const vector<double>& b, int delay = 0) {
    for (int i = 0; i < n; ++i) {
        cout << "\n" << name << ": " ;
        if (delay > 0) this_thread::sleep_for(chrono::milliseconds(delay));
        cout<< a[i] << " + " << b[i] << " = " << a[i] + b[i];
    }
    cout << endl;
}

void thread_3(const string& name, int n, int delay = 0) {
    mt19937 generator(time(0) + 3);
    uniform_real_distribution<> dis(0, 100);
    for (int i = 0; i < n; ++i) {
        cout << "\n" << name << ": " ;
        if (delay > 0) this_thread::sleep_for(chrono::milliseconds(delay));
        cout << dis(generator);
    }
    cout << endl;
}

int main() {
    int n1 = 20, n2 = 20, n3 = 20;
    vector<double> a1(30), a2(30);
    mt19937 generator(time(0));
    uniform_real_distribution<> distributor(1, 10);

    for (int i = 0; i < 30; ++i) {
        a1[i] = distributor(generator);
        a2[i] = distributor(generator);
    }

    thread t1(thread_1, "thread1", n1, ref(a1), ref(a2), 10);
    thread t2(thread_2, "thread2", n2, ref(a1), ref(a2), 5);
    thread t3(thread_3, "thread3", n3, 10);

    t1.join();
    t2.join();
    t3.join();

    cout << "\nMAIN: All children are done!" << endl;
    return 0;
}
