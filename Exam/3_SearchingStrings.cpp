#include <iostream>
#include <vector>
#include <string>
using namespace std;

int linearSearch(const vector<string>& arr, const string& target) {
    for (int i = 0; i < (int)arr.size(); i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    vector<string> arr = { "apple", "banana", "cherry", "date", "fig" };
    string target = "cherry";
    int index = linearSearch(arr, target);

    if (index != -1) {
        cout << "Element found at index " << index << endl;
    }
    else {
        cout << "Element not found!" << endl;
    }
    return 0;
}

// -------------- //

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int binarySearch(const vector<string>& arr, const string& target) {
    int left = 0, right = (int)arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<string> arr = { "apple", "banana", "cherry", "date", "fig" };
    // Already sorted alphabetically
    string target = "date";
    int index = binarySearch(arr, target);

    if (index != -1) {
        cout << "Element found at index " << index << endl;
    }
    else {
        cout << "Element not found!" << endl;
    }
    return 0;
}

// -------------- //

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int jumpSearch(const vector<string>& arr, const string& target) {
    int n = (int)arr.size();
    int step = (int)sqrt(n);
    int prev = 0;

    // Jump forward while the last element of the block is lexicographically less than target
    while (prev < n && arr[min(step, n) - 1] < target) {
        prev = step;
        step += (int)sqrt(n);
        if (prev >= n) return -1;
    }

    // Perform linear search in the identified block
    for (int i = prev; i < min(step, n); i++) {
        if (arr[i] == target) {
            return i;
        }
    }

    return -1;
}

int main() {
    vector<string> arr = { "apple", "banana", "cherry", "date", "fig", "grape" };
    string target = "fig";
    int index = jumpSearch(arr, target);

    if (index != -1) {
        cout << "Element found at index " << index << endl;
    }
    else {
        cout << "Element not found!" << endl;
    }
    return 0;
}

// -------------- //

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int stringValue(const string& s) {
    // Example: sum of character positions: 'a' = 1, 'b' = 2, etc.
    // This is simplistic and may cause collisions.
    int val = 0;
    for (char c : s) {
        val += (c - 'a' + 1);
    }
    return val;
}

int interpolationSearchStrings(const vector<string>& arr, const string& target) {
    int low = 0, high = (int)arr.size() - 1;
    int targetVal = stringValue(target);
    int lowVal = stringValue(arr[low]);
    int highVal = stringValue(arr[high]);

    while (low <= high && targetVal >= lowVal && targetVal <= highVal) {
        if (low == high) {
            if (arr[low] == target) return low;
            return -1;
        }

        int pos = low + ((targetVal - lowVal) * (high - low)) / (highVal - lowVal);

        if (arr[pos] == target) {
            return pos;
        }
        else if (arr[pos] < target) {
            low = pos + 1;
            lowVal = stringValue(arr[low]);
        }
        else {
            high = pos - 1;
            highVal = stringValue(arr[high]);
        }
    }

    return -1;
}

int main() {
    vector<string> arr = { "apple", "banana", "cherry", "date", "fig" };
    // Make sure arr is sorted lexicographically
    sort(arr.begin(), arr.end());
    string target = "date";
    int index = interpolationSearchStrings(arr, target);

    if (index != -1) {
        cout << "Element found at index " << index << endl;
    }
    else {
        cout << "Element not found!" << endl;
    }
    return 0;
}

// -------------- //

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string kthSmallest(vector<string>& arr, int k) {
    sort(arr.begin(), arr.end());
    return arr[k - 1];
}

int main() {
    vector<string> arr = { "pear", "apple", "orange", "banana", "kiwi" };
    int k = 3;
    cout << "The " << k << "-th smallest element is " << kthSmallest(arr, k) << endl;
    return 0;
}

// -------------- // Bonus 1

#include <iostream>
#include <string>
using namespace std;

int substringSearch(const string& text, const string& pattern) {
    int n = (int)text.size();
    int m = (int)pattern.size();

    if (m == 0) return 0; // empty pattern matches at the start

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == m) {
            return i; // Found a match at index i
        }
    }
    return -1; // Not found
}

int main() {
    string text = "Hello, this is a sample string.";
    string pattern = "sample";

    int index = substringSearch(text, pattern);
    if (index != -1) {
        cout << "Substring found at index " << index << endl;
    }
    else {
        cout << "Substring not found!" << endl;
    }

    return 0;
}

// -------------- // Bonus 2

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void computeLPSArray(const string& pattern, vector<int>& lps) {
    int length = 0; // length of the previous longest prefix suffix
    lps[0] = 0; // lps[0] is always 0
    int i = 1;

    while (i < (int)pattern.size()) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        }
        else {
            if (length != 0) {
                length = lps[length - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int KMPSearch(const string& text, const string& pattern) {
    int n = (int)text.size();
    int m = (int)pattern.size();

    vector<int> lps(m, 0);
    computeLPSArray(pattern, lps);

    int i = 0; // index for text
    int j = 0; // index for pattern
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        if (j == m) {
            return i - j; // found match
        }
        else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                i++;
            }
        }
    }
    return -1; // not found
}

int main() {
    string text = "Hello, this is a sample string.";
    string pattern = "sample";

    int index = KMPSearch(text, pattern);
    if (index != -1) {
        cout << "Substring found at index " << index << endl;
    }
    else {
        cout << "Substring not found!" << endl;
    }

    return 0;
}
