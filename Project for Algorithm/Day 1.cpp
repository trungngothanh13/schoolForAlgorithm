#include <iostream>
#include <algorithm>
#include "List.h"

using namespace std;


int main()
{
	List exampleList;
	exampleList.insertion(3);
	exampleList.insertion(7);
	exampleList.insertion(13);
	exampleList.insertion(19);
	exampleList.insertion(26);

	List anotherExampleList;
	anotherExampleList.insertion(7);
	anotherExampleList.insertion(19);
	anotherExampleList.insertion(26);
	anotherExampleList.insertion(45);

	List anotherAnotherExampleList;
	anotherAnotherExampleList.findIntersection(exampleList, anotherExampleList);
	anotherAnotherExampleList.traverse();
	cout << endl;

	exampleList.traverse();
	anotherExampleList.traverse();
}
