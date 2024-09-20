#include "Node.h"
#include <iostream>

using namespace std;

void Node::traverse() {
    Node* curr = this; // Start from the current node
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}