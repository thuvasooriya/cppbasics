#include <iostream>
#include <vector>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * hourglassSum
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */
int hourglassSum(vector<vector<int>> arr) {
  // Initialize maxSum to the smallest possible integer in the compiler
  // to ensure comparision with negative sums
  int maxSum = INT_MIN;

  // Iterate through the 2D array to calculate hourglass sums
  for (int i = 0; i <= 3; i++) {
    for (int j = 0; j <= 3; j++) {
      int currentSum = 0;

      // Calculate the sum of the current hourglass
      currentSum += arr[i][j] + arr[i][j + 1] + arr[i][j + 2];
      currentSum += arr[i + 1][j + 1];
      currentSum += arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 2][j + 2];

      // Update maxSum if needed
      maxSum = max(maxSum, currentSum);
    }
  }
  //   cout << maxSum << endl;
  return maxSum;
}

int main() {
  vector<vector<int>> arr(6);

  for (int i = 0; i < 6; i++) {
    arr[i].resize(6);

    string arr_row_temp_temp;
    getline(cin, arr_row_temp_temp);

    vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

    for (int j = 0; j < 6; j++) {
      int arr_row_item = stoi(arr_row_temp[j]);

      arr[i][j] = arr_row_item;
    }
  }

  int result = hourglassSum(arr);

  cout << result << "\n";

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
Given a 6 x 6 2D Array, arr:
111000
010000
111000
000000
000000
000000

An hourglass in A is a subset of values with indices falling in this pattern in
arr's graphical representation:

a b c
  d
e f g

There are 16 hourglasses in arr. An hourglass sum is the sum of an hourglass'
values. Calculate the hourglass sum for every hourglass in arr, then print the
maximum hourglass sum. The array will always be 6 × 6.

Example

arr =
-9-9-9 111
0-9 0 432
-9-9-9 123
0 0 8 660
0 0 0-200
0 0 1 240

The 16 hourglass sums are:
-63, -34, -9, 12,
-10, 0, 28, 23,
-27, -11, -2, 10,
9, 17, 25, 18

The highest hourglass sum is 28 from the hourglass beginning at row 1, column 2:
0 4 3
  1
8 6 6

Function Description
Complete the function hourglassSum in the editor below.

hourglassSum has the following parameters):
int arr[6][6]: an array of integers

Returns
int: the maximum hourglass sum

Input Format
Each of the 6 lines of inputs arr i contains 6 space-separated integers arri j.

Constraints
9 < arrill < 9
0 ≤ i, j≤ 5

Output Format
Print the largest (maximum) hourglass sum found in arr.
Sample Input
111000
010000
111000
002440
000200
001240

Sample Output
19

Explanation
arr contains the following hourglasses:
The hourglass with the maximum sum (19) is:

244
2
124

For example:

Input Result

111000
010000
1 1 1 0 0 0
002440
000200
0 0 1 2 40 19
*/
