#include <iostream>

using namespace std;

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // Return the index if the key is found
        }
    }
    return -1; // Return -1 if the key is not found
}

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to print an integer array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Selection Sort algorithm for integers (ascending order)
void selectionSort(int arr[], int n) {
    int i, j, min_index;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) {
        // Find the minimum element in unsorted array
        min_index = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        // Swap the found minimum element with the first element of the unsorted array
        swap(&arr[i], &arr[min_index]);
    }
}

int main() {
    // Test with an integer array of size 5
    int intArray[5] = { 64, 25, 12, 22, 11 };
    int size = sizeof(intArray) / sizeof(intArray[0]);
    int searchKey = 22;

    cout << "Original integer array: ";
    printArray(intArray, size);

    // Perform linear search
    int searchResult = linearSearch(intArray, size, searchKey);
    if (searchResult != -1) {
        cout << searchKey << " found at index: " << searchResult << endl;
    }
    else {
        cout << searchKey << " not found in the array." << endl;
    }

    selectionSort(intArray, size);
    cout << "Sorted integer array: ";
    printArray(intArray, size);

    // Perform linear search on the sorted array
    searchKey = 12;
    searchResult = linearSearch(intArray, size, searchKey);
    if (searchResult != -1) {
        cout << searchKey << " found at index: " << searchResult << endl;
    }
    else {
        cout << searchKey << " not found in the array." << endl;
    }

    searchKey = 50; // Key not present
    searchResult = linearSearch(intArray, size, searchKey);
    if (searchResult != -1) {
        cout << searchKey << " found at index: " << searchResult << endl;
    }
    else {
        cout << searchKey << " not found in the array." << endl;
    }

    return 0;
}
