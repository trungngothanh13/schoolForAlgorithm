#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <vector>

using namespace std;

int sizeList = 12;

class Node {
public:
    string nameZodiac;
    string dateRange;
    string rulingPlanet;
    string personalityTrait;
    int startDate;
    Node* next;
    Node* prev;

    Node(string _nameZodiac, string _dateRange, string _rulingPlanet, string _personalityTrait) {
        this->nameZodiac = _nameZodiac;
        this->dateRange = _dateRange;
        this->rulingPlanet = _rulingPlanet;
        this->personalityTrait = _personalityTrait;
        this->next = nullptr;
        this->prev = nullptr;
        this->startDate = parseStartDate(_dateRange);
    }

    static int monthToNumber(const string& month) {
        string m = month;
        for (auto& c : m) c = tolower((unsigned char)c);

        if (m == "january") return 1;
        else if (m == "february") return 2;
        else if (m == "march") return 3;
        else if (m == "april") return 4;
        else if (m == "may") return 5;
        else if (m == "june") return 6;
        else if (m == "july") return 7;
        else if (m == "august") return 8;
        else if (m == "september") return 9;
        else if (m == "october") return 10;
        else if (m == "november") return 11;
        else if (m == "december") return 12;
        return 0;
    }

    static int parseStartDate(const string& dateRange) {
        string month1, month2, dash;
        int day1, day2;
        char c;
        stringstream ss(dateRange);
        ss >> month1 >> day1 >> dash >> month2 >> day2;
        int m1 = monthToNumber(month1);
        return m1 * 100 + day1;
    }
};

class List {
public:
    Node* head;
    Node* tail;

    List() {
        head = nullptr;
        tail = nullptr;
    }

    void InsertAtHead(Node* info) {
        if (head == NULL) {
            head = info;
            tail = head;
        }
        else {
            info->next = head;
            head->prev = info;
            head = info;
        }
    }

    void insertAtPosition(Node* info, int position) {
        if (position == 0) {
            InsertAtHead(info);
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Position out of bounds!" << endl;
            delete info;
            return;
        }

        info->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = info;
        }
        else {
            tail = info;
        }
        temp->next = info;
        info->prev = temp;
    }

    void traverse() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->nameZodiac << ", "
                << temp->dateRange << ", "
                << temp->rulingPlanet << ", "
                << temp->personalityTrait << " -> " << endl;
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    Node* findByName(const string& name) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->nameZodiac == name)
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }
};

Node* getTail(Node* head) {
    if (!head) return nullptr;
    while (head->next) {
        head = head->next;
    }
    return head;
}

void concatenateLists(Node* lessHead, Node* lessTail, Node* equalHead, Node* equalTail, Node* greaterHead, Node* greaterTail, Node*& newHead, Node*& newTail) {
    newHead = nullptr;
    newTail = nullptr;

    if (lessHead) {
        newHead = lessHead;
        newTail = lessTail;
    }

    if (equalHead) {
        if (!newHead) {
            newHead = equalHead;
            newTail = equalTail;
        }
        else {
            newTail->next = equalHead;
            equalHead->prev = newTail;
            newTail = equalTail;
        }
    }

    if (greaterHead) {
        if (!newHead) {
            newHead = greaterHead;
            newTail = greaterTail;
        }
        else {
            newTail->next = greaterHead;
            greaterHead->prev = newTail;
            newTail = greaterTail;
        }
    }
}

void partitionList(Node* head, Node* tail, Node* pivot, Node*& newHead, Node*& newTail, Node*& pivotHead, Node*& pivotTail) {
    pivotHead = pivot;
    pivotTail = pivot;
    Node* curr = head;

    Node* lessHead = nullptr, * lessTail = nullptr;
    Node* equalHead = pivotHead, * equalTail = pivotTail;
    Node* greaterHead = nullptr, * greaterTail = nullptr;

    int pivotValue = pivot->startDate;

    while (curr != nullptr) {
        if (curr == pivot) {
            curr = curr->next;
            continue;
        }
        int currValue = curr->startDate;
        if (currValue < pivotValue) {
            if (!lessHead) {
                lessHead = curr;
                lessTail = curr;
            }
            else {
                lessTail->next = curr;
                curr->prev = lessTail;
                lessTail = curr;
            }
        }
        else if (currValue == pivotValue) {
            equalTail->next = curr;
            curr->prev = equalTail;
            equalTail = curr;
        }
        else {
            if (!greaterHead) {
                greaterHead = curr;
                greaterTail = curr;
            }
            else {
                greaterTail->next = curr;
                curr->prev = greaterTail;
                greaterTail = curr;
            }
        }
        curr = curr->next;
    }

    if (lessTail) lessTail->next = nullptr;
    if (equalTail) equalTail->next = nullptr;
    if (greaterTail) greaterTail->next = nullptr;

    concatenateLists(lessHead, lessTail, equalHead, equalTail, greaterHead, greaterTail, newHead, newTail);

    pivotHead = equalHead;
    pivotTail = equalTail;
}


