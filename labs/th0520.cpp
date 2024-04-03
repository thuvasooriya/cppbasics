#include <iostream>
#include <vector>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * twoStacks
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER maxSum
 *  2. INTEGER_ARRAY a
 *  3. INTEGER_ARRAY b
 */
int twoStacks(int maxSum, vector<int> a, vector<int> b) {
  int n = a.size(), m = b.size();
  int i = 0, j = 0, score = 0, sum = 0;

  // method with careful checks :::wip
  // // Iterate until either the sum exceeds maxSum or we reach the end of both
  // // arrays
  // while ((i < n || j < m) &&
  //        sum + min(i < n ? a[i] : INT_MAX, j < m ? b[j] : INT_MAX) <= maxSum) {
  //   // Choose the next smallest element between a[i] and b[j]
  //   int nextElement = min(i < n ? a[i] : INT_MAX, j < m ? b[j] : INT_MAX);
  //
  //   // Update sum and count
  //   sum += nextElement;
  //   score++;
  //
  //   // Move to the next element in the array from which the smallest element was
  //   // chosen
  //   if (i < n && a[i] == nextElement)
  //     i++;
  //   else
  //     j++;
  // }

  // method involving a lot of undos
  // // remove from first array untill it exceeds maxSum
  // while (i < n && sum + a[i] <= maxSum) {
  //   // using compound assignment for shorter code
  //   sum += a[i++]; // access a[i] and increment i, post-increment operation
  //   score++;
  // }
  //
  // // now iteratively undo the first array and check with second array
  // while (j < m && i >= 0) {
  //   sum += b[j++];
  //
  //   // undo first array if sum is high and elements left
  //   while (sum > maxSum && i > 0)
  //     sum -= a[--i]; // here decrement i is performed before access,
  //     pre-decrement
  //
  //   // only update the score when correct
  //   if (sum <= maxSum)
  //     score = max(score, i + j);
  // }
  return score;
}

int main() {
  string g_temp;
  getline(cin, g_temp);

  int g = stoi(ltrim(rtrim(g_temp)));

  for (int g_itr = 0; g_itr < g; g_itr++) {
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input =
        split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    int maxSum = stoi(first_multiple_input[2]);

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
      int a_item = stoi(a_temp[i]);

      a[i] = a_item;
    }

    string b_temp_temp;
    getline(cin, b_temp_temp);

    vector<string> b_temp = split(rtrim(b_temp_temp));

    vector<int> b(m);

    for (int i = 0; i < m; i++) {
      int b_item = stoi(b_temp[i]);

      b[i] = b_item;
    }

    int result = twoStacks(maxSum, a, b);

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
Alexa has two stacks of non-negative integers, stack a[n] and stack b[m] where
index 0 denotes the top of the stack. Alexa challenges Nick to play the
following game:
1. In each move, Nick can remove one integer from the top of either stack a or
stack b.
2. Nick keeps a running sum of the integers he removes from the two stacks.
3. Nick is disqualified from the game if, at any point, his running sum becomes
greater than some integer max Sum given at the beginning of the game.
4. Nick's final score is the total number of integers he has removed from the
two stacks.

Given a, b, and max Sum for g games, find the maximum possible score Nick can
achieve. Example a = 11, 2, 3, 4, 5| 6 = 16, 7,8, 9] The maximum number of
values Nick can remove is 4. There are two sets of choices with this result.

1. Remove 1, 2, 3, 4 from a with a sum of 10.
2. Remove 1, 2, 3 from a and 6 from b with a sum of 12.

Function Description
Complete the twoStacks function in the editor below.

two Stacks has the following parameters: - int maxSum: the maximum allowed sum
- int a[n]: the first stack
- int b[m]: the second stack
Returns
- int: the maximum number of selections Nick can make
Input Format
The first line contains an integer, g (the number of games). The 3 • g
subsequent lines describe each game in the following format:
1. The first line contains three space-separated integers describing the
respective values of n (the number of integers in stack a), m (the number of
integers in stack b), and max Sum (the number that the sum of the integers
removed from the two stacks cannot exceed).
2. The second line contains n space-separated integers, the respective values of
a i•
3. The third line contains m space-separated integers, the respective values of
bi.

Constraints

• 1 ≤ 9 ≤ 50
• 1 In, m ≤ 10°
• 0 < all, bil ≤ 106
• 1 ≤ maxSum ≤ 10º

Subtasks

• 1 ≤ n, m, ≤ 100 for 50% of the maximum score.

Sample Input 0
1
5410
42461
2185

Sample Output 0
4

Explanation 0
The two stacks initially look like this:
 * */
