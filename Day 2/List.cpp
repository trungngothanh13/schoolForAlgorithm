#include "List.h"
#include <iostream>

using namespace std;

List::~List() {
	Node* current = head;
	while (current != nullptr) {
		Node* next = current->next;
		delete current;
		current = next;
	}
	head = nullptr;
}

void List::traverse()
{
	for (Node* i = head; i != nullptr; i = i->next)
		cout << i->data << " ";
}