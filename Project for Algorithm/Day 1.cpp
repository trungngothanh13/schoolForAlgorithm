#include <iostream>
#include <algorithm>
#include "Node.h"

using namespace std;



int findNodeMiddle(Node* head) {
	if (head == 0) return -1;
	Node* slow = head;
	Node* fast = head;
	while (fast != 0 && fast->next != 0) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow->data;
}

Node* sortedListCombine(Node* n1, Node* n2) {
	Node* dummy = new Node(0);
	Node* dummyTail = dummy;
	while ((n1 != 0) && (n2 != 0))
	{
		if (n1->data < n2->data) {
			dummyTail->next = new Node(n1->data);
			n1 = n1->next;
		}
		else
		{
			dummyTail->next = new Node(n2->data);
			n2 = n2->next;
		}
		dummyTail = dummyTail->next;
	}

	while (n1 != 0) {
		dummyTail->next = new Node(n1->data);
		n1 = n1->next;
		dummyTail = dummyTail->next;
	}
	while (n2 != 0) {
		dummyTail->next = new Node(n2->data);
		n2 = n2->next;
		dummyTail = dummyTail->next;
	}

	Node* combinedList = dummy->next;
	delete dummy;
	return combinedList;
}

Node* findIntersection(Node* head1, Node* head2) { // 2 pointers technique
	Node* dummy = new Node(0); // Simplifying edge cases
	Node* tail = dummy;
	Node* ptr1 = head1;
	Node* ptr2 = head2;

	while (ptr1 != 0 && ptr2 != 0) {
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

	Node* intersectionList = dummy->next;
	delete dummy;
	return intersectionList;
}

void deleteList(Node* head) {
	Node* temp;
	while (head != 0) {
		temp = head;
		head = head->next;
		delete temp;
	}
}

int main()
{
	Node* n1 = new Node(9);
	Node* n2 = new Node(17);
	Node* n3 = new Node(32);
	Node* head1 = n1;
	head1->next = n2;
	n2->next = n3;
	n3->next = 0;

	Node* n4 = new Node(17);
	Node* n5 = new Node(32);
	Node* n6 = new Node(64);
	Node* head2 = n4;
	head2->next = n5;
	n5->next = n6;
	n6->next = 0;


	Node* result = findIntersection(head1, head2);
	result->traverse();
	deleteList(result);


}
