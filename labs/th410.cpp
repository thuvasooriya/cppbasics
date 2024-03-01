#include <iostream>
#include <vector>
using namespace std;

// partition function for quicksort
void partition(vector<int> arr) {
  int length = arr.size() - 1; // length of array without pivot
  int p = arr.front();         // pivot is first element in array
  arr.erase(arr.begin());      // remove pivot from array

  vector<int> left;
  vector<int> right;

  int i, n;

  // putting rest of the elements in their respective arrays
  for (i = 0; i < length; i++) {
    (arr[i] > p) ? right.push_back(arr[i]) : left.push_back(arr[i]);
  }

  // print left, pivot, and right
  for (i = 0, n = left.size(); i < n; i++)
    cout << left[i] << " ";
  cout << p << " ";
  for (i = 0, n = right.size(); i < n; i++)
    cout << right[i] << " ";
  cout << "\n";
}

int main(void) {
  // get input
  vector<int> _arr;
  int _arr_size;
  cin >> _arr_size;
  for (int arr_i = 0; arr_i < _arr_size; arr_i++) {
    int ar_tmp;
    cin >> ar_tmp;
    _arr.push_back(ar_tmp);
  }

  partition(_arr);

  return 0;
}

/*
The previous challenges covered Insertion Sort, which is a simple and
intuitive sorting algorithm with a running time of O(n?). In these next few
challenges, we're covering a divide-and-conquer algorithm called Quicksort (also
known as Partition Sort). This challenge is a modified version of the algorithm
that only addresses partitioning. It is implemented as follows: Step 1: Divide
Choose some pivot element, p, and partition your unsorted array, arr, into three
smaller arrays: left, right, and equal, where each element in left < p, each
element in right > p, and each element in equal = p.
Example
arr = 15, 7, 4, 3, 8|
In this challenge, the pivot will always be at arr 0], so the pivot is 5.

arr is divided into left = {4, 3}, equal = {5}, and right = {7, 8}.
Putting them all together, you get {4, 3, 5, 7, 8}. There is a flexible checker
that allows the elements of le ft and right to be in any order. For example, {3,
4, 5, 8, 7} is valid as well. Given arr and p = arr [0], partition arr into
left, right, and equal using the Divide instructions above. Return a
1-dimensional array containing each element in left first, followed by each
element in equal, followed by each element in right. Function Description
Complete the quickSortfunction in the editor below.
quickSort has the following parameters):
quickSort has the following parameters):

• int arrin]: arr 0] is the pivot element

Returns

• int/n]: an array of integers as described above

Input Format

The first line contains n, the size of arr.
The second line contains n space-separated integers arr|i (the unsorted array).
The first integer, arr|°], is the pivot element, p.
Constraints

• 1 < n ≤ 1000
• -1000 < arri
• All elements are distinct. 1000 where 0 < i < n

Sample Input
STDIN Function
-----
5 arr[] size n =5
45372 arr =[4, 5, 3, 7, 2]

Sample Output
32457

Explanation

arr = [4, 5, 3, 7, 2] Pivot: p = arr [0] = 4.
left = (}; equal = {4}; right = 0}
arr |1] = 5 > p, so it is added to right.
left = [}; equal = {4}; right = {5}
arr 2] = 3 < p, so it is added to left.
left = {3}; equal = {4}; right = {5}
arr 3 = 7 > p, so it is added to right.
left = {3}; equal = {4}; right = {5, 7}
arr 4 = 2 < p, so it is added to left.
left = {3, 2}; equal = {4}; right = {5, 7}
Return the array { 32457}.
The order of the elements to the left and right of 4 needs to match the order of
the original list. For example:

Input Result

5 32457
45372
*/
