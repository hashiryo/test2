---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Math/ModIntPrototype.hpp
    title: "ModInt\u306E\u30D7\u30ED\u30C8\u30BF\u30A4\u30D7"
  - icon: ':question:'
    path: src/Math/is_prime.hpp
    title: "\u7D20\u6570\u5224\u5B9A"
  - icon: ':question:'
    path: src/Math/mod_sqrt.hpp
    title: "\u5E73\u65B9\u6839 ($\\mathbb{F}_p$)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sqrt_mod
    links:
    - https://judge.yosupo.jp/problem/sqrt_mod
  bundledCode: "#line 1 \"test/yosupo/sqrt_mod.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/sqrt_mod\"\
    \n#include <bits/stdc++.h>\n#line 3 \"src/Math/ModIntPrototype.hpp\"\n/**\n *\
    \ @title ModInt\u306E\u30D7\u30ED\u30C8\u30BF\u30A4\u30D7\n * @category \u6570\
    \u5B66\n * \u30E2\u30F3\u30B4\u30E1\u30EA\u3068\u304B\n */\n\n// BEGIN CUT HERE\n\
    namespace math_internal {\nusing namespace std;\nusing u32 = uint32_t;\nusing\
    \ u64 = uint64_t;\nusing u128 = __uint128_t;\nstruct MIntPro_Montg {\n  const\
    \ u64 mod;\n  constexpr MIntPro_Montg() : mod(0), iv(0), r2(0) {}\n  constexpr\
    \ MIntPro_Montg(u64 m) : mod(m), iv(inv(m)), r2(-u128(mod) % mod) {}\n  constexpr\
    \ inline u64 mul(u64 l, u64 r) const { return reduce(u128(l) * r); }\n#define\
    \ BOP(op, a) return l op## = a, l += (mod << 1) & -(l >> 63)\n  constexpr inline\
    \ u64 plus(u64 l, u64 r) const { BOP(+, r - (mod << 1)); }\n  constexpr inline\
    \ u64 diff(u64 l, u64 r) const { BOP(-, r); }\n#undef BOP\n  constexpr inline\
    \ u64 set(u64 n) const { return mul(n, r2); }\n  constexpr inline u64 get(u64\
    \ n) const {\n    u64 ret = reduce(n) - mod;\n    return ret + (mod & -(ret >>\
    \ 63));\n  }\n  constexpr inline u64 norm(u64 n) const { return n - (mod & -(n\
    \ >= mod)); }\n\n private:\n  const u64 iv, r2;\n  constexpr u64 inv(u64 n, int\
    \ e = 6, u64 x = 1) {\n    return e ? inv(n, e - 1, x * (2 - x * n)) : x;\n  }\n\
    \  constexpr inline u64 reduce(const u128 &w) const {\n    return u64(w >> 64)\
    \ + mod - ((u128(u64(w) * iv) * mod) >> 64);\n  }\n};\ntemplate <class Uint>\n\
    class MIntPro_Na {\n  using DUint = conditional_t<is_same_v<Uint, u32>, u64, u128>;\n\
    \n public:\n  const Uint mod;\n  constexpr MIntPro_Na() : mod(0){};\n  constexpr\
    \ MIntPro_Na(Uint m) : mod(m) {}\n  constexpr inline Uint mul(Uint l, Uint r)\
    \ const { return DUint(l) * r % mod; }\n#define BOP(m, p) return l m## = mod &\
    \ -((l p## = r) >= mod)\n  constexpr inline Uint plus(Uint l, Uint r) const {\
    \ BOP(-, +); }\n  constexpr inline Uint diff(Uint l, Uint r) const { BOP(+, -);\
    \ }\n#undef BOP\n  static constexpr inline Uint set(Uint n) { return n; }\n  static\
    \ constexpr inline Uint get(Uint n) { return n; }\n  static constexpr inline Uint\
    \ norm(Uint n) { return n; }\n};\ntemplate <class Uint, class mod_pro_t>\nconstexpr\
    \ Uint pow(Uint x, u64 k, const mod_pro_t &md) {\n  for (Uint ret = md.set(1);;\
    \ x = md.mul(x, x))\n    if (k & 1 ? ret = md.mul(ret, x) : 0; !(k >>= 1)) return\
    \ ret;\n}\n}  // namespace math_internal\n#line 4 \"src/Math/is_prime.hpp\"\n\
    /**\n * @title \u7D20\u6570\u5224\u5B9A\n * @category \u6570\u5B66\n *  O(log\
    \ N)\n */\n\n// BEGIN CUT HERE\nnamespace math_internal {\ntemplate <class Uint,\
    \ class mod_pro_t, u64... args>\nconstexpr bool miller_rabin(Uint n) {\n  const\
    \ mod_pro_t md(n);\n  const Uint s = __builtin_ctzll(n - 1), d = n >> s, one =\
    \ md.set(1),\n             n1 = md.norm(md.set(n - 1));\n  for (auto a : {args...})\
    \ {\n    Uint b = a % n, p = pow(md.set(b), d, md), i = s;\n    while (p = md.norm(p),\
    \ (p != one && p != n1 && b && i--)) p = md.mul(p, p);\n    if (md.norm(p) !=\
    \ n1 && i != s) return false;\n  }\n  return true;\n}\nconstexpr bool is_prime(u64\
    \ n) {\n  if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;\n  if (n < UINT_MAX)\
    \ return miller_rabin<u32, MIntPro_Na<u32>, 2, 7, 61>(n);\n  if (n < LLONG_MAX)\n\
    \    return miller_rabin<u64, MIntPro_Montg, 2, 325, 9375, 28178, 450775,\n  \
    \                      9780504, 1795265022>(n);\n  return miller_rabin<u64, MIntPro_Na<u64>,\
    \ 2, 325, 9375, 28178, 450775,\n                      9780504, 1795265022>(n);\n\
    }\n}  // namespace math_internal\nusing math_internal::is_prime;\n#line 4 \"src/Math/mod_sqrt.hpp\"\
    \n/**\n * @title \u5E73\u65B9\u6839 ($\\mathbb{F}_p$)\n * @category \u6570\u5B66\
    \n * O( log p )\n */\n\n// BEGIN CUT HERE\nnamespace math_internal {\ntemplate\
    \ <class Int, class mod_pro_t>\nconstexpr Int inner_sqrt(Int a, Int p) {\n  const\
    \ mod_pro_t md(p);\n  Int e = (p - 1) >> 1, one = md.set(1);\n  if (a = md.set(a);\
    \ md.norm(pow(a, e, md)) != one) return -1;\n  Int b = 0, d = md.diff(0, a), ret\
    \ = one, r2 = 0, b2 = one;\n  while (md.norm(pow(d, e, md)) == one)\n    b = md.plus(b,\
    \ one), d = md.diff(md.mul(b, b), a);\n  auto mult = [&md, d](Int &u1, Int &u2,\
    \ Int v1, Int v2) {\n    Int tmp = md.plus(md.mul(u1, v1), md.mul(md.mul(u2, v2),\
    \ d));\n    u2 = md.plus(md.mul(u1, v2), md.mul(u2, v1)), u1 = tmp;\n  };\n  for\
    \ (++e;; mult(b, b2, b, b2)) {\n    if (e & 1) mult(ret, r2, b, b2);\n    if (!(e\
    \ >>= 1)) return ret = md.get(ret), ret * 2 < p ? ret : p - ret;\n  }\n}\nconstexpr\
    \ int64_t mod_sqrt(int64_t a, int64_t p) {\n  assert(p > 0), assert(a > 0), assert(is_prime(p)),\
    \ a %= p;\n  if (a <= 1 || p == 2) return a;\n  if (p < INT_MAX) return inner_sqrt<int,\
    \ MIntPro_Na<u32>>(a, p);\n  return inner_sqrt<int64_t, MIntPro_Montg>(a, p);\n\
    }\n}  // namespace math_internal\nusing math_internal::mod_sqrt;\n#line 4 \"test/yosupo/sqrt_mod.test.cpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  int T;\n  cin >> T;\n  while (T--) {\n    int Y, P;\n    cin >> Y >> P;\n \
    \   cout << mod_sqrt(Y, P) << '\\n';\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sqrt_mod\"\n#include <bits/stdc++.h>\n\
    #include \"src/Math/mod_sqrt.hpp\"\nusing namespace std;\n\nsigned main() {\n\
    \  cin.tie(0);\n  ios::sync_with_stdio(0);\n  int T;\n  cin >> T;\n  while (T--)\
    \ {\n    int Y, P;\n    cin >> Y >> P;\n    cout << mod_sqrt(Y, P) << '\\n';\n\
    \  }\n  return 0;\n}"
  dependsOn:
  - src/Math/mod_sqrt.hpp
  - src/Math/is_prime.hpp
  - src/Math/ModIntPrototype.hpp
  isVerificationFile: true
  path: test/yosupo/sqrt_mod.test.cpp
  requiredBy: []
  timestamp: '2022-12-04 16:01:47+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/sqrt_mod.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/sqrt_mod.test.cpp
- /verify/test/yosupo/sqrt_mod.test.cpp.html
title: test/yosupo/sqrt_mod.test.cpp
---