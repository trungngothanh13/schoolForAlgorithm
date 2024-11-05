#include <iostream>
#include <vector>
#include <algorithm>
#include "VariousAlgorithm.h"

using namespace std;

int main()
{
	vector<int> A;
	A.push_back(12);
	A.push_back(17);
	A.push_back(63);
	A.push_back(44);
	A.push_back(27);
	A.push_back(117);
	A.push_back(741);
	A.push_back(624);
	A.push_back(44);
	A.push_back(32);
	A.push_back(367);
	A.push_back(181);

	sort(A.begin(), A.end());

	cout << interpolationSearch(A, 367);
}
