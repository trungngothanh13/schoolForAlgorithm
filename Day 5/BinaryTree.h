#pragma once

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
private:
    Node* root;
    Node* insert(Node* node, int value);
    int calculateDepth(Node* node);

public:
    BinaryTree() {
        root = nullptr;
    }

    void printTreeVisually();
    void insert(int value);
    int getDepth();
};