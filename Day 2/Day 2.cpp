#include <iostream>
#include <algorithm>
#include "Stack.h"

using namespace std;

void part1_IC()
{
	Stack checkStack;
	checkStack.push(12);
	checkStack.push(18);
	checkStack.push(72);
	checkStack.push(64);
	checkStack.push(138);
	checkStack.push(456);
	checkStack.pop();
	checkStack.pop();
	if (checkStack.isEmpty()) cout << "Stack is empty" << endl;
	if (checkStack.isFull()) cout << "Stack is full" << endl;
}

int main() 
{
	part1_IC();

}
