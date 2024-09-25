#include <iostream>
#include <algorithm>
#include "List.h"

using namespace std;


int main()
{
	List exampleList;
	exampleList.insertion(3);
	exampleList.insertion(7);
	exampleList.insertion(5);

	exampleList.traverse();
}
