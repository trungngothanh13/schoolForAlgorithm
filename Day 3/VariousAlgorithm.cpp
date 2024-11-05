#include "VariousAlgorithm.h"

int countBinarySearchStyle(vector<int>& arr, int item, int low, int high) {
    if (arr.empty()) return 0;

    int first = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == item) {
            first = mid;
            high = mid - 1;
        }
        else if (arr[mid] < item) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if (first == -1) return 0;
    low = 0;
    high = arr.size() - 1;
    int last = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == item) {
            last = mid;
            low = mid + 1; 
        }
        else if (arr[mid] < item) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return last - first + 1;
}

int jumpSearch(const vector<int>& arr, int item, int stepSize) {
    int n = arr.size();

    if (n == 0) return -1;

    int prev = 0;
    int step = stepSize;

    while (arr[min(step, n) - 1] < item) {
        prev = step;
        step += stepSize;
        if (prev >= n)
            return -1;
    }

    for (int i = prev; i < min(step, n); ++i) {
        if (arr[i] == item) {
            return i;
        }
    }

    return -1;
}

int interpolationSearch(const vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        int probe = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low]);
        if (arr[probe] == target)
            return probe;
        if (arr[probe] < target)
            low = probe + 1;
        else
            high = probe - 1;
    }
    return -1;
}

int exponentialSearch(const vector<int>& arr, int target) {
    int n = arr.size();

    if (arr[0] == target)
        return 0;

    int i = 1;
    while (i < n && arr[i] <= target)
        i *= 2;

    // Binary search to return the target position
    auto it = lower_bound(arr.begin() + i / 2, arr.begin() + min(i, n), target);
    if (it != arr.end() && *it == target)
        return it - arr.begin();
    else
        return -1;
}
