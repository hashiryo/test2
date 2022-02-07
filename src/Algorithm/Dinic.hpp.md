---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1615.Dinic.test.cpp
    title: test/aoj/1615.Dinic.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2313.Dinic.test.cpp
    title: test/aoj/2313.Dinic.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2803.Dinic.test.cpp
    title: test/aoj/2803.Dinic.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2835.Dinic.test.cpp
    title: test/aoj/2835.Dinic.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_6_A.Dinic.test.cpp
    title: test/aoj/GRL_6_A.Dinic.test.cpp
  - icon: ':x:'
    path: test/atcoder/arc085_c.Dinic.test.cpp
    title: test/atcoder/arc085_c.Dinic.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/arc107_f.Dinic.test.cpp
    title: test/atcoder/arc107_f.Dinic.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/arc129_e.Dinic.test.cpp
    title: test/atcoder/arc129_e.Dinic.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/119.Dinic.test.cpp
    title: test/yukicoder/119.Dinic.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: Dinic
    links:
    - https://misawa.github.io/others/flow/dinic_time_complexity.html
  bundledCode: "#line 2 \"src/Algorithm/Dinic.hpp\"\n#include <bits/stdc++.h>\n/**\n\
    \ * @title Dinic\n * @category \u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\n *  O(n^2\
    \ m)\n * @see https://misawa.github.io/others/flow/dinic_time_complexity.html\n\
    \ */\n\n// BEGIN CUT HERE\n\ntemplate <class flow_t>\nstruct Dinic {\n  Dinic(std::size_t\
    \ _n = 0) : n(_n), m(0), adj(n) {}\n\n protected:\n  struct Edge {\n    int dst,\
    \ rev;\n    flow_t cap;\n  };\n  int n, m;\n  std::vector<std::vector<Edge>> adj;\n\
    \  std::vector<int> level, iter;\n  inline void levelize(const int &s, const int\
    \ &t) {\n    level.assign(n, -1), level[s] = 0;\n    std::queue<int> que;\n  \
    \  for (que.push(s); !que.empty();) {\n      int u = que.front();\n      que.pop();\n\
    \      for (auto &e : adj[u])\n        if (e.cap > 0 && level[e.dst] < 0) {\n\
    \          level[e.dst] = level[u] + 1;\n          if (e.dst == t) return;\n \
    \         que.push(e.dst);\n        }\n    }\n  }\n  inline flow_t dfs(int u,\
    \ const int &s, flow_t cur) {\n    if (u == s) return cur;\n    flow_t ret = 0;\n\
    \    for (int &i = iter[u]; i < int(adj[u].size()); i++) {\n      Edge &e = adj[u][i],\
    \ &re = adj[e.dst][e.rev];\n      if (level[u] <= level[e.dst] || re.cap == 0)\
    \ continue;\n      flow_t f = dfs(e.dst, s, std::min(cur - ret, re.cap));\n  \
    \    if (f <= 0) continue;\n      e.cap += f, re.cap -= f, ret += f;\n      if\
    \ (ret == cur) return ret;\n    }\n    return level[u] = n, ret;\n  }\n  flow_t\
    \ flow(int s, int t, flow_t flow_lim) {\n    assert(0 <= s && s < n);\n    assert(0\
    \ <= t && t < n);\n    assert(s != t);\n    flow_t ret = 0;\n    for (flow_t f;\
    \ ret < flow_lim; ret += f) {\n      if (levelize(s, t), level[t] == -1) break;\n\
    \      iter.assign(n, 0);\n      if (!(f = dfs(t, s, flow_lim - ret))) break;\n\
    \    }\n    return ret;\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title Dinic\n * @category\
    \ \u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\n *  O(n^2 m)\n * @see https://misawa.github.io/others/flow/dinic_time_complexity.html\n\
    \ */\n\n// BEGIN CUT HERE\n\ntemplate <class flow_t>\nstruct Dinic {\n  Dinic(std::size_t\
    \ _n = 0) : n(_n), m(0), adj(n) {}\n\n protected:\n  struct Edge {\n    int dst,\
    \ rev;\n    flow_t cap;\n  };\n  int n, m;\n  std::vector<std::vector<Edge>> adj;\n\
    \  std::vector<int> level, iter;\n  inline void levelize(const int &s, const int\
    \ &t) {\n    level.assign(n, -1), level[s] = 0;\n    std::queue<int> que;\n  \
    \  for (que.push(s); !que.empty();) {\n      int u = que.front();\n      que.pop();\n\
    \      for (auto &e : adj[u])\n        if (e.cap > 0 && level[e.dst] < 0) {\n\
    \          level[e.dst] = level[u] + 1;\n          if (e.dst == t) return;\n \
    \         que.push(e.dst);\n        }\n    }\n  }\n  inline flow_t dfs(int u,\
    \ const int &s, flow_t cur) {\n    if (u == s) return cur;\n    flow_t ret = 0;\n\
    \    for (int &i = iter[u]; i < int(adj[u].size()); i++) {\n      Edge &e = adj[u][i],\
    \ &re = adj[e.dst][e.rev];\n      if (level[u] <= level[e.dst] || re.cap == 0)\
    \ continue;\n      flow_t f = dfs(e.dst, s, std::min(cur - ret, re.cap));\n  \
    \    if (f <= 0) continue;\n      e.cap += f, re.cap -= f, ret += f;\n      if\
    \ (ret == cur) return ret;\n    }\n    return level[u] = n, ret;\n  }\n  flow_t\
    \ flow(int s, int t, flow_t flow_lim) {\n    assert(0 <= s && s < n);\n    assert(0\
    \ <= t && t < n);\n    assert(s != t);\n    flow_t ret = 0;\n    for (flow_t f;\
    \ ret < flow_lim; ret += f) {\n      if (levelize(s, t), level[t] == -1) break;\n\
    \      iter.assign(n, 0);\n      if (!(f = dfs(t, s, flow_lim - ret))) break;\n\
    \    }\n    return ret;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Algorithm/Dinic.hpp
  requiredBy: []
  timestamp: '2021-12-16 12:41:45+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/atcoder/arc085_c.Dinic.test.cpp
  - test/atcoder/arc129_e.Dinic.test.cpp
  - test/atcoder/arc107_f.Dinic.test.cpp
  - test/aoj/GRL_6_A.Dinic.test.cpp
  - test/aoj/2835.Dinic.test.cpp
  - test/aoj/2803.Dinic.test.cpp
  - test/aoj/1615.Dinic.test.cpp
  - test/aoj/2313.Dinic.test.cpp
  - test/yukicoder/119.Dinic.test.cpp
documentation_of: src/Algorithm/Dinic.hpp
layout: document
redirect_from:
- /library/src/Algorithm/Dinic.hpp
- /library/src/Algorithm/Dinic.hpp.html
title: Dinic
---