#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <random>
#include <chrono>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex mtx;
condition_variable cv;
int finished_threads = 0;

void thread_1(const string& name, int n, const vector<double>& a, const vector<double>& b, int delay = 0) {
    for (int i = 0; i < n; ++i) {
        mtx.lock();
        cout << "\n" << name << ": ";
        if (delay > 0) this_thread::sleep_for(chrono::milliseconds(delay));
        cout << a[i] << " * " << b[i] << " = " << a[i] * b[i] << flush;
        mtx.unlock();
    }

    {
        lock_guard<mutex> lock(mtx);
        finished_threads++;
    }
    cv.notify_one();
}

void thread_2(const string& name, int n, const vector<double>& a, const vector<double>& b, int delay = 0) {
    for (int i = 0; i < n; ++i) {
        lock_guard<mutex> lock(mtx);
        cout << "\n" << name << ": " ;
        if (delay > 0) this_thread::sleep_for(chrono::milliseconds(delay));
        cout<< a[i] << " + " << b[i] << " = " << a[i] + b[i] << flush;
    }
    
    {
        lock_guard<mutex> lock(mtx);
        finished_threads++;
    }
    cv.notify_one();
}

void thread_3(const string& name, int n, int delay = 0) {
    mt19937 generator(time(0) + 3);
    uniform_real_distribution<> dis(0, 100);
    for (int i = 0; i < n; ++i) {
        lock_guard<mutex> lock(mtx);
        cout << "\n" << name << ": " ;
        if (delay > 0) this_thread::sleep_for(chrono::milliseconds(delay));
        cout << dis(generator) << flush;
    }
    
    {
        lock_guard<mutex> lock(mtx);
        finished_threads++;
    }
    cv.notify_one();
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

    thread t1(thread_1, "thread1", n1, ref(a1), ref(a2), 0);
    thread t2(thread_2, "thread2", n2, ref(a1), ref(a2), 0);
    thread t3(thread_3, "thread3", n3, 0);

    for (int i = 0; i < 3; ++i) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [] { return finished_threads > 0; });
        cout << "\nMAIN: CV signaled! A child is done." << endl;
        finished_threads--;
    }

    t1.join();
    t2.join();
    t3.join();

    cout << "\nMAIN: All children are done!" << endl;
    return 0;
}
