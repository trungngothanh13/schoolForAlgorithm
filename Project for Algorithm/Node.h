#pragma once
class Node {
public:
	int data;
	Node* next;
	Node(int data) {
		this->data = data;
		this->next = 0;
	}
	void traverse();
	int findNodeMiddle();
};

Node* sortedListCombine(Node* n1, Node* n2);
Node* findIntersection(Node* head1, Node* head2);
void deleteList(Node* head);