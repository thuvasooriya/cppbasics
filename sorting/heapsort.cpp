#include <iostream>
using namespace std;

// Function to heapify the tree
void heapify(int arr[], int n, int root) {
    int smallest = root; // Initialize smallest as root
    int left = 2 * root + 1; // Left child
    int right = 2 * root + 2; // Right child

    // If left child is smaller than root
    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    // If right child is smaller than smallest so far
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    // If smallest is not root
    if (smallest != root) {
        swap(arr[root], arr[smallest]); // Swap root and smallest
        heapify(arr, n, smallest); // Recursively heapify the affected sub-tree
    }
}

// Implementing heap sort
void heapSort(int arr[], int n) {
    // Build min heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from heap one by one
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // Call min heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

/* Print contents of array */
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// Main program
int main() {
    int heap_arr[] = {4, 17, 3, 12, 9, 6};
    int n = sizeof(heap_arr) / sizeof(heap_arr[0]);
    cout << "Input array" << endl;
    displayArray(heap_arr, n);

    heapSort(heap_arr, n);

    cout << "Sorted array" << endl;
    displayArray(heap_arr, n);

    return 0;
}
