#include <iostream>
#include <vector>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// modified bruteforce insertion sort to handle more deranged arrays
void insertionSort2(int n, vector<int> arr) {
  for (int i = 1; i < n; ++i) {
    int key = arr[i];
    int j = i - 1;

    // Move elements of arr[0..i-1], that are greater than key,
    // to one position ahead of their current position
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;

    // Print the array after each iteration
    for (int k = 0; k < n; ++k) {
      cout << arr[k] << " ";
    }
    cout << endl;
  }
}

int main() {
  string n_temp;
  getline(cin, n_temp);

  int n = stoi(ltrim(rtrim(n_temp)));

  string arr_temp_temp;
  getline(cin, arr_temp_temp);

  vector<string> arr_temp = split(rtrim(arr_temp_temp));

  vector<int> arr(n);

  for (int i = 0; i < n; i++) {
    int arr_item = stoi(arr_temp[i]);

    arr[i] = arr_item;
  }

  insertionSort2(n, arr);

  return 0;
}

string ltrim(const string &str) {
  string s(str);
  s.erase(s.begin(), find_if(s.begin(), s.end(),
                             [](unsigned char c) { return !isspace(c); }));
  return s;
}

string rtrim(const string &str) {
  string s(str);
  s.erase(
      find_if(s.rbegin(), s.rend(), [](unsigned char c) { return !isspace(c); })
          .base(),
      s.end());
  return s;
}

vector<string> split(const string &str) {
  vector<string> tokens;

  string::size_type start = 0;
  string::size_type end = 0;

  while ((end = str.find(" ", start)) != string::npos) {
    tokens.push_back(str.substr(start, end - start));

    start = end + 1;
  }

  tokens.push_back(str.substr(start));

  return tokens;
}

/*
In Insertion Sort Part 1, you inserted one element into an array at its correct
sorted position. Using the same approach repeatedly, can you sort an entire
array? Guideline: You already can place an element into a sorted array. How can
you use that code to build up a sorted array, one element at a time? Note that
in the first step, when you consider an array with just the first element, it is
already sorted since there's nothing to compare it to.

In this challenge, print the array after each iteration of the insertion sort,
i.e., whenever the next element has been inserted at its correct position. Since
the array composed of just the first element is already sorted, begin printing
after placing the second element. Example.

n = 7
arp =[ 3, 4, 7, 5, 6, 2, 1]

Working from left to right, we get the following output:
3475621
3475621
3457621
3456721
2345671
1234567

Function Description

Complete the insertionSort2 function in the editor below.

insertionSort2 has the following parameters):

int n: the length of arr
int arr[n]: an array of integers

Prints
At each iteration, print the array as space-separated integers on its own line.

Input Format
The first line contains an integer, n, the size of arr.
The next line contains n space-separated integers arr i .

Constraints
1In ≤ 1000
10000 ≤ arr|i] ≤ 10000, 0 ≤ i < n

Output Format
Print the entire array on a new line at every iteration.

Sample Input
n = 6
143562 arr = [1, 4, 3, 5, 6, 2]

Sample Output
143562
134562
134562
134562
123456
 */