void quickSortRecur(Node*& head, Node*& tail) {
    if (!head || head == tail) return;

    Node* pivot = tail;

    Node* newHead = nullptr, * newTail = nullptr;
    Node* pivotHead = nullptr, * pivotTail = nullptr;

    partitionList(head, tail, pivot, newHead, newTail, pivotHead, pivotTail);

    Node* lessHead = newHead;
    Node* lessTail = (pivotHead) ? pivotHead->prev : nullptr;

    if (lessHead && lessHead != pivotHead) {
        quickSortRecur(lessHead, lessTail);
    }

    Node* greaterHead = pivotTail ? pivotTail->next : nullptr;
    Node* greaterTail = newTail;

    if (greaterHead && greaterHead != pivotTail) {
        quickSortRecur(greaterHead, greaterTail);
    }

    if (lessHead) {
        head = lessHead;
    }
    else {
        head = pivotHead;
    }

    if (greaterTail) {
        tail = greaterTail;
    }
    else {
        tail = pivotTail;
    }

    Node* temp = head;
    Node* prev = nullptr;
    while (temp) {
        temp->prev = prev;
        prev = temp;
        temp = temp->next;
    }
}

void quickSortList(List& lst) {
    if (!lst.head || lst.head == lst.tail) return;
    Node* tail = getTail(lst.head);
    quickSortRecur(lst.head, tail);
    lst.tail = tail;
}

int stringValue(const string& s) {
    int val = 0;
    for (char c : s) {
        val += (c - 'a' + 1);
    }
    return val;
}

int interpolationSearchStrings(const vector<string>& arr, const string& target) {
    // Idea: convert string to a sum of number, sort the number and find that exact number
    int low = 0, high = (int)arr.size() - 1;
    int targetVal = stringValue(target);

    while (low <= high) {
        int lowVal = stringValue(arr[low]);
        int highVal = stringValue(arr[high]);
        if (lowVal == highVal) {
            if (arr[low] == target)
                return low;
            else
                return -1;
        }

        if (targetVal < lowVal || targetVal > highVal) {
            return -1;
        }

        int pos = low + ((targetVal - lowVal) * (high - low)) / (highVal - lowVal);

        if (arr[pos] == target) {
            return pos;
        }
        else if (stringValue(arr[pos]) < targetVal) {
            low = pos + 1;
        }
        else {
            high = pos - 1;
        }
    }

    return -1;
}

void searchAndPrintZodiac(List& signList, const vector<string>& sortedSigns, const string& signName) {
    int index = interpolationSearchStrings(sortedSigns, signName);
    if (index == -1) {
        cout << "Not Found." << endl;
        return;
    }

    Node* signNode = signList.findByName(signName);
    if (signNode) {
        cout << "Sign: " << signNode->nameZodiac << endl;
        cout << "Date Range: " << signNode->dateRange << endl;
        cout << "Ruling Planet: " << signNode->rulingPlanet << endl;
        cout << "Personality Traits: " << signNode->personalityTrait << endl;
    }
    else {
        cout << "Not Found." << endl;
    }
}

void searchSignsByLetter(List& signList, char letter) {
    letter = tolower((unsigned char)letter);
    Node* temp = signList.head;
    bool found = false;
    while (temp != nullptr) {
        if (!temp->nameZodiac.empty() && tolower((unsigned char)temp->nameZodiac[0]) == letter) {
            cout << temp->nameZodiac << endl;
            found = true;
        }
        temp = temp->next;
    }
    if (!found)
        cout << "No signs found" << endl;
}

int main() {
    List signList;
    Node* sign = new Node("Aries", "March 21 - April 19", "planet1", "umm1");
    signList.insertAtPosition(sign, 0);
    sign = new Node("Taurus", "April 20 - May 20", "planet2", "umm2");
    signList.insertAtPosition(sign, 1);
    sign = new Node("Gemini", "May 21 - June 20", "planet3", "umm3");
    signList.insertAtPosition(sign, 2);
    sign = new Node("Cancer", "June 21 - July 22", "Moon", "umm4");
    signList.insertAtPosition(sign, 3);
    sign = new Node("Leo", "July 23 - August 22", "Sun", "umm5");
    signList.insertAtPosition(sign, 4);
    sign = new Node("Virgo", "August 23 - September 22", "planet6", "umm6");
    signList.insertAtPosition(sign, 5);
    sign = new Node("Libra", "September 23 - October 22", "planet7", "umm7");
    signList.insertAtPosition(sign, 6);
    sign = new Node("Scorpio", "October 23 - November 21", "planet8", "umm8");
    signList.insertAtPosition(sign, 7);
    sign = new Node("Sagittarius", "November 22 - December 21", "planet9", "umm9");
    signList.insertAtPosition(sign, 8);
    sign = new Node("Capricorn", "December 22 - January 19", "planet10", "umm10");
    signList.insertAtPosition(sign, 9);
    sign = new Node("Aquarius", "January 20 - February 18", "planet11", "umm11");
    signList.insertAtPosition(sign, 10);
    sign = new Node("Pisces", "February 19 - March 20", "planet12", "umm12");
    signList.insertAtPosition(sign, 11);

    signList.traverse();

    vector<string> sortedSigns = {
    "Aquarius", "Aries", "Cancer", "Capricorn", "Gemini",
    "Leo", "Libra", "Pisces", "Sagittarius", "Scorpio", "Taurus", "Virgo"
    };

    searchAndPrintZodiac(signList, sortedSigns, "Leo");
    // Expected: Signed: Leo, Date Range: trait 5", " July 23 - August 22, Ruling Planet: planet 5, Personality Traits: trait 5
    searchAndPrintZodiac(signList, sortedSigns, "Ophiuchus");
    searchSignsByLetter(signList, 'C');

    quickSortList(signList);

    cout << endl;
    cout << "Sorting by start date:" << endl;
    signList.traverse();

    return 0;
}