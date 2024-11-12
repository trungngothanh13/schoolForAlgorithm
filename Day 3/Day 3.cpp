#include <iostream>
#include <vector>
#include <algorithm>
#include "VariousAlgorithm.h"

using namespace std;

int main()
{
	vector<int> A = { 12, 12, 12, 6, 3, 4, 7, 367 };

	sort(A.begin(), A.end());


	cout << interpolationSearch(A, 367);
	cout << exponentialSearch(A, 7);
}
