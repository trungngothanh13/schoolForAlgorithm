#pragma once

class Node {
public:
	int data;
	Node* next;
	Node(int data) {
		this->data = data;
		this->next = 0;
	}
};

class List
{
public:
	Node* head;
	List() {
		head = nullptr;
	}

	void traverse();

	~List();
};
