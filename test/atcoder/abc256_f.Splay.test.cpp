// competitive-verifier: PROBLEM https://atcoder.jp/contests/abc256/tasks/abc256_f
// competitive-verifier: TLE 0.5
// competitive-verifier: MLE 64
// 双対 の verify

#include <iostream>
#include <array>
#include "src/Math/ModInt.hpp"
#include "src/DataStructure/SplayTree.hpp"
using namespace std;

using Mint= ModInt<998244353>;
struct Mono {
 struct T {
  Mint val, coef[2];
  T()= default;
  T(Mint id, Mint v): val(v), coef{(id + 1) * (id + 2) / 2, (id * 2 + 3) / 2} {}
 };
 using E= array<Mint, 3>;
 static void mp(T &x, const E &mapp) { x.val+= mapp[0] * x.coef[0] - mapp[1] * x.coef[1] + mapp[2]; }
 static void cp(E &pre, const E &suf) { pre[0]+= suf[0], pre[1]+= suf[1], pre[2]+= suf[2]; }
};
signed main() {
 cin.tie(0);
 ios::sync_with_stdio(false);
 int N, Q;
 cin >> N >> Q;
 Mint A[N], D[N];
 for (int i= 0; i < N; i++) cin >> A[i], D[i]= A[i];
 for (int j= 0; j < 3; j++)
  for (int i= 1; i < N; i++) D[i]+= D[i - 1];
 SplayTree<Mono> spt(N);
 for (int i= 0; i < N; i++) spt.set(i, {i, D[i]});
 while (Q--) {
  int op, x;
  cin >> op >> x, x--;
  if (op == 1) {
   Mint v;
   cin >> v, v-= A[x], A[x]+= v;
   spt.apply(x, N, {v, v * x, v * x * x / 2});
  } else {
   cout << spt[x].val << '\n';
  }
 }
 return 0;
}