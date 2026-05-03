#include <iostream>
#include <future>
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

    future<void> f1 = async(thread_1, "thread1", n1, std::ref(a1), std::ref(a2), 0);
    future<void> f2 = async(thread_2, "thread2", n2, std::ref(a1), std::ref(a2), 0);
    future<void> f3 = async(thread_3, "thread3", n3, 0);

    f1.get();
    f2.get();
    f3.get();

    cout << "\nMAIN: All children are done!" << endl;
    return 0;
}
