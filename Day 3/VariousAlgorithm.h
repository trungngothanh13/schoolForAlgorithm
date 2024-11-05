#pragma once
#include <vector>
#include <algorithm>

using namespace std;

class VariousAlgorithm
{
};

int countBinarySearchStyle(vector<int>& arr, int item, int low, int high);
int jumpSearch(const vector<int>& arr, int item, int stepSize);
int interpolationSearch(const vector<int>& arr, int target);
int exponentialSearch(const vector<int>& arr, int target);