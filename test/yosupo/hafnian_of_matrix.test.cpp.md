---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Internal/Remainder.hpp
    title: "\u5270\u4F59\u306E\u9AD8\u901F\u5316"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':heavy_check_mark:'
    path: src/Math/hafnian.hpp
    title: "\u30CF\u30D5\u30CB\u30A2\u30F3 (\u7121\u5411\u30B0\u30E9\u30D5\u306E\u5B8C\
      \u5168\u30DE\u30C3\u30C1\u30F3\u30B0\u6570)"
  - icon: ':question:'
    path: src/Math/mod_inv.hpp
    title: "\u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/hafnian_of_matrix
    links:
    - https://judge.yosupo.jp/problem/hafnian_of_matrix
  bundledCode: "#line 1 \"test/yosupo/hafnian_of_matrix.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/hafnian_of_matrix\"\n#include <bits/stdc++.h>\n\
    #line 3 \"src/Math/mod_inv.hpp\"\ntemplate <class Int> constexpr inline Int mod_inv(Int\
    \ a, Int mod) {\n static_assert(std::is_signed_v<Int>);\n Int x= 1, y= 0, b= mod;\n\
    \ for (Int q= 0, z= 0, c= 0; b;) z= x, c= a, x= y, y= z - y * (q= a / b), a= b,\
    \ b= c - b * q;\n return assert(a == 1), x < 0 ? mod - (-x) % mod : x % mod;\n\
    }\n#line 3 \"src/Internal/Remainder.hpp\"\nnamespace math_internal {\nusing namespace\
    \ std;\nusing u8= uint8_t;\nusing u32= uint32_t;\nusing u64= uint64_t;\nusing\
    \ i64= int64_t;\nusing u128= __uint128_t;\n#define CE constexpr\n#define IL inline\n\
    #define NORM \\\n if (n >= mod) n-= mod; \\\n return n\n#define PLUS(U, M) \\\n\
    \ CE IL U plus(U l, U r) const { \\\n  if (l+= r; l >= M) l-= M; \\\n  return\
    \ l; \\\n }\n#define DIFF(U, C, M) \\\n CE IL U diff(U l, U r) const { \\\n  if\
    \ (l-= r; l >> C) l+= M; \\\n  return l; \\\n }\n#define SGN(U) \\\n static CE\
    \ IL U set(U n) { return n; } \\\n static CE IL U get(U n) { return n; } \\\n\
    \ static CE IL U norm(U n) { return n; }\ntemplate <class u_t, class du_t, u8\
    \ B, u8 A> struct MP_Mo {\n const u_t mod;\n CE MP_Mo(): mod(0), iv(0), r2(0)\
    \ {}\n CE MP_Mo(u_t m): mod(m), iv(inv(m)), r2(-du_t(mod) % mod) {}\n CE IL u_t\
    \ mul(u_t l, u_t r) const { return reduce(du_t(l) * r); }\n PLUS(u_t, mod << 1)\n\
    \ DIFF(u_t, A, mod << 1)\n CE IL u_t set(u_t n) const { return mul(n, r2); }\n\
    \ CE IL u_t get(u_t n) const {\n  n= reduce(n);\n  NORM;\n }\n CE IL u_t norm(u_t\
    \ n) const { NORM; }\nprivate:\n const u_t iv, r2;\n static CE u_t inv(u_t n,\
    \ int e= 6, u_t x= 1) { return e ? inv(n, e - 1, x * (2 - x * n)) : x; }\n CE\
    \ IL u_t reduce(const du_t &w) const { return u_t(w >> B) + mod - ((du_t(u_t(w)\
    \ * iv) * mod) >> B); }\n};\nstruct MP_Na {\n const u32 mod;\n CE MP_Na(): mod(0){};\n\
    \ CE MP_Na(u32 m): mod(m) {}\n CE IL u32 mul(u32 l, u32 r) const { return u64(l)\
    \ * r % mod; }\n PLUS(u32, mod) DIFF(u32, 31, mod) SGN(u32)\n};\nstruct MP_Br\
    \ {  // mod < 2^31\n const u32 mod;\n CE MP_Br(): mod(0), s(0), x(0) {}\n CE MP_Br(u32\
    \ m): mod(m), s(__lg(m - 1) + 64), x(((u128(1) << s) + m - 1) / m) {}\n CE IL\
    \ u32 mul(u32 l, u32 r) const { return rem(u64(l) * r); }\n PLUS(u32, mod) DIFF(u32,\
    \ 31, mod) SGN(u32) private: const u8 s;\n const u64 x;\n CE IL u64 quo(u64 n)\
    \ const { return (u128(x) * n) >> s; }\n CE IL u32 rem(u64 n) const { return n\
    \ - quo(n) * mod; }\n};\nstruct MP_Br2 {  // 2^20 < mod <= 2^41\n const u64 mod;\n\
    \ CE MP_Br2(): mod(0), x(0) {}\n CE MP_Br2(u64 m): mod(m), x((u128(1) << 84) /\
    \ m) {}\n CE IL u64 mul(u64 l, u64 r) const { return rem(u128(l) * r); }\n PLUS(u64,\
    \ mod << 1)\n DIFF(u64, 63, mod << 1)\n static CE IL u64 set(u64 n) { return n;\
    \ }\n CE IL u64 get(u64 n) const { NORM; }\n CE IL u64 norm(u64 n) const { NORM;\
    \ }\nprivate:\n const u64 x;\n CE IL u128 quo(const u128 &n) const { return (n\
    \ * x) >> 84; }\n CE IL u64 rem(const u128 &n) const { return n - quo(n) * mod;\
    \ }\n};\nstruct MP_D2B1 {\n const u64 mod;\n CE MP_D2B1(): mod(0), s(0), d(0),\
    \ v(0) {}\n CE MP_D2B1(u64 m): mod(m), s(__builtin_clzll(m)), d(m << s), v(u128(-1)\
    \ / d) {}\n CE IL u64 mul(u64 l, u64 r) const { return rem((u128(l) * r) << s)\
    \ >> s; }\n PLUS(u64, mod) DIFF(u64, 63, mod) SGN(u64) private: CE IL u64 rem(const\
    \ u128 &u) const {\n  u128 q= (u >> 64) * v + u;\n  u64 r= u64(u) - (q >> 64)\
    \ * d - d;\n  if (r > u64(q)) r+= d;\n  if (r >= d) r-= d;\n  return r;\n }\n\
    \ const u8 s;\n const u64 d, v;\n};\ntemplate <class u_t, class MP> CE u_t pow(u_t\
    \ x, u64 k, const MP &md) {\n for (u_t ret= md.set(1);; x= md.mul(x, x))\n  if\
    \ (k & 1 ? ret= md.mul(ret, x) : 0; !(k>>= 1)) return ret;\n}\n#undef NORM\n#undef\
    \ PLUS\n#undef DIFF\n#undef SGN\n#undef CE\n}\n#line 5 \"src/Math/ModInt.hpp\"\
    \nnamespace math_internal {\n#define CE constexpr\nstruct m_b {};\nstruct s_b:\
    \ m_b {};\ntemplate <class mod_t> CE bool is_modint_v= is_base_of_v<m_b, mod_t>;\n\
    template <class mod_t> CE bool is_staticmodint_v= is_base_of_v<s_b, mod_t>;\n\
    template <class MP, u64 MOD> struct SB: s_b {\nprotected:\n static CE MP md= MP(MOD);\n\
    };\ntemplate <class Int, class U, class B> struct MInt: public B {\n using Uint=\
    \ U;\n static CE inline auto mod() { return B::md.mod; }\n CE MInt(): x(0) {}\n\
    \ CE MInt(const MInt& r): x(r.x) {}\n template <class T, enable_if_t<is_modint_v<T>,\
    \ nullptr_t> = nullptr> CE MInt(T v): x(B::md.set(v.val() % B::md.mod)) {}\n template\
    \ <class T, enable_if_t<is_convertible_v<T, __int128_t>, nullptr_t> = nullptr>\
    \ CE MInt(T n): x(B::md.set((n < 0 ? B::md.mod - (-n) % B::md.mod : n % B::md.mod)))\
    \ {}\n CE MInt operator-() const { return MInt() - *this; }\n#define FUNC(name,\
    \ op) \\\n CE MInt name const { \\\n  MInt ret; \\\n  ret.x= op; \\\n  return\
    \ ret; \\\n }\n FUNC(operator+(const MInt& r), B::md.plus(x, r.x))\n FUNC(operator-(const\
    \ MInt& r), B::md.diff(x, r.x))\n FUNC(operator*(const MInt& r), B::md.mul(x,\
    \ r.x))\n FUNC(pow(u64 k), math_internal::pow(x, k, B::md))\n#undef FUNC\n CE\
    \ MInt operator/(const MInt& r) const { return *this * r.inv(); }\n CE MInt& operator+=(const\
    \ MInt& r) { return *this= *this + r; }\n CE MInt& operator-=(const MInt& r) {\
    \ return *this= *this - r; }\n CE MInt& operator*=(const MInt& r) { return *this=\
    \ *this * r; }\n CE MInt& operator/=(const MInt& r) { return *this= *this / r;\
    \ }\n CE bool operator==(const MInt& r) const { return B::md.norm(x) == B::md.norm(r.x);\
    \ }\n CE bool operator!=(const MInt& r) const { return !(*this == r); }\n CE bool\
    \ operator<(const MInt& r) const { return B::md.norm(x) < B::md.norm(r.x); }\n\
    \ CE inline MInt inv() const { return mod_inv<Int>(val(), B::md.mod); }\n CE inline\
    \ Uint val() const { return B::md.get(x); }\n friend ostream& operator<<(ostream&\
    \ os, const MInt& r) { return os << r.val(); }\n friend istream& operator>>(istream&\
    \ is, MInt& r) {\n  i64 v;\n  return is >> v, r= MInt(v), is;\n }\nprivate:\n\
    \ Uint x;\n};\ntemplate <u64 MOD> using ModInt= conditional_t < (MOD < (1 << 30))\
    \ & MOD, MInt<int, u32, SB<MP_Mo<u32, u64, 32, 31>, MOD>>, conditional_t<(MOD\
    \ < (1ull << 62)) & MOD, MInt<i64, u64, SB<MP_Mo<u64, u128, 64, 63>, MOD>>, conditional_t<MOD<INT_MAX,\
    \ MInt<int, u32, SB<MP_Na, MOD>>, conditional_t<MOD <= UINT_MAX, MInt<i64, u32,\
    \ SB<MP_Na, MOD>>, conditional_t<MOD <= (1ull << 41), MInt<i64, u64, SB<MP_Br2,\
    \ MOD>>, MInt<i64, u64, SB<MP_D2B1, MOD>>>>>>>;\n#undef CE\n}\nusing math_internal::ModInt,\
    \ math_internal::is_modint_v, math_internal::is_staticmodint_v;\ntemplate <class\
    \ mod_t, size_t LM> mod_t get_inv(int n) {\n static_assert(is_modint_v<mod_t>);\n\
    \ static const auto m= mod_t::mod();\n static mod_t dat[LM];\n static int l= 1;\n\
    \ if (l == 1) dat[l++]= 1;\n while (l <= n) dat[l++]= dat[m % l] * (m - m / l);\n\
    \ return dat[n];\n}\n#line 3 \"src/Math/hafnian.hpp\"\ntemplate <typename T, unsigned\
    \ short MAX_N= 38> T hafnian(const std::vector<std::vector<T>> &mat) {\n using\
    \ Poly= std::array<T, MAX_N / 2 + 1>;\n const int n= mat.size(), n2= n / 2;\n\
    \ assert(!(n & 1));\n for (int i= n; i--;)\n  for (int j= i; j--;) assert(mat[i][j]\
    \ == mat[j][i]);\n std::vector<std::vector<Poly>> a(n);\n for (int i= n, j; i--;)\n\
    \  for (a[j= i].resize(i); j--;) a[i][j][0]= mat[i][j];\n auto rec= [&](auto self,\
    \ const auto &b) -> Poly {\n  const int m= b.size() - 2;\n  if (m < 0) return\
    \ Poly{1};\n  auto c= b;\n  c.resize(m);\n  Poly r= self(self, c);\n  for (int\
    \ i= m; i--;)\n   for (int j= i; j--;)\n    for (int k= n2 - m / 2; k--;)\n  \
    \   for (int l= k; l >= 0; l--) c[i][j][k + 1]+= b[m][i][l] * b[m + 1][j][k -\
    \ l] + b[m + 1][i][l] * b[m][j][k - l];\n  Poly t= self(self, c);\n  for (int\
    \ i= n2, j; i >= 0; i--)\n   for (r[i]= t[j= i] - r[i]; j--;) r[i]+= t[j] * b[m\
    \ + 1][m][i - j - 1];\n  return r;\n };\n return rec(rec, a)[n2];\n}\n#line 5\
    \ \"test/yosupo/hafnian_of_matrix.test.cpp\"\nusing namespace std;\nsigned main()\
    \ {\n cin.tie(0);\n ios::sync_with_stdio(false);\n using Mint= ModInt<998244353>;\n\
    \ int N;\n cin >> N;\n vector a(N, vector<Mint>(N));\n for (int i= 0; i < N; i++)\n\
    \  for (int j= 0; j < N; j++) cin >> a[i][j];\n cout << hafnian(a) << '\\n';\n\
    \ return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/hafnian_of_matrix\"\n#include\
    \ <bits/stdc++.h>\n#include \"src/Math/ModInt.hpp\"\n#include \"src/Math/hafnian.hpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n\
    \ using Mint= ModInt<998244353>;\n int N;\n cin >> N;\n vector a(N, vector<Mint>(N));\n\
    \ for (int i= 0; i < N; i++)\n  for (int j= 0; j < N; j++) cin >> a[i][j];\n cout\
    \ << hafnian(a) << '\\n';\n return 0;\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Internal/Remainder.hpp
  - src/Math/hafnian.hpp
  isVerificationFile: true
  path: test/yosupo/hafnian_of_matrix.test.cpp
  requiredBy: []
  timestamp: '2023-01-15 15:10:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/hafnian_of_matrix.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/hafnian_of_matrix.test.cpp
- /verify/test/yosupo/hafnian_of_matrix.test.cpp.html
title: test/yosupo/hafnian_of_matrix.test.cpp
---