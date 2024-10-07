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

    void enQueue(char value);
    void deQueue();
    char front();
    bool isEmpty();
    bool isFull();
};