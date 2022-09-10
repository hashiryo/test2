#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/challenges/sources/VPC/HUPC/2842"
#include <bits/stdc++.h>
#include "src/DataStructure/KDTree.hpp"
using namespace std;

struct RSQ {
  using T = pair<int, int>;
  static T ti() { return {0, 0}; }
  static T op(const T &l, const T &r) {
    return {l.first + r.first, l.second + r.second};
  }
};
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int H, W, T, Q;
  cin >> H >> W >> T >> Q;
  map<array<int, 2>, pair<int, int>> mp;
  vector<array<int, 6>> query;
  for (int i = 0; i < Q; i++) {
    int t, c, h1, w1, h2, w2;
    cin >> t >> c >> h1 >> w1;
    if (c == 2)
      cin >> h2 >> w2;
    else if (c == 0) {
      query.push_back({t + T, -1, h1, w1, h2, w2});
    }
    mp[{h1, w1}] = {0, 0};
    query.push_back({t, c, h1, w1, h2, w2});
  }
  KDTree<2, int, RSQ> kdt({mp.begin(), mp.end()});
  sort(query.begin(), query.end());
  for (auto [t, c, h1, w1, h2, w2] : query) {
    if (c == 0) {
      kdt.set({1, 0}, h1, w1);
    } else if (c == 1) {
      if (kdt.get(h1, w1).second) kdt.set({0, 0}, h1, w1);
    } else if (c == 2) {
      auto [x, y] = kdt.fold({h1, h2}, {w1, w2});
      cout << y << " " << x << '\n';
    } else {
      kdt.set({0, 1}, h1, w1);
    }
  }
  return 0;
}