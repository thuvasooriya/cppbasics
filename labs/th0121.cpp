#include <iostream>
#include <vector>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * reverseArray
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY a as parameter.
 */
vector<int> reverseArray(const vector<int> &a) {
  int n = a.size();
  vector<int> reversedArray(n);

  // Reversing the array
  for (int i = 0; i < n; ++i) {
    reversedArray[i] = a[n - 1 - i];
  }

  return reversedArray;
}

int main() {

  // get the array count input and convert to int
  string arr_count_temp;
  getline(cin, arr_count_temp);
  int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

  // get the space separated integers and convert it to a vector of strings
  string arr_temp_temp;
  getline(cin, arr_temp_temp);
  vector<string> arr_temp = split(rtrim(arr_temp_temp));

  //
  vector<int> arr(arr_count);

  for (int i = 0; i < arr_count; i++) {
    int arr_item = stoi(arr_temp[i]);

    arr[i] = arr_item;
  }

  vector<int> res = reverseArray(arr);

  for (size_t i = 0; i < res.size(); i++) {
    cout << res[i];

    if (i != res.size() - 1) {
      cout << " ";
    }
  }

  cout << "\n";

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
An array is a type of data structure that stores elements of the same type in a
contiguous block of memory. In an array, A, of size N, each memory location has
some unique index, i (where 0 < i < N), that can be referenced as A[i] or A_i

Reverse an array of integers.
Example A = [1,2,3]
Return [3, 2, 1]

Function Description
Complete the function reverseArray in the editor below.
reverseArray has the following parameters):
• int A[n]: the array to reverse
Returns
• int[n]: the reversed array

Input Format
The first line contains an integer, N, the number of integers in A.
The second line contains N space-separated integers that make up A.

Constraints
1 ≤ N ≤ 10^3
1 ≤ A[i] ≤ 10^4, where A[i] is the i'th integer in A

For example:
Input
4
1432
3
123

Result
2341
321

*/

/*
// Solution ######
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
            int N;
            cin>>N;

            vector<int> arr(N);

            for (int i=0;i<N;i++)
                cin>>arr[i];

            reverse(arr.begin(),arr.end());

                for (int i=0;i<N;i++)
                cout<<arr[i]<<" ";

            return 0;
}
*/
