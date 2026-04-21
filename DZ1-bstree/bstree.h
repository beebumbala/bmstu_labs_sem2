#pragma once

#include <iostream>
#include <fstream>
#include <string>

namespace lab {

    class BSTree {
    private:
        struct Node {
            int data;
            Node* left;
            Node* right;

            Node(int k) : data(k), left(nullptr), right(nullptr) {}
        };

        Node* root;

        Node* copyTree(Node* node);
        void clear(Node* node);
        Node* insert(Node* node, int key);
        Node* remove(Node* node, int key);
        Node* findMin(Node* node) const;
        Node* search(Node* node, int key) const;

        void straightOrder(Node* node, std::ostream& os = std::cout) const;
        void symOrder(Node* node, std::ostream& os = std::cout) const;
        void backOrder(Node* node, std::ostream& os = std::cout) const;

    public:
        BSTree();
        BSTree(const BSTree& other);
        BSTree(BSTree&& other) noexcept;
        ~BSTree();

        void insert(int key);
        void remove(int key);
        bool search(int key) const;
        void clear();

        void straightOrder(std::ostream& os = std::cout) const;
        void symOrder(std::ostream& os = std::cout) const;
        void backOrder(std::ostream& os = std::cout) const;

        void saveTree(const std::string& file) const;
        void loadTree(const std::string& file);

        friend std::ostream& operator<<(std::ostream& os, const BSTree& tree);
    };

}
