#pragma once
#include "Node.h"

class List
{
private:
	Node* head;

public:

	List() {
		head = nullptr;
	}

	void insertion(int value);
	void traverse();
	int findNodeMiddle();
	
	~List();
};

