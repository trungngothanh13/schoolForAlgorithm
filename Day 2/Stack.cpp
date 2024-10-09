#include "Stack.h"

using namespace std;

// Pushes a new value onto the stack
void Stack::push(int value) {
    Node* newNode = new Node(value);
    newNode->next = list.head;
    list.head = newNode;
}

// Pops the top value off the stack
void Stack::pop() {
    if (!isEmpty()) {
        Node* temp = list.head;
        list.head = list.head->next;
        delete temp;
    }
    else {
        cout << "Stack underflow!" << endl;
    }
}

// Returns the top value of the stack without removing it
int Stack::top() {
    if (!isEmpty()) {
        return list.head->data;
    }
    else {
        cout << "Stack is empty!" << endl;
        return '-1';
    }
}

// Checks if the stack is empty
bool Stack::isEmpty() {
    return list.head == nullptr;
}

// Dummy function for isFull (no practical limit in a dynamic list)
bool Stack::isFull() {
    return false; // Stack is never full since it's based on dynamic memory allocation
}

void Stack::print() {
    list.traverse();
}