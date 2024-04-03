#include <iostream>
#include <string>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * twoStrings
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */
string twoStrings(string s1, string s2) {
  // create a vector of bool for characters
  vector<bool> char_present(26, false);
  // mark characters present in s1
  for (char c : s1) {
    char_present[c - 'a'] = true;
  }

  // check if any character of s2 is present in s1
  for (char c : s2) {
    if (char_present[c - 'a']) {
      return "YES";
    }
  }

  return "NO";
}

// another implementation using find_first_of method from string
// needs profiling to check whether vector implementation is better or not
// string twoStrings(string s1, string s2) {
//     return (s1.find_first_of(s2) != string::npos || s2.find_first_of(s1) !=
//     string::npos) ? "YES" : "NO";
// }

// another implementation from author using unordered_set
// string twoStrings(string s1, string s2) {
//     unordered_set<char> charSet;

//     // Insert characters from the first string into the set
//     for (char ch : s1) {
//         charSet.insert(ch);
//     }

//     // Check if any character from the second string is present in the set
//     for (char ch : s2) {
//         if (charSet.find(ch) != charSet.end()) {
//             return "YES";
//         }
//     }

//     // No common substring found
//     return "NO";
// }

int main() {
  string q_temp;
  getline(cin, q_temp);

  int q = stoi(ltrim(rtrim(q_temp)));

  for (int q_itr = 0; q_itr < q; q_itr++) {
    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    string result = twoStrings(s1, s2);

    cout << result << "\n";
  }

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

// Given two strings, determine if they share a common substring. A substring
// may be as small as one character.

// Example

// s1 = 'and'
// s2 = 'art'
// These share the common substring a.

// s1 = 'be'
// s2 = 'cat'
// These do not share a substring.

// Function Description
// twoStrings has the following parameters):
// string s1: a string
// string s2: another string
// Returns
// string: either YES or NO

// Input Format
// The first line contains a single integer p, the number of test cases.
// The following p pairs of lines are as follows:
// The first line contains string s1.
// The second line contains string s2.

// Constraints
// s1 and s2 consist of characters in the range ascil[a-z.
// 1 ≤ p ≤ 10
// 1 ≤ |s1|, |s2| ≤ 10^5

// Output Format
// For each pair of strings, return YES or NO.
