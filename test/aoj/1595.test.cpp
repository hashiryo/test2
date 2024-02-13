#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/challenges/sources/UOA/UAPC/1595"
#include <iostream>
#include "src/Graph/Graph.hpp"
#include "src/Graph/Rerooting.hpp"
using namespace std;
signed main() {
 cin.tie(0);
 ios::sync_with_stdio(0);
 int N;
 cin >> N;
 Graph g(N - 1);
 for (int i= 0; i < N - 1; ++i) cin >> g[i], --g[i];
 g.build(N, 0);
 auto put_edge= [&](int, int, int d) { return d + 1; };
 auto op= [&](int l, int r) { return max(l, r); };
 auto put_vertex= [&](int v, int d) { return d; };
 for (int x: Rerooting<int>(g, put_edge, op, 0, put_vertex)) cout << 2 * (N - 1) - x << '\n';
 return 0;
}