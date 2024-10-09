#pragma once
#include "List.h"
#include <iostream>
#include <string>


class Stack {
private:
    List list;
public:
    void push(int value);
    void pop();
    int top();
    bool isEmpty();
    bool isFull();
};