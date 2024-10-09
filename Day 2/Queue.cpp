#include "Queue.h"
using namespace std;

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

void Queue::deQueue() {
    if (!isEmpty()) {
        Node* temp = list.head;
        list.head = list.head->next;
        delete temp;
        if (list.head == nullptr) {
            tail = nullptr;
        }
    }
    else {
        cout << "Queue underflow!" << endl;
    }
}

int Queue::front() {
    if (!isEmpty()) {
        return list.head->data;
    }
    else {
        cout << "Queue is empty!" << endl;
        return '-1';
    }
}

int Queue::rear()
{
    if (!isEmpty()) {
        return tail->data;
    }
    else {
        cout << "Queue is empty!" << endl;
        return '-1';
    }
}

bool Queue::isEmpty() {
    return list.head == nullptr;
}

bool Queue::isFull() {
    return false; // Queue is never full since it's based on dynamic memory allocation
}

void Queue::print() {
    list.traverse();
}