#include "deposit.h"
#include <iostream>
#include <fstream>
#include <list>
#include <set>
#include <unordered_set>

using namespace std;

template <typename T>
void print(const T& stl, ostream& out, char del = '\n') {
    for (const auto& i : stl)
        out << i << del;
}

int main() {
    list<Deposit> deposits;

    ifstream in("input.txt");
    if (!in) {
        cerr << "error opening input.txt" << endl;
        return 52;
    }

    Deposit temp;
    while (in >> temp)
        deposits.push_back(temp);
    in.close();

    cout << "start containers:" << endl;
    print(deposits, cout);
    cout << endl;

    ofstream out("output.txt");
    if (!out) {
        cerr << "error opening output.txt" << endl;
        return 52;
    }
    print(deposits, out);

    out << "set:" << std::endl;
    set<Deposit> depositSet(deposits.begin(), deposits.end());
    print(depositSet, cout);
    cout << endl;
    print(depositSet, out);

    out << "unordered set:" << std::endl;
    unordered_set<Deposit, Hasher> depositUSet(
        deposits.begin(), deposits.end()
    );
    print(depositUSet, cout);
    cout << endl;
    print(depositUSet, out);

    return 0;
}