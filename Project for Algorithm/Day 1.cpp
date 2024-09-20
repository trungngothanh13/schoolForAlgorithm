#include <iostream>
#include <algorithm>
#include "Node.h"

using namespace std;


int main()
{
	Node* n1 = new Node(9);
	Node* n2 = new Node(17);
	Node* n3 = new Node(32);
	Node* list1 = n1;
	list1->next = n2;
	n2->next = n3;
	n3->next = 0;

	Node* n4 = new Node(17);
	Node* n5 = new Node(32);
	Node* n6 = new Node(64);
	Node* list2 = n4;
	list2->next = n5;
	n5->next = n6;
	n6->next = 0;


	Node* intersections = findIntersection(list1, list2);
	intersections->traverse();


}
