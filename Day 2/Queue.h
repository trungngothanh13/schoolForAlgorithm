#pragma once
#include "List.h"
#include <iostream>
#include <string>

class Queue {
private:
    List list;    // Using the List to represent the queue
    Node* tail;   // Keep track of the last node (for enQueue)

public:
    Queue() {
        tail = nullptr;
    }

    void enQueue(int value);
    void deQueue();
    int front();
    int rear();
    bool isEmpty();
    bool isFull();
    void print();
};