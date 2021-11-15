#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/challenges/sources/ICPC/Regional/1328"
// double型の行列の連立一次方程式のverify

#include <bits/stdc++.h>
#include "src/Math/LUDecomposition.hpp"
using namespace std;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int d;
  while (cin >> d && d) {
    vector<vector<double>> m(d + 3, vector<double>(d + 1));
    vector<double> v(d + 3);
    for (int i = 0; i < d + 3; i++) cin >> v[i];
    for (int i = 0; i < d + 3; i++)
      for (int j = 0; j < d + 1; j++) m[i][j] = j ? m[i][j - 1] * i : 1;
    int ans = d + 2;
    for (int k = 0; k + 1 < d + 3; k++) {
      for (int l = k + 1; l < d + 3; l++) {
        vector<vector<double>> A(d + 1, vector<double>(d + 1));
        vector<double> b(d + 1);
        int ii = 0;
        for (int i = 0; i < d + 3; i++)
          if (i != k && i != l) {
            b[ii] = v[i];
            A[ii] = m[i];
            ii++;
          }
        auto c = LUDecomposition(A).linear_equations(b);
        double u1 = 0, u2 = 0;
        for (int i = d; i >= 0; i--) {
          u1 += c[i] * m[k][i];
          u2 += c[i] * m[l][i];
        }
        if (abs(u1 - v[k]) < 1e-5) {
          ans = l;
          break;
        }
        if (abs(u2 - v[l]) < 1e-5) {
          ans = k;
          break;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}