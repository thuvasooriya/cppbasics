#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int super_digit_helper(string n) {
  // Base case: if n has only one digit
  if (n.length() == 1) {
    return stoi(n);
  }

  // Calculate sum of digits
  int sum = 0;
  for (char digit : n) {
    sum += digit - '0';
  }

  // Recursively calculate super digit of the sum
  return super_digit_helper(to_string(sum));
}

/*
 * super_digit
 * 
 * tldr:: add digits of x until number of digits become 1
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING n
 *  2. INTEGER k
 */
int super_digit(string n, int k) {
  // there is no efficient way to concatnate a string k number of times in cpp
  // let's hack our way in
  int super_digit_of_n = super_digit_helper(n);
  super_digit_helper(p);

  // Multiply the super digit of n by k
  super_digit_of_n *= k;

  // Calculate super digit of the resulting number
  return super_digit_helper(to_string(super_digit_of_n));
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string first_multiple_input_temp;
  getline(cin, first_multiple_input_temp);

  vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

  string n = first_multiple_input[0];

  int k = stoi(first_multiple_input[1]);

  int result = super_digit(n, k);

  cout << result << "\n";

  fout.close();

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
super_digit of an integer x is defined as,
If x has only 1 digit, then its super digit is x.
Otherwise, the super digit of x is equal to the super digit of the sum of the
digits of x.
tldr:: add digits of x until number of digits become 1

For example, the super digit of 9875 will be calculated as:
super_digit(9875) = 9+8+7+5 = 29
super_digit(29) = 2 + 9 = 11
super_digit(11) = 1 + 1 = 2
super_digit(2) = 2

Example
n = 9875
k = 4
The number p is created by concatenating the string n, k times so the initial
р = 9875987598759875
superDigit(p) = superDigit(9875987598759875)
9+8+7+5+9+8+7+5+9+8+7+5+9+8+7+5 = 116
superDigit(p) = superDigit(116)
1+1+6 = 8
superDigit(p) = superDigit(8)

All of the digits of p sum to 116. The digits of 116 sum to 8. 8 is only one digit, so it is
the super digit.

Input Format
The first line contains two space separated integers, n and k.
Constraints
1 ≤ n < 10^100000
1 ≤ k ≤ 10^5

Sample Input 0
148 3

Sample Output 0
3

Explanation 0

Here n = 148 and k = 3, so p = 148148148.
super_digit(P) = super_digit(148148148)
= super_digit(1+4+8+1+4+8+1+4+8)
= super_digit(39)
= super_digit(3+9)
= super_digit(12)
= super_digit(1+2)
= super_digit (3)
= 3

Sample Input 1
9875 4

Sample Output 1
8
 */
