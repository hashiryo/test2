---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Misc/Automaton.hpp
    title: "\u6709\u9650\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc121/tasks/abc121_d
    links:
    - https://atcoder.jp/contests/abc121/tasks/abc121_d
  bundledCode: "#line 1 \"test/atcoder/abc121_d.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc121/tasks/abc121_d\"\
    \n#include <iostream>\n#include <vector>\n#line 2 \"src/Misc/Automaton.hpp\"\n\
    #include <type_traits>\n#include <set>\n#include <map>\n#include <unordered_map>\n\
    #line 7 \"src/Misc/Automaton.hpp\"\n#include <algorithm>\n#include <queue>\n#include\
    \ <cstdlib>\n#include <cassert>\ntemplate <class symbol_t> class Automaton {\n\
    \ std::vector<int> table;\n std::vector<int8_t> info;\n std::vector<symbol_t>\
    \ alph;\n const int m;\n template <class Map, class state_t, class F, class G,\
    \ class H> void build(const state_t &initial_state, const F &transition, const\
    \ G &is_accept, const H &abs_reject) {\n  static_assert(std::is_same_v<bool, std::invoke_result_t<G,\
    \ state_t>>);\n  static_assert(std::is_same_v<bool, std::invoke_result_t<H, state_t>>);\n\
    \  Map encode;\n  std::vector<state_t> decode;\n  int ts= 0;\n  decode.push_back(initial_state),\
    \ encode.emplace(initial_state, ts++);\n  for (int i= 0, k= 0; i < ts; ++i) {\n\
    \   auto s= decode[i];\n   table.resize(table.size() + m);\n   for (int j= 0;\
    \ j < m; ++j) {\n    if (auto t= transition(s, j); abs_reject(t)) table[k++]=\
    \ -1;\n    else if (auto it= encode.find(t); it != encode.end()) table[k++]= it->second;\n\
    \    else table[k++]= ts, decode.push_back(t), encode.emplace(t, ts++);\n   }\n\
    \  }\n  info.resize(ts);\n  for (int i= ts; i--;) info[i]= is_accept(decode[i]);\n\
    \ }\n Automaton(const std::vector<symbol_t> &alphabet): alph(alphabet), m(alph.size())\
    \ {}\npublic:\n template <class state_t, class F, class G, std::enable_if_t<std::is_same_v<state_t,\
    \ std::invoke_result_t<F, state_t, symbol_t>>, std::nullptr_t> = nullptr> Automaton(const\
    \ std::vector<symbol_t> &alphabet, const state_t &initial_state, const F &transition,\
    \ const G &is_accept): alph(alphabet), m(alph.size()) {\n  std::sort(alph.begin(),\
    \ alph.end());\n  auto tr= [&](const state_t &s, int i) { return transition(s,\
    \ alph[i]); };\n  auto rej= [](const state_t &) { return false; };\n  if constexpr\
    \ (std::is_integral_v<state_t>) build<std::unordered_map<state_t, int>, state_t>(initial_state,\
    \ tr, is_accept, rej);\n  else build<std::map<state_t, int>, state_t>(initial_state,\
    \ tr, is_accept, rej);\n }\n template <class state_t, class F, class G, std::enable_if_t<std::is_same_v<state_t,\
    \ std::invoke_result_t<F, state_t, symbol_t>>, std::nullptr_t> = nullptr> Automaton(const\
    \ std::vector<symbol_t> &alphabet, const state_t &initial_state, const F &transition,\
    \ const G &is_accept, const state_t &abs_rej_state): alph(alphabet), m(alph.size())\
    \ {\n  std::sort(alph.begin(), alph.end());\n  auto tr= [&](const state_t &s,\
    \ int i) { return transition(s, alph[i]); };\n  auto rej= [abs_rej_state](const\
    \ state_t &s) { return s == abs_rej_state; };\n  if constexpr (std::is_integral_v<state_t>)\
    \ build<std::unordered_map<state_t, int>, state_t>(initial_state, tr, is_accept,\
    \ rej);\n  else build<std::map<state_t, int>, state_t>(initial_state, tr, is_accept,\
    \ rej);\n }\n template <class state_t, class F, class G, std::enable_if_t<std::is_same_v<std::set<state_t>,\
    \ std::invoke_result_t<F, state_t, symbol_t>>, std::nullptr_t> = nullptr> Automaton(const\
    \ std::vector<symbol_t> &alphabet, const state_t &initial_state, const F &transition,\
    \ const G &is_accept): alph(alphabet), m(alph.size()) {\n  static_assert(std::is_same_v<bool,\
    \ std::invoke_result_t<G, state_t>>);\n  std::sort(alph.begin(), alph.end());\n\
    \  auto tr= [&](const std::set<state_t> &s, int i) {\n   std::set<state_t> ret;\n\
    \   for (const auto &x: s) {\n    auto ys= transition(x, alph[i]);\n    ret.insert(ys.begin(),\
    \ ys.end());\n   }\n   return ret;\n  };\n  auto ac= [&](const std::set<state_t>\
    \ &s) { return std::any_of(s.begin(), s.end(), is_accept); };\n  auto rej= [](const\
    \ std::set<state_t> &s) { return s == std::set<state_t>(); };\n  build<std::map<std::set<state_t>,\
    \ int>, std::set<state_t>>(std::set<state_t>({initial_state}), tr, ac, rej);\n\
    \ }\n template <class state_t, class F, class G, class H, std::enable_if_t<std::is_same_v<std::set<state_t>,\
    \ std::invoke_result_t<F, state_t, symbol_t>>, std::nullptr_t> = nullptr> Automaton(const\
    \ std::vector<symbol_t> &alphabet, const state_t &initial_state, const F &transition,\
    \ const G &is_accept, const H &eps_trans): alph(alphabet), m(alph.size()) {\n\
    \  static_assert(std::is_same_v<bool, std::invoke_result_t<G, state_t>>);\n  static_assert(std::is_same_v<std::set<state_t>,\
    \ std::invoke_result_t<H, state_t>>);\n  std::sort(alph.begin(), alph.end());\n\
    \  auto eps_closure= [&](std::set<state_t> s) {\n   for (std::set<state_t> t;\
    \ s != t;) {\n    t= s;\n    for (const auto &x: t) {\n     auto ys= eps_trans(x);\n\
    \     s.insert(ys.begin(), ys.end());\n    }\n   }\n   return s;\n  };\n  auto\
    \ tr= [&](const std::set<state_t> &s, int i) {\n   std::set<state_t> ret;\n  \
    \ for (const auto &x: s) {\n    auto ys= transition(x, alph[i]);\n    ret.insert(ys.begin(),\
    \ ys.end());\n   }\n   return eps_closure(ret);\n  };\n  auto ac= [&](const std::set<state_t>\
    \ &s) { return std::any_of(s.begin(), s.end(), is_accept); };\n  auto rej= [](const\
    \ std::set<state_t> &s) { return s == std::set<state_t>(); };\n  build<std::map<std::set<state_t>,\
    \ int>, std::set<state_t>>(eps_closure({initial_state}), tr, ac, rej);\n }\n Automaton\
    \ operator&(const Automaton &r) const {\n  assert(alph == r.alph);\n  const int\
    \ S= info.size();\n  auto tr= [&](int s, int q) {\n   auto [s1, s0]= std::div(s,\
    \ S);\n   int t1= r.table[s1 * m + q], t0= table[s0 * m + q];\n   return t0 ==\
    \ -1 || t1 == -1 ? -1 : t1 * S + t0;\n  };\n  auto ac= [&](int s) {\n   auto [s1,\
    \ s0]= std::div(s, S);\n   return info[s0] == 1 && r.info[s1] == 1;\n  };\n  auto\
    \ rej= [](int s) { return s == -1; };\n  Automaton ret(alph);\n  return ret.build<std::unordered_map<int,\
    \ int>, int>(0, tr, ac, rej), ret;\n }\n template <class T, class A, class F>\
    \ T dp_run(int n, const A &op, const T &ti, const F &f, const T &init) const {\n\
    \  static_assert(std::is_same_v<T, std::invoke_result_t<A, T, T>>);\n  static_assert(std::is_same_v<T,\
    \ std::invoke_result_t<F, T, symbol_t, int>>);\n  const size_t S= info.size();\n\
    \  std::queue<std::pair<int, int>> que;\n  T dp[2][S], ret= ti;\n  bool in[2][S];\n\
    \  for (std::fill_n(dp[0], S, ti), std::fill_n(dp[1], S, ti), std::fill_n(in[0],\
    \ S, 0), std::fill_n(in[1], S, 0), dp[0][0]= init, que.emplace(0, 0), in[0][0]=\
    \ 1; que.size();) {\n   auto [s, i]= que.front();\n   bool b= i & 1;\n   T tmp=\
    \ dp[b][s];\n   if (que.pop(), in[b][s]= 0, dp[b][s]= ti; i == n) {\n    if (info[s]\
    \ == 1) ret= op(ret, tmp);\n    continue;\n   }\n   auto l= table.cbegin() + s\
    \ * m;\n   for (int j= m; j--;)\n    if (int t= l[j]; t != -1)\n     if (dp[!b][t]=\
    \ op(dp[!b][t], f(tmp, alph[j], i)); !in[!b][t]) que.emplace(t, i + 1), in[!b][t]=\
    \ 1;\n  }\n  return ret;\n }\n template <class T> T num(int n) const {\n  return\
    \ dp_run(\n      n, [](const T &l, const T &r) { return l + r; }, T(), [](const\
    \ T &x, const auto &, auto) { return x; }, T(1));\n }\n};\n#line 5 \"test/atcoder/abc121_d.test.cpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n\
    \ long long A, B;\n cin >> A >> B;\n vector alp= {0, 1};\n auto tr_le= [&](int\
    \ s, int c) {\n  if (s < 0) return s;\n  int d= (B >> s) & 1;\n  if (c < d) return\
    \ -1;\n  if (c > d) return -2;\n  return s - 1;\n };\n auto tr_ge= [&](int s,\
    \ int c) {\n  if (s < 0) return s;\n  int d= (A >> s) & 1;\n  if (c > d) return\
    \ -1;\n  if (c < d) return -2;\n  return s - 1;\n };\n auto ac= [](int) { return\
    \ true; };\n Automaton dfa_a(alp, 39, tr_ge, ac, -2), dfa_b(alp, 39, tr_le, ac,\
    \ -2);\n auto dfa= dfa_a & dfa_b;\n using T= pair<bool, long long>;\n auto op=\
    \ [](const T &l, const T &r) { return T{l.first ^ r.first, l.second ^ r.second};\
    \ };\n auto f= [](T x, int c, int) {\n  x.second<<= 1;\n  if (c) x.second|= x.first;\n\
    \  return x;\n };\n cout << dfa.dp_run(40, op, T{0, 0}, f, T{1, 0}).second <<\
    \ '\\n';\n return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc121/tasks/abc121_d\"\n#include\
    \ <iostream>\n#include <vector>\n#include \"src/Misc/Automaton.hpp\"\nusing namespace\
    \ std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n long long\
    \ A, B;\n cin >> A >> B;\n vector alp= {0, 1};\n auto tr_le= [&](int s, int c)\
    \ {\n  if (s < 0) return s;\n  int d= (B >> s) & 1;\n  if (c < d) return -1;\n\
    \  if (c > d) return -2;\n  return s - 1;\n };\n auto tr_ge= [&](int s, int c)\
    \ {\n  if (s < 0) return s;\n  int d= (A >> s) & 1;\n  if (c > d) return -1;\n\
    \  if (c < d) return -2;\n  return s - 1;\n };\n auto ac= [](int) { return true;\
    \ };\n Automaton dfa_a(alp, 39, tr_ge, ac, -2), dfa_b(alp, 39, tr_le, ac, -2);\n\
    \ auto dfa= dfa_a & dfa_b;\n using T= pair<bool, long long>;\n auto op= [](const\
    \ T &l, const T &r) { return T{l.first ^ r.first, l.second ^ r.second}; };\n auto\
    \ f= [](T x, int c, int) {\n  x.second<<= 1;\n  if (c) x.second|= x.first;\n \
    \ return x;\n };\n cout << dfa.dp_run(40, op, T{0, 0}, f, T{1, 0}).second << '\\\
    n';\n return 0;\n}"
  dependsOn:
  - src/Misc/Automaton.hpp
  isVerificationFile: true
  path: test/atcoder/abc121_d.test.cpp
  requiredBy: []
  timestamp: '2023-04-16 00:00:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc121_d.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc121_d.test.cpp
- /verify/test/atcoder/abc121_d.test.cpp.html
title: test/atcoder/abc121_d.test.cpp
---