#include <iostream>
#include <vector>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * lilysHomework
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
int lilysHomework(vector<int> arr) {
  vector<pair<int, size_t>> parr1, parr2;
  for (size_t i = 0; i < arr.size(); ++i) {
    parr1.emplace_back(arr[i], i);
    parr2.emplace_back(arr[i], i);
  }
  sort(parr1.begin(), parr1.end());
  sort(parr2.rbegin(), parr2.rend());

  int counta = 0, countd = 0;
  for (size_t i = 0; i < arr.size(); ++i) {
    while (i != parr1[i].second) {
      swap(parr1[i], parr1[parr1[i].second]);
      ++counta;
    }
  }
  for (size_t i = 0; i < arr.size(); ++i) {
    while (i != parr2[i].second) {
      swap(parr2[i], parr2[parr2[i].second]);
      ++countd;
    }
  }

  return min(counta, countd);
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

  int result = lilysHomework(arr);

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
Whenever George asks Lily to hang out, she's busy doing homework. George wants
to help her finish it faster, but he's in over his head! Can you help George
understand Lily's homework so she can hang out with him?

Consider an array of n distinct integers, arp = a |0|, a 1|, ..., an - 1]].
George can swap any two elements of the array any number of times. An array is
beautiful if the sum of arrli] — arri - 1]| among 0 < i < n is minimal. Given
the array arr, determine and return the minimum number of swaps that should be
performed in order to make the array beautiful. Example

arr = [7,15, 12, 3]

One minimal array is [3, 7, 12, 15]. To get there, George performed the
following swaps: Swap Result [7, 15, 12, 3] 37 [3, 15, 12, 7) 7 15 [3, 7, 12,
15]

It took 2 swaps to make the array beautiful. This is minimal among the choices
of beautiful arrays possible. Function Description Complete the lilysHomework
function in the editor below. lilysHomework has the following parameters): • int
arr[n]: an integer array

Returns

• int: the minimum number of swaps required
Input Format

The first line contains a single integer, n, the number of elements in arr. The
second line contains n space-separated integers, arr i .

Constraints

• 1 < n ≤ 105
• 1 ≤ arpil ≤ 2 × 10°

Sample Input
STDIN Function
-====
4
2531 arr]size n = 4
arr = [2, 5, 3, 1]

Sample Output
2

Explanation

Define arp = 1, 2, 3, 5 to be the beautiful reordering of arr. The sum of the
absolute values of differences between its adjacent elements is minimal among
all permutations and only two swaps (1 with 2 and then 2 with 5) were performed.
*/
