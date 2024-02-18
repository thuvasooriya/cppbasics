#include <iostream>
#include <fstream>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * powerSum
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER X
 *  2. INTEGER N
 */
int powerSum(int X, int N, int init = 1) {
  if (X == 0) {
    return 1;
  }

  int max_e = pow(X, 1.0 / N);
  int num = 0;
  for (int i = init; i <= max_e + 1; i++) {
    int remaining = X - pow(i, N);
    num +=
        powerSum(remaining, N, i + 1); // Exclude current number for uniqueness
  }

  return num;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string X_temp;
  getline(cin, X_temp);

  int X = stoi(ltrim(rtrim(X_temp)));

  string N_temp;
  getline(cin, N_temp);

  int N = stoi(ltrim(rtrim(N_temp)));

  int result = powerSum(X, N);

  cout << result << "\n";
  fout << result << "\n";

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

/*
Find the number of ways that a given integer, X, can be expressed as the sum of
the Nth powers of unique, natural numbers.

For example, if X = 13 and N = 2, we have to find all combinations of unique
squares adding up to 13. The only solution is 22 + 32.

Input Format
The first line contains an integer X.
The second line contains an integer N.

Constraints
1 < X ≤ 1000
2 < N ≤ 10

Output Format
Output a single integer, the number of possible combinations caclulated.

Sample Input 0
10
2

Sample Output 0
1

Explanation 0
If X = 10 and N = 2, we need to find the number of ways that 10 can be
represented as the sum of squares of unique numbers.
10 = 1^2 + 3^2
This is the only way in which 10 can be expressed as the sum of unique squares.

Sample Input 1
100
2

Sample Output 1
3

Explanation 1
100 = (10^2) = (6^2 + 8^2) = (1^2 + 3^2 + 4^2 + 5^2 + 7^2)
*/

// #include <iostream>
// using namespace std;
// //recursive function
// int func(int x,int n, int c){
//     if (pow(c,n)<x){
//         return func(x,n,c+1)+func(x-pow(c,n),n,c+1);
//     }
//     else if(pow(c,n)==x){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }
//
// int main() {
//     int x;
//     int n;
//     int c=1;
//     int res;
//     cin>>x>>n;//input X and C vales
//     func(x,n,c);
//     res=func(x,n,c);
//     cout<<res;
//     
//     return 0;
// }
