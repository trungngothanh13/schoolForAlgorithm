#include "List.h"
#include "Node.h"
#include <iostream>

using namespace std;

void List::traverse() {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int List::findNodeMiddle()
{
	if (head == 0) return -1;
	Node* slow = head;
	Node* fast = head;
	while (fast != 0 && fast->next != 0) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow->data;
}

void List::insertion(int value)
{
	Node* newNode = new Node(value);

	if (head == nullptr) {
		head = newNode;
		return;
	}
	Node* temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}

	temp->next = newNode;
}

List::~List() {
	Node* current = head;
	while (current != nullptr) {
		Node* next = current->next;
		delete current;
		current = next;
	}
	head = nullptr;
}