#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_of_formal_power_series"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "Math/FormalPowerSeries.hpp"
#undef call_from_test

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int N;
  cin >> N;
  FPS::init(998244353);
  FPS a(N);
  for (int i = 0; i < N; i++) cin >> a[i];
  auto b = a.sqrt();
  if (b.size() == 0) {
    cout << -1 << endl;
  } else {
    for (int i = 0; i < N; i++) {
      cout << b[i] << (i < N - 1 ? " " : "\n");
    }
    cout << flush;
  }
  return 0;
}