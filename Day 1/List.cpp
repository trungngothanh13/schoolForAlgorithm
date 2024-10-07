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

void List::sortedListsCombine(List& list1, List& list2) {
    // Create local pointers to traverse through list1 and list2
    Node* l1 = list1.head;
    Node* l2 = list2.head;

    Node* dummy = new Node(0);
    Node* dummyTail = dummy;

    // Merge the two lists
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->data < l2->data) {
            dummyTail->next = new Node(l1->data);
            l1 = l1->next;
        }
        else {
            dummyTail->next = new Node(l2->data);
            l2 = l2->next;
        }
        dummyTail = dummyTail->next;
    }
    if (l1 != nullptr) {
        dummyTail->next = new Node(l1->data);
    }
    else {
        dummyTail->next = new Node(l2->data);
    }

    head = dummy->next;
    delete dummy;
}

void List::findIntersection(List& list1, List& list2) {

    Node* ptr1 = list1.head;
    Node* ptr2 = list2.head;

    Node* dummy = new Node(0);
    Node* tail = dummy;

    while (ptr1 != nullptr && ptr2 != nullptr) {
        if (ptr1->data == ptr2->data) {
            tail->next = new Node(ptr1->data);
            tail = tail->next;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if (ptr1->data < ptr2->data) {
            ptr1 = ptr1->next;
        }
        else {
            ptr2 = ptr2->next;
        }
    }

    head = dummy->next;
    delete dummy;
}
