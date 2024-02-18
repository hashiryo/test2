---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Graph/Graph.hpp
    title: "\u30B0\u30E9\u30D5"
  - icon: ':question:'
    path: src/Internal/ListRange.hpp
    title: "CSR \u8868\u73FE\u3092\u7528\u3044\u305F\u4E8C\u6B21\u5143\u914D\u5217\
      \ \u4ED6"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/3032.test.cpp
    title: test/aoj/3032.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3198.general_matching.test.cpp
    title: test/aoj/3198.general_matching.test.cpp
  - icon: ':x:'
    path: test/yosupo/bipartitematching.general_matching.test.cpp
    title: test/yosupo/bipartitematching.general_matching.test.cpp
  - icon: ':x:'
    path: test/yosupo/general_matching.test.cpp
    title: test/yosupo/general_matching.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Graph/general_matching.hpp\"\n#include <cassert>\n#line\
    \ 2 \"src/Internal/ListRange.hpp\"\n#include <vector>\n#include <iostream>\n#include\
    \ <iterator>\n#include <type_traits>\n#define _LR(name, IT, CT) \\\n template\
    \ <class T> struct name { \\\n  using Iterator= typename std::vector<T>::IT; \\\
    \n  Iterator bg, ed; \\\n  Iterator begin() const { return bg; } \\\n  Iterator\
    \ end() const { return ed; } \\\n  size_t size() const { return std::distance(bg,\
    \ ed); } \\\n  CT &operator[](int i) const { return bg[i]; } \\\n }\n_LR(ListRange,\
    \ iterator, const T);\n_LR(ConstListRange, const_iterator, const T);\n#undef _LR\n\
    template <class T> struct CSRArray {\n std::vector<T> dat;\n std::vector<int>\
    \ p;\n size_t size() const { return p.size() - 1; }\n ListRange<T> operator[](int\
    \ i) { return {dat.begin() + p[i], dat.begin() + p[i + 1]}; }\n ConstListRange<T>\
    \ operator[](int i) const { return {dat.cbegin() + p[i], dat.cbegin() + p[i +\
    \ 1]}; }\n};\ntemplate <template <class> class F, class T> std::enable_if_t<std::disjunction_v<std::is_same<F<T>,\
    \ ListRange<T>>, std::is_same<F<T>, ConstListRange<T>>, std::is_same<F<T>, CSRArray<T>>>,\
    \ std::ostream &> operator<<(std::ostream &os, const F<T> &r) {\n os << '[';\n\
    \ for (int _= 0, __= r.size(); _ < __; ++_) os << (_ ? \", \" : \"\") << r[_];\n\
    \ return os << ']';\n}\n#line 3 \"src/Graph/Graph.hpp\"\nstruct Edge: std::pair<int,\
    \ int> {\n using std::pair<int, int>::pair;\n Edge &operator--() { return --first,\
    \ --second, *this; }\n int to(int v) const { return first ^ second ^ v; }\n friend\
    \ std::istream &operator>>(std::istream &is, Edge &e) { return is >> e.first >>\
    \ e.second, is; }\n};\nstruct Graph: std::vector<Edge> {\n size_t n;\n Graph(size_t\
    \ n= 0, size_t m= 0): vector(m), n(n) {}\n size_t vertex_size() const { return\
    \ n; }\n size_t edge_size() const { return size(); }\n size_t add_vertex() { return\
    \ n++; }\n size_t add_edge(int s, int d) { return emplace_back(s, d), size() -\
    \ 1; }\n size_t add_edge(Edge e) { return emplace_back(e), size() - 1; }\n#define\
    \ _ADJ_FOR(a, b) \\\n for (auto [u, v]: *this) a; \\\n for (int i= 0; i < n; ++i)\
    \ p[i + 1]+= p[i]; \\\n for (int i= size(); i--;) { \\\n  auto [u, v]= (*this)[i];\
    \ \\\n  b; \\\n }\n#define _ADJ(a, b) \\\n vector<int> p(n + 1), c(size() << !dir);\
    \ \\\n if (!dir) { \\\n  _ADJ_FOR((++p[u], ++p[v]), (c[--p[u]]= a, c[--p[v]]=\
    \ b)) \\\n } else if (dir > 0) { \\\n  _ADJ_FOR(++p[u], c[--p[u]]= a) \\\n } else\
    \ { \\\n  _ADJ_FOR(++p[v], c[--p[v]]= b) \\\n } \\\n return {c, p}\n CSRArray<int>\
    \ adjacency_vertex(int dir) const { _ADJ(v, u); }\n CSRArray<int> adjacency_edge(int\
    \ dir) const { _ADJ(i, i); }\n#undef _ADJ\n#undef _ADJ_FOR\n};\n#line 4 \"src/Graph/general_matching.hpp\"\
    \n// {matching, partner(-1 if unmatched)}\nstd::pair<std::vector<int>, std::vector<int>>\
    \ general_matching(const Graph &g, const std::vector<int> &partner= {}) {\n auto\
    \ adj= g.adjacency_vertex(0);\n const int n= adj.size();\n std::vector<int> q(n),\
    \ id(n, -1), p(n), m(partner);\n if (m.empty()) m.assign(n, -1);\n assert((int)m.size()\
    \ == n);\n std::vector<Edge> fs(n);\n auto rematch= [&](auto self, int u, int\
    \ v) -> void {\n  int w;\n  if (w= m[u], m[u]= v; w == -1 || m[w] != u) return;\n\
    \  if (auto [x, y]= fs[u]; y == -1) self(self, m[w]= x, w);\n  else self(self,\
    \ x, y), self(self, y, x);\n };\n int t= 0;\n auto f= [&](auto self, int x) ->\
    \ int { return id[x] != t || p[x] == -1 ? x : (p[x]= self(self, p[x])); };\n auto\
    \ check= [&](int rt) {\n  fs[rt]= {-1, -1}, id[rt]= t, p[q[0]= rt]= -1;\n  for\
    \ (int i= 0, s= 1; i < s; ++i) {\n   int x= q[i];\n   for (int y: adj[x]) {\n\
    \    if (y == rt) continue;\n    if (m[y] == -1) return rematch(rematch, m[y]=\
    \ x, y), true;\n    if (id[y] == t) {\n     int u= f(f, x), v= f(f, y), w= rt;\n\
    \     if (u == v) continue;\n     for (; u != rt || v != rt; fs[u]= {x, y}, u=\
    \ f(f, fs[m[u]].first)) {\n      if (v != rt) std::swap(u, v);\n      if (fs[u].first\
    \ == x && fs[u].second == y) {\n       w= u;\n       break;\n      }\n     }\n\
    \     for (int a= u; a != w; a= f(f, fs[m[a]].first)) id[a]= t, p[a]= w, q[s++]=\
    \ a;\n     for (int b= v; b != w; b= f(f, fs[m[b]].first)) id[b]= t, p[b]= w,\
    \ q[s++]= b;\n    } else if (id[m[y]] != t) fs[y]= {-1, -1}, fs[m[y]]= {x, -1},\
    \ id[m[y]]= t, p[m[y]]= y, q[s++]= m[y];\n   }\n  }\n  return false;\n };\n for\
    \ (int rt= n; rt--;)\n  if (m[rt] == -1) t+= check(rt);\n p.clear();\n for (int\
    \ i= 0, e= g.edge_size(); i < e; ++i)\n  if (auto [u, v]= g[i]; m[u] == v && q[u]\
    \ >= 0) p.push_back(i), q[u]= q[v]= -1;\n return {p, m};\n}\n"
  code: "#pragma once\n#include <cassert>\n#include \"src/Graph/Graph.hpp\"\n// {matching,\
    \ partner(-1 if unmatched)}\nstd::pair<std::vector<int>, std::vector<int>> general_matching(const\
    \ Graph &g, const std::vector<int> &partner= {}) {\n auto adj= g.adjacency_vertex(0);\n\
    \ const int n= adj.size();\n std::vector<int> q(n), id(n, -1), p(n), m(partner);\n\
    \ if (m.empty()) m.assign(n, -1);\n assert((int)m.size() == n);\n std::vector<Edge>\
    \ fs(n);\n auto rematch= [&](auto self, int u, int v) -> void {\n  int w;\n  if\
    \ (w= m[u], m[u]= v; w == -1 || m[w] != u) return;\n  if (auto [x, y]= fs[u];\
    \ y == -1) self(self, m[w]= x, w);\n  else self(self, x, y), self(self, y, x);\n\
    \ };\n int t= 0;\n auto f= [&](auto self, int x) -> int { return id[x] != t ||\
    \ p[x] == -1 ? x : (p[x]= self(self, p[x])); };\n auto check= [&](int rt) {\n\
    \  fs[rt]= {-1, -1}, id[rt]= t, p[q[0]= rt]= -1;\n  for (int i= 0, s= 1; i < s;\
    \ ++i) {\n   int x= q[i];\n   for (int y: adj[x]) {\n    if (y == rt) continue;\n\
    \    if (m[y] == -1) return rematch(rematch, m[y]= x, y), true;\n    if (id[y]\
    \ == t) {\n     int u= f(f, x), v= f(f, y), w= rt;\n     if (u == v) continue;\n\
    \     for (; u != rt || v != rt; fs[u]= {x, y}, u= f(f, fs[m[u]].first)) {\n \
    \     if (v != rt) std::swap(u, v);\n      if (fs[u].first == x && fs[u].second\
    \ == y) {\n       w= u;\n       break;\n      }\n     }\n     for (int a= u; a\
    \ != w; a= f(f, fs[m[a]].first)) id[a]= t, p[a]= w, q[s++]= a;\n     for (int\
    \ b= v; b != w; b= f(f, fs[m[b]].first)) id[b]= t, p[b]= w, q[s++]= b;\n    }\
    \ else if (id[m[y]] != t) fs[y]= {-1, -1}, fs[m[y]]= {x, -1}, id[m[y]]= t, p[m[y]]=\
    \ y, q[s++]= m[y];\n   }\n  }\n  return false;\n };\n for (int rt= n; rt--;)\n\
    \  if (m[rt] == -1) t+= check(rt);\n p.clear();\n for (int i= 0, e= g.edge_size();\
    \ i < e; ++i)\n  if (auto [u, v]= g[i]; m[u] == v && q[u] >= 0) p.push_back(i),\
    \ q[u]= q[v]= -1;\n return {p, m};\n}"
  dependsOn:
  - src/Graph/Graph.hpp
  - src/Internal/ListRange.hpp
  isVerificationFile: false
  path: src/Graph/general_matching.hpp
  requiredBy: []
  timestamp: '2024-02-18 23:01:54+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/general_matching.test.cpp
  - test/yosupo/bipartitematching.general_matching.test.cpp
  - test/aoj/3198.general_matching.test.cpp
  - test/aoj/3032.test.cpp
