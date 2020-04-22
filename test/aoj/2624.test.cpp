#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2624"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "Math/BitMatrix.hpp"
#undef call_from_test

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int N;
  cin >> N;
  BitMatrix A(N);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      cin >> A[i][j];
    }
  vector<int> v(N);
  for (int i = 0; i < N; i++) cin >> v[i];
  int T;
  cin >> T;
  auto ans = BitMatrix::linear_equations(A.pow(T), v);
  if (!ans.first.size()) {
    cout << "none" << endl;
  } else if (ans.second.size()) {
    cout << "ambiguous" << endl;
  } else {
    for (int i = 0; i < N; i++) {
      cout << (i ? " " : "") << ans.first[i];
    }
    cout << endl;
  }
  return 0;
}