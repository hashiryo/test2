#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/all/ITP2_4_A"
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
  SplayTree<int, true> ar(a, a + n);
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int b, e;
    cin >> b >> e;
    ar.reverse(b, e);
  }
  auto ans = ar.dump();
  for (int i = 0; i < n; i++) cout << (i ? " " : "") << ans[i];
  cout << '\n';
  return 0;
}