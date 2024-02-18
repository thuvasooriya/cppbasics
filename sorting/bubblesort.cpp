#include <iostream>
#include <vector>

int main() {
  int n;
  bool swap_check = true;
  std::cout << "Enter the amount of numbers to sort: ";
  std::cin >> n;
  std::vector<int> numbers;
  std::cout << "Enter " << n << " numbers: ";
  int num;

  // input
  for (int i = 0; i < n; i++) {
    std::cin >> num;
    numbers.push_back(num);
  }

  // optimized bubble sort
  for (int i = 0; (i < n) && (swap_check); i++) {
    swap_check = false; // there hasn't been a swap yet
    for (int j = 0; j < n - 1 - i; j++) {
      if (numbers[j] > numbers[j + 1]) {
        swap_check = true; // swap found, sorting still incomplete
        std::swap(numbers[j], numbers[j + 1]);
      }
      // no swap found => array sorted => skip rest of the loops
    }
  }

  // output
  std::cout << "\nSorted Array : ";
  for (int i = 0; i < numbers.size(); i++) {
    if (i != numbers.size() - 1) {
      std::cout << numbers[i] << ", ";
    } else {
      std::cout << numbers[i] << std::endl;
    }
  }
  return 0;
}

/*
 * bubble sort
 * the largest value bubbles up to the top (last element)
 * uses swap (switching the positions of two elements in the array,
 * usually with a help of another variable)
 * int z; // temporary variable to hold swap value
 * z = x;
 * x = y;
 * y = z;
 *
 * complexity analysis
 * worst or average case: O(n²): nested loops: n * (n - 1)
 *
 * best case: O(n): when optimized to detect sorted state early :)
 */
