#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// global space constrained arrays to track cities and groups
int Size[100001];
int Root[100001];

// recursively find the root
int find(int a) {
  if (a == Root[a])
    return a;
  return Root[a] = find(Root[a]);
}

// group cities based on the potential roads
void group(int a, int b) {
  // find roots of a and b
  a = find(a);
  b = find(b);
  if (a == b)
    return; // already in the same group
  if (Size[a] < Size[b])
    swap(a, b);
  Root[b] = a;
  Size[a] += Size[b];
}

/*
 * roadsAndLibraries
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER c_lib
 *  3. INTEGER c_road
 *  4. 2D_INTEGER_ARRAY cities
 */
long roadsAndLibraries(int n, int c_lib, int c_road,
                       vector<vector<int>> cities) {
  // if library is cheaper build than road
  if (c_lib <= c_road)
    return n * 1LL * c_lib; // cost to build library in every city

  // initializing each node as its parent with size of 1
  for (int i = 1; i <= n; i++) {
    Size[i] = 1;
    Root[i] = i;
  }

  // iterating over connected cities to group them
  for (const auto &c : cities) {
    group(c[0], c[1]);
  }

  unordered_map<int, bool> libmap; // track cities with library
  long long cost = 0;

  // check each city
  for (int i = 1; i <= n; i++) {
    int p = find(i);
    if (libmap[p])
      continue;                       // the city group has a library
    cost += c_lib;                    // build a library
    cost += ((Size[p] - 1) * c_road); // add road cost
    libmap[p] = true;
  }

  return cost;
}

int main() {
  string q_temp;
  getline(cin, q_temp);
  int q = stoi(ltrim(rtrim(q_temp)));

  for (int q_itr = 0; q_itr < q; q_itr++) {
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input =
        split(rtrim(first_multiple_input_temp));
    int n = stoi(first_multiple_input[0]);
    int m = stoi(first_multiple_input[1]);
    int c_lib = stoi(first_multiple_input[2]);
    int c_road = stoi(first_multiple_input[3]);
    vector<vector<int>> cities(m);

    for (int i = 0; i < m; i++) {
      cities[i].resize(2);
      string cities_row_temp_temp;
      getline(cin, cities_row_temp_temp);
      vector<string> cities_row_temp = split(rtrim(cities_row_temp_temp));

      for (int j = 0; j < 2; j++) {
        int cities_row_item = stoi(cities_row_temp[j]);
        cities[i][j] = cities_row_item;
      }
    }

    long result = roadsAndLibraries(n, c_lib, c_road, cities);
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
Determine the minimum cost to provide library access to all citizens of
HackerLand. There are n cities numbered from 1 to n. Currently there are no
libraries and the cities are not connected. Bidirectional roads may be built
between any city pair listed in cities. A citizen has access to a library if: •
Their city contains a library. • They can travel by road from their city to a
city containing a library.

Example
The following figure is a sample map of HackerLand where the dotted lines denote
possible roads:

7-1-3-2
  |___」

5-6-8

c_road = 2
c_lib = 3
cities = [[1, 7], [1, 3], [1, 2], [2, 3], [5, 6], [6, 8]]
The cost of building any road is cc_road = 2, and the cost to build a library in
any city is c_lib = 3. Build 5 roads at a cost of 5 × 2 = 10 and 2 libraries for
a cost of 6. One of the available roads in the cycle 1 → 2 → 3 → 1 is not
necessary.

There are 9 queries, where each query consists of a map of HackerLand and value
of c_lib and c_road. For each query, find the minimum cost to make libraries
accessible to all the citizens. Function Description roadsAndLibraries has the
following parameters: • int n: integer, the number of cities • int c_lib:
integer, the cost to build a library • int o_road: integer, the cost to repair a
road • int cities(m][2]: each cities|i] contains two integers that represent
cities that can be connected by a new road Returns
- int: the minimal cost

Input Format
The first line contains a single integer 9, that denotes the number of queries.
The subsequent lines describe each query in the following format:
- The first line contains four space-separated integers that describe the
respective values of n, m, c_lib and c_road, the number of cities, number of
roads, cost of a library and cost of a road.
- Each of the next m lines contains two space-separated integers, u i and vi,
that describe a bidirectional road that can be built to connect cities u i and
vli].

Constraints
1 ≤ 9 ≤ 10
1 <n ≤ 105
0≤m ≤ min (105 n. (п-]))
1 ≤ c road, c lib ≤ 105
1 ≤ ui, vi <n
Each road connects two distinct cities.

For example:

Input
2
3 3 2 1
1 2
3 1
2 3
6 6 2 5
1 3
3 4
2 4
1 2
2 3
5 6

Result
4
12
*/
