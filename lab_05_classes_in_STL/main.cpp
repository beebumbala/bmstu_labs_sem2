#include "deposit.h"
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <algorithm>


template <typename T>
void print(const T& stl, std::ostream& out, char del='\n') {
    for (const auto& i : stl)
        out << i << del;
}

int main() {
    std::list<Deposit> deposits;

    std::ifstream in("input.txt");
    if (!in) {
        std::cerr << "error opening file" << std::endl;
        return 52;
    }
    Deposit temp("popa", 0, "USD", 552);
    while (in >> temp)
        deposits.push_back(temp);
    in.close();
    std::cout << "read from output.txt!" << std::endl;

    std::cout << "first container: " << std::endl;
    print(deposits, std::cout);

    std::ofstream out("output.txt");
    if (!out) {
        std::cerr << "error opening file" << std::endl;
        return 52;
    }
    print(deposits, out);
    std::cout << "wrote to output.txt!" << std::endl;

    std::vector<Deposit> copied;
    for (auto& i: deposits) {copied.push_back(i);}

    std::cout << "New vector from list (assumably same): " << std::endl;
    print(copied, std::cout);

    deposits.sort();
    std::cout << "Sorted by amount: " << std::endl;
    print(deposits, std::cout);
    print(deposits, out);
    std::cout << "wrote to output.txt!" << std::endl;

    out.close();
    return 0;
}