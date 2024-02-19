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
  bundledCode: "#line 2 \"src/old/BipartiteGraph.hpp\"\n#include <array>\n#include\
    \ <algorithm>\n#include <numeric>\n#include <cassert>\n#line 2 \"src/Internal/ListRange.hpp\"\
    \n#include <vector>\n#include <iostream>\n#include <iterator>\n#include <type_traits>\n\
    #define _LR(name, IT, CT) \\\n template <class T> struct name { \\\n  using Iterator=\
    \ typename std::vector<T>::IT; \\\n  Iterator bg, ed; \\\n  Iterator begin() const\
    \ { return bg; } \\\n  Iterator end() const { return ed; } \\\n  size_t size()\
    \ const { return std::distance(bg, ed); } \\\n  CT &operator[](int i) const {\
    \ return bg[i]; } \\\n }\n_LR(ListRange, iterator, T);\n_LR(ConstListRange, const_iterator,\
    \ const T);\n#undef _LR\ntemplate <class T> struct CSRArray {\n std::vector<T>\
    \ dat;\n std::vector<int> p;\n size_t size() const { return p.size() - 1; }\n\
    \ ListRange<T> operator[](int i) { return {dat.begin() + p[i], dat.begin() + p[i\
    \ + 1]}; }\n ConstListRange<T> operator[](int i) const { return {dat.cbegin()\
    \ + p[i], dat.cbegin() + p[i + 1]}; }\n};\ntemplate <template <class> class F,\
    \ class T> std::enable_if_t<std::disjunction_v<std::is_same<F<T>, ListRange<T>>,\
    \ std::is_same<F<T>, ConstListRange<T>>, std::is_same<F<T>, CSRArray<T>>>, std::ostream\
    \ &> operator<<(std::ostream &os, const F<T> &r) {\n os << '[';\n for (int _=\
    \ 0, __= r.size(); _ < __; ++_) os << (_ ? \", \" : \"\") << r[_];\n return os\
    \ << ']';\n}\n#line 7 \"src/old/BipartiteGraph.hpp\"\nclass BipartiteGraph {\n\
    \ std::vector<std::array<int, 2>> es;\n std::vector<int> col, pos, ord, pre, mate,\
    \ blg;\n CSRArray<int> dag_[2];\n int l;\npublic:\n BipartiteGraph(int n): col(n,\
    \ -1), pos(n + 1), ord(n), mate(n, -1), blg(n, -3), l(0) {}\n void add_edge(int\
    \ u, int v) { es.push_back({u, v}); }\n void build() {\n  const int n= col.size();\n\
    \  std::vector<int> rt, que(n), g(es.size() * 2);\n  for (auto [u, v]: es) ++pos[u],\
    \ ++pos[v];\n  for (int i= 0; i < n; ++i) pos[i + 1]+= pos[i];\n  for (auto [u,\
    \ v]: es) g[--pos[u]]= v, g[--pos[v]]= u;\n  for (int s= n, i= 0, t= 0, r= n;\
    \ s--;)\n   if (col[s] == -1)\n    for (col[s]= 0, ord[l++]= que[t++]= s; i <\
    \ t; ++i)\n     for (int v= que[i], c= col[v], j= pos[v], u; j < pos[v + 1]; ++j)\n\
    \      if (assert(col[u= g[j]] != c); col[u] == -1) col[u]= !c, ord[(c ? l++ :\
    \ --r)]= que[t++]= u;\n  int t= 0, k= 0;\n  for (bool upd= true; upd; t= 0) {\n\
    \   upd= false, rt.assign(n, -1), pre.assign(n, -1);\n   for (int i= l; i--;)\n\
    \    if (int v= ord[i]; mate[v] == -1) que[t++]= rt[v]= pre[v]= v;\n   for (int\
    \ i= 0; i < t; ++i)\n    if (int v= que[i]; mate[rt[v]] == -1)\n     for (int\
    \ j= pos[v], u, w; j < pos[v + 1]; ++j) {\n      if (w= mate[u= g[j]]; w == -1)\
    \ {\n       for (upd= true; u != -1; v= pre[v]) mate[u]= v, std::swap(mate[v],\
    \ u);\n       break;\n      }\n      if (pre[w] == -1) rt[que[t++]= w]= rt[pre[w]=\
    \ v];\n     }\n  }\n  for (int i= l; i--;)\n   if (int s= ord[i]; rt[s] != -1)\n\
    \    if (blg[s]= -1, s= mate[s]; s != -1) blg[s]= -1;\n  for (int i= l; i < n;\
    \ ++i)\n   if (int s= ord[i]; mate[s] == -1) blg[que[t++]= s]= 0;\n  for (int\
    \ i= 0; i < t; ++i)\n   for (int v= que[i], j= pos[v], u, w; j < pos[v + 1]; ++j)\n\
    \    if (blg[u= g[j]] == -3)\n     if (w= mate[u], blg[u]= 0; w != -1 && blg[w]\
    \ == -3) blg[que[t++]= w]= 0;\n  pre.assign(pos.begin(), pos.begin() + n), t=\
    \ 0;\n  for (int i= l; i--;)\n   if (int v= ord[i]; blg[v] == -3)\n    for (blg[v]=\
    \ -4; v >= 0;) {\n     if (pre[v] == pos[v + 1]) rt[t++]= v, v= blg[v];\n    \
    \ else if (int w= mate[g[pre[v]++]]; blg[w] == -3) blg[w]= v, v= w;\n    }\n \
    \ for (int i= 0, e= 0; t--;)\n   if (int s= rt[t], p= mate[s]; blg[p] == -3)\n\
    \    for (que[e++]= p, blg[s]= blg[p]= ++k; i < e; ++i)\n     for (int v= que[i],\
    \ j= pos[v]; j < pos[v + 1]; ++j)\n      if (int u= g[j], w= mate[u]; blg[w] ==\
    \ -3) que[e++]= w, blg[u]= blg[w]= k;\n  pos.assign(++k + 2, 0);\n  for (int v=\
    \ n; v--; ++pos[blg[v]])\n   if (blg[v] == -1) blg[v]= k;\n  for (int i= 0; i\
    \ <= k; ++i) pos[i + 1]+= pos[i];\n  for (int v= n; v--;) pre[--pos[blg[v]]]=\
    \ v;\n  std::vector<std::array<int, 2>> es_;\n  for (auto &[u, v]: es) {\n   if\
    \ (col[u]) std::swap(u, v);\n   if (int a= blg[u], b= blg[v]; a != b) es_.push_back({a,\
    \ b});\n  }\n  std::sort(es_.begin(), es_.end()), es_.erase(std::unique(es_.begin(),\
    \ es_.end()), es_.end());\n  std::vector<int> dg0(es_.size()), dg1(es_.size()),\
    \ sp0(k + 2), sp1(k + 2);\n  for (auto [u, v]: es_) ++sp0[u], ++sp1[v];\n  std::partial_sum(sp0.begin(),\
    \ sp0.end(), sp0.begin()), std::partial_sum(sp1.begin(), sp1.end(), sp1.begin());\n\
    \  for (auto [u, v]: es_) dg0[--sp0[u]]= v, dg1[--sp1[v]]= u;\n  dag_[0]= {dg0,\
    \ sp0}, dag_[1]= {dg1, sp1};\n }\n const std::vector<std::array<int, 2>> &edges()\
    \ const { return es; }\n bool color(int v) const { return col[v]; }\n ConstListRange<int>\
    \ left_vertices() const { return {ord.cbegin(), ord.cbegin() + l}; }\n ConstListRange<int>\
    \ right_vertices() const { return {ord.cbegin() + l, ord.cend()}; }\n int match(int\
    \ v) const { return mate[v]; }\n int component_num() const { return pos.size()\
    \ - 1; }\n int belong(int v) const { return blg[v]; }\n ConstListRange<int> block(int\
    \ k) const { return {pre.cbegin() + pos[k], pre.cbegin() + pos[k + 1]}; }\n template\
    \ <bool rev> const CSRArray<int> &dag() { return dag_[rev]; }\n std::vector<std::array<int,\
    \ 2>> max_matching() const {\n  std::vector<std::array<int, 2>> ret;\n  for (int\
    \ i= l; i--;)\n   if (int v= ord[i], u= mate[v]; u != -1) ret.push_back({v, u});\n\
    \  return ret;\n }\n std::vector<int> min_vertex_cover() const {\n  const int\
    \ n= col.size(), m= component_num();\n  std::vector<int> sel(m, -1), ret, que(m);\n\
    \  sel[0]= 1, sel.back()= 0;\n  for (int v= 0, k, s, c, i, t; v < n; ++v) {\n\
    \   if (c= col[v], s= sel[k= blg[v]]; s == -1)\n    for (sel[que[0]= k]= s= !c,\
    \ i= 0, t= 1; i < t; ++i)\n     for (int u: dag_[s][que[i]])\n      if (sel[u]\
    \ == -1) sel[u]= s, que[t++]= u;\n   if (c ^ s) ret.push_back(v);\n  }\n  return\
    \ ret;\n }\n std::vector<int> max_independent_set() const {\n  const int n= col.size(),\
    \ m= component_num();\n  std::vector<int> sel(m, -1), ret, que(m);\n  sel[0]=\
    \ 0, sel.back()= 1;\n  for (int v= 0, k, s, c, i, t; v < n; ++v) {\n   if (c=\
    \ col[v], s= sel[k= blg[v]]; s == -1)\n    for (sel[que[0]= k]= s= !c, i= 0, t=\
    \ 1; i < t; ++i)\n     for (int u: dag_[c][que[i]])\n      if (sel[u] == -1) sel[u]=\
    \ s, que[t++]= u;\n   if (c ^ s) ret.push_back(v);\n  }\n  return ret;\n }\n};\n"
  code: "#pragma once\n#include <array>\n#include <algorithm>\n#include <numeric>\n\
    #include <cassert>\n#include \"src/Internal/ListRange.hpp\"\nclass BipartiteGraph\
    \ {\n std::vector<std::array<int, 2>> es;\n std::vector<int> col, pos, ord, pre,\
    \ mate, blg;\n CSRArray<int> dag_[2];\n int l;\npublic:\n BipartiteGraph(int n):\
    \ col(n, -1), pos(n + 1), ord(n), mate(n, -1), blg(n, -3), l(0) {}\n void add_edge(int\
    \ u, int v) { es.push_back({u, v}); }\n void build() {\n  const int n= col.size();\n\
    \  std::vector<int> rt, que(n), g(es.size() * 2);\n  for (auto [u, v]: es) ++pos[u],\
    \ ++pos[v];\n  for (int i= 0; i < n; ++i) pos[i + 1]+= pos[i];\n  for (auto [u,\
    \ v]: es) g[--pos[u]]= v, g[--pos[v]]= u;\n  for (int s= n, i= 0, t= 0, r= n;\
    \ s--;)\n   if (col[s] == -1)\n    for (col[s]= 0, ord[l++]= que[t++]= s; i <\
    \ t; ++i)\n     for (int v= que[i], c= col[v], j= pos[v], u; j < pos[v + 1]; ++j)\n\
    \      if (assert(col[u= g[j]] != c); col[u] == -1) col[u]= !c, ord[(c ? l++ :\
    \ --r)]= que[t++]= u;\n  int t= 0, k= 0;\n  for (bool upd= true; upd; t= 0) {\n\
    \   upd= false, rt.assign(n, -1), pre.assign(n, -1);\n   for (int i= l; i--;)\n\
    \    if (int v= ord[i]; mate[v] == -1) que[t++]= rt[v]= pre[v]= v;\n   for (int\
    \ i= 0; i < t; ++i)\n    if (int v= que[i]; mate[rt[v]] == -1)\n     for (int\
    \ j= pos[v], u, w; j < pos[v + 1]; ++j) {\n      if (w= mate[u= g[j]]; w == -1)\
    \ {\n       for (upd= true; u != -1; v= pre[v]) mate[u]= v, std::swap(mate[v],\
    \ u);\n       break;\n      }\n      if (pre[w] == -1) rt[que[t++]= w]= rt[pre[w]=\
    \ v];\n     }\n  }\n  for (int i= l; i--;)\n   if (int s= ord[i]; rt[s] != -1)\n\
    \    if (blg[s]= -1, s= mate[s]; s != -1) blg[s]= -1;\n  for (int i= l; i < n;\
    \ ++i)\n   if (int s= ord[i]; mate[s] == -1) blg[que[t++]= s]= 0;\n  for (int\
    \ i= 0; i < t; ++i)\n   for (int v= que[i], j= pos[v], u, w; j < pos[v + 1]; ++j)\n\
    \    if (blg[u= g[j]] == -3)\n     if (w= mate[u], blg[u]= 0; w != -1 && blg[w]\
    \ == -3) blg[que[t++]= w]= 0;\n  pre.assign(pos.begin(), pos.begin() + n), t=\
    \ 0;\n  for (int i= l; i--;)\n   if (int v= ord[i]; blg[v] == -3)\n    for (blg[v]=\
    \ -4; v >= 0;) {\n     if (pre[v] == pos[v + 1]) rt[t++]= v, v= blg[v];\n    \
    \ else if (int w= mate[g[pre[v]++]]; blg[w] == -3) blg[w]= v, v= w;\n    }\n \
    \ for (int i= 0, e= 0; t--;)\n   if (int s= rt[t], p= mate[s]; blg[p] == -3)\n\
    \    for (que[e++]= p, blg[s]= blg[p]= ++k; i < e; ++i)\n     for (int v= que[i],\
    \ j= pos[v]; j < pos[v + 1]; ++j)\n      if (int u= g[j], w= mate[u]; blg[w] ==\
    \ -3) que[e++]= w, blg[u]= blg[w]= k;\n  pos.assign(++k + 2, 0);\n  for (int v=\
    \ n; v--; ++pos[blg[v]])\n   if (blg[v] == -1) blg[v]= k;\n  for (int i= 0; i\
    \ <= k; ++i) pos[i + 1]+= pos[i];\n  for (int v= n; v--;) pre[--pos[blg[v]]]=\
    \ v;\n  std::vector<std::array<int, 2>> es_;\n  for (auto &[u, v]: es) {\n   if\
    \ (col[u]) std::swap(u, v);\n   if (int a= blg[u], b= blg[v]; a != b) es_.push_back({a,\
    \ b});\n  }\n  std::sort(es_.begin(), es_.end()), es_.erase(std::unique(es_.begin(),\
    \ es_.end()), es_.end());\n  std::vector<int> dg0(es_.size()), dg1(es_.size()),\
    \ sp0(k + 2), sp1(k + 2);\n  for (auto [u, v]: es_) ++sp0[u], ++sp1[v];\n  std::partial_sum(sp0.begin(),\
    \ sp0.end(), sp0.begin()), std::partial_sum(sp1.begin(), sp1.end(), sp1.begin());\n\
    \  for (auto [u, v]: es_) dg0[--sp0[u]]= v, dg1[--sp1[v]]= u;\n  dag_[0]= {dg0,\
    \ sp0}, dag_[1]= {dg1, sp1};\n }\n const std::vector<std::array<int, 2>> &edges()\
    \ const { return es; }\n bool color(int v) const { return col[v]; }\n ConstListRange<int>\
    \ left_vertices() const { return {ord.cbegin(), ord.cbegin() + l}; }\n ConstListRange<int>\
    \ right_vertices() const { return {ord.cbegin() + l, ord.cend()}; }\n int match(int\
    \ v) const { return mate[v]; }\n int component_num() const { return pos.size()\
    \ - 1; }\n int belong(int v) const { return blg[v]; }\n ConstListRange<int> block(int\
    \ k) const { return {pre.cbegin() + pos[k], pre.cbegin() + pos[k + 1]}; }\n template\
    \ <bool rev> const CSRArray<int> &dag() { return dag_[rev]; }\n std::vector<std::array<int,\
    \ 2>> max_matching() const {\n  std::vector<std::array<int, 2>> ret;\n  for (int\
    \ i= l; i--;)\n   if (int v= ord[i], u= mate[v]; u != -1) ret.push_back({v, u});\n\
    \  return ret;\n }\n std::vector<int> min_vertex_cover() const {\n  const int\
    \ n= col.size(), m= component_num();\n  std::vector<int> sel(m, -1), ret, que(m);\n\
    \  sel[0]= 1, sel.back()= 0;\n  for (int v= 0, k, s, c, i, t; v < n; ++v) {\n\
    \   if (c= col[v], s= sel[k= blg[v]]; s == -1)\n    for (sel[que[0]= k]= s= !c,\
    \ i= 0, t= 1; i < t; ++i)\n     for (int u: dag_[s][que[i]])\n      if (sel[u]\
    \ == -1) sel[u]= s, que[t++]= u;\n   if (c ^ s) ret.push_back(v);\n  }\n  return\
    \ ret;\n }\n std::vector<int> max_independent_set() const {\n  const int n= col.size(),\
    \ m= component_num();\n  std::vector<int> sel(m, -1), ret, que(m);\n  sel[0]=\
    \ 0, sel.back()= 1;\n  for (int v= 0, k, s, c, i, t; v < n; ++v) {\n   if (c=\
    \ col[v], s= sel[k= blg[v]]; s == -1)\n    for (sel[que[0]= k]= s= !c, i= 0, t=\
    \ 1; i < t; ++i)\n     for (int u: dag_[c][que[i]])\n      if (sel[u] == -1) sel[u]=\
    \ s, que[t++]= u;\n   if (c ^ s) ret.push_back(v);\n  }\n  return ret;\n }\n};"
  dependsOn:
  - src/Internal/ListRange.hpp
  isVerificationFile: false
  path: src/old/BipartiteGraph.hpp
  requiredBy: []
  timestamp: '2024-02-19 22:51:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/old/BipartiteGraph.hpp
layout: document
title: "(\u6697\u9ED9\u7684\u306A)\u4E8C\u90E8\u30B0\u30E9\u30D5"
---
明示的に二部グラフを与えない \
内部で頂点の色分けを自動で行う \
色0が左、色1が右を意味する

## メンバ関数

| 関数名                  | 内容                                                                              | 計算量                              |
| ----------------------- | --------------------------------------------------------------------------------- | ----------------------------------- |
| `BipartiteGraph(N)`     | コンストラクタ. 二部グラフの頂点数 N を渡す                                       |                                     |
| `add_edge(u,v)`         | 無向辺 (u,v) を追加                                                               |                                     |
| `build()`               | 頂点の色分け、マッチング、DM分解を実行                                            | $\mathcal{O}\left(E\sqrt{V}\right)$ |
| `color(v)`              | 頂点 v の色 ( 0 or 1 ) を返す                                                     |                                     |
| `component_num()`       | DM分解で分割された集合の個数(K+1)を返す                                           |                                     |
| `belong(v)`             | 頂点 v の所属先 ( DM分解で分割された集合 ) を返す                                 |                                     |
| `block(k)`              | DM分解で分割された集合の k 番目のものを返す                                       |                                     |
| `match(v)`              | (最大マッチングの一つを固定して) 頂点 v のマッチング相手を返す. 存在しないなら -1 |                                     |
| `max_matching()`        | (最大マッチングの一つを固定して) マッチングに使う辺を返す                         |                                     |
| `min_vertex_cover()`    | 最小頂点被覆を返す. 辞書順最小のものを返す                                        |                                     |
| `max_independent_set()` | 最大独立集合を返す. 辞書順最小のものを返す(はず)                                  |                                     |


## 問題例
[Chokudai SpeedRun 002 K - 種類数 β](https://atcoder.jp/contests/chokudai_S002/tasks/chokudai_S002_k) (頂点:2e5+4e5, 辺:4e5) \
[東京大学プログラミングコンテスト2013 K - 辞書順最小頂点被覆](https://atcoder.jp/contests/utpc2013/tasks/utpc2013_11) (辞書順最小頂点被覆のverify)