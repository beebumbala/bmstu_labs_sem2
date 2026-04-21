#include "bstree.h"
#include <iostream>

int main() {
    lab::BSTree tree;
    for (auto& i: {50, 30, 70, 20, 40, 60, 80}) {
        tree.insert(i);
    }

    std::cout << "Tree (Straight order):" << std::endl;
    std::cout << tree << std::endl;

    // WALKTHROUGHES
    std::cout << "Straight-order: ";
    tree.straightOrder();

    std::cout << "Symmetrical-order: ";
    tree.symOrder();

    std::cout << "Back-order: ";
    tree.backOrder();

    // SEARCH
    std::cout << "Search 40: " << (tree.search(40) ? "Found" : "Not found") << std::endl;
    std::cout << "Search 52: " << (tree.search(52) ? "Found" : "Not found") << std::endl;
    std::cout << std::endl;

    // REMOVE
    std::cout << "Removing 50, new tree: " << std::endl;
    tree.remove(50);
    std::cout << tree << std::endl;

    // FILES INTERACTION
    std::cout << "Saving to tree.txt.." << std::endl;
    tree.saveTree("tree.txt");
    tree.clear();
    std::cout << "[OK] SAVED" << std::endl;
    
    std::cout << "Loading from tree.txt.." << std::endl;
    tree.loadTree("tree.txt");
    std::cout << tree << std::endl;

    return 0;
}