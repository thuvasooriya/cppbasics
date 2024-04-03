#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'bfs' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 *  3. 2D_INTEGER_ARRAY edges
 *  4. INTEGER s
 */

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
  // create an adjacency list to represent the graph
  vector<vector<int>> adj_list(n + 1);
  for (const auto &edge : edges) {
    int u = edge[0], v = edge[1];
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
  }

  // initialize distances and visited set
  vector<int> distances(n + 1, -1);
  unordered_set<int> visited;

  // start bfs from the source node
  queue<int> q;
  q.push(s);
  visited.insert(s);
  distances[s] = 0;

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int v : adj_list[u]) {
      if (visited.count(v) == 0) {
        visited.insert(v);
        q.push(v);
        distances[v] = distances[u] + 6; // Each edge weighs 6 units
      }
    }
  }

  // construct the result vector without the source node
  vector<int> result;
  for (int i = 1; i <= n; i++) {
    if (i != s) {
      result.push_back(distances[i]);
    }
  }

  return result;
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

    vector<vector<int>> edges(m);

    for (int i = 0; i < m; i++) {
      edges[i].resize(2);

      string edges_row_temp_temp;
      getline(cin, edges_row_temp_temp);

      vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

      for (int j = 0; j < 2; j++) {
        int edges_row_item = stoi(edges_row_temp[j]);

        edges[i][j] = edges_row_item;
      }
    }

    string s_temp;
    getline(cin, s_temp);

    int s = stoi(ltrim(rtrim(s_temp)));

    vector<int> result = bfs(n, m, edges, s);

    for (size_t i = 0; i < result.size(); i++) {
      cout << result[i];

      if (i != result.size() - 1) {
        cout << " ";
      }
    }

    cout << "\n";
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
// Consider an undirected graph where each edge weighs 6 units. Each of the
// nodes is labeled consecutively from 1 to n.

// You will be given a number of queries. For each query, you will be given a
// list of edges describing an undirected graph. After you create a
// representation of the graph, you must determine and report the shortest
// distance to each of the other nodes from a given starting position using the
// breadth-first search algorithm (BFS). Return an array of distances from the
// start node in node number order. If a node is unreachable, return - 1 for
// that node.

// Example
// The following graph is based on the listed inputs:
// n = 5 // number of nodes
// m = 3 // number of edges
// edges = [1, 2], [1, 3], [3, 4]
// 8 = 1// starting node

// All distances are from the start node 1. Outputs are calculated for distances
// to nodes 2 through 5: [6, 6, 12, - 1]. Each edge is 6 units, and the
// unreachable node 5 has the required return distance of - 1. Function
// Description

// Complete the bis function in the editor below. If a node is unreachable, its
// distance is -1.

// bfs has the following parameters):
// int n: the number of nodes
// int m: the number of edges
// int edges[m][2]: start and end nodes for edges
// int s: the node to start traversals from

// Returns

// is not reachable) int[n-1]: the distances to nodes in increasing node number
// order, not including the start node (-1 if a node

// Input Format

// The first line contains an integer 9, the number of queries. Each of the
// following 9 sets of lines has the following format:

// The first line contains two space-separated integers n and m, the number of
// nodes and edges in the graph. Each line i of the m subsequent lines contains
// two space-separated integers, u and v, that describe an edge between nodes u
// and v. The last line contains a single integer, s, the node number to start
// from.

// Constraints

// 1 <= q <= 10
// 2 <= n <= 1000
// 1 <= n(n-1)/2
// 1 <= u, v, s <= n

// Input
// 2
// 4 2
// 1 2
// 1 3
// 1
// 3 1
// 2 3
// 2
// Result
// 6 6 -1
// -1 6
// 1
// 5 3
// 1 2
// 1 3
// 3 4
// 1
// 6 6 12 -1
