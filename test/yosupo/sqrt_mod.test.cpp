#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_mod"
#include <bits/stdc++.h>
#include "src/Math/mod_sqrt.hpp"
using namespace std;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int T;
  cin >> T;
  while (T--) {
    int Y, P;
    cin >> Y >> P;
    cout << sqrt(Y, P) << '\n';
  }
  return 0;
}