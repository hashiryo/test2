#define PROBLEM "https://yukicoder.me/problems/no/649"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "DataStructure/BinaryIndexedTree.hpp"
#undef call_from_test

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int Q, K;
  cin >> Q >> K;
  K--;
  vector<long long> query;
  vector<long long> x;
  while (Q--) {
    long long v;
    cin >> v;
    if (v == 1) {
      cin >> v;
      x.push_back(v);
    } else {
      v = -1;
    }
    query.push_back(v);
  }
  sort(x.begin(), x.end());
  x.erase(unique(x.begin(), x.end()), x.end());
  BinaryIndexedTree bit(x.size());
  for (auto q : query) {
    if (q < 0) {
      int i = bit.find(K);
      if (i >= 0) {
        cout << x[i] << endl;
        bit.add(i, -1);
      } else {
        cout << -1 << endl;
      }
    } else {
      int i = lower_bound(x.begin(), x.end(), q) - x.begin();
      bit.add(i, 1);
    }
  }
  return 0;
}
