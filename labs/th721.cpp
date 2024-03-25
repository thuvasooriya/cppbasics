// author's solution
#include <iostream>
#include <vector>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * 'cookies' function
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY A
 */

int cookies(int k, vector<int> A) {
  int count = 0;
  make_heap(A.begin(), A.end(), greater<int>()); // create min heap

  while (A.size() > 1 && A.front() < k) {
    int least1 = A.front();
    pop_heap(A.begin(), A.end(), greater<int>());
    A.pop_back(); // remove the smallest element

    int least2 = A.front();
    pop_heap(A.begin(), A.end(), greater<int>());
    A.pop_back(); // remove the new smallest element

    int temp = least1 + 2 * least2;
    A.push_back(temp);
    push_heap(
        A.begin(), A.end(),
        greater<int>()); // adjusts the heap to maintain the min heap property

    count++;
  }
  return (A.front() >= k) ? count : -1;
}

int main() {
  string first_multiple_input_temp;
  getline(cin, first_multiple_input_temp);

  vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

  int n = stoi(first_multiple_input[0]);

  int k = stoi(first_multiple_input[1]);

  string A_temp_temp;
  getline(cin, A_temp_temp);

  vector<string> A_temp = split(rtrim(A_temp_temp));

  vector<int> A(n);

  for (int i = 0; i < n; i++) {
    int A_item = stoi(A_temp[i]);

    A[i] = A_item;
  }

  int result = cookies(k, A);

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
