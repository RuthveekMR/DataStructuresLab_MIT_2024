#include <iostream>
using namespace std;

// Function to perform Selection Sort
void selectionSort(int list[], int last) {
    for (int i = 0; i <= last; i++) {
        int smallest = i;
        for (int j = i + 1; j <= last; j++) {
            if (list[j] < list[smallest]) {
                smallest = j;
            }
        }
        swap(list[i], list[smallest]);
    }
}

// Function to perform Bubble Sort
void bubbleSort(int list[], int last) {
    int i = 0;
    bool sorted = false;

    while (i <= last && !sorted) {
        int j = last;
        sorted = true;
        while (j > i) {
            if (list[j] < list[j - 1]) {
                sorted = false;
                swap(list[j], list[j - 1]);
            }
            j--;
        }
        i++;
    }
}

// Function to perform Quick Sort
int partition(int list[], int low, int high) {
    int key = list[low];
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= high && list[i] <= key) {
            i++;
        }
        while (list[j] > key) {
            j--;
        }
        if (i < j) {
            swap(list[i], list[j]);
        }
    }
    swap(list[low], list[j]);
    return j;
}

void quickSort(int list[], int low, int high) {
    if (low < high) {
        int mid = partition(list, low, high);
        quickSort(list, low, mid - 1);
        quickSort(list, mid + 1, high);
    }
}

// Function to perform Insertion Sort
void insertionSort(int list[], int last) {
    for (int i = 1; i <= last; i++) {
        int hold = list[i];
        int j = i - 1;

        while (j >= 0 && hold < list[j]) {
            list[j + 1] = list[j];
            j--;
        }
        list[j + 1] = hold;
    }
}

int main() {
    int n, choice;

    // User input: size of the array
    cout << "Enter the number of elements in the list: ";
    cin >> n;

    int list[n];

    // User input: elements of the array
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }

    // User input: choice of sorting algorithm
    cout << "Choose a sorting algorithm:\n";
    cout << "1. Selection Sort\n";
    cout << "2. Bubble Sort\n";
    cout << "3. Quick Sort\n";
    cout << "4. Insertion Sort\n";
    cin >> choice;

    // Sorting based on user choice
    switch (choice) {
        case 1:
            selectionSort(list, n - 1);
            break;
        case 2:
            bubbleSort(list, n - 1);
            break;
        case 3:
            quickSort(list, 0, n - 1);
            break;
        case 4:
            insertionSort(list, n - 1);
            break;
        default:
            cout << "Invalid choice!\n";
            return 1;
    }

    // Output: Sorted array
    cout << "Sorted list:\n";
    for (int i = 0; i < n; i++) {
        cout << list[i] << " ";
    }
    cout << endl;

    return 0;
}
