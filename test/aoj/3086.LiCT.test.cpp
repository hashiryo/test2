#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/3086"
#include <iostream>
#include <vector>
#include <algorithm>
#include "src/DataStructure/SegmentTree.hpp"
#include "src/Optimization/LiChaoTree.hpp"
using namespace std;
struct RMQ {
 using T= long long;
 static T ti() { return -1e18; }
 static T op(T l, T r) { return max(l, r); }
};
signed main() {
 cin.tie(0);
 ios::sync_with_stdio(0);
 int N, L;
 cin >> N >> L;
 vector<long long> a(N);
 for (int i= 0; i < N; ++i) cin >> a[i];
 SegmentTree<RMQ> seg(a);
 auto w= [&](int i, int j, long long d) { return d + seg.fold(j, i); };
 LiChaoTree lct(w, 1, N + 1);
 auto tree= lct.make_tree<MAXIMIZE>();
 tree.insert(L, N + 1, 0, 0);
 for (int i= 1; i < N; ++i) {
  auto dp= tree.query(i).first;
  tree.insert(i + L, N + 1, i, dp);
 }
 cout << tree.query(N).first << '\n';
 return 0;
}