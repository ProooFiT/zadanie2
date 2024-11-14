#ifndef BST_H
#define BST_H

#include <iostream>
#include <vector>

class BST {
private:
    struct Node {
        int value;
        Node* left;
        Node* right;
        Node(int val) : value(val), left(nullptr), right(nullptr) {}
    };
    
    Node* root;

    // Prywatne metody pomocnicze
    Node* add(Node* node, int value);
    Node* remove(Node* node, int value);
    void clear(Node* node);
    bool findPath(Node* node, int value, std::vector<int>& path) const;
    void printPreorder(Node* node) const;
    void printInorder(Node* node) const;
    void printPostorder(Node* node) const;
    void saveToTextFile(Node* node, std::ostream& out) const;

public:
    BST();
    ~BST();
    
    void add(int value);
    void remove(int value);
    void clear();
    bool findPath(int value, std::vector<int>& path) const;
    void display(int orderType) const; // 1-preorder, 2-inorder, 3-postorder
    void saveToTextFile(const std::string& filename) const;
};

#endif
