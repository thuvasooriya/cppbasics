#include <iostream>
#include <vector>

using namespace std;

void insertionSort1(int n, vector<int> arr) {
  int i = n - 1;     // last index
  int temp = arr[i]; // last element
  // while the element before the last element is greater than the last element
  while (i > 0 && arr[i - 1] > temp) {
    arr[i] = arr[i - 1]; // shift the greater element to the right
    i--;                 // moving to the left index
    for (int j = 0; j < n; j++) {
      cout << arr[j] << " ";
    }
    cout << endl;
  }
  arr[i] = temp;
  for (int j = 0; j < n; j++) {
    cout << arr[j] << " ";
  }
  cout << endl;
}

int main() { insertionSort1(n, arr); }
