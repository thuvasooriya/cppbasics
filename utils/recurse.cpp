// memoization

#include <iostream>
using namespace std;

int fib(int n) {
  if (n <= 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return fib(n - 1) + fib(n - 2);
  }
}

int mergesort(vector<int> arr) {
  // let the sorting begin
}

int main() {
  cout << "Hello" << endl;
  return 0;
}
