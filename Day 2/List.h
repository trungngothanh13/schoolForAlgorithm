#pragma once

class Node {
public:
	char data;
	Node* next;
	Node(char data) {
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

	~List();
};
