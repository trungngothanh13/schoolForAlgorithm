#include "Queue.h"
using namespace std;

// Adds a new value to the back of the queue
void Queue::enQueue(int value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        list.head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Removes the value at the front of the queue
void Queue::deQueue() {
    if (!isEmpty()) {
        Node* temp = list.head;
        list.head = list.head->next;
        delete temp;
        if (list.head == nullptr) { // If the list becomes empty, reset the tail as well
            tail = nullptr;
        }
    }
    else {
        cout << "Queue underflow!" << endl;
    }
}

// Returns the value at the front of the queue without removing it
int Queue::front() {
    if (!isEmpty()) {
        return list.head->data;
    }
    else {
        cout << "Queue is empty!" << endl;
        return '-1';
    }
}

// Checks if the queue is empty
bool Queue::isEmpty() {
    return list.head == nullptr;
}

// Dummy function for isFull (no practical limit in a dynamic list)
bool Queue::isFull() {
    return false; // Queue is never full since it's based on dynamic memory allocation
}