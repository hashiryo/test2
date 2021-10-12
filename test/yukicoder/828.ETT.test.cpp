#define PROBLEM "https://yukicoder.me/problems/no/828"
#include <bits/stdc++.h>

#include "src/DataStructure/EulerTourTree_MonoidDual.hpp"

using namespace std;

struct RaddQ {
  using T = long long;
  using E = long long;
  static E ei() { return 0; }
  static T mapping(const T &t, const E &e) { return t + e; }
  static E composition(const E &l, const E &r) { return l + r; }
};

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int N;
  cin >> N;
  int r[N];
  for (int i = 0; i < N; i++) cin >> r[i];
  EulerTourTree_MonoidDual<RaddQ> ett(N);
  vector<int> tree[N];
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    if (u > v) swap(u, v);
    ett.link(u, v);
    tree[v].push_back(u);
  }
  for (int v = N - 1; v >= 0; v--) {
    ett.apply_tree(v, 1);
    for (int u : tree[v]) ett.cut(u, v);
  }
  long long ans = 1;
  for (int i = 0; i < N; i++) (ans *= r[i] + ett[i]) %= int(1e9 + 7);
  cout << ans << '\n';
  return 0;
}