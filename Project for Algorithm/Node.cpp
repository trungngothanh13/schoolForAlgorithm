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

int Node::findNodeMiddle()
{
	if (this == 0) return -1;
	Node* slow = this;
	Node* fast = this;
	while (fast != 0 && fast->next != 0) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow->data;
}