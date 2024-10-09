#include <iostream>
#include <algorithm>
#include "Queue.h"

using namespace std;


int main() 
{
	Queue newQueue;
	newQueue.enQueue(117);
	newQueue.enQueue(446);
	newQueue.enQueue(2);
	newQueue.enQueue(53);
	newQueue.enQueue(468);

	newQueue.print(); cout << endl;

	newQueue.deQueue();

	newQueue.print(); cout << endl;

	if (newQueue.isEmpty())
		cout << "Queue is empty";
	else
		cout << "Queue is not empty";
	cout << endl;

	if (newQueue.isFull())
		cout << "Queue is full";
	else
		cout << "Queue is not full";
	cout << endl;

	cout << newQueue.front() << " " << newQueue.rear();
}
