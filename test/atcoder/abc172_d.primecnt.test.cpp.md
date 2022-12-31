---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/prime_count.hpp
    title: "\u7D20\u6570\u30AB\u30A6\u30F3\u30C8\u306A\u3069"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc172/tasks/abc172_d
    links:
    - https://atcoder.jp/contests/abc172/tasks/abc172_d
  bundledCode: "#line 1 \"test/atcoder/abc172_d.primecnt.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc172/tasks/abc172_d\"\n\n// O(N^(3/4)/log N)\n\
    \n#include <bits/stdc++.h>\n#line 3 \"src/Math/prime_count.hpp\"\ntemplate <class\
    \ T= __int128_t> auto polynomial_prime_sum_table(std::uint64_t N, const std::vector<T>\
    \ &poly) {\n const int sqrtN= std::sqrt(N), d= poly.size();\n std::vector<int>\
    \ primes;\n std::vector<T> small(sqrtN + 1, 0), large(sqrtN + 1, 0);\n std::vector<std::vector<T>>\
    \ s(d, std::vector<T>(sqrtN + 1)), l(d, std::vector<T>(sqrtN + 1));\n for (int\
    \ n= 1, k= 0; n <= sqrtN; n++, k= 0)\n  for (T prd= n; k < d; prd*= (n + ++k))\
    \ s[k][n]= prd / (k + 1);\n for (int n= 1, k= 0; n <= sqrtN; n++, k= 0)\n  for\
    \ (T prd= N / n; k < d; prd*= ((N / n) + ++k)) l[k][n]= prd / (k + 1);\n if (d\
    \ > 2) {\n  std::vector<T> stir(d, 0);\n  stir[1]= 1;\n  for (int k= 2; k < d;\
    \ stir[k++]= 1) {\n   for (int j= k - 1; j; j--) stir[j]= stir[j - 1] + stir[j]\
    \ * (k - 1);\n   for (int n= 1; n <= sqrtN; n++)\n    for (int j= 1; j < k; j++)\
    \ s[k][n]-= stir[j] * s[j][n], l[k][n]-= stir[j] * l[j][n];\n  }\n }\n for (int\
    \ k= 0; k < d; k++)\n  for (int n= 1; n <= sqrtN; n++) s[k][n]-= 1, l[k][n]-=\
    \ 1;\n for (int p= 2, k= 0; p <= sqrtN; p++, k= 0)\n  if (s[0][p] != s[0][p -\
    \ 1]) {\n   primes.emplace_back(p);\n   std::uint64_t q= std::uint64_t(p) * p,\
    \ M= N / p;\n   int t= sqrtN / p, u= std::min<std::uint64_t>(sqrtN, N / q);\n\
    \   for (T pw= 1; k < d; k++, pw*= p)\n    if (!k || poly[k] != T(0)) {\n    \
    \ T tk= s[k][p - 1];\n     for (int i= 1; i <= t; i++) l[k][i]-= (l[k][i * p]\
    \ - tk) * pw;\n     for (int i= t + 1; i <= u; i++) l[k][i]-= (s[k][double(M)\
    \ / i] - tk) * pw;\n     for (int i= sqrtN; (std::uint64_t)i >= q; i--) s[k][i]-=\
    \ (s[k][double(i) / p] - tk) * pw;\n    }\n  }\n for (int n= 1; n <= sqrtN; n++)\n\
    \  for (int k= 0; k < d; k++) small[n]+= s[k][n] * poly[k], large[n]+= l[k][n]\
    \ * poly[k];\n return std::make_tuple(primes, small, large);\n}\nauto prime_count_table(std::uint64_t\
    \ N) { return polynomial_prime_sum_table<std::uint64_t>(N, {1}); }\nstd::uint64_t\
    \ prime_count(std::uint64_t N) { return std::get<2>(prime_count_table(N))[1];\
    \ }\ntemplate <class T> T polynomial_prime_sum(std::uint64_t N, const std::vector<T>\
    \ &poly) { return std::get<2>(polynomial_prime_sum_table<T>(N, poly))[1]; }\n\
    template <class T, class F> T additive_sum(std::uint64_t N, F f, std::vector<T>\
    \ poly) {\n const std::uint64_t sqrtN= std::sqrt(N);\n auto [primes, s, l]= polynomial_prime_sum_table<T>(N,\
    \ poly);\n T ret= l[1];\n for (std::uint64_t d= 2, nN= N / d, nd; nN; nN= N /\
    \ (d= nd)) ret+= (nN > sqrtN ? l[d] : s[nN]) * ((nd= N / nN + 1) - d);\n for (std::uint64_t\
    \ p: primes)\n  for (std::uint64_t pw= p * p, e= 2; pw <= N; e++, pw*= p) ret+=\
    \ (f(p, e) - f(p, e - 1)) * (N / pw);\n return ret;\n}\ntemplate <class T= __int128_t,\
    \ class F> T multiplicative_sum(std::uint64_t N, const F &f, const std::vector<T>\
    \ &poly) {\n const std::uint64_t sqrtN= std::sqrt(N);\n std::vector<int> primes;\n\
    \ std::vector<T> s, l;\n tie(primes, s, l)= polynomial_prime_sum_table<T>(N, poly);\n\
    \ for (auto it= primes.rbegin(); it != primes.rend(); it++) {\n  std::uint64_t\
    \ p= *it, M= N / p, q= p * p;\n  int t= sqrtN / p, u= std::min(sqrtN, N / q);\n\
    \  T tk= s[p - 1];\n  for (auto i= q; i <= sqrtN; i++) s[i]+= (s[double(i) / p]\
    \ - tk) * f(p, 1);\n  for (int i= u; i > t; i--) l[i]+= (s[double(M) / i] - tk)\
    \ * f(p, 1);\n  for (int i= t; i >= 1; i--) l[i]+= (l[i * p] - tk) * f(p, 1);\n\
    \ }\n for (auto n= sqrtN; n; n--) s[n]+= 1, l[n]+= 1;\n auto dfs= [&](auto rc,\
    \ std::uint64_t n, std::size_t bg, T cf) -> T {\n  if (cf == T(0)) return T(0);\n\
    \  T ret= cf * (n > sqrtN ? l[double(N) / n] : s[n]);\n  for (auto i= bg; i <\
    \ primes.size(); i++) {\n   std::uint64_t p= primes[i], q= p * p, nn= double(n)\
    \ / q;\n   if (!nn) break;\n   for (int e= 2; nn; nn= double(nn) / p, e++) ret+=\
    \ rc(rc, nn, i + 1, cf * (f(p, e) - f(p, 1) * f(p, e - 1)));\n  }\n  return ret;\n\
    \ };\n return dfs(dfs, N, 0, 1);\n}\n#line 7 \"test/atcoder/abc172_d.primecnt.test.cpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  auto f = [](long long p, short e) {\n    long long ret = e + 1;\n    while\
    \ (e--) ret *= p;\n    return ret;\n  };\n  long long N;\n  cin >> N;\n  cout\
    \ << (long long)multiplicative_sum<>(N, f, {0, 2}) << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc172/tasks/abc172_d\"\n\n\
    // O(N^(3/4)/log N)\n\n#include <bits/stdc++.h>\n#include \"src/Math/prime_count.hpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  auto f = [](long long p, short e) {\n    long long ret = e + 1;\n    while\
    \ (e--) ret *= p;\n    return ret;\n  };\n  long long N;\n  cin >> N;\n  cout\
    \ << (long long)multiplicative_sum<>(N, f, {0, 2}) << '\\n';\n  return 0;\n}"
  dependsOn:
  - src/Math/prime_count.hpp
  isVerificationFile: true
  path: test/atcoder/abc172_d.primecnt.test.cpp
  requiredBy: []
  timestamp: '2022-12-31 21:15:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc172_d.primecnt.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc172_d.primecnt.test.cpp
- /verify/test/atcoder/abc172_d.primecnt.test.cpp.html
title: test/atcoder/abc172_d.primecnt.test.cpp
---