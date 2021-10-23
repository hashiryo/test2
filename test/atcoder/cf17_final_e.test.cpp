#define PROBLEM "https://atcoder.jp/contests/cf17-final/tasks/cf17_final_e"
#include <bits/stdc++.h>
#include "src/Math/ModInt.hpp"
#include "src/Graph/LinearSystemIncidence.hpp"
using namespace std;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  using Mint = ModInt<26>;
  string S;
  cin >> S;
  int N, M = S.length() + 1;
  cin >> N;
  LinearSystemIncidence<Mint> lsi((M + 1) / 2);
  for (int i = 0; i < N; i++) {
    int L, R;
    cin >> L >> R;
    L--;
    if (2 * L >= M) L = M - 1 - L;
    if (2 * R >= M) R = M - 1 - R;
    lsi.add_edge(L, R);
  }
  vector<Mint> b((M + 1) / 2);
  b[0] = S[0] - S.back();
  for (int i = 1; i < M / 2; i++)
    b[i] = (S[i] - S[i - 1]) + (S[M - 1 - i] - S[M - 2 - i]);
  if (M & 1) b[M / 2] = S[M / 2] - S[M / 2 - 1];
  auto [isok, sol] = lsi.solve(b);
  cout << (isok ? "YES" : "NO") << '\n';
  return 0;
}