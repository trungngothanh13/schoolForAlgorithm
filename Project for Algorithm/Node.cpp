#include "Node.h"
#include <iostream>

using namespace std;


// Implement sortedListCombine here
Node* sortedListCombine(Node* n1, Node* n2) {
    Node* dummy = new Node(0);
    Node* dummyTail = dummy;

    while ((n1 != nullptr) && (n2 != nullptr)) {
        if (n1->data < n2->data) {
            dummyTail->next = new Node(n1->data);
            n1 = n1->next;
        }
        else {
            dummyTail->next = new Node(n2->data);
            n2 = n2->next;
        }
        dummyTail = dummyTail->next;
    }

    while (n1 != nullptr) {
        dummyTail->next = new Node(n1->data);
        n1 = n1->next;
        dummyTail = dummyTail->next;
    }
    while (n2 != nullptr) {
        dummyTail->next = new Node(n2->data);
        n2 = n2->next;
        dummyTail = dummyTail->next;
    }

    Node* combinedList = dummy->next;
    delete dummy;
    return combinedList;
}

// Implement findIntersection() here
Node* findIntersection(Node* head1, Node* head2) {
    Node* dummy = new Node(0);
    Node* tail = dummy;
    Node* ptr1 = head1;
    Node* ptr2 = head2;

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

    Node* intersectionList = dummy->next;
    delete dummy;
    return intersectionList;
}

// Implement deleteList() here
void deleteList(Node* head) {
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}