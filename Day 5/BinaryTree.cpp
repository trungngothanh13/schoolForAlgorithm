#include "BinaryTree.h"
#include <iostream>
#include <queue>
#include <iomanip>

using namespace std;

Node* BinaryTree::insert(Node* node, int value) {
    if (node == nullptr)
        return new Node(value);

    if (value < node->data)
        node->left = insert(node->left, value);
    else
        node->right = insert(node->right, value);
    return node;
}

void BinaryTree::printTreeVisually() {
    if (root == nullptr) {
        cout << "Tree is empty.\n";
        return;
    }

    queue<Node*> q;
    q.push(root);

    int height = calculateDepth(root);  // Calculate height of the tree
    int maxWidth = pow(2, height) - 1;  // Max width at the bottom level

    int currentLevel = 0;
    while (!q.empty() && currentLevel < height) {
        int levelSize = q.size();          // Number of nodes at the current level
        int spaces = maxWidth / pow(2, currentLevel + 1); // Spacing between nodes

        // Print leading spaces for the first node
        cout << string(spaces, ' ');

        for (int i = 0; i < levelSize; i++) {
            Node* current = q.front();
            q.pop();

            // Print node data or empty brackets if null
            if (current) {
                cout << setw(2) << current->data;
                q.push(current->left);
                q.push(current->right);
            }
            else {
                cout << "[]";
                q.push(nullptr);
                q.push(nullptr);
            }

            // Print spaces between nodes
            cout << string(spaces * 2 - 2, ' ');
        }
        cout << endl;

        // Print connections (branches)
        if (currentLevel < height - 1) {
            cout << string(spaces / 2, ' '); // Leading spaces
            for (int i = 0; i < levelSize; i++) {
                cout << "/ \\ ";
                cout << string(spaces - 1, ' ');
            }
            cout << endl;
        }

        currentLevel++;
    }
}

int BinaryTree::calculateDepth(Node* node) {
    if (node == nullptr) return 0;
    int leftDepth = calculateDepth(node->left);
    int rightDepth = calculateDepth(node->right);
    return 1 + max(leftDepth, rightDepth);
}



void BinaryTree::insert(int value) {
    root = insert(root, value);
}

int BinaryTree::getDepth() {
    return calculateDepth(root);
}