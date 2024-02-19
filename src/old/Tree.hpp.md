---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Internal/ListRange.hpp
    title: "CSR \u8868\u73FE\u3092\u7528\u3044\u305F\u4E8C\u6B21\u5143\u914D\u5217\
      \ \u4ED6"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/old/Tree.hpp\"\n#include <type_traits>\n#include <cstddef>\n\
    #include <algorithm>\n#include <array>\n#include <tuple>\n#include <numeric>\n\
    #include <cassert>\n#line 2 \"src/Internal/ListRange.hpp\"\n#include <vector>\n\
    #include <iostream>\n#include <iterator>\n#line 6 \"src/Internal/ListRange.hpp\"\
    \n#define _LR(name, IT, CT) \\\n template <class T> struct name { \\\n  using\
    \ Iterator= typename std::vector<T>::IT; \\\n  Iterator bg, ed; \\\n  Iterator\
    \ begin() const { return bg; } \\\n  Iterator end() const { return ed; } \\\n\
    \  size_t size() const { return std::distance(bg, ed); } \\\n  CT &operator[](int\
    \ i) const { return bg[i]; } \\\n }\n_LR(ListRange, iterator, T);\n_LR(ConstListRange,\
    \ const_iterator, const T);\n#undef _LR\ntemplate <class T> struct CSRArray {\n\
    \ std::vector<T> dat;\n std::vector<int> p;\n size_t size() const { return p.size()\
    \ - 1; }\n ListRange<T> operator[](int i) { return {dat.begin() + p[i], dat.begin()\
    \ + p[i + 1]}; }\n ConstListRange<T> operator[](int i) const { return {dat.cbegin()\
    \ + p[i], dat.cbegin() + p[i + 1]}; }\n};\ntemplate <template <class> class F,\
    \ class T> std::enable_if_t<std::disjunction_v<std::is_same<F<T>, ListRange<T>>,\
    \ std::is_same<F<T>, ConstListRange<T>>, std::is_same<F<T>, CSRArray<T>>>, std::ostream\
    \ &> operator<<(std::ostream &os, const F<T> &r) {\n os << '[';\n for (int _=\
    \ 0, __= r.size(); _ < __; ++_) os << (_ ? \", \" : \"\") << r[_];\n return os\
    \ << ']';\n}\n#line 10 \"src/old/Tree.hpp\"\ntemplate <class Cost= void, bool\
    \ weight= false> class Tree {\n template <class D, class T> struct Edge_B {\n\
    \  int to;\n  T cost;\n  operator int() const { return to; }\n };\n template <class\
    \ D> struct Edge_B<D, void> {\n  int to;\n  operator int() const { return to;\
    \ }\n };\n using Edge= Edge_B<void, Cost>;\n using C= std::conditional_t<std::is_void_v<Cost>,\
    \ std::nullptr_t, Cost>;\n std::vector<std::conditional_t<std::is_void_v<Cost>,\
    \ std::pair<int, int>, std::tuple<int, int, Cost>>> es;\n std::vector<Edge> g;\n\
    \ std::vector<int> P, PP, D, I, L, R, pos;\n std::vector<C> DW, W;\npublic:\n\
    \ Tree(int n): P(n, -2) {}\n template <class T= Cost> std::enable_if_t<std::is_void_v<T>,\
    \ void> add_edge(int u, int v) { es.emplace_back(u, v), es.emplace_back(v, u);\
    \ }\n template <class T> std::enable_if_t<std::is_convertible_v<T, Cost>, void>\
    \ add_edge(int u, int v, T c) { es.emplace_back(u, v, c), es.emplace_back(v, u,\
    \ c); }\n template <class T, class U, std::enable_if_t<std::conjunction_v<std::is_convertible<T,\
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
    \ size_t size() const { return P.size(); }\n ConstListRange<Edge> operator[](int\
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
    \  return up.insert(up.end(), down.rbegin(), down.rend()), up;\n }\n};\n"
  code: "#pragma once\n#include <type_traits>\n#include <cstddef>\n#include <algorithm>\n\
    #include <array>\n#include <tuple>\n#include <numeric>\n#include <cassert>\n#include\
    \ \"src/Internal/ListRange.hpp\"\ntemplate <class Cost= void, bool weight= false>\
    \ class Tree {\n template <class D, class T> struct Edge_B {\n  int to;\n  T cost;\n\
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
    \ size_t size() const { return P.size(); }\n ConstListRange<Edge> operator[](int\
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
    \  return up.insert(up.end(), down.rbegin(), down.rend()), up;\n }\n};"
  dependsOn:
  - src/Internal/ListRange.hpp
  isVerificationFile: false
  path: src/old/Tree.hpp
  requiredBy: []
  timestamp: '2024-02-19 22:51:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/old/Tree.hpp
layout: document
title: "\u6728"
---
HL分解＋オイラーツアーで頂点集合を数列に \
非連結(森)でも動くはず

## テンプレート `Tree<Cost=void, weight=false>`

`Cost`: 辺に乗せる情報の型. デフォルト (void) の時は何も乗らない. \
`weight`: true なら重みつき (型 は `Cost`) 辺の距離等を扱える (この場合`Cost`は int などの +, - が定義された型でないといけない). デフォルトは false. 

## メンバ関数
**※`add_edge` (とコンストラクタと`build`) 以外の関数は `build` 関数が実行済みであることを前提とする**

| 名前                                             | 概要                                                                                                              | 備考                          |
| ------------------------------------------------ | ----------------------------------------------------------------------------------------------------------------- | ----------------------------- |
| `Tree(n)`                                        | コンストラクタ. 頂点数 n を渡す                                                                                   |                               |
| `add_edge(u,v)`                                  | 無向辺 (u, v) を追加                                                                                              | 重みなし(Cost=void)の場合のみ |
| 1. `add_edge(u,v,c) `<br> 2. `add_edge(u,v,c,d)` | 1.  無向辺 (u, v) を重み c で追加 <br> 2.  有向辺 (u, v) を重み c で、 有向辺 (v, u) を重み d で追加              | 重みあり(Cost≠void)の場合のみ |
| `build(root=0)`                                  | 頂点 root を根としてHL分解を実行. 辺をセットし終えたらとにかく最初に実行.                                         |                               |
| `size()`                                         | 頂点数を返す.                                                                                                     |                               |
| `operator[](v)`                                  | 頂点 v から隣接する辺集合                                                                                         |                               |
| `path<edge=0>(u,v)`                              | 頂点 u から頂点 v へのパスを表す"**閉**"区間列を返す. <br> `edge`フラグが true なら lca を含めないような区間列を返す. |                               |
| `subtree(v)`                                     | 頂点 v を根とする部分木を表す"**半開**"区間を返す.                                                                      |                               |
| `depth(v)`                                       | 頂点 v の深さを返す.                                                                                               |                               |
|`depth_w(v)`|頂点 v の重みつき深さを返す.  | `weight` = true の時のみ|
| `to_seq(v)`                                      | 頂点 v がオイラーツアー列で何番目に対応するかを返す                                                               |                               |
| `to_node(i)`                                     | オイラーツアー列で i 番目が指す頂点を返す                                                                         |                               |
| `parent(v)`                                      | 頂点 v の親を返す. v が根なら -1                                                                                  |                               |
| `head(v)`                                      | HL分解における頂点 v の head を返す.  |                               |
| `root(v)`                                        | 頂点 v が属する木の根を返す                                                                                       |                               |
| `lca(u,v)`                                       | 頂点 u と 頂点 v の最小共通祖先を返す. u と v が非連結の場合は未定義.                                             |                               |  |
| `la(v,k)`                                        | 頂点 v から距離 k の祖先頂点を返す. k が頂点 v の深さより大きいと assert で落ちる.                             |                               |
| `la_w(v,w)`                                        | 頂点 v から重みつき距離 w 以内の最も祖先の頂点を返す.                           |           `weight` = true の時のみ     |
| `jump(u,v,k)`                                    | 頂点 u から 頂点 v へ向けて 長さ k 移動した先の頂点を返す.  存在しないなら -1                                     |                               |
| `jump_w(u,v,w)`                                    | 頂点 u から 頂点 v までのパスのうち u からの重みつき距離 w 以内で最も v に近い頂点を返す.        |  `weight` = true の時のみ    |
| `dist(u,v)`                                      | 頂点 u から 頂点 v までの辺の数を返す. u と v が非連結の場合は未定義.                                             |                               |
| `connected(u,v)`                                 | 頂点 u と 頂点 v が連結なら true, 非連結なら false                                                                |                               |
| `in_subtree(u,v)`                                | 頂点 u が 頂点 v を根とする部分木に属するなら true, そうでないなら false.                                         |                               |
| `subtree_size(v)`                                | 頂点 v を根とする部分木の頂点数を返す.                                                                            |                               |

使用例 \
クエリ
```c++
while(Q--){
 int t;cin>>t;
 if(t==1){
  // path query
  int u,v;cin>>u>>v;
  int ans=0;
  for(auto [a,b]: tree.path(u,v)) ans += a<b? seg1.fold(a,b+1) : seg2.fold(b,a+1);
  cout<<ans<<'\n';
 }else if(t==2){
  // subtree query
  int v;cin>>v;
  auto [l,r] = tree.subtree(v);
  cout << seg3.fold(l,r)<<'\n';
 }
}
```