#pragma once
class Node {
public:
	int data;
	Node* next;
	Node(int data) {
		this->data = data;
		this->next = 0;
	}
	void traverse();     // Traverses the linked list starting from this node
	int findNodeMiddle();
};