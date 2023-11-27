---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/CsrArray.hpp
    title: "CSR\u5F62\u5F0F"
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/SparseTable.hpp
    title: Sparse-Table
  - icon: ':heavy_check_mark:'
    path: src/Graph/Tree.hpp
    title: "\u6728"
  - icon: ':heavy_check_mark:'
    path: src/Misc/CartesianTree.hpp
    title: Cartesian-Tree
  - icon: ':heavy_check_mark:'
    path: src/String/SuffixArray.hpp
    title: "Suffix Array (\u63A5\u5C3E\u8F9E\u914D\u5217)"
  - icon: ':heavy_check_mark:'
    path: src/String/SuffixTree.hpp
    title: "Suffix Tree (\u63A5\u5C3E\u8F9E\u6728)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc141/tasks/abc141_e
    links:
    - https://atcoder.jp/contests/abc141/tasks/abc141_e
  bundledCode: "#line 1 \"test/atcoder/abc141_e.SuffixTree.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc141/tasks/abc141_e\"\n#include <iostream>\n\
    #include <string>\n#line 2 \"src/DataStructure/SparseTable.hpp\"\n#include <vector>\n\
    template <class T, class F> class SparseTable {\n std::vector<std::vector<T>>\
    \ dat;\n F f;\npublic:\n SparseTable() {}\n SparseTable(const std::vector<T> &v,\
    \ const F &f): f(f) {\n  int n= v.size(), log= n > 1 ? 31 - __builtin_clz(n -\
    \ 1) : 0;\n  dat.resize(log + 1), dat[0].assign(v.begin(), v.end());\n  for (int\
    \ i= 0, I= 1, j; i < log; ++i, I<<= 1)\n   for (dat[i + 1].resize(j= dat[i].size()\
    \ - I); j--;) dat[i + 1][j]= f(dat[i][j], dat[i][j + I]);\n }\n // [l, r)\n T\
    \ fold(int l, int r) const {\n  if (r == l + 1) return dat[0][l];\n  int k= 31\
    \ - __builtin_clz(r - l - 1);\n  return f(dat[k][l], dat[k][r - (1 << k)]);\n\
    \ }\n};\n#line 4 \"src/String/SuffixArray.hpp\"\n#include <algorithm>\ntemplate\
    \ <class String> struct SuffixArray {\n String s;\n std::vector<int> sa;\n static\
    \ inline std::vector<int> sa_is(const std::vector<int> &s, int K) {\n  const int\
    \ n= s.size();\n  std::vector<char> t(n);\n  std::vector<int> bkt(K, 0), bkt_l(K),\
    \ bkt_r(K), sa(n), p1;\n  t.back()= true;\n  for (int i= n; --i;)\n   if (t[i\
    \ - 1]= (s[i - 1] < s[i] || (t[i] && s[i - 1] == s[i])); t[i] && !t[i - 1]) p1.push_back(i);\n\
    \  std::reverse(p1.begin(), p1.end());\n  const int n1= p1.size();\n  for (int\
    \ i= n; i--;) ++bkt[s[i]];\n  for (int i= 0, sum= 0; i < K; ++i) sum+= bkt[i],\
    \ bkt_r[i]= sum, bkt_l[i]= sum - bkt[i];\n  std::vector<int> s1(n1), sa1(n1);\n\
    \  std::fill_n(sa.begin(), n, -1), std::copy_n(bkt_r.begin(), K, bkt.begin());\n\
    \  for (int i= n1; i--;) sa[--bkt[s[p1[i]]]]= p1[i];\n  std::copy_n(bkt_l.begin(),\
    \ K, bkt.begin());\n  for (int i= 0, j; i < n; ++i)\n   if ((j= sa[i] - 1) >=\
    \ 0 && !t[j]) sa[bkt[s[j]]++]= j;\n  std::copy_n(bkt_r.begin(), K, bkt.begin());\n\
    \  for (int i= n, j; i--;)\n   if ((j= sa[i] - 1) >= 0 && t[j]) sa[--bkt[s[j]]]=\
    \ j;\n  for (int i= 0, j= 0; i < n; ++i)\n   if (t[sa[i]] && sa[i] > 0 && !t[sa[i]\
    \ - 1]) sa1[j++]= sa[i];\n  int name= 0;\n  for (int i= 0, prev= -1, j, pos; i\
    \ < n1; ++i, sa[pos]= name - 1)\n   for (j= 0, pos= sa1[i];; ++j)\n    if (prev\
    \ == -1 || s[pos + j] != s[prev + j] || t[pos + j] != t[prev + j]) {\n     prev=\
    \ pos, ++name;\n     break;\n    } else if (j && ((t[pos + j] && !t[pos + j -\
    \ 1]) || (t[prev + j] && !t[prev + j - 1]))) break;\n  for (int i= n1; i--;) s1[i]=\
    \ sa[p1[i]];\n  if (name != n1) sa1= sa_is(s1, name);\n  else\n   for (int i=\
    \ n1; i--;) sa1[s1[i]]= i;\n  std::copy_n(bkt_r.begin(), K, bkt.begin()), std::fill_n(sa.begin(),\
    \ n, -1);\n  for (int i= n1; i--;) sa[--bkt[s[p1[sa1[i]]]]]= p1[sa1[i]];\n  for\
    \ (int i= 0, j; i < n; ++i)\n   if ((j= sa[i] - 1) >= 0 && !t[j]) sa[bkt_l[s[j]]++]=\
    \ j;\n  for (int i= n, j; i--;)\n   if ((j= sa[i] - 1) >= 0 && t[j]) sa[--bkt_r[s[j]]]=\
    \ j;\n  return sa;\n }\npublic:\n SuffixArray(const String &S): s(S) {\n  std::vector<int>\
    \ s_cpy(s.size() + 1);\n  if constexpr (std::is_convertible_v<String, std::string>)\
    \ std::copy(s.begin(), s.end(), s_cpy.begin()), sa= sa_is(s_cpy, 128), sa.erase(sa.begin());\n\
    \  else {\n   auto v= s;\n   sort(v.begin(), v.end()), v.erase(unique(v.begin(),\
    \ v.end()), v.end());\n   for (int i= s.size(); i--;) s_cpy[i]= std::lower_bound(v.begin(),\
    \ v.end(), s[i]) - v.begin() + 1;\n   sa= sa_is(s_cpy, v.size() + 1), sa.erase(sa.begin());\n\
    \  }\n }\n int operator[](int i) const { return sa[i]; }\n size_t size() const\
    \ { return sa.size(); }\n auto begin() const { return sa.begin(); }\n auto end()\
    \ const { return sa.end(); }\n // return {l,r} s.t. P is a prefix of S[sa[i]:]\
    \ ( i in [l,r) )\n // l == r if P is not a substring of S\n // O(|P|log|S|)\n\
    \ std::pair<int, int> pattern_matching(const String &P) const {\n  const int n=\
    \ s.size(), m= P.size();\n  if (n < m) return {0, 0};\n  auto f1= [&](int h) {\n\
    \   auto t= s.begin() + h;\n   for (int j= 0, e= std::min(n - h, m); j < e; ++j)\
    \ {\n    if (t[j] < P[j]) return true;\n    if (t[j] > P[j]) return false;\n \
    \  }\n   return n - h < m;\n  };\n  auto f2= [&](int h) {\n   auto t= s.begin()\
    \ + h;\n   for (int j= 0, e= std::min(n - h, m); j < e; ++j)\n    if (t[j] > P[j])\
    \ return false;\n   return true;\n  };\n  auto L= std::partition_point(sa.begin(),\
    \ sa.end(), f1), R= std::partition_point(L, sa.end(), f2);\n  return {L - sa.begin(),\
    \ R - sa.begin()};\n }\n};\nstruct LCPArray {\n std::vector<int> rnk;\n template\
    \ <class String> LCPArray(const SuffixArray<String> &sa): rnk(sa.size()) {\n \
    \ const int n= sa.size(), log= n > 2 ? 31 - __builtin_clz(n - 2) : 0;\n  dat.resize(log\
    \ + 1), dat[0].resize(n - 1);\n  auto &lcp= dat[0];\n  for (int i= n; i--;) rnk[sa[i]]=\
    \ i;\n  for (int i= 0, h= 0; i < n; ++i) {\n   if (rnk[i] == n - 1) {\n    h=\
    \ 0;\n    continue;\n   }\n   for (int j= sa[rnk[i] + 1]; i + h < n && j + h <\
    \ n && sa.s[i + h] == sa.s[j + h];) ++h;\n   if ((lcp[rnk[i]]= h)) --h;\n  }\n\
    \  for (int i= 0, I= 1, j; i < log; ++i, I<<= 1)\n   for (dat[i + 1].resize(j=\
    \ dat[i].size() - I); j--;) dat[i + 1][j]= std::min(dat[i][j], dat[i][j + I]);\n\
    \ }\n int operator[](int i) const { return dat[0][i]; }\n size_t size() const\
    \ { return dat[0].size(); }\n auto begin() const { return dat[0].begin(); }\n\
    \ auto end() const { return dat[0].end(); }\n int operator()(int i, int j) const\
    \ {\n  if (i == j) return rnk.size() - i;\n  auto [l, r]= std::minmax(rnk[i],\
    \ rnk[j]);\n  if (r == l + 1) return dat[0][l];\n  int k= 31 - __builtin_clz(r\
    \ - l - 1);\n  return std::min(dat[k][l], dat[k][r - (1 << k)]);\n }\nprivate:\n\
    \ std::vector<std::vector<int>> dat;\n};\n#line 2 \"src/Graph/Tree.hpp\"\n#include\
    \ <type_traits>\n#include <cstddef>\n#line 5 \"src/Graph/Tree.hpp\"\n#include\
    \ <array>\n#include <tuple>\n#include <numeric>\n#include <cassert>\n#line 3 \"\
    src/DataStructure/CsrArray.hpp\"\n#include <iterator>\ntemplate <class T> struct\
    \ ListRange {\n using Iterator= typename std::vector<T>::const_iterator;\n Iterator\
    \ bg, ed;\n Iterator begin() const { return bg; }\n Iterator end() const { return\
    \ ed; }\n size_t size() const { return std::distance(bg, ed); }\n const T &operator[](int\
    \ i) const { return bg[i]; }\n};\ntemplate <class T> class CsrArray {\n std::vector<T>\
    \ csr;\n std::vector<int> pos;\npublic:\n CsrArray()= default;\n CsrArray(const\
    \ std::vector<T> &c, const std::vector<int> &p): csr(c), pos(p) {}\n size_t size()\
    \ const { return pos.size() - 1; }\n const ListRange<T> operator[](int i) const\
    \ { return {csr.cbegin() + pos[i], csr.cbegin() + pos[i + 1]}; }\n};\n#line 10\
    \ \"src/Graph/Tree.hpp\"\ntemplate <class Cost= void, bool weight= false> class\
    \ Tree {\n template <class D, class T> struct Edge_B {\n  int to;\n  T cost;\n\
    \  operator int() const { return to; }\n };\n template <class D> struct Edge_B<D,\
    \ void> {\n  int to;\n  operator int() const { return to; }\n };\n using Edge=\
    \ Edge_B<void, Cost>;\n using C= std::conditional_t<std::is_void_v<Cost>, std::nullptr_t,\
    \ Cost>;\n std::vector<std::conditional_t<std::is_void_v<Cost>, std::pair<int,\
    \ int>, std::tuple<int, int, Cost>>> es;\n std::vector<Edge> g;\n std::vector<int>\
    \ P, PP, D, I, L, R, pos;\n std::vector<C> DW, W;\npublic:\n Tree(int n): P(n,\
    \ -2) {}\n template <class T= Cost> std::enable_if_t<std::is_void_v<T>, void>\
    \ add_edge(int u, int v) { es.emplace_back(u, v), es.emplace_back(v, u); }\n template\
    \ <class T> std::enable_if_t<std::is_convertible_v<T, Cost>, void> add_edge(int\
    \ u, int v, T c) { es.emplace_back(u, v, c), es.emplace_back(v, u, c); }\n template\
    \ <class T, class U, std::enable_if_t<std::conjunction_v<std::is_convertible<T,\
    \ Cost>, std::is_convertible<U, Cost>>, std::nullptr_t> = nullptr> void add_edge(int\
    \ u, int v, T c, U d) /* c:u->v, d:v->u */ { es.emplace_back(u, v, c), es.emplace_back(v,\
    \ u, d); }\n void build(int root= 0) {\n  size_t n= P.size();\n  I.resize(n),\
    \ PP.resize(n), std::iota(PP.begin(), PP.end(), 0), D.assign(n, 0), L.assign(n,\
    \ 0), R.assign(n, 0), pos.resize(n + 1), g.resize(es.size());\n  for (const auto\
    \ &e: es) ++pos[std::get<0>(e)];\n  std::partial_sum(pos.begin(), pos.end(), pos.begin());\n\
    \  if constexpr (std::is_void_v<Cost>)\n   for (const auto &[f, t]: es) g[--pos[f]]=\
    \ {t};\n  else\n   for (const auto &[f, t, c]: es) g[--pos[f]]= {t, c};\n  auto\
    \ f= [&, i= 0, v= 0, t= 0](int r) mutable {\n   for (P[r]= -1, I[t++]= r; i <\
    \ t; ++i)\n    for (int u: operator[](v= I[i]))\n     if (P[v] != u) P[I[t++]=\
    \ u]= v;\n  };\n  f(root);\n  for (size_t r= 0; r < n; ++r)\n   if (P[r] == -2)\
    \ f(r);\n  std::vector<int> Z(n, 1), nx(n, -1);\n  for (int i= n, v; i--;) {\n\
    \   if (P[v= I[i]] == -1) continue;\n   if (Z[P[v]]+= Z[v]; nx[P[v]] == -1) nx[P[v]]=\
    \ v;\n   if (Z[nx[P[v]]] < Z[v]) nx[P[v]]= v;\n  }\n  for (int v: I)\n   if (nx[v]\
    \ != -1) PP[nx[v]]= v;\n  for (int v: I)\n   if (P[v] != -1) PP[v]= PP[PP[v]],\
    \ D[v]= D[P[v]] + 1;\n  for (int i= n; i--;) L[I[i]]= i;\n  for (int v: I) {\n\
    \   int ir= R[v]= L[v] + Z[v];\n   for (int u: operator[](v))\n    if (u != P[v]\
    \ && u != nx[v]) L[u]= ir-= Z[u];\n   if (nx[v] != -1) L[nx[v]]= L[v] + 1;\n \
    \ }\n  if constexpr (weight) {\n   DW.resize(n), W.resize(n);\n   for (int v:\
    \ I)\n    for (auto &[u, c]: operator[](v)) {\n     if (u != P[v]) DW[u]= DW[v]\
    \ + c;\n     else W[v]= c;\n    }\n  }\n  for (int i= n; i--;) I[L[i]]= i;\n }\n\
    \ size_t size() const { return P.size(); }\n const ListRange<Edge> operator[](int\
    \ v) const { return {g.cbegin() + pos[v], g.cbegin() + pos[v + 1]}; }\n int depth(int\
    \ v) const { return D[v]; }\n C depth_w(int v) const {\n  static_assert(weight,\
    \ \"\\'depth_w\\' is not available\");\n  return DW[v];\n }\n int to_seq(int v)\
    \ const { return L[v]; }\n int to_node(int i) const { return I[i]; }\n int parent(int\
    \ v) const { return P[v]; }\n int head(int v) const { return PP[v]; }\n int root(int\
    \ v) const {\n  for (v= PP[v];; v= PP[P[v]])\n   if (P[v] == -1) return v;\n }\n\
    \ bool connected(int u, int v) const { return root(u) == root(v); }\n int lca(int\
    \ u, int v) const {\n  for (;; v= P[PP[v]]) {\n   if (L[u] > L[v]) std::swap(u,\
    \ v);\n   if (PP[u] == PP[v]) return u;\n  }\n }\n int la(int v, int k) const\
    \ {\n  assert(k <= D[v]);\n  for (int u;; k-= L[v] - L[u] + 1, v= P[u])\n   if\
    \ (L[v] - k >= L[u= PP[v]]) return I[L[v] - k];\n }\n int la_w(int v, C w) const\
    \ {\n  static_assert(weight, \"\\'la_w\\' is not available\");\n  for (C c;; w-=\
    \ c) {\n   int u= PP[v];\n   if (c= DW[v] - DW[u] + W[u]; w < c) {\n    int ok=\
    \ L[v], ng= L[u] - 1;\n    for (int m; ok - ng > 1;) m= (ok + ng) / 2, (DW[v]\
    \ - DW[I[m]] <= w ? ok : ng)= m;\n    return I[ok];\n   }\n   if (v= P[u]; v ==\
    \ -1) return u;\n  }\n }\n int jump(int u, int v, int k) const {\n  if (!k) return\
    \ u;\n  if (u == v) return -1;\n  if (k == 1) return in_subtree(v, u) ? la(v,\
    \ D[v] - D[u] - 1) : P[u];\n  int w= lca(u, v), d_uw= D[u] - D[w], d_vw= D[v]\
    \ - D[w];\n  return k > d_uw + d_vw ? -1 : k <= d_uw ? la(u, k) : la(v, d_uw +\
    \ d_vw - k);\n }\n int jump_w(int u, int v, C w) const {\n  static_assert(weight,\
    \ \"\\'jump_w\\' is not available\");\n  if (u == v) return u;\n  int z= lca(u,\
    \ v);\n  C d_uz= DW[u] - DW[z], d_vz= DW[v] - DW[z];\n  return w >= d_uz + d_vz\
    \ ? v : w <= d_uz ? la_w(u, w) : la_w(v, d_uz + d_vz - w);\n }\n int dist(int\
    \ u, int v) const { return D[u] + D[v] - D[lca(u, v)] * 2; }\n C dist_w(int u,\
    \ int v) const {\n  static_assert(weight, \"\\'dist_w\\' is not available\");\n\
    \  return DW[u] + DW[v] - DW[lca(u, v)] * 2;\n }\n // u is in v\n bool in_subtree(int\
    \ u, int v) const { return L[v] <= L[u] && L[u] < R[v]; }\n int subtree_size(int\
    \ v) const { return R[v] - L[v]; }\n // half-open interval\n std::array<int, 2>\
    \ subtree(int v) const { return std::array{L[v], R[v]}; }\n // sequence of closed\
    \ intervals\n template <bool edge= 0> std::vector<std::array<int, 2>> path(int\
    \ u, int v) const {\n  std::vector<std::array<int, 2>> up, down;\n  while (PP[u]\
    \ != PP[v]) {\n   if (L[u] < L[v]) down.emplace_back(std::array{L[PP[v]], L[v]}),\
    \ v= P[PP[v]];\n   else up.emplace_back(std::array{L[u], L[PP[u]]}), u= P[PP[u]];\n\
    \  }\n  if (L[u] < L[v]) down.emplace_back(std::array{L[u] + edge, L[v]});\n \
    \ else if (L[v] + edge <= L[u]) up.emplace_back(std::array{L[u], L[v] + edge});\n\
    \  return up.insert(up.end(), down.rbegin(), down.rend()), up;\n }\n};\n#line\
    \ 4 \"src/Misc/CartesianTree.hpp\"\nclass CartesianTree {\n std::vector<std::array<int,\
    \ 2>> rg, ch;\n std::vector<int> par;\n int rt;\npublic:\n template <class Vec>\
    \ CartesianTree(const Vec &a, bool is_min= 1): rg(a.size()), ch(a.size(), std::array{-1,\
    \ -1}), par(a.size(), -1) {\n  const int n= a.size();\n  auto comp= [&](int l,\
    \ int r) { return (is_min ? a[l] < a[r] : a[l] > a[r]) || (a[l] == a[r] && l <\
    \ r); };\n  int st[n], t= 0;\n  for (int i= n; i--; rg[i][1]= (t ? st[t - 1] :\
    \ n), st[t++]= i)\n   while (t && comp(i, st[t - 1])) ch[i][1]= st[--t];\n  for\
    \ (int i= t= 0; i < n; rg[i][0]= (t ? st[t - 1] + 1 : 0), st[t++]= i++)\n   while\
    \ (t && comp(i, st[t - 1])) ch[i][0]= st[--t];\n  for (int i= 0; i < n; ++i)\n\
    \   for (int b= 2; b--;)\n    if (ch[i][b] != -1) par[ch[i][b]]= i;\n  for (int\
    \ i= 0; i < n; ++i)\n   if (par[i] == -1) rt= i;\n }\n std::array<int, 2> children(int\
    \ i) const { return ch[i]; }\n int parent(int i) const { return par[i]; }\n int\
    \ root() const { return rt; }\n // [l,r)\n std::array<int, 2> range(int i) const\
    \ { return rg[i]; }\n};\n#line 5 \"src/String/SuffixTree.hpp\"\nstruct SuffixTree\
    \ {\n Tree<void> tree;\n std::vector<std::tuple<int, int, int, int>> node;\n std::vector<int>\
    \ suf;\n template <class String> SuffixTree(const SuffixArray<String> &sa, const\
    \ LCPArray &lcp): tree(1), suf(sa.size()) {\n  const int n= sa.size();\n  node.emplace_back(0,\
    \ n, 0, 0);\n  if (n == 1) {\n   tree= Tree<void>(2), tree.add_edge(0, 1), tree.build(),\
    \ node.emplace_back(0, 1, 0, 1), suf[0]= 1;\n   return;\n  }\n  std::vector<std::tuple<int,\
    \ int>> es;\n  CartesianTree ct(lcp);\n  auto dfs= [&](auto dfs, int p, int idx,\
    \ int h) -> void {\n   auto [l, r]= ct.range(idx);\n   ++r;\n   int hh= lcp[idx];\n\
    \   if (h < hh) es.emplace_back(p, node.size()), p= node.size(), node.emplace_back(l,\
    \ r, h, hh);\n   auto [lch, rch]= ct.children(idx);\n   if (lch == -1) {\n   \
    \ if (hh < n - sa[idx]) es.emplace_back(p, node.size()), suf[sa[idx]]= node.size(),\
    \ node.emplace_back(idx, idx + 1, hh, n - sa[idx]);\n    else suf[sa[idx]]= p;\n\
    \   } else dfs(dfs, p, lch, hh);\n   if (rch == -1) {\n    if (hh < n - sa[idx\
    \ + 1]) es.emplace_back(p, node.size()), suf[sa[idx + 1]]= node.size(), node.emplace_back(idx\
    \ + 1, idx + 2, hh, n - sa[idx + 1]);\n    else suf[sa[idx + 1]]= p;\n   } else\
    \ dfs(dfs, p, rch, hh);\n  };\n  if (int r= ct.root(); lcp[r] > 0) es.emplace_back(0,\
    \ 1), node.emplace_back(0, n, 0, lcp[r]), dfs(dfs, 1, r, lcp[r]);\n  else dfs(dfs,\
    \ 0, r, 0);\n  tree= Tree<void>(node.size());\n  for (auto [u, v]: es) tree.add_edge(u,\
    \ v);\n  tree.build();\n }\n int size() const { return node.size(); }\n auto &operator[](int\
    \ i) const { return node[i]; }\n auto begin() const { return node.begin(); }\n\
    \ auto end() const { return node.end(); }\n int substr(int l) const { return suf[l];\
    \ }\n int substr(int l, int n) const {\n  for (int v= suf[l], u, w;; v= w)\n \
    \  if (u= tree.head(v), w= tree.parent(u); w == -1 || std::get<3>(node[w]) < n)\
    \ {\n    int ok= tree.to_seq(v), ng= tree.to_seq(u) - 1;\n    for (int m; ok -\
    \ ng > 1;) m= (ok + ng) / 2, (n <= std::get<3>(node[tree.to_node(m)]) ? ok : ng)=\
    \ m;\n    return tree.to_node(ok);\n   }\n }\n template <class String> std::string\
    \ debug_output(const SuffixArray<String> &sa) const {\n  std::string res= \"\\\
    n\";\n  for (int i= 0; i < node.size(); ++i) {\n   auto [l, r, h, hh]= node[i];\n\
    \   res+= std::to_string(i) + \": (\" + std::to_string(l) + \",\" + std::to_string(r)\
    \ + \",\" + std::to_string(h) + \",\" + std::to_string(hh) + \") \";\n   res+=\
    \ sa.s.substr(sa[l] + h, hh - h);\n   res+= \"\\n\";\n  }\n  for (int i= 0; i\
    \ < sa.size(); ++i) {\n   res+= \" \" + sa.s.substr(sa[i]) + \"\\n\";\n  }\n \
    \ return res;\n }\n};\n#line 6 \"test/atcoder/abc141_e.SuffixTree.test.cpp\"\n\
    using namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ int N;\n cin >> N;\n string S;\n cin >> S;\n SuffixArray sa(S);\n LCPArray lcp(sa);\n\
    \ SuffixTree st(sa, lcp);\n SparseTable sa_mn(sa.sa, [&](int i, int j) { return\
    \ min(i, j); });\n SparseTable sa_mx(sa.sa, [&](int i, int j) { return max(i,\
    \ j); });\n int ans= 0;\n for (auto [l, r, h, hh]: st) {\n  int i= sa_mn.fold(l,\
    \ r), j= sa_mx.fold(l, r);\n  ans= max(ans, min(j - i, hh));\n }\n cout << ans\
    \ << '\\n';\n return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc141/tasks/abc141_e\"\n#include\
    \ <iostream>\n#include <string>\n#include \"src/DataStructure/SparseTable.hpp\"\
    \n#include \"src/String/SuffixTree.hpp\"\nusing namespace std;\nsigned main()\
    \ {\n cin.tie(0);\n ios::sync_with_stdio(0);\n int N;\n cin >> N;\n string S;\n\
    \ cin >> S;\n SuffixArray sa(S);\n LCPArray lcp(sa);\n SuffixTree st(sa, lcp);\n\
    \ SparseTable sa_mn(sa.sa, [&](int i, int j) { return min(i, j); });\n SparseTable\
    \ sa_mx(sa.sa, [&](int i, int j) { return max(i, j); });\n int ans= 0;\n for (auto\
    \ [l, r, h, hh]: st) {\n  int i= sa_mn.fold(l, r), j= sa_mx.fold(l, r);\n  ans=\
    \ max(ans, min(j - i, hh));\n }\n cout << ans << '\\n';\n return 0;\n}"
  dependsOn:
  - src/DataStructure/SparseTable.hpp
  - src/String/SuffixTree.hpp
  - src/String/SuffixArray.hpp
  - src/Graph/Tree.hpp
  - src/DataStructure/CsrArray.hpp
  - src/Misc/CartesianTree.hpp
  isVerificationFile: true
  path: test/atcoder/abc141_e.SuffixTree.test.cpp
  requiredBy: []
  timestamp: '2023-11-24 00:33:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc141_e.SuffixTree.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc141_e.SuffixTree.test.cpp
- /verify/test/atcoder/abc141_e.SuffixTree.test.cpp.html
title: test/atcoder/abc141_e.SuffixTree.test.cpp
---