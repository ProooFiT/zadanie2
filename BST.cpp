#include "BST.h"
#include <fstream>

BST::BST() : root(nullptr) {}

BST::~BST() {
    clear();
}

BST::Node* BST::add(Node* node, int value) {
    if (!node) return new Node(value);
    if (value < node->value)
        node->left = add(node->left, value);
    else
        node->right = add(node->right, value);
    return node;
}

void BST::add(int value) {
    root = add(root, value);
}

BST::Node* BST::remove(Node* node, int value) {
    if (!node) return nullptr;
    if (value < node->value)
        node->left = remove(node->left, value);
    else if (value > node->value)
        node->right = remove(node->right, value);
    else {
        if (!node->left) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (!node->right) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        Node* successor = node->right;
        while (successor->left)
            successor = successor->left;
        node->value = successor->value;
        node->right = remove(node->right, successor->value);
    }
    return node;
}

void BST::remove(int value) {
    root = remove(root, value);
}


void BST::clear(Node* node) {
    if (!node) return;
    clear(node->left);
    clear(node->right);
    delete node;
}

void BST::clear() {
    clear(root);
    root = nullptr;
}

bool BST::findPath(Node* node, int value, std::vector<int>& path) const {
    if (!node) return false;
    path.push_back(node->value);
    if (node->value == value) return true;
    if ((node->left && findPath(node->left, value, path)) || 
        (node->right && findPath(node->right, value, path)))
        return true;
    path.pop_back();
    return false;
}

bool BST::findPath(int value, std::vector<int>& path) const {
    path.clear();
    return findPath(root, value, path);
}

