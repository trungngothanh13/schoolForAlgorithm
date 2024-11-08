#include <iostream>
#include <vector>
#include <algorithm>
#include "VariousAlgorithm.h"

using namespace std;

void inputArray(vector<int>& arr) {
    int n;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> quickSortArray;
    vector<int> mergeSortArray;

    inputArray(quickSortArray);
    quickSort(quickSortArray, 0, quickSortArray.size() - 1);
    printArray(quickSortArray);

    inputArray(mergeSortArray);
    mergeSort(mergeSortArray, 0, mergeSortArray.size() - 1);
    printArray(mergeSortArray);

    return 0;
}
