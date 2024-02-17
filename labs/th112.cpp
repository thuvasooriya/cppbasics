/*

In this challenge, you will use a for loop to increment a variable through a
range. Input Format You will be given two positive integers, a and b (a < b),
separated by a newline.

Output Format
For each integer n in the inclusive interval a, b :

If 1 <= n <= 9, then print the English representation of it in lowercase.
Else if n > 9 and it is an even number, then print "even".
Else if n > 9 and it is an odd number, then print "odd".

Note: a, b = {x; a < x < b} = {a, a + 1, .., b}

Sample Input
8
11

Sample Output
eight
nine
even
odd
*/

#include <iostream>
using namespace std;

// return the word for n
string n2word(int n) {
  string words[] = {"zero", "one", "two",   "three", "four",
                    "five", "six", "seven", "eight", "nine"};
  return words[n];
}

int main() {
  int start, end;
  cin >> start >> end;
  ////////////////////////////////
  // lame method
  // for (int i = start; i < (end + 1); i++) {
  //   if (i == 1) {
  //     cout << "one" << endl;
  //   } else if (i == 2) {
  //     cout << "two" << endl;
  //   } else if (i == 3) {
  //     cout << "three" << endl;
  //   } else if (i == 4) {
  //     cout << "four" << endl;
  //   } else if (i == 5) {
  //     cout << "five" << endl;
  //   } else if (i == 6) {
  //     cout << "six" << endl;
  //   } else if (i == 7) {
  //     cout << "seven" << endl;
  //   } else if (i == 8) {
  //     cout << "eight" << endl;
  //   } else if (i == 9) {
  //     cout << "nine" << endl;
  //   } else if (i > 9) {
  //     if (i % 2 == 0) {
  //       cout << "even" << endl;
  //     } else {
  //       cout << "odd" << endl;
  //     }
  //   } else {
  //     cout << "error" << endl;
  //   }
  // }
  ////////////////////////////////
  // better method
  // for (int i = start; i < (end + 1); i++) {
  //  if (i < 10) {
  //  cout << n2word(i) << endl;
  // } else {
  // cout << ((i % 2 == 0) ? "even" : "odd") << endl;
  // }
  // }
  ////////////////////////////////
  // best method
  for (int i = start; i < (end + 1); i++) {
    cout << ((i < 10) ? n2word(i) : ((i % 2 == 0) ? "even" : "odd")) << endl;
  }
  return 0;
}
