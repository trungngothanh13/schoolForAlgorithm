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