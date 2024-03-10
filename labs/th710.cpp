// #include <cmath>
// #include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

// Function to heapify the tree at index i
void heapify(std::vector<int> &heap, int root, int n) {
  int i = root;             // Initialize smallest as root
  int left = 2 * root + 1;  // left child
  int right = 2 * root + 2; // right child

  // If left child is smaller than root
  if (left < n && heap[left] < heap[i])
    i = left;

  // If right child is smaller than smallest so far
  if (right < n && heap[right] < heap[i])
    i = right;

  // If smallest is not root
  if (i != root) {
    std::swap(heap[root], heap[i]);

    // Recursively heapify the affected sub-tree
    heapify(heap, i, n);
  }
}

int main() {
  int Q;
  std::cin >> Q; // Number of queries

  std::vector<int> heap; // Min-heap to store elements

  for (int i = 0; i < Q; i++) {
    int q;
    std::cin >> q;

    if (q == 1) { // Insert
      int val;
      std::cin >> val;
      heap.push_back(val);
      int n = heap.size();

      // Heapify from the last index
      for (int i = n / 2 - 1; i >= 0; i--)
        heapify(heap, i, n);
    } else if (q == 2) { // Delete
      int val;
      std::cin >> val;
      auto it = find(heap.begin(), heap.end(), val);

      // If the element is found, remove it
      if (it != heap.end()) {
        std::swap(*it, heap.back());
        heap.pop_back();
        heapify(heap, 0, heap.size());
      }
    } else if (q == 3) { // Print minimum
      std::cout << heap.front() << std::endl;
    }
  }

  return 0;
}
// void heapSort(int arr[], int n) {
//   // build heap
// }

/* print contents of array */
// void displayArray(int arr[], int n)
// {
//    for (int i=0; i<n; ++i)
//    cout << arr[i] << " ";
//    cout << "\n";
// }

// main program
// int main()
// {
//    int heap_arr[] = {4,17,3,12,9,6};
//    int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
//    cout<<"Input array"<<endl;
//    displayArray(heap_arr,n);
//
//    heapSort(heap_arr, n);
//    cout << "Sorted array"<<endl;
//    displayArray(heap_arr, n);
// }

/*
This question is designed to help you get a better understanding of basic
heap operations.

There are 3 types of query:

• "1 v" - Add an element v to the heap.
• "2 v" - Delete the element v from the heap.
• "3" - Print the minimum of all the elements in the heap.

NOTE: It is guaranteed that the element to be deleted will be there in the heap.
Also, at any instant, only distinct elements will be in the heap.

Input Format
The first line contains the number of queries, •
Each of the next Q lines contains one of the 3 types of query.

Constraints
1 ≤ Q ≤ 10^5
-10^9 ≤ v ≤ 10^9

Output Format
For each query of type 3, print the minimum value on a single line.

Sample Input
STDIN Function
-----
5 -> Q = 5
1 4 ->  insert 4
1 9 -> insert 9
3 -> print minimum
2 4 -> delete 4
3 -> print minimum

Sample Output
4
9

Explanation
After the first 2 queries, the heap contains {4, 9}. Printing the minimum gives
4 as the output. Then, the 4th query deletes 4 from the heap, and the 5th query
gives 9 as the output.
*/
