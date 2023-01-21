---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Math/DirichletConvSumTable.hpp
    title: "\u6570\u8AD6\u95A2\u6570\u306E\u7D2F\u7A4D\u548C"
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
  bundledCode: "#line 1 \"test/atcoder/abc179_c.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc179/tasks/abc179_c\"\
    \n// O(\u221AN)\n#include <bits/stdc++.h>\n#line 3 \"src/Math/DirichletConvSumTable.hpp\"\
    \ntemplate <class T> struct DirichletConvSumTable {\n std::uint64_t N;  // <=\
    \ K * L\n std::vector<T> x /* (1 <= i <= K) */, X /* \u2211^{N/i} (1 <= i <= L)\
    \ */;\n static DirichletConvSumTable get_epsilon(std::uint64_t N, std::size_t\
    \ K) {\n  std::size_t L= (N - 1 + K) / K;\n  std::vector<T> a(K + 1, 0);\n  return\
    \ a[1]= 1, DirichletConvSumTable(N, a, std::vector<T>(L + 1, 1));\n }\n DirichletConvSumTable(std::uint64_t\
    \ n_, const std::vector<T> &x_, const std::vector<T> &X_): N(n_), x(x_), X(X_)\
    \ { assert(N < std::uint64_t(x.size()) * X.size()); }\n DirichletConvSumTable(std::uint64_t\
    \ n_, std::size_t k_): N(n_), x(k_ + 1, 0), X((n_ - 1 + k_) / k_ + 1, 0) {}\n\
    \ template <class F> DirichletConvSumTable(std::uint64_t n_, std::size_t k_, const\
    \ F &sum): N(n_), x(k_ + 1), X((n_ - 1 + k_) / k_ + 1) {\n  assert(N < std::uint64_t(x.size())\
    \ * X.size());\n  for (std::size_t i= x.size(); --i;) x[i]= sum(i);\n  for (std::size_t\
    \ i= x.size(); --i > 1;) x[i]-= x[i - 1];\n  for (std::size_t i= X.size(); --i;)\
    \ X[i]= sum(N / i);\n }\n DirichletConvSumTable operator*(const DirichletConvSumTable\
    \ &r) const {\n  const std::size_t K= x.size() - 1, L= X.size() - 1;\n  assert(N\
    \ <= std::uint64_t(K) * L), assert(N == r.N);\n  assert(K == r.x.size() - 1),\
    \ assert(L == r.X.size() - 1);\n  std::vector<T> c(K + 1, 0), C(L + 1, 0), A_l(K\
    \ + 1, 0), B_l(K + 1, 0);\n  for (std::size_t i= 1; i <= K; i++) A_l[i]= A_l[i\
    \ - 1] + x[i];\n  for (std::size_t i= 1; i <= K; i++) B_l[i]= B_l[i - 1] + r.x[i];\n\
    \  auto A= [&](std::uint64_t n) { return n <= K ? A_l[n] : X[N / n]; };\n  auto\
    \ B= [&](std::uint64_t n) { return n <= K ? B_l[n] : r.X[N / n]; };\n  std::uint64_t\
    \ n;\n  for (std::size_t i= K, j; i; i--)\n   for (j= K / i; j; j--) c[i * j]+=\
    \ x[i] * r.x[j];\n  for (std::size_t l= L, m, i; l; C[l--]-= A(m) * B(m))\n  \
    \ for (i= m= std::sqrt(n= N / l); i; i--) C[l]+= x[i] * B(n / i) + r.x[i] * A(n\
    \ / i);\n  return DirichletConvSumTable<T>(N, c, C);\n }\n DirichletConvSumTable\
    \ &operator*=(const DirichletConvSumTable &r) { return *this= *this * r; }\n DirichletConvSumTable\
    \ operator/(const DirichletConvSumTable &r) const { return DirichletConvSumTable(*this)/=\
    \ r; }\n DirichletConvSumTable &operator/=(const DirichletConvSumTable &r) {\n\
    \  const std::size_t K= x.size() - 1, L= X.size() - 1;\n  assert(N <= std::uint64_t(K)\
    \ * L), assert(N == r.N);\n  assert(K == r.x.size() - 1), assert(L == r.X.size()\
    \ - 1);\n  std::vector<T> A_l(K + 1, 0), B_l(K + 1, 0);\n  for (std::size_t i=\
    \ 1, j, ed; i <= K; i++)\n   for (x[i]/= r.x[1], j= 2, ed= K / i; j <= ed; j++)\
    \ x[i * j]-= x[i] * r.x[j];\n  for (std::size_t i= 1; i <= K; i++) A_l[i]= A_l[i\
    \ - 1] + r.x[i];\n  for (std::size_t i= 1; i <= K; i++) B_l[i]= B_l[i - 1] + x[i];\n\
    \  auto A= [&](std::uint64_t n) { return n <= K ? A_l[n] : r.X[N / n]; };\n  auto\
    \ B= [&](std::uint64_t n) { return n <= K ? B_l[n] : X[N / n]; };\n  std::uint64_t\
    \ n;\n  for (std::size_t l= L, m; l; X[l--]/= r.x[1])\n   for (m= std::sqrt(n=\
    \ N / l), X[l]+= A(m) * B(m) - x[1] * A(n); m > 1;) X[l]-= r.x[m] * B(n / m) +\
    \ x[m] * A(n / m), m--;\n  return *this;\n }\n DirichletConvSumTable square()\
    \ const {\n  const std::size_t K= x.size() - 1, L= X.size() - 1;\n  assert(N <=\
    \ std::uint64_t(K) * L);\n  std::vector<T> c(K + 1, 0), C(L + 1, 0), A_l(K + 1,\
    \ 0);\n  for (int i= 1; i <= K; i++) A_l[i]= A_l[i - 1] + x[i];\n  auto A= [&](std::uint64_t\
    \ n) { return n <= K ? A_l[n] : X[N / n]; };\n  std::size_t i, j, l= std::sqrt(K);\n\
    \  std::uint64_t n;\n  T tmp;\n  for (i= l; i; i--)\n   for (j= K / i; j > i;\
    \ j--) c[i * j]+= x[i] * x[j];\n  for (i= K; i; i--) c[i]+= c[i];\n  for (i= l;\
    \ i; i--) c[i * i]+= x[i] * x[i];\n  for (l= L; l; C[l]+= C[l], C[l--]-= tmp *\
    \ tmp)\n   for (tmp= A(i= std::sqrt(n= N / l)); i; i--) C[l]+= x[i] * A(n / i);\n\
    \  return DirichletConvSumTable<T>(N, c, C);\n }\n DirichletConvSumTable pow1(std::uint64_t\
    \ M) const {\n  for (auto ret= get_epsilon(N, x.size() - 1), b= *this;; b= b.square())\
    \ {\n   if (M & 1) ret*= b;\n   if (!(M>>= 1)) return ret;\n  }\n }\n DirichletConvSumTable\
    \ pow2(std::uint64_t M) const {\n  const std::size_t K= x.size() - 1, L= X.size()\
    \ - 1;\n  assert(N <= std::uint64_t(K) * L);\n  if (M == 0) return get_epsilon(N,\
    \ K);\n  if (M == 1) return *this;\n  std::size_t n= 0, m, i, l, p= 2;\n  std::uint64_t\
    \ e, j;\n  while (n <= M && (1ULL << n) <= N) n++;\n  DirichletConvSumTable ret(N,\
    \ x.size() - 1);\n  T pw[65]= {1}, b= x[1], tmp;\n  for (e= M - n + 1;; b*= b)\n\
    \   if (e & 1 ? pw[0]*= b : 0; !(e>>= 1)) break;\n  for (m= 1; m < n; m++) pw[m]=\
    \ pw[m - 1] * x[1];\n  std::vector<T> XX(X), z(K + 1, 0), Z(L + 1, 0), A_l(K +\
    \ 1, 0);\n  for (i= 2; i <= K; i++) A_l[i]= A_l[i - 1] + x[i];\n  for (i= L; i;\
    \ i--) XX[i]-= x[1];\n  auto A= [&](std::uint64_t n) { return n <= K ? A_l[n]\
    \ : XX[N / n]; };\n  std::vector<T> y(x), Y(XX), B_l(A_l), c(y), C(Y);\n  auto\
    \ B= [&](std::uint64_t n) { return n <= K ? B_l[n] : Y[N / n]; };\n  for (tmp=\
    \ pw[n - 2] * M, l= L; l; l--) C[l]*= tmp;\n  for (i= 2; i <= K; i++) c[i]*= tmp;\n\
    \  for (c[1]= pw[n - 1], l= L; l; l--) C[l]+= c[1];\n  for (m= 1, b= M, l= std::min<std::uint64_t>(L,\
    \ N / p / 2); m + 1 < n;) {\n   b*= M - m, b/= ++m, tmp= b * pw[n - 1 - m];\n\
    \   for (; l; C[l--]+= Z[l] * tmp) {\n    for (i= j= std::sqrt(e= N / l); i >=\
    \ p; i--) Z[l]+= y[i] * A(e / i);\n    for (i= std::min(j, e / p); i >= 2; i--)\
    \ Z[l]+= x[i] * B(e / i);\n    if (j >= p) Z[l]-= A(j) * B(j);\n   }\n   for (i=\
    \ K; i >= p; i--)\n    for (l= K / i; l >= 2; l--) z[i * l]+= y[i] * x[l];\n \
    \  for (i= p= 1 << m; i <= K; i++) c[i]+= z[i] * tmp;\n   if (m + 1 == n) break;\n\
    \   l= std::min<std::uint64_t>(L, N / p / 2);\n   y.swap(z), Y.swap(Z), std::fill_n(Z.begin()\
    \ + 1, l, 0);\n   if (p * 2 <= K) std::fill(z.begin() + p * 2, z.end(), 0);\n\
    \   if (p <= K)\n    for (B_l[p]= y[p], i= p + 1; i <= K; i++) B_l[i]= B_l[i -\
    \ 1] + y[i];\n  }\n  return DirichletConvSumTable<T>(N, c, C);\n }\n inline T\
    \ sum() const { return X[1]; }\n};\ntemplate <class T>  // zeta(s)\nDirichletConvSumTable<T>\
    \ get_1(std::uint64_t N, std::size_t K) {\n std::size_t L= (N - 1 + K) / K;\n\
    \ std::vector<T> A(L + 1);\n for (std::size_t l= L; l; l--) A[l]= N / l;\n return\
    \ DirichletConvSumTable<T>(N, std::vector<T>(K + 1, 1), A);\n}\ntemplate <class\
    \ T>  // M\xF6bius, O(KlogK + \u221A(NL))\nDirichletConvSumTable<T> get_mu(std::uint64_t\
    \ N, std::size_t K) {\n return DirichletConvSumTable<T>::get_epsilon(N, K) / get_1<T>(N,\
    \ K);\n}\ntemplate <class T>  // zeta(s-1)\nDirichletConvSumTable<T> get_Id(std::uint64_t\
    \ N, std::size_t K) {\n std::size_t L= (N - 1 + K) / K;\n std::vector<T> a(K +\
    \ 1), A(L + 1);\n for (std::size_t l= L; l; l--) A[l]= N / l, (A[l]*= A[l] + 1)/=\
    \ 2;\n return std::iota(a.begin(), a.end(), 0), DirichletConvSumTable<T>(N, a,\
    \ A);\n}\ntemplate <class T>  // Euler's totient, O(KlogK + \u221A(NL))\nDirichletConvSumTable<T>\
    \ get_phi(std::uint64_t N, std::size_t K) {\n return get_Id<T>(N, K) / get_1<T>(N,\
    \ K);\n}\ntemplate <class T>  // zeta(2s)\nDirichletConvSumTable<T> get_1sq(std::uint64_t\
    \ N, std::size_t K) {\n std::size_t L= (N - 1 + K) / K;\n std::vector<T> a(K +\
    \ 1, 0), A(L + 1);\n for (std::size_t i= 1; i * i <= K; i++) a[i * i]= 1;\n for\
    \ (std::size_t l= L; l; l--) A[l]= sqrt(N / l);\n return DirichletConvSumTable<T>(N,\
    \ a, A);\n}\ntemplate <class T>  // Liouville, O(KlogK + \u221A(NL))\nDirichletConvSumTable<T>\
    \ get_lambda(std::uint64_t N, std::size_t K) {\n return get_1sq<T>(N, K) / get_1<T>(N,\
    \ K);\n}\ntemplate <class T>  // |\xB5|, O(KlogK + \u221A(NL))\nDirichletConvSumTable<T>\
    \ get_absmu(std::uint64_t N, std::size_t K) {\n return get_1<T>(N, K) / get_1sq<T>(N,\
    \ K);\n}\ntemplate <class T>  // O(\u221AN)\nT dirichlet_mul_sum(const DirichletConvSumTable<T>\
    \ &a, const DirichletConvSumTable<T> &b) {\n const std::size_t K= a.x.size() -\
    \ 1, L= a.X.size() - 1, M= std::min(K, L);\n assert(a.N == b.N), assert(M <= b.x.size()\
    \ - 1), assert(M <= b.X.size() - 1);\n assert(std::uint64_t(M + 1) * (M + 1) >\
    \ a.N);\n T ret= 0, A= 0, B= 0;\n for (int i= M; i; i--) ret+= a.x[i] * b.X[i]\
    \ + b.x[i] * a.X[i];\n for (int i= M; i; i--) A+= a.x[i], B+= b.x[i];\n return\
    \ ret-= A * B;\n}\ntemplate <class mod_t>  // return \u2211g s.t. s+t\u2211g =\
    \ \u2211f*g\nauto SemiRelaxed(const DirichletConvSumTable<mod_t> &F, mod_t s,\
    \ mod_t t) {\n const std::size_t K= F.x.size() - 1, L= F.X.size() - 1;\n assert(F.N\
    \ <= std::uint64_t(K) * L), assert(F.x[1] != t);\n std::vector<mod_t> A_l(K +\
    \ 1, 0), B_l(K + 1, 0), g(K + 1, 0), G(L + 1, 0);\n g[1]= s;\n for (std::size_t\
    \ j= 1, i, ed; j <= K; j++)\n  for (g[j]/= F.x[1] - t, i= 2, ed= K / j; i <= ed;\
    \ i++) g[i * j]-= F.x[i] * g[j];\n for (std::size_t i= 1; i <= K; i++) A_l[i]=\
    \ A_l[i - 1] + F.x[i];\n for (std::size_t i= 1; i <= K; i++) B_l[i]= B_l[i - 1]\
    \ + g[i];\n auto A= [&](std::uint64_t n) { return n <= K ? A_l[n] : F.X[F.N /\
    \ n]; };\n auto B= [&](std::uint64_t n) { return n <= K ? B_l[n] : G[F.N / n];\
    \ };\n std::uint64_t n;\n for (std::size_t l= L, m; l; (G[l--]+= s)/= F.x[1] -\
    \ t)\n  for (m= std::sqrt(n= F.N / l), G[l]= A(m) * B(m) - g[1] * A(n); m > 1;)\
    \ G[l]-= F.x[m] * B(n / m) + g[m] * A(n / m), m--;\n return DirichletConvSumTable<mod_t>(F.N,\
    \ g, G);\n}\n#line 5 \"test/atcoder/abc179_c.test.cpp\"\nusing namespace std;\n\
    \nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n  long long N;\n\
    \  cin >> N;\n  auto f = get_1<long long>(N - 1, (int)sqrt(N - 1));\n  cout <<\
    \ dirichlet_mul_sum<long long>(f, f) << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc179/tasks/abc179_c\"\n//\
    \ O(\u221AN)\n#include <bits/stdc++.h>\n#include \"src/Math/DirichletConvSumTable.hpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  long long N;\n  cin >> N;\n  auto f = get_1<long long>(N - 1, (int)sqrt(N -\
    \ 1));\n  cout << dirichlet_mul_sum<long long>(f, f) << '\\n';\n  return 0;\n}"
  dependsOn:
  - src/Math/DirichletConvSumTable.hpp
  isVerificationFile: true
  path: test/atcoder/abc179_c.test.cpp
  requiredBy: []
  timestamp: '2022-12-31 19:53:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc179_c.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc179_c.test.cpp
- /verify/test/atcoder/abc179_c.test.cpp.html
title: test/atcoder/abc179_c.test.cpp
---