#include "bstree.h"

namespace lab {

    // CONSTRUCTORS && DESTRUCTOR
    BSTree::BSTree() : root(nullptr) {}
    BSTree::BSTree(const BSTree& other) {
        root = copyTree(other.root);
    }
    BSTree::BSTree(BSTree&& other) noexcept : root(other.root) {
        other.root = nullptr;
    }
    BSTree::~BSTree() {
        clear();
    }

    BSTree::Node* BSTree::copyTree(Node* node) {
        if (!node) return nullptr;
        Node* newNode = new Node(node->data);
        newNode->left = copyTree(node->left);
        newNode->right = copyTree(node->right);
        return newNode;
    }

    // CLEAR TREE
    void BSTree::clear() {
        clear(root);
        root = nullptr;
    }

    void BSTree::clear(Node* node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    // INSERT NODE
    void BSTree::insert(int key) {
        root = insert(root, key);
    }

    BSTree::Node* BSTree::insert(Node* node, int key) {
        if (!node) return new Node(key);
        if (key < node->data) {
            node->left = insert(node->left, key);
        } else if (key > node->data) {
            node->right = insert(node->right, key);
        }
        return node;
    }

    // SEARCH FOR NODE
    bool BSTree::search(int key) const {
        return search(root, key) != nullptr;
    }

    BSTree::Node* BSTree::search(Node* node, int key) const {
        if (!node || node->data == key) return node;
        if (key < node->data) return search(node->left, key);
        return search(node->right, key);
    }

    // REMOVE NODE
    void BSTree::remove(int key) {
        root = remove(root, key);
    }

    BSTree::Node* BSTree::findMin(Node* node) const {
        while (node && node->left) node = node->left;
        return node;
    }

    BSTree::Node* BSTree::remove(Node* node, int key) {
        if (!node) return nullptr;

        if (key < node->data) {
            node->left = remove(node->left, key);
        } else if (key > node->data) {
            node->right = remove(node->right, key);
        } else {
            // node found
            if (!node->left || !node->right) {
                Node* temp = node->left ? node->left : node->right;
                delete node;
                return temp;
            }
            // if both left and right children exist (zhopa)
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
        return node;
    }

    // WALKTHROUGHES
    void BSTree::straightOrder(std::ostream& os) const {
        straightOrder(root, os);
        os << std::endl;
    }

    void BSTree::straightOrder(Node* node, std::ostream& os) const {
        if (node) {
            os << node->data << " ";
            straightOrder(node->left, os);
            straightOrder(node->right, os);
        }
    }

    void BSTree::symOrder(std::ostream& os) const {
        symOrder(root, os);
        os << std::endl;
    }

    void BSTree::symOrder(Node* node, std::ostream& os) const {
        if (node) {
            symOrder(node->left, os);
            os << node->data << " ";
            symOrder(node->right, os);
        }
    }

    void BSTree::backOrder(std::ostream& os) const {
        backOrder(root, os);
        os << std::endl;
    }

    void BSTree::backOrder(Node* node, std::ostream& os) const {
        if (node) {
            backOrder(node->left, os);
            backOrder(node->right, os);
            os << node->data << " ";
        }
    }

    // FILE SAVE/LOAD
    void BSTree::saveTree(const std::string& file) const {
        std::ofstream out(file);
        if (out.is_open()) {
            straightOrder(out);
            out.close();
        }
    }

    void BSTree::loadTree(const std::string& file) {
        std::ifstream in(file);
        if (in.is_open()) {
            clear();
            int val;
            while (in >> val) {
                insert(val);
            }
            in.close();
        }
    }

    std::ostream& operator<<(std::ostream& os, const BSTree& tree) {
        tree.straightOrder(os);
        return os;
    }

}
