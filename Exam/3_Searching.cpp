#include <iostream>
#include <vector>
using namespace std;

int linearSearch(vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50};
    int target = 30;
    int index = linearSearch(arr, target);

    if (index != -1) {
        cout << "Element found at index " << index << endl;
    } else {
        cout << "Element not found!" << endl;
    }
    return 0;
}

// -------------- //

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50};
    int target = 40;
    int index = binarySearch(arr, target);

    if (index != -1) {
        cout << "Element found at index " << index << endl;
    } else {
        cout << "Element not found!" << endl;
    }
    return 0;
}

// -------------- //

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int jumpSearch(vector<int>& arr, int target) {
    int n = arr.size();
    int step = sqrt(n);
    int prev = 0;

    while (arr[min(step, n) - 1] < target) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) return -1;
    }

    for (int i = prev; i < min(step, n); i++) {
        if (arr[i] == target) {
            return i;
        }
    }

    return -1;
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15};
    int target = 11;
    int index = jumpSearch(arr, target);

    if (index != -1) {
        cout << "Element found at index " << index << endl;
    } else {
        cout << "Element not found!" << endl;
    }
    return 0;
}

// -------------- //

#include <iostream>
#include <vector>
using namespace std;

int interpolationSearch(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            if (arr[low] == target) return low;
            return -1;
        }

        int pos = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (arr[pos] == target) {
            return pos;
        } else if (arr[pos] < target) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }

    return -1;
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50};
    int target = 40;
    int index = interpolationSearch(arr, target);

    if (index != -1) {
        cout << "Element found at index " << index << endl;
    } else {
        cout << "Element not found!" << endl;
    }
    return 0;
}

// -------------- //

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int kthSmallest(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());
    return arr[k - 1];
}

int main() {
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;
    cout << "The " << k << "-th smallest element is " << kthSmallest(arr, k) << endl;
    return 0;
}