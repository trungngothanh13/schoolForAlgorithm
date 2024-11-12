#include <iostream>
#include <vector>
#include <algorithm>
#include "VariousAlgorithm.h"

using namespace std;


void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> quickSortArray = { 4, 1, 2, 4, 5 };
    vector<int> mergeSortArray = { 4, 1, 2, 5, 7 };

    quickSort(quickSortArray, 0, quickSortArray.size() - 1);
    printArray(quickSortArray);

    mergeSort(mergeSortArray, 0, mergeSortArray.size() - 1);
    printArray(mergeSortArray);

    return 0;
}
