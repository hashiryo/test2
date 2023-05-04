---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/CsrArray.hpp
    title: "CSR\u5F62\u5F0F"
  - icon: ':heavy_check_mark:'
    path: src/Graph/FunctionalGraph.hpp
    title: "Functional\u30B0\u30E9\u30D5"
  - icon: ':heavy_check_mark:'
    path: src/Graph/Tree.hpp
    title: "\u6728\u30AF\u30E9\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc179/tasks/abc179_e
    links:
    - https://atcoder.jp/contests/abc179/tasks/abc179_e
  bundledCode: "#line 1 \"test/atcoder/abc179_e.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc179/tasks/abc179_e\"\
    \n#include <iostream>\n#line 2 \"src/Graph/Tree.hpp\"\n#include <type_traits>\n\
    #include <cstddef>\n#include <algorithm>\n#include <array>\n#include <tuple>\n\
    #include <numeric>\n#include <cassert>\n#line 2 \"src/DataStructure/CsrArray.hpp\"\
    \n#include <vector>\n#include <iterator>\ntemplate <class T> struct ListRange\
    \ {\n using Iterator= typename std::vector<T>::const_iterator;\n Iterator bg,\
    \ ed;\n Iterator begin() const { return bg; }\n Iterator end() const { return\
    \ ed; }\n size_t size() const { return std::distance(bg, ed); }\n const T &operator[](int\
    \ i) const { return bg[i]; }\n};\ntemplate <class T> class CsrArray {\n std::vector<T>\
    \ csr;\n std::vector<int> pos;\npublic:\n CsrArray()= default;\n CsrArray(const\
    \ std::vector<T> &c, const std::vector<int> &p): csr(c), pos(p) {}\n size_t size()\
    \ const { return pos.size() - 1; }\n const ListRange<T> operator[](int i) const\
    \ { return {csr.cbegin() + pos[i], csr.cbegin() + pos[i + 1]}; }\n};\n#line 10\
    \ \"src/Graph/Tree.hpp\"\ntemplate <class Cost= void> class Tree {\n template\
    \ <class D, class T> struct Edge_B {\n  int to;\n  T cost;\n  operator int() const\
    \ { return to; }\n };\n template <class D> struct Edge_B<D, void> {\n  int to;\n\
    \  operator int() const { return to; }\n };\n using Edge= Edge_B<void, Cost>;\n\
    \ std::vector<std::conditional_t<std::is_same_v<Cost, void>, std::pair<int, int>,\
    \ std::tuple<int, int, Cost>>> es;\n std::vector<Edge> g;\n std::vector<int> P,\
    \ PP, D, I, L, R, pos;\npublic:\n Tree(int n): P(n, -2) {}\n template <class T=\
    \ Cost, std::enable_if_t<std::is_same_v<T, void>, std::nullptr_t> = nullptr> void\
    \ add_edge(int u, int v) { es.emplace_back(u, v), es.emplace_back(v, u); }\n template\
    \ <class T, std::enable_if_t<std::is_convertible_v<T, Cost>, std::nullptr_t> =\
    \ nullptr> void add_edge(int u, int v, T c) { es.emplace_back(u, v, c), es.emplace_back(v,\
    \ u, c); }\n template <class T, class U, std::enable_if_t<std::conjunction_v<std::is_convertible<T,\
    \ Cost>, std::is_convertible<U, Cost>>, std::nullptr_t> = nullptr> void add_edge(int\
    \ u, int v, T c, U d) /* c:u->v, d:v->u */ { es.emplace_back(u, v, c), es.emplace_back(v,\
    \ u, d); }\n void build(int root= 0) {\n  size_t n= P.size();\n  I.resize(n),\
    \ PP.resize(n), std::iota(PP.begin(), PP.end(), 0), D.assign(n, 0), L.assign(n,\
    \ 0), R.assign(n, 0), pos.resize(n + 1), g.resize(es.size());\n  for (const auto\
    \ &e: es) ++pos[std::get<0>(e)];\n  std::partial_sum(pos.begin(), pos.end(), pos.begin());\n\
    \  if constexpr (std::is_same_v<Cost, void>)\n   for (const auto &[f, t]: es)\
    \ g[--pos[f]]= {t};\n  else\n   for (const auto &[f, t, c]: es) g[--pos[f]]= {t,\
    \ c};\n  auto f= [&, i= 0, v= 0, t= 0](int r) mutable {\n   for (P[r]= -1, I[t++]=\
    \ r; i < t; ++i)\n    for (int u: operator[](v= I[i]))\n     if (P[v] != u) P[I[t++]=\
    \ u]= v;\n  };\n  f(root);\n  for (size_t r= 0; r < n; ++r)\n   if (P[r] == -2)\
    \ f(r);\n  std::vector<int> Z(n, 1), nx(n, -1);\n  for (int i= n, v; i--;) {\n\
    \   if (P[v= I[i]] == -1) continue;\n   if (Z[P[v]]+= Z[v]; nx[P[v]] == -1) nx[P[v]]=\
    \ v;\n   if (Z[nx[P[v]]] < Z[v]) nx[P[v]]= v;\n  }\n  for (int v: I)\n   if (nx[v]\
    \ != -1) PP[nx[v]]= v;\n  for (int v: I)\n   if (P[v] != -1) PP[v]= PP[PP[v]],\
    \ D[v]= D[P[v]] + 1;\n  for (int i= n; i--;) L[I[i]]= i;\n  for (int v: I) {\n\
    \   int ir= R[v]= L[v] + Z[v];\n   for (int u: operator[](v))\n    if (u != P[v]\
    \ && u != nx[v]) L[u]= ir-= Z[u];\n   if (nx[v] != -1) L[nx[v]]= L[v] + 1;\n \
    \ }\n  for (int i= n; i--;) I[L[i]]= i;\n }\n size_t size() const { return P.size();\
    \ }\n const ListRange<Edge> operator[](int v) const { return {g.cbegin() + pos[v],\
    \ g.cbegin() + pos[v + 1]}; }\n int depth(int v) const { return D[v]; }\n int\
    \ to_seq(int v) const { return L[v]; }\n int to_node(int i) const { return I[i];\
    \ }\n int parent(int v) const { return P[v]; }\n int root(int v) const {\n  for\
    \ (v= PP[v];; v= PP[P[v]])\n   if (P[v] == -1) return v;\n }\n bool connected(int\
    \ u, int v) const { return root(u) == root(v); }\n int lca(int u, int v) const\
    \ {\n  for (;; v= P[PP[v]]) {\n   if (L[u] > L[v]) std::swap(u, v);\n   if (PP[u]\
    \ == PP[v]) return u;\n  }\n }\n int la(int v, int k) const {\n  assert(k <= D[v]);\n\
    \  for (int u;; k-= L[v] - L[u] + 1, v= P[u])\n   if (L[v] - k >= L[u= PP[v]])\
    \ return I[L[v] - k];\n }\n int jump(int u, int v, int k) const {\n  if (!k) return\
    \ u;\n  if (u == v) return -1;\n  if (k == 1) return in_subtree(v, u) ? la(v,\
    \ D[v] - D[u] - 1) : P[u];\n  int w= lca(u, v), d_uw= D[u] - D[w], d_vw= D[v]\
    \ - D[w];\n  return k > d_uw + d_vw ? -1 : k <= d_uw ? la(u, k) : la(v, d_uw +\
    \ d_vw - k);\n }\n int dist(int u, int v) const { return depth(u) + depth(v) -\
    \ depth(lca(u, v)) * 2; }\n // u is in v\n bool in_subtree(int u, int v) const\
    \ { return L[v] <= L[u] && L[u] < R[v]; }\n int subtree_size(int v) const { return\
    \ R[v] - L[v]; }\n // half-open interval\n std::array<int, 2> subtree(int v) const\
    \ { return std::array{L[v], R[v]}; }\n // sequence of closed intervals\n template\
    \ <bool edge= 0> std::vector<std::array<int, 2>> path(int u, int v) const {\n\
    \  std::vector<std::array<int, 2>> up, down;\n  while (PP[u] != PP[v]) {\n   if\
    \ (L[u] < L[v]) down.emplace_back(std::array{L[PP[v]], L[v]}), v= P[PP[v]];\n\
    \   else up.emplace_back(std::array{L[u], L[PP[u]]}), u= P[PP[u]];\n  }\n  if\
    \ (L[u] < L[v]) down.emplace_back(std::array{L[u] + edge, L[v]});\n  else if (L[v]\
    \ + edge <= L[u]) up.emplace_back(std::array{L[u], L[v] + edge});\n  return up.insert(up.end(),\
    \ down.rbegin(), down.rend()), up;\n }\n};\n#line 3 \"src/Graph/FunctionalGraph.hpp\"\
    \nclass FunctionalGraph {\n std::vector<int> to, rt;\n Tree<> tree;\npublic:\n\
    \ FunctionalGraph(int n): to(n, -1), rt(n, -1), tree(n + 1) {}\n void add_edge(int\
    \ src, int dst) { assert(to[src] == -1), to[src]= dst; }\n void build() {\n  const\
    \ int n= to.size();\n  for (int u, w, v= n; v--;)\n   if (rt[v] == -1) {\n   \
    \ for (rt[v]= -2, w= to[v];; rt[w]= -2, w= to[w])\n     if (assert(w != -1); rt[w]\
    \ != -1) {\n      if (rt[w] != -2) w= rt[w];\n      break;\n     }\n    for (u=\
    \ v; rt[u] == -2; u= to[u]) rt[u]= w;\n   }\n  for (int v= n; v--;)\n   if (rt[v]\
    \ == v) tree.add_edge(v, n);\n   else tree.add_edge(v, to[v]);\n  tree.build(n);\n\
    \ }\n template <class Int> std::enable_if_t<std::is_convertible_v<int, Int>, int>\
    \ jump(int v, Int k) const {\n  int n= to.size(), d= tree.depth(v) - 1;\n  if\
    \ (k <= d) return tree.jump(v, n, (int)k);\n  int b= to[v= rt[v]], l= (k-= d)\
    \ % tree.depth(b);\n  if (l == 0) return v;\n  return tree.jump(b, n, l - 1);\n\
    \ }\n // ((a_0,...,a_{i-1}) x 1, (a_i,...,a_{j-1}) x loop_num, (a_j,...,a_m) x\
    \ 1)\n template <class Int> std::enable_if_t<std::is_convertible_v<int, Int>,\
    \ std::array<std::pair<std::vector<int>, Int>, 3>> path(int v, Int k) const {\n\
    \  std::array<std::pair<std::vector<int>, Int>, 3> ret;\n  int n= to.size(), d=\
    \ tree.depth(v) - 1;\n  if (ret[0].second= 1; k <= d) {\n   for (int e= k; e--;\
    \ v= to[v]) ret[0].first.push_back(v);\n   return ret;\n  }\n  for (int e= d;\
    \ e--; v= to[v]) ret[0].first.push_back(v);\n  int b= to[v= rt[v]], c= tree.depth(b),\
    \ l= (k-= d) % c;\n  ret[1].second= k / c, ret[2].second= 1;\n  for (int e= c;\
    \ e--; v= to[v]) ret[1].first.push_back(v);\n  for (int e= l; e--; v= to[v]) ret[2].first.push_back(v);\n\
    \  return ret;\n }\n};\n#line 4 \"test/atcoder/abc179_e.test.cpp\"\nusing namespace\
    \ std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n long long N,\
    \ X, M;\n cin >> N >> X >> M;\n FunctionalGraph graph(M);\n for (long long i=\
    \ 0; i < M; ++i) graph.add_edge(i, i * i % M);\n graph.build();\n auto [a, b,\
    \ c]= graph.path(X, N);\n long long ans= 0;\n for (int x: b.first) ans+= x;\n\
    \ ans*= b.second;\n for (int x: a.first) ans+= x;\n for (int x: c.first) ans+=\
    \ x;\n cout << ans << '\\n';\n return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc179/tasks/abc179_e\"\n#include\
    \ <iostream>\n#include \"src/Graph/FunctionalGraph.hpp\"\nusing namespace std;\n\
    signed main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n long long N, X, M;\n\
    \ cin >> N >> X >> M;\n FunctionalGraph graph(M);\n for (long long i= 0; i < M;\
    \ ++i) graph.add_edge(i, i * i % M);\n graph.build();\n auto [a, b, c]= graph.path(X,\
    \ N);\n long long ans= 0;\n for (int x: b.first) ans+= x;\n ans*= b.second;\n\
    \ for (int x: a.first) ans+= x;\n for (int x: c.first) ans+= x;\n cout << ans\
    \ << '\\n';\n return 0;\n}"
  dependsOn:
  - src/Graph/FunctionalGraph.hpp
  - src/Graph/Tree.hpp
  - src/DataStructure/CsrArray.hpp
  isVerificationFile: true
  path: test/atcoder/abc179_e.test.cpp
  requiredBy: []
  timestamp: '2023-04-23 14:23:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc179_e.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc179_e.test.cpp
- /verify/test/atcoder/abc179_e.test.cpp.html
title: test/atcoder/abc179_e.test.cpp
---