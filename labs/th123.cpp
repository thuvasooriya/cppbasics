/*
A left rotation operation on an array of size n shifts each of the array's
elements 1 unit to the left. Given an integer, d, rotate the array that many
steps left and return the result.

Example
d = 2
arp = [1, 2, 3, 4, 5]

After 2 rotations, arp' = [3, 4, 5, 1, 2].
Function Description
Complete the rotateLeft function in the editor below.

rotateLeft has the following parameters:

• int d: the amount to rotate by
• int arr[n]: the array to rotate

Returns

• intin]: the rotated array

Input Format

The first line contains two space-separated integers that denote n, the number
of integers, and d, the number of left rotations to perform. The second line
contains n space-separated integers that describe arr . Constraints

• 1 ≤ n ≤ 105
• 1 ≤ d ≤n
• 1 ≤ ail ≤ 106

Sample Input
54
12345

Sample Output
51234
Explanation

To perform d = 4 left rotations, the array undergoes the following sequence of
changes:

[1, 2, 3, 4, 5] → [2, 3, 4, 5, 1] → [3, 4, 5, 1, 2] → [4, 5, 1, 2, 3] → [5, 1,
2, 3, 4]

For example:

Input

54
12345 Result

51234
*/

// Solution #####
/*
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;


int main() {
    int N, d, i;
    cin >> N >> d;
    int start = N - d;
    int *arr = new int[N];
    for (i=0; i<N; ++i) {
        if (start == N) start = 0;
        cin >> arr[start++];
    }
    for (i=0; i<N; ++i) cout << arr[i] << " ";
    return 0;
}
*/

#include "bits_stdc++.h"

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'rotateLeft' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER d
 *  2. INTEGER_ARRAY arr
 */

vector<int> rotateLeft(int d, vector<int> arr) {
  int n = arr.size();
  vector<int> rotatedArray(n);

  // Perform left rotations
  for (int i = 0; i < n; ++i) {
    int newIndex = (i + n - d) % n;
    rotatedArray[newIndex] = arr[i];
  }

  return rotatedArray;
}

int main() {
  string first_multiple_input_temp;
  getline(cin, first_multiple_input_temp);

  vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

  int n = stoi(first_multiple_input[0]);

  int d = stoi(first_multiple_input[1]);

  string arr_temp_temp;
  getline(cin, arr_temp_temp);

  vector<string> arr_temp = split(rtrim(arr_temp_temp));

  vector<int> arr(n);

  for (int i = 0; i < n; i++) {
    int arr_item = stoi(arr_temp[i]);

    arr[i] = arr_item;
  }

  vector<int> result = rotateLeft(d, arr);

  for (size_t i = 0; i < result.size(); i++) {
    cout << result[i];

    if (i != result.size() - 1) {
      cout << " ";
    }
  }

  cout << "\n";

  return 0;
}

string ltrim(const string &str) {
  string s(str);

  s.erase(s.begin(),
          find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

  return s;
}

string rtrim(const string &str) {
  string s(str);

  s.erase(
      find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
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
