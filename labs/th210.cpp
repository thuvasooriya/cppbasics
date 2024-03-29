#include <iostream>
#include <vector>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * insertionSort1
 *
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY arr
 */
void insertionSort1(int n, vector<int> arr) {
  int i = n - 1;     // last index
  int temp = arr[i]; // last element
  // while the element before the last element is greater than the last element
  while (i > 0 && arr[i - 1] > temp) {
    arr[i] = arr[i - 1]; // clone the greater element to the right
    i--;                 // moving to the left index
    // print the current state
    for (int j = 0; j < n; j++) {
      cout << arr[j] << " ";
    }
    cout << endl;
  }
  // put the initial copy of the last element in the right place
  arr[i] = temp;
  // print the final state (last element in the right place)
  for (int j = 0; j < n; j++) {
    cout << arr[j] << " ";
  }
  cout << endl;
  // this is not the complete insertion sort
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

  insertionSort1(n, arr);

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
