---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/NumberTheory/DirichletSeries.hpp
    title: "\u30C7\u30A3\u30EA\u30AF\u30EC\u7D1A\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc179/tasks/abc179_c
    links:
    - https://atcoder.jp/contests/abc179/tasks/abc179_c
  bundledCode: "#line 1 \"test/atcoder/abc179_c.Dirichlet.test.cpp\"\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc179/tasks/abc179_c\"\n// O(N^(2/3)log^(1/3)N))\n\
    #include <iostream>\n#line 2 \"src/NumberTheory/DirichletSeries.hpp\"\n#include\
    \ <valarray>\n#include <iterator>\n#include <algorithm>\n#include <cmath>\n#include\
    \ <cassert>\n#include <numeric>\n#include <cstdint>\ntemplate <class T> struct\
    \ DirichletSeries {\n using Self= DirichletSeries;\n uint64_t N;  // <= K * L\n\
    \ size_t K, L;\n std::valarray<T> x, X;\n DirichletSeries(uint64_t N, bool unit=\
    \ false): N(N), K(N > 1 ? std::max(std::ceil(std::pow((double)N / std::log2(N),\
    \ 2. / 3)), std::sqrt(N) + 1) : 1), L((N - 1 + K) / K), x(K + 1), X(K + L + 1)\
    \ {\n  if (assert(N > 0); unit) x[1]= 1, X= 1;\n }\n template <class F, typename=\
    \ std::enable_if_t<std::is_convertible_v<std::invoke_result_t<F, uint64_t>, T>>>\
    \ DirichletSeries(uint64_t N, const F &sum): DirichletSeries(N) {\n  for (size_t\
    \ i= 1; i <= K; ++i) X[i]= sum(i);\n  for (size_t i= 1; i <= L; ++i) X[K + i]=\
    \ sum(uint64_t((double)N / i));\n  for (size_t i= K; i; --i) x[i]= X[i] - X[i\
    \ - 1];\n }\n Self operator-() const {\n  Self ret(N);\n  return ret.x= -x, ret.X=\
    \ -X, ret;\n }\n Self &operator+=(T r) { return x[1]+= r, X+= r, *this; }\n Self\
    \ &operator-=(T r) { return x[1]-= r, X-= r, *this; }\n Self &operator*=(T r)\
    \ { return x*= r, X*= r, *this; }\n Self &operator/=(T r) {\n  if (T iv= T(1)\
    \ / r; iv == 0) x/= r, X/= r;\n  else x*= iv, X*= iv;\n  return *this;\n }\n Self\
    \ &operator+=(const Self &r) { return assert(N == r.N), assert(K == r.K), assert(L\
    \ == r.L), x+= r.x, X+= r.X, *this; }\n Self &operator-=(const Self &r) { return\
    \ assert(N == r.N), assert(K == r.K), assert(L == r.L), x-= r.x, X-= r.X, *this;\
    \ }\n Self operator+(T r) const { return Self(*this)+= r; }\n Self operator-(T\
    \ r) const { return Self(*this)-= r; }\n Self operator*(T r) const { return Self(*this)*=\
    \ r; }\n Self operator/(T r) const { return Self(*this)/= r; }\n Self operator+(const\
    \ Self &r) const { return Self(*this)+= r; }\n Self operator-(const Self &r) const\
    \ { return Self(*this)-= r; }\n friend Self operator+(T l, Self r) { return r+=\
    \ l; }\n friend Self operator-(T l, Self r) { return r.x[1]-= l, r.X-= l, r.x=\
    \ -r.x, r.X= -r.X, r; }\n friend Self operator*(T l, const Self &r) { return r\
    \ * l; }\n friend Self operator/(T l, const Self &r) { return (Self(r.N, true)/=\
    \ r)*= l; }\n Self operator*(const Self &r) const {\n  assert(N == r.N), assert(K\
    \ == r.K), assert(L == r.L);\n  Self ret(N);\n  uint64_t n;\n  for (size_t i=\
    \ K, j; i; --i)\n   for (j= K / i; j; --j) ret.x[i * j]+= x[i] * r.x[j];\n  for\
    \ (size_t l= L, m, i; l; ret.X[K + l--]-= sum(m) * r.sum(m))\n   for (i= m= std::sqrt(n=\
    \ (double)N / l); i; --i) ret.X[K + l]+= x[i] * r.sum((double)n / i) + r.x[i]\
    \ * sum((double)n / i);\n  for (size_t i= 1; i <= K; ++i) ret.X[i]= ret.X[i -\
    \ 1] + ret.x[i];\n  return ret;\n }\n Self operator/(const Self &r) const { return\
    \ Self(*this)/= r; }\n Self &operator*=(const Self &r) { return *this= *this *\
    \ r; }\n Self &operator/=(const Self &r) {\n  assert(N == r.N), assert(K == r.K),\
    \ assert(L == r.L);\n  for (size_t i= 1, j, ed; i <= K; i++)\n   for (x[i]/= r.x[1],\
    \ j= 2, ed= K / i; j <= ed; j++) x[i * j]-= x[i] * r.x[j];\n  X[1]= x[1];\n  for\
    \ (size_t i= 2; i <= K; ++i) X[i]= X[i - 1] + x[i];\n  uint64_t n;\n  for (size_t\
    \ l= L, m; l; X[K + l--]/= r.x[1])\n   for (m= std::sqrt(n= (double)N / l), X[K\
    \ + l]+= r.sum(m) * sum(m) - x[1] * r.sum(n); m > 1;) X[K + l]-= r.x[m] * sum((double)n\
    \ / m) + x[m] * r.sum((double)n / m), --m;\n  return *this;\n }\n Self square()\
    \ const {\n  Self ret(N);\n  size_t i, j, l= std::sqrt(K);\n  uint64_t n;\n  T\
    \ tmp;\n  for (i= l; i; --i)\n   for (j= K / i; j > i; --j) ret.x[i * j]+= x[i]\
    \ * x[j];\n  ret.x+= ret.x;\n  for (i= l; i; --i) ret.x[i * i]+= x[i] * x[i];\n\
    \  for (l= L; l; ret.X[K + l]+= ret.X[K + l], ret.X[K + l--]-= tmp * tmp)\n  \
    \ for (tmp= sum(i= std::sqrt(n= (double)N / l)); i; --i) ret.X[K + l]+= x[i] *\
    \ sum((double)n / i);\n  for (size_t i= 1; i <= K; ++i) ret.X[i]= ret.X[i - 1]\
    \ + ret.x[i];\n  return ret;\n }\n Self pow(uint64_t M) const {\n  if (N / M >\
    \ M)\n   for (auto ret= Self(N, true), b= *this;; b= b.square()) {\n    if (M\
    \ & 1) ret*= b;\n    if (!(M>>= 1)) return ret;\n   }\n  size_t n= 0, m, i, l,\
    \ p= 2;\n  uint64_t e, j;\n  while (n <= M && (1ULL << n) <= N) ++n;\n  T pw[65]=\
    \ {1}, b= x[1], tmp;\n  for (e= M - n + 1;; b*= b)\n   if (e & 1 ? pw[0]*= b :\
    \ T(); !(e>>= 1)) break;\n  for (m= 1; m < n; ++m) pw[m]= pw[m - 1] * x[1];\n\
    \  Self ret(*this);\n  std::valarray<T> D= (ret.X-= x[1]), E(std::begin(D), K\
    \ + 1), Y(std::begin(D) + K, L + 1), y= x, z(K + 1), Z(L + 1);\n  auto A= [&](uint64_t\
    \ n) { return n > K ? D[K + (double)N / n] : D[n]; };\n  auto B= [&](uint64_t\
    \ n) { return n > K ? Y[(double)N / n] : E[n]; };\n  for (tmp= pw[n - 2] * M,\
    \ l= L; l; l--) ret.X[K + l]*= tmp;\n  for (i= 2; i <= K; ++i) ret.x[i]*= tmp;\n\
    \  for (ret.x[1]= pw[n - 1], l= L; l; l--) ret.X[K + l]+= ret.x[1];\n  for (m=\
    \ 1, b= M, l= std::min<uint64_t>(L, uint64_t((double)N / p) / 2); m + 1 < n;)\
    \ {\n   for (b*= M - m, b/= ++m, tmp= b * pw[n - 1 - m]; l; ret.X[K + l--]+= Z[l]\
    \ * tmp) {\n    for (i= j= std::sqrt(e= (double)N / l); i >= p; --i) Z[l]+= y[i]\
    \ * A((double)e / i);\n    for (i= std::min(j, e / p); i >= 2; --i) Z[l]+= x[i]\
    \ * B((double)e / i);\n    if (j >= p) Z[l]-= A(j) * B(j);\n   }\n   for (i= K;\
    \ i >= p; --i)\n    for (l= K / i; l >= 2; l--) z[i * l]+= y[i] * x[l];\n   for\
    \ (i= p= 1 << m; i <= K; ++i) ret.x[i]+= z[i] * tmp;\n   if (m + 1 == n) break;\n\
    \   if (l= std::min<uint64_t>(L, uint64_t((double)N / p) / 2), y.swap(z), Y.swap(Z),\
    \ std::fill_n(std::begin(Z) + 1, l, 0); p * 2 <= K) std::fill(std::begin(z) +\
    \ p * 2, std::end(z), 0);\n   if (p <= K)\n    for (E[p]= y[p], i= p + 1; i <=\
    \ K; ++i) E[i]= E[i - 1] + y[i];\n  }\n  for (size_t i= 1; i <= K; ++i) ret.X[i]=\
    \ ret.X[i - 1] + ret.x[i];\n  return ret;\n }\n inline T sum() const { return\
    \ X[K + 1]; }\n inline T sum(uint64_t n) const { return n > K ? X[K + (double)N\
    \ / n] : X[n]; }\n inline T operator()(uint64_t n) const { return n > K ? x[K\
    \ + (double)N / n] : x[n]; }\n};\n// 1, zeta(s), O(K+L)\ntemplate <class T> DirichletSeries<T>\
    \ get_1(uint64_t N) {\n DirichletSeries<T> ret(N);\n for (size_t i= ret.L; i;\
    \ --i) ret.X[ret.K + i]= uint64_t((double)N / i);\n return std::fill(std::begin(ret.x)\
    \ + 1, std::end(ret.x), T(1)), std::iota(std::begin(ret.X), std::begin(ret.X)\
    \ + ret.K + 1, 0), ret;\n}\n// Mobius, 1/zeta(s), O(N^(2/3)log^(1/3)N))\ntemplate\
    \ <class T> DirichletSeries<T> get_mu(uint64_t N) { return DirichletSeries<T>(N,\
    \ true)/= get_1<T>(N); }\n// n, zeta(s-1)\ntemplate <class T> DirichletSeries<T>\
    \ get_Id(uint64_t N) {\n DirichletSeries<T> ret(N);\n __uint128_t a;\n for (size_t\
    \ l= ret.L; l; --l) a= (double)N / l, ret.X[ret.K + l]= (a * (a + 1)) >> 1;\n\
    \ std::iota(std::begin(ret.x), std::end(ret.x), 0);\n for (size_t i= 1; i <= ret.K;\
    \ ++i) ret.X[i]= ret.X[i - 1] + ret.x[i];\n return ret;\n}\n// n^2, zeta(s-2),\
    \ O(K+L)\ntemplate <class T> DirichletSeries<T> get_Id2(uint64_t N) {\n DirichletSeries<T>\
    \ ret(N);\n __uint128_t a, b, c;\n for (size_t l= ret.L; l; --l) a= (double)N\
    \ / l, b= (a * (a + 1)) >> 1, c= (a + a + 1), ret.X[ret.K + l]= c % 3 == 0 ? T(c\
    \ / 3) * b : T(b / 3) * c;\n for (uint64_t i= ret.K; i; --i) ret.x[i]= i * i;\n\
    \ for (size_t i= 1; i <= ret.K; ++i) ret.X[i]= ret.X[i - 1] + ret.x[i];\n return\
    \ ret;\n}\n// number-of-divisors, zeta(s)zeta(s-1), O(N^(2/3)log^(1/3)N))\ntemplate\
    \ <class T> DirichletSeries<T> get_d(uint64_t N) { return get_1<T>(N).square();\
    \ }\n// sum-of-divisors, zeta(s)zeta(s-2), function, O(N^(2/3)log^(1/3)N))\ntemplate\
    \ <class T> DirichletSeries<T> get_sigma(uint64_t N) { return get_1<T>(N) * get_Id<T>(N);\
    \ }\n// Euler's totient, zeta(s-1)/zeta(s), O(N^(2/3)log^(1/3)N))\ntemplate <class\
    \ T> DirichletSeries<T> get_phi(uint64_t N) { return get_Id<T>(N)/= get_1<T>(N);\
    \ }\ntemplate <class T>  // zeta(2s), O(K+L)\nDirichletSeries<T> get_1sq(uint64_t\
    \ N) {\n DirichletSeries<T> ret(N);\n for (size_t i= 1, e= ret.x.size(); i * i\
    \ <= e; ++i) ret.x[i * i]= 1;\n for (size_t i= 1; i <= ret.K; ++i) ret.X[i]= ret.X[i\
    \ - 1] + ret.x[i];\n for (size_t l= ret.L; l; --l) ret.X[ret.K + l]= uint64_t(std::sqrt((double)N\
    \ / l));\n return ret;\n}\n// Liouville, zeta(2s)/zeta(s), O(N^(2/3)log^(1/3)N))\n\
    template <class T> DirichletSeries<T> get_lambda(uint64_t N) { return get_1sq<T>(N)/=\
    \ get_1<T>(N); }\n// square-free, zeta(s)/zeta(2s), O(N^(2/3)log^(1/3)N))\ntemplate\
    \ <class T> DirichletSeries<T> get_absmu(uint64_t N) { return get_1<T>(N)/= get_1sq<T>(N);\
    \ }\n#line 5 \"test/atcoder/abc179_c.Dirichlet.test.cpp\"\nusing namespace std;\n\
    signed main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n long long N;\n cin\
    \ >> N;\n cout << get_d<long long>(N - 1).sum() << '\\n';\n return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc179/tasks/abc179_c\"\n//\
    \ O(N^(2/3)log^(1/3)N))\n#include <iostream>\n#include \"src/NumberTheory/DirichletSeries.hpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ long long N;\n cin >> N;\n cout << get_d<long long>(N - 1).sum() << '\\n';\n\
    \ return 0;\n}"
  dependsOn:
  - src/NumberTheory/DirichletSeries.hpp
  isVerificationFile: true
  path: test/atcoder/abc179_c.Dirichlet.test.cpp
  requiredBy: []
  timestamp: '2024-02-08 01:24:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc179_c.Dirichlet.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc179_c.Dirichlet.test.cpp
- /verify/test/atcoder/abc179_c.Dirichlet.test.cpp.html
title: test/atcoder/abc179_c.Dirichlet.test.cpp
---