#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/all/ITP2_4_C"
#include <bits/stdc++.h>
#include "src/DataStructure/SplayTree.hpp"
using namespace std;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  SplayTree<int> ar(a, a + n);
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int b, e, t;
    cin >> b >> e >> t;
    int f = t + e - b;
    if (t < b) swap(b, t), swap(e, f);
    auto [tl, tc, tr] = ar.split3(t, f);
    auto [bl, bc, br] = tl.split3(b, e);
    ar = bl + tc + br + bc + tr;
  }
  auto ans = ar.dump();
  for (int i = 0; i < n; i++) cout << (i ? " " : "") << ans[i];
  cout << '\n';
  return 0;
}