---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Optimization/MatchingWeighted.hpp
    title: "\u91CD\u307F\u4ED8\u304D\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0(\u4E00\
      \u822C\u30B0\u30E9\u30D5)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/general_weighted_matching
    links:
    - https://judge.yosupo.jp/problem/general_weighted_matching
  bundledCode: "#line 1 \"test/yosupo/general_weighted_matching.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/general_weighted_matching\"\n#include\
    \ <bits/stdc++.h>\n#line 3 \"src/Optimization/MatchingWeighted.hpp\"\ntemplate\
    \ <class cost_t= long long> class MatchingWeighted {\n static constexpr cost_t\
    \ INF= std::numeric_limits<cost_t>::max() / 2;\n struct E {\n  int u, v;\n  cost_t\
    \ w;\n };\n int n, m, in;\n std::vector<std::vector<E>> G;\n std::vector<int>\
    \ mt, slk, rt, par, isS, used;\n std::vector<std::vector<int>> fwr, blg;\n std::vector<cost_t>\
    \ dual;\n std::queue<int> que;\n inline cost_t dist(const E &e) const { return\
    \ dual[e.u] + dual[e.v] - e.w; }\n void recalc(int v, int i= 1) {\n  for (slk[v]=\
    \ 0; i <= n; i++)\n   if (G[i][v].w && rt[i] != v && isS[rt[i]] == 1)\n    if\
    \ (!slk[v] || dist(G[i][v]) < dist(G[slk[v]][v])) slk[v]= i;\n }\n void push(int\
    \ v) {\n  if (v <= n) return que.push(v);\n  for (int nxt: fwr[v]) push(nxt);\n\
    \ }\n void set(int v, int r) {\n  if (rt[v]= r; v > n)\n   for (int nxt: fwr[v])\
    \ set(nxt, r);\n }\n int findeven(int b, int v, int p= 0) {\n  if (p= std::find(fwr[b].begin(),\
    \ fwr[b].end(), v) - fwr[b].begin(); p & 1) std::reverse(fwr[b].begin() + 1, fwr[b].end()),\
    \ p= fwr[b].size() - p;\n  return p;\n }\n void match(int u, int v) {\n  if (mt[u]=\
    \ G[u][v].v; u > n) {\n   int x= blg[u][G[u][v].u], p= findeven(u, x);\n   for\
    \ (int i= 0; i < p; i++) match(fwr[u][i], fwr[u][i ^ 1]);\n   match(x, v), rotate(fwr[u].begin(),\
    \ fwr[u].begin() + p, fwr[u].end());\n  }\n }\n bool path(const E &e) {\n  if\
    \ (int u= rt[e.u], v= rt[e.v], bu= u, bv= v, x; isS[v] == 1) {\n   for (in++;\
    \ bu; bu= rt[mt[bu]] ? rt[par[rt[mt[bu]]]] : 0) used[bu]= in;\n   for (int i,\
    \ id= n + 1; bv; bv= rt[mt[bv]] ? rt[par[rt[mt[bv]]]] : 0)\n    if (used[bv] ==\
    \ in) {\n     while (id <= m && rt[id]) id++;\n     for (m+= (id > m), i= 1; i\
    \ <= m; i++) G[id][i].w= G[i][id].w= 0;\n     std::fill_n(blg[id].begin() + 1,\
    \ n, 0), mt[id]= mt[bv];\n     for (fwr[id].clear(); u != bv; fwr[id].push_back(u),\
    \ u= rt[par[u]]) fwr[id].push_back(u), push(u= rt[mt[u]]);\n     fwr[id].push_back(bv),\
    \ std::reverse(fwr[id].begin(), fwr[id].end());\n     for (; v != bv; fwr[id].push_back(v),\
    \ v= rt[par[v]]) fwr[id].push_back(v), push(v= rt[mt[v]]);\n     isS[id]= 1, dual[id]=\
    \ 0, set(id, id);\n     for (int c: fwr[id]) {\n      for (i= 1; i <= m; i++)\n\
    \       if (!G[id][i].w || dist(G[c][i]) < dist(G[id][i])) G[id][i]= G[c][i],\
    \ G[i][id]= G[i][c];\n      for (i= 1; i <= n; i++)\n       if (blg[c][i]) blg[id][i]=\
    \ c;\n     }\n     return recalc(id), false;\n    }\n   for (bu= u, bv= v;; match(bv=\
    \ x, bu= rt[par[x]]))\n    if (x= rt[mt[bu]], match(bu, bv); !x)\n     for (;;\
    \ match(u= x, v= rt[par[x]]))\n      if (x= rt[mt[v]], match(v, u); !x) return\
    \ true;\n  } else if (!isS[v]) par[v]= e.u, isS[v]= 2, slk[v]= slk[x= rt[mt[v]]]=\
    \ 0, isS[x]= 1, push(x);\n  return false;\n }\n bool augment() {\n  isS= slk=\
    \ par= std::vector<int>(n * 2), que= std::queue<int>();\n  for (int i= 1; i <=\
    \ m; i++)\n   if (rt[i] == i && !mt[i]) isS[i]= 1, push(i);\n  if (que.empty())\
    \ return false;\n  for (cost_t del= INF;; del= INF) {\n   for (int v, i; !que.empty();)\n\
    \    for (v= que.front(), que.pop(), i= 1; i <= n; i++)\n     if (G[v][i].w &&\
    \ rt[i] != rt[v]) {\n      if (!dist(G[v][i])) {\n       if (path(G[v][i])) return\
    \ true;\n      } else if (isS[rt[i]] != 2)\n       if (!slk[rt[i]] || dist(G[v][rt[i]])\
    \ < dist(G[slk[rt[i]]][rt[i]])) slk[rt[i]]= v;\n     }\n   for (int i= n + 1;\
    \ i <= m; i++)\n    if (rt[i] == i && isS[i] == 2 && del > dual[i] / 2) del= dual[i]\
    \ / 2;\n   for (int i= 1; i <= m; i++)\n    if (rt[i] == i && slk[i] && isS[i]\
    \ != 2)\n     if (cost_t c= dist(G[slk[i]][i]) / (isS[i] + 1); del > c) del= c;\n\
    \   for (int i= 1; i <= n; i++) {\n    if (isS[rt[i]] == 1) {\n     if ((dual[i]-=\
    \ del) <= 0) return false;\n    } else if (isS[rt[i]] == 2) dual[i]+= del;\n \
    \  }\n   for (int i= n + 1; i <= m; i++)\n    if (rt[i] == i && isS[i]) dual[i]+=\
    \ isS[i] == 1 ? 2 * del : -2 * del;\n   for (int i= 1; i <= m; i++)\n    if (rt[i]\
    \ == i && slk[i] && rt[slk[i]] != i && !dist(G[slk[i]][i]))\n     if (path(G[slk[i]][i]))\
    \ return true;\n   for (int b= n + 1, x, p, i, T, S; b <= m; b++)\n    if (rt[b]\
    \ == b && isS[b] == 2 && dual[b] == 0) {\n     isS[x= blg[b][G[b][par[b]].u]]=\
    \ 2, par[x]= par[b];\n     for (int c: fwr[b]) set(c, c);\n     for (p= findeven(b,\
    \ x), i= 0, x= fwr[b].size(); i < p; i+= 2) isS[S= fwr[b][i + 1]]= 1, isS[T= fwr[b][i]]=\
    \ 2, par[T]= G[S][T].u, slk[S]= slk[T]= 0, push(S);\n     for (i= p + 1; i < x;\
    \ i++) isS[T= fwr[b][i]]= 0, recalc(T);\n     fwr[b].clear(), rt[b]= 0;\n    }\n\
    \  }\n }\npublic:\n MatchingWeighted(int _n): n(_n), m(n), in(0), G(n * 2, std::vector<E>(n\
    \ * 2)), mt(n * 2), rt(n * 2), used(n * 2), fwr(n * 2), blg(n * 2, std::vector<int>(n\
    \ * 2)), dual(n * 2) {\n  for (int i= 1; i <= n; i++) rt[i]= i, blg[i][i]= i,\
    \ dual[i]= INF;\n  for (int i= 0; i <= n; i++)\n   for (int j= 0; j <= n; j++)\
    \ G[i][j]= E{i, j, 0};\n }\n void add_edge(int u, int v, cost_t w) {\n  if (G[++u][++v].w\
    \ < w * 2) G[u][v].w= G[v][u].w= w * 2;\n }\n std::tuple<int, cost_t, std::vector<int>>\
    \ get_matching() {\n  for (bool upd= augment(); upd;) upd= augment();\n  std::vector<int>\
    \ ret(n);\n  int num= 0;\n  cost_t sum= 0;\n  for (int i= 1; i <= n; i++) ret[i\
    \ - 1]= mt[i] - 1;\n  for (int i= 0; i < n; i++)\n   if (ret[i] > i) num++, sum+=\
    \ G[ret[i] + 1][i + 1].w;\n  return std::make_tuple(num, sum / 2, ret);\n }\n\
    };\n#line 4 \"test/yosupo/general_weighted_matching.test.cpp\"\nusing namespace\
    \ std;\n\nint main() {\n  int n, m;\n  cin >> n >> m;\n  auto solver = MatchingWeighted(n);\n\
    \  vector g(n, vector<long long>(n));\n  for (int i = 0; i < m; i++) {\n    int\
    \ u, v, w;\n    cin >> u >> v >> w;\n    g[u][v] = g[v][u] = w;\n    solver.add_edge(u,\
    \ v, w);\n  }\n  auto [r1, r2, res] = solver.get_matching();\n  cout << r1 <<\
    \ \" \" << r2 << '\\n';\n  for (int i = 0; i < n; i++)\n    if (res[i] > i) cout\
    \ << i << \" \" << res[i] << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/general_weighted_matching\"\
    \n#include <bits/stdc++.h>\n#include \"src/Optimization/MatchingWeighted.hpp\"\
    \nusing namespace std;\n\nint main() {\n  int n, m;\n  cin >> n >> m;\n  auto\
    \ solver = MatchingWeighted(n);\n  vector g(n, vector<long long>(n));\n  for (int\
    \ i = 0; i < m; i++) {\n    int u, v, w;\n    cin >> u >> v >> w;\n    g[u][v]\
    \ = g[v][u] = w;\n    solver.add_edge(u, v, w);\n  }\n  auto [r1, r2, res] = solver.get_matching();\n\
    \  cout << r1 << \" \" << r2 << '\\n';\n  for (int i = 0; i < n; i++)\n    if\
    \ (res[i] > i) cout << i << \" \" << res[i] << '\\n';\n  return 0;\n}"
  dependsOn:
  - src/Optimization/MatchingWeighted.hpp
  isVerificationFile: true
  path: test/yosupo/general_weighted_matching.test.cpp
  requiredBy: []
  timestamp: '2022-12-31 23:54:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/general_weighted_matching.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/general_weighted_matching.test.cpp
- /verify/test/yosupo/general_weighted_matching.test.cpp.html
title: test/yosupo/general_weighted_matching.test.cpp
---