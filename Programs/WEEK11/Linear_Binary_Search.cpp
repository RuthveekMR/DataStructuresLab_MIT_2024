#include <iostream>
using namespace std;

// Linear Search (Sequential Search)
bool seqSearch(int list[], int last, int target, int& locn) {
    int looker = 0; // Start from the first element
    bool found = false;

    // Loop to find the target
    while (looker < last && target != list[looker]) {
        looker++;
    }

    locn = looker;
    if (target == list[looker]) {
        found = true;  // Target found
    } else {
        found = false; // Target not found
    }

    return found; // Return the result
}

// Binary Search
bool binarySearch(int list[], int last, int target, int& locn) {
    int begin = 0;
    int end = last;
    bool found = false;

    // Binary search loop
    while (begin <= end) {
        int mid = (begin + end) / 2;

        if (target > list[mid]) {
            begin = mid + 1;  // Look in the upper half
        } else if (target < list[mid]) {
            end = mid - 1;    // Look in the lower half
        } else {
            locn = mid;       // Target found
            found = true;
            break;
        }
    }

    if (!found) {
        locn = begin;  // If not found, locn points to where it would be
        found = false;
    }

    return found; // Return the result
}

int main() {
    int n, target, locn;
    int choice;

    // Input size of the list
    cout << "Enter the number of elements in the list: ";
    cin >> n;

    int list[n];

    // Input elements of the list
    cout << "Enter " << n << " elements (for binary search, ensure the list is sorted):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }

    // Input the target to search for
    cout << "Enter the target number to search: ";
    cin >> target;

    // Choose search method
    cout << "Choose search method: \n1. Linear Search \n2. Binary Search\n";
    cin >> choice;

    bool found;

    switch (choice) {
        case 1: // Linear Search
            found = seqSearch(list, n, target, locn);
            break;
        case 2: // Binary Search
            found = binarySearch(list, n - 1, target, locn); // n-1 is the last index
            break;
        default:
            cout << "Invalid choice!" << endl;
            return 1;
    }

    // Display the result
    if (found) {
        cout << "Target found at index " << locn << endl;
    } else {
        cout << "Target not found. Closest position would be at index " << locn << endl;
    }

    return 0;
}