documentation_of: src/Graph/general_matching.hpp
layout: document
title: "\u4E00\u822C\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0"
---
GabowのEdmonds' Algorithm

|関数名|概要|計算量|
|---|---|---|
|`generate_matching(Graph g, vector<int> partner = {})`| 無向グラフ g の最大マッチングの一例を返す.  <br> 引数は [`Graph`クラス](Graph.hpp). <br> 第二引数は推論補助(※)<br> 返り値は `pair` でラッピングした二つを返す．<br> 一つ目は使用する辺のidを表す `vector<int>`．<br>　二つ目は各頂点のマッチング相手が記録されている `vector<int>` (いないなら -1 )． |$O(nm \log n)$<br> ただし頂点数，辺数をそれぞれ $n,m$ とした． <br>はやい|

※ 各頂点の（最大マッチングとは限らない）マッチング相手が記録されている `vector<int>`　( 返り値の二つ目の形式と同じ ) を渡す. マッチングとして矛盾している場合の挙動は未定義．一度この関数を実行した後，（辺を一本追加あるいは削除などの）少しだけ変化させた場合の再計算を効率よくするためのもの．
## 問題例
[Chokudai SpeedRun 002 K - 種類数 β](https://atcoder.jp/contests/chokudai_S002/tasks/chokudai_S002_k) (二部マッチング, 頂点:2e5+4e5, 辺:4e5) 