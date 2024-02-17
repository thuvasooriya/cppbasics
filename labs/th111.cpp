#include <iostream>
using namespace std;

// trim from start (in place)
string ltrim(const string &);
// trim from end (in place)
string rtrim(const string &);

// return the word for n
string n2word(int n);

int main() {
  string n_temp; // to store input from cin
  getline(cin, n_temp);

  int n = stoi(ltrim(rtrim(n_temp))); // convert the input to int

  //////////////////////////////
  // lame method
  // if (n == 1) {
  //   cout << "one" << endl;
  // } else if (n == 2) {
  //   cout << "two" << endl;
  // } else if (n == 3) {
  //   cout << "three" << endl;
  // } else if (n == 4) {
  //   cout << "four" << endl;
  // } else if (n == 5) {
  //   cout << "five" << endl;
  // } else if (n == 6) {
  //   cout << "six" << endl;
  // } else if (n == 7) {
  //   cout << "seven" << endl;
  // } else if (n == 8) {
  //   cout << "eight" << endl;
  // } else if (n == 9) {
  //   cout << "nine" << endl;
  // } else {
  //   cout << "Greater than 9" << endl;
  // }

  //////////////////////////////
  // better method
  // if (n >= 1 && n <= 9) {
  //  cout << n2word(n) << endl;
  // } else {
  // cout << "Greater than 9" << endl;
  // }

  //////////////////////////////
  // best method
  // bug:: zero and below will also print "Greater than 9"
  cout << ((n >= 1 && n <= 9) ? n2word(n) : "Greater than 9") << endl;
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

string n2word(int n) {
  // includes zero to account for array indexing
  string words[] = {"zero", "one", "two",   "three", "four",
                    "five", "six", "seven", "eight", "nine"};
  return words[n];
}

/*
Given a positive integer n, do the following:

If 1 <= n <= 9, print the lowercase English word corresponding to the number
(e.g., one for 1, two for 2, etc.).
If n > 9, print Greater than 9.

Input Format
A single integer, n.
Constraints: 1 < n < 10^3

Output Format
If 1 <= n <= 9, print the lowercase English word corresponding to the number
(e.g., one for 1, two for 2, etc.); otherwise, print Greater than 9.

Sample Input 0
5
Sample Output 0
five
Explanation 0
five is the English word for the number 5.

Sample Input 1
8
Sample Output 1
eight
Explanation 1
eight is the English word for the number 8.

Sample Input 2
44
Sample Output 2
Greater than 9
Explanation 2
n = 44 is greater than 9, so we print Greater than 9.
*/
