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
	void sortedListsCombine(List& list1, List& list2);
	void findIntersection(List& list1, List& list2);

	~List();
};

