---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/ModIntPrototype.hpp
    title: "ModInt\u306E\u30D7\u30ED\u30C8\u30BF\u30A4\u30D7"
  - icon: ':x:'
    path: src/Math/StirlingNumber.hpp
    title: "\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570 ($\\mathbb{F}_p$)"
  - icon: ':question:'
    path: src/Math/is_prime.hpp
    title: "\u7D20\u6570\u5224\u5B9A"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind_small_p_large_n
    links:
    - https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind_small_p_large_n
  bundledCode: "#line 1 \"test/yosupo/stirling_1_small_p_large_n.test.cpp\"\n#define\
    \ PROBLEM \\\n  \"https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind_small_p_large_n\"\
    \n#include <bits/stdc++.h>\n#line 3 \"src/Math/ModIntPrototype.hpp\"\nnamespace\
    \ math_internal {\nusing namespace std;\nusing u8= uint8_t;\nusing u32= uint32_t;\n\
    using u64= uint64_t;\nusing i64= int64_t;\nusing u128= __uint128_t;\nstruct MP_Mo\
    \ {\n const u64 mod;\n constexpr MP_Mo(): mod(0), iv(0), r2(0) {}\n constexpr\
    \ MP_Mo(u64 m): mod(m), iv(inv(m)), r2(-u128(mod) % mod) {}\n constexpr inline\
    \ u64 mul(u64 l, u64 r) const { return reduce(u128(l) * r); }\n#define BOP(op,\
    \ a) return l op##= a, l+= (mod << 1) & -(l >> 63)\n constexpr inline u64 plus(u64\
    \ l, u64 r) const { BOP(+, r - (mod << 1)); }\n constexpr inline u64 diff(u64\
    \ l, u64 r) const { BOP(-, r); }\n#undef BOP\n constexpr inline u64 set(u64 n)\
    \ const { return mul(n, r2); }\n constexpr inline u64 get(u64 n) const {\n  u64\
    \ ret= reduce(n) - mod;\n  return ret + (mod & -(ret >> 63));\n }\n constexpr\
    \ inline u64 norm(u64 n) const { return n - (mod & -(n >= mod)); }\nprivate:\n\
    \ const u64 iv, r2;\n constexpr u64 inv(u64 n, int e= 6, u64 x= 1) { return e\
    \ ? inv(n, e - 1, x * (2 - x * n)) : x; }\n constexpr inline u64 reduce(const\
    \ u128& w) const { return u64(w >> 64) + mod - ((u128(u64(w) * iv) * mod) >> 64);\
    \ }\n};\ntemplate <class Uint> class MP_Na {\n using DUint= conditional_t<is_same_v<Uint,\
    \ u32>, u64, u128>;\npublic:\n const Uint mod;\n constexpr MP_Na(): mod(0){};\n\
    \ constexpr MP_Na(Uint m): mod(m) {}\n constexpr inline Uint mul(Uint l, Uint\
    \ r) const { return DUint(l) * r % mod; }\n#define BOP(m, p) return l m##= mod\
    \ & -((l p##= r) >= mod)\n constexpr inline Uint plus(Uint l, Uint r) const {\
    \ BOP(-, +); }\n constexpr inline Uint diff(Uint l, Uint r) const { BOP(+, -);\
    \ }\n#undef BOP\n static constexpr inline Uint set(Uint n) { return n; }\n static\
    \ constexpr inline Uint get(Uint n) { return n; }\n static constexpr inline Uint\
    \ norm(Uint n) { return n; }\n};\ntemplate <class Uint, class mod_pro_t> constexpr\
    \ Uint pow(Uint x, u64 k, const mod_pro_t& md) {\n for (Uint ret= md.set(1);;\
    \ x= md.mul(x, x))\n  if (k& 1 ? ret= md.mul(ret, x) : 0; !(k>>= 1)) return ret;\n\
    }\n}\n#line 4 \"src/Math/is_prime.hpp\"\nnamespace math_internal {\ntemplate <class\
    \ Uint, class mod_pro_t, u64... args> constexpr bool miller_rabin(Uint n) {\n\
    \ const mod_pro_t md(n);\n const Uint s= __builtin_ctzll(n - 1), d= n >> s, one=\
    \ md.set(1), n1= md.norm(md.set(n - 1));\n for (auto a: {args...}) {\n  Uint b=\
    \ a % n, p= pow(md.set(b), d, md), i= s;\n  while (p= md.norm(p), (p != one &&\
    \ p != n1 && b && i--)) p= md.mul(p, p);\n  if (md.norm(p) != n1 && i != s) return\
    \ 0;\n }\n return true;\n}\nconstexpr bool is_prime(u64 n) {\n if (n < 2 || n\
    \ % 6 % 4 != 1) return (n | 1) == 3;\n if (n < UINT_MAX) return miller_rabin<u32,\
    \ MP_Na<u32>, 2, 7, 61>(n);\n if (n < LLONG_MAX) return miller_rabin<u64, MP_Mo,\
    \ 2, 325, 9375, 28178, 450775, 9780504, 1795265022>(n);\n return miller_rabin<u64,\
    \ MP_Na<u64>, 2, 325, 9375, 28178, 450775, 9780504, 1795265022>(n);\n}\n}\nusing\
    \ math_internal::is_prime;\n#line 4 \"src/Math/StirlingNumber.hpp\"\n/**\n * @title\
    \ \u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570 ($\\mathbb{F}_p$)\n * @category \u6570\
    \u5B66\n * @see\n * https://maspypy.com/stirling-%e6%95%b0%e3%82%92-p-%e3%81%a7%e5%89%b2%e3%81%a3%e3%81%9f%e4%bd%99%e3%82%8a%e3%81%ae%e8%a8%88%e7%ae%97\n\
    \ * \u524D\u51E6\u7406 O(p^2), \u30AF\u30A8\u30EA O(log n)\n */\n\n// BEGIN CUT\
    \ HERE\nclass StirlingNumber {\n  const std::uint16_t p;\n  std::vector<std::vector<std::uint16_t>>\
    \ c, s1, s2;\n  void buildS1() {\n    s1.resize(p), s1[0] = {1};\n    for (int\
    \ i = 1, j, t; i < p; s1[i][i] = 1, i++)\n      for (s1[i].resize(i + 1, 0), j\
    \ = 1, t = p - i + 1; j < i; j++)\n        s1[i][j] = (t * s1[i - 1][j] + s1[i\
    \ - 1][j - 1]) % p;\n  }\n  void buildS2() {\n    s2.resize(p), s2[0] = {1};\n\
    \    for (int i = 1, j; i < p; s2[i][i] = 1, i++)\n      for (s2[i].resize(i +\
    \ 1, 0), j = 1; j < i; j++)\n        s2[i][j] = (j * s2[i - 1][j] + s2[i - 1][j\
    \ - 1]) % p;\n  }\n\n public:\n  StirlingNumber(std::uint32_t p_, bool first =\
    \ true, bool second = true)\n      : p(p_), c(p) {\n    assert(is_prime(p_)),\
    \ assert(p_ < (1 << 15)), c[0] = {1};\n    for (int i = 1, j; i < p; i++)\n  \
    \    for (c[i] = c[i - 1], c[i].emplace_back(0), j = 1; j <= i; j++)\n       \
    \ c[i][j] -= p & -((c[i][j] += c[i - 1][j - 1]) >= p);\n    if (first) buildS1();\n\
    \    if (second) buildS2();\n  }\n  int nCk(std::uint64_t n, std::uint64_t k)\
    \ {\n    if (k > n) return 0;\n    int ret = 1, i, j;\n    for (k = std::min(k,\
    \ n - k); k; ret = ret * c[i][j] % p, n /= p, k /= p)\n      if (i = n % p, j\
    \ = k % p; j > i) return 0;\n    return ret;\n  }\n  int S1(std::uint64_t n, std::uint64_t\
    \ k) {\n    if (k > n) return 0;\n    std::uint64_t i = n / p;\n    if (i > k)\
    \ return 0;\n    std::int64_t a = (k - i) / (p - 1);\n    std::uint16_t j = n\
    \ % p, b = (k - i) % (p - 1);\n    if (!b && j) b += (p - 1), a -= 1;\n    if\
    \ (a < 0 || i < a || b > j) return 0;\n    return (j = nCk(i, a) * s1[j][b] %\
    \ p) && ((i + a) & 1) ? p - j : j;\n  }\n  int S2(std::uint64_t n, std::uint64_t\
    \ k) {\n    if (k > n) return 0;\n    if (!n) return 1;\n    std::uint64_t i =\
    \ k / p;\n    if (n <= i) return 0;\n    std::uint64_t a = (n - i - 1) / (p -\
    \ 1);\n    std::uint16_t j = k % p, b = (n - i) - a * (p - 1);\n    if (j > b)\
    \ return 0;\n    return b == p - 1 && !j ? nCk(a, i - 1) : nCk(a, i) * s2[b][j]\
    \ % p;\n  }\n};\n#line 5 \"test/yosupo/stirling_1_small_p_large_n.test.cpp\"\n\
    using namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n\
    \  int T, p;\n  cin >> T >> p;\n  StirlingNumber SN(p, 1, 0);\n  while (T--) {\n\
    \    long long n, k;\n    cin >> n >> k;\n    cout << SN.S1(n, k) << '\\n';\n\
    \  }\n  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind_small_p_large_n\"\
    \n#include <bits/stdc++.h>\n#include \"src/Math/StirlingNumber.hpp\"\nusing namespace\
    \ std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(false);\n  int\
    \ T, p;\n  cin >> T >> p;\n  StirlingNumber SN(p, 1, 0);\n  while (T--) {\n  \
    \  long long n, k;\n    cin >> n >> k;\n    cout << SN.S1(n, k) << '\\n';\n  }\n\
    \  return 0;\n}"
  dependsOn:
  - src/Math/StirlingNumber.hpp
  - src/Math/is_prime.hpp
  - src/Math/ModIntPrototype.hpp
  isVerificationFile: true
  path: test/yosupo/stirling_1_small_p_large_n.test.cpp
  requiredBy: []
  timestamp: '2022-12-31 18:14:29+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/stirling_1_small_p_large_n.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/stirling_1_small_p_large_n.test.cpp
- /verify/test/yosupo/stirling_1_small_p_large_n.test.cpp.html
title: test/yosupo/stirling_1_small_p_large_n.test.cpp
---