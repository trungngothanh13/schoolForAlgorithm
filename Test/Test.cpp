#include <iostream>
#include <queue>
#include <ctime>
#include <cstdlib>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

TreeNode* blank = new TreeNode(-1);

class BinaryTree {
public:
    TreeNode* root;
    int levels;

    void printLevelOrder(TreeNode* node) {
        if (!node) {
            cout << "[]\n";
            return;
        }

        queue<TreeNode*> q;
        q.push(node);
        q.push(nullptr); // Marker for the end of the current level

        int currentLevel = 1;
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            if (current) {
                if (current->data != -1)
                    cout << current->data << " ";
                else cout << "[] ";

                if (current->left)
                    q.push(current->left);
                else q.push(blank); // Placeholder for missing left child

                if (current->right) 
                    q.push(current->right);
                else q.push(blank); // Placeholder for missing right child
            }
            else {
                cout << endl; // End of the current level
                if (!q.empty()) q.push(nullptr); // Add marker for the next level
                if (currentLevel < levels) currentLevel++;
                else break;
            }
        }
    }

    BinaryTree() : root(nullptr) {}

    // Function to create a random binary tree
    void createRandomTree() {
        srand(time(0));

        root = new TreeNode(rand() % 100); // Create root with random value
        queue<TreeNode*> q;
        q.push(root);

        int currentLevel = 1;
        while (currentLevel < levels) {
            int nodesInLevel = q.size(); // Nodes at the current level
            for (int i = 0; i < nodesInLevel; i++) {
                TreeNode* current = q.front();
                q.pop();

                // Randomly create left child
                if (rand() % 2 == 1) {
                    current->left = new TreeNode(rand() % 100);
                    q.push(current->left);
                }

                // Randomly create right child
                if (rand() % 2 == 1) {
                    current->right = new TreeNode(rand() % 100);
                    q.push(current->right);
                }
            }
            currentLevel++;
        }

        cout << "Initial random tree: " << endl;
        printLevelOrder(root);
    }

    // Function to add a new node to the tree using BFS
    void addNode(int value) {
        if (!root) {
            root = new TreeNode(value);
            return;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            if (!current->left) {
                current->left = new TreeNode(value);
                break;
            }
            else q.push(current->left);


            if (!current->right) {
                current->right = new TreeNode(value);
                break;
            }
            else q.push(current->right);
        }
    }

    // Function to print the current state of the tree
    void printTree() {
        printLevelOrder(root);
    }
};

int main() {
    BinaryTree tree;

    cout << "Enter the number of levels for the tree: ";
    int levels; cin >> levels;
    tree.levels = levels;

    tree.createRandomTree();

    int option;
    while (true) {
        cout << endl;
        cout << "1. Add a value to the tree\n";
        cout << "2. Print the current tree\n";
        cout << "Enter your choice: ";
        cin >> option;

        if (option == 1) {
            int value;
            cout << "Value: ";
            cin >> value;
            tree.addNode(value);
        }
        else if (option == 2) {
            tree.printTree();
        }
        else break;
    }

    return 0;
}