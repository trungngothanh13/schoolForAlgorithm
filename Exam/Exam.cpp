#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

void preOrder(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(TreeNode* root) {
    if (root == nullptr) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(TreeNode* root) {
    if (root == nullptr) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) return new TreeNode(value);
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

bool search(TreeNode* root, int value) {
    if (root == nullptr) return false;
    if (root->data == value) return true;
    if (value < root->data) return search(root->left, value);
    return search(root->right, value);
}

int findMin(TreeNode* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root->data;
}

TreeNode* deleteNode(TreeNode* root, int value) {
    if (root == nullptr) return root;
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    }
    else {
        // Node found
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        // Two children
        root->data = findMin(root->right);
        root->right = deleteNode(root->right, root->data);
    }
    return root;
}

int height(TreeNode* root) {
    if (root == nullptr) return 0;
    return 1 + max(height(root->left), height(root->right));
}

int diameter(TreeNode* root, int& diameterLength) {
    if (root == nullptr) return 0;

    int leftHeight = diameter(root->left, diameterLength);
    int rightHeight = diameter(root->right, diameterLength);

    diameterLength = max(diameterLength, leftHeight + rightHeight);
    return 1 + max(leftHeight, rightHeight);
}

int calculateDiameter(TreeNode* root) {
    int diameterLength = 0;
    diameter(root, diameterLength);
    return diameterLength;
}

bool isBalanced(TreeNode* root) {
    if (root == nullptr) return true;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

TreeNode* findLCA(TreeNode* root, int n1, int n2) {
    if (root == nullptr) return nullptr;

    if (root->data > n1 && root->data > n2) {
        return findLCA(root->left, n1, n2);
    }

    if (root->data < n1 && root->data < n2) {
        return findLCA(root->right, n1, n2);
    }

    return root;
}

void levelOrder(TreeNode* root) {
    if (root == nullptr) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        cout << current->data << " ";

        if (current->left != nullptr) q.push(current->left);
        if (current->right != nullptr) q.push(current->right);
    }
}


int main() {
    TreeNode* root = nullptr;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "In-order Traversal: ";
    inOrder(root);
    cout << endl;

    cout << "Height of Tree: " << height(root) << endl;

    cout << "Diameter of Tree: " << calculateDiameter(root) << endl;

    cout << "Is Balanced: " << (isBalanced(root) ? "Yes" : "No") << endl;

    cout << "Level Order Traversal: ";
    levelOrder(root);
    cout << endl;

    int data = findLCA(root, 20, 40)->data;
    cout << "Lowest Common Ancestor of (20, 40) is: " << data;

    return 0;
}