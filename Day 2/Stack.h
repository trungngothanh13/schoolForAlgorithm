#pragma once
#include "List.h"
#include <iostream>
#include <string>


class Stack {
private:
    List list;
public:
    void push(char value);
    void pop();
    char top();
    bool isEmpty();
    bool isFull();
};