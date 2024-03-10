// not exactly a heap sort implementaion from groundup, but passes all the cases
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

int main() {
  // store heap
  std::vector<int> vec;
  // number of queries
  int q;
  std::cin >> q;
  int minval = 1000000007; // fix edge case: first element negative
  bool flag = false; // minvalue deleted in last query
  
  for (int i = 0; i < q; i++) {
    int a, v;
    std::cin >> a;
    if (a == 1) {
      std::cin >> v;
      vec.push_back(v);
      minval = std::min(minval, v);
    }
    if (a == 2) {
      std::cin >> v;
      if (v == minval)
        flag = true;
      for (size_t j = 0; j < vec.size(); j++) {
        if (vec[j] == v) {
          vec.erase(vec.begin() + j);
        }
      }
    }
    if (a == 3) {
      if (flag) {
        minval = 1000000007;
        for (size_t j = 0; j < vec.size(); j++) {
          minval = std::min(minval, vec[j]);
        }
        flag = false;
      }
      std::cout << minval << std::endl;
    }
  }
  return 0;
}

/*
priority_queue<int> pq;
int q;
cin >> q;
for (int i=0; i<q; i++)
{
    int a,v;
    cin >> a;
    if (a==1)
    {
        cin >> v;
        pq.push(-1*v);
    }
    if (a==2)
    {
        cin >> v;
        pq.pop();
    }
    if (a==3)
    {
        cout << pq.top()*-1 << endl;
        //pq.pop();
    }
}
*/
