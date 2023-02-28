---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/BinaryIndexedTree_RangeAdd.hpp
    title: "Binary-Indexed-Tree(\u533A\u9593\u52A0\u7B97)"
  - icon: ':question:'
    path: src/Internal/Remainder.hpp
    title: "\u5270\u4F59\u306E\u9AD8\u901F\u5316"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':question:'
    path: src/Math/mod_inv.hpp
    title: "\u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)"
  - icon: ':question:'
    path: src/Misc/CartesianTree.hpp
    title: Cartesian-Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/arc115/tasks/arc115_e
    links:
    - https://atcoder.jp/contests/arc115/tasks/arc115_e
  bundledCode: "#line 1 \"test/atcoder/arc115_e.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/arc115/tasks/arc115_e\"\
    \n#include <iostream>\n#include <vector>\n#line 2 \"src/Math/mod_inv.hpp\"\n#include\
    \ <type_traits>\n#include <cassert>\ntemplate <class Int> constexpr inline Int\
    \ mod_inv(Int a, Int mod) {\n static_assert(std::is_signed_v<Int>);\n Int x= 1,\
    \ y= 0, b= mod;\n for (Int q= 0, z= 0, c= 0; b;) z= x, c= a, x= y, y= z - y *\
    \ (q= a / b), a= b, b= c - b * q;\n return assert(a == 1), x < 0 ? mod - (-x)\
    \ % mod : x % mod;\n}\n#line 2 \"src/Internal/Remainder.hpp\"\nnamespace math_internal\
    \ {\nusing namespace std;\nusing u8= uint8_t;\nusing u32= uint32_t;\nusing u64=\
    \ uint64_t;\nusing i64= int64_t;\nusing u128= __uint128_t;\n#define CE constexpr\n\
    #define IL inline\n#define NORM \\\n if (n >= mod) n-= mod; \\\n return n\n#define\
    \ PLUS(U, M) \\\n CE IL U plus(U l, U r) const { \\\n  if (l+= r; l >= M) l-=\
    \ M; \\\n  return l; \\\n }\n#define DIFF(U, C, M) \\\n CE IL U diff(U l, U r)\
    \ const { \\\n  if (l-= r; l >> C) l+= M; \\\n  return l; \\\n }\n#define SGN(U)\
    \ \\\n static CE IL U set(U n) { return n; } \\\n static CE IL U get(U n) { return\
    \ n; } \\\n static CE IL U norm(U n) { return n; }\ntemplate <class u_t, class\
    \ du_t, u8 B, u8 A> struct MP_Mo {\n u_t mod;\n CE MP_Mo(): mod(0), iv(0), r2(0)\
    \ {}\n CE MP_Mo(u_t m): mod(m), iv(inv(m)), r2(-du_t(mod) % mod) {}\n CE IL u_t\
    \ mul(u_t l, u_t r) const { return reduce(du_t(l) * r); }\n PLUS(u_t, mod << 1)\n\
    \ DIFF(u_t, A, mod << 1)\n CE IL u_t set(u_t n) const { return mul(n, r2); }\n\
    \ CE IL u_t get(u_t n) const {\n  n= reduce(n);\n  NORM;\n }\n CE IL u_t norm(u_t\
    \ n) const { NORM; }\nprivate:\n u_t iv, r2;\n static CE u_t inv(u_t n, int e=\
    \ 6, u_t x= 1) { return e ? inv(n, e - 1, x * (2 - x * n)) : x; }\n CE IL u_t\
    \ reduce(const du_t &w) const { return u_t(w >> B) + mod - ((du_t(u_t(w) * iv)\
    \ * mod) >> B); }\n};\nstruct MP_Na {\n u32 mod;\n CE MP_Na(): mod(0){};\n CE\
    \ MP_Na(u32 m): mod(m) {}\n CE IL u32 mul(u32 l, u32 r) const { return u64(l)\
    \ * r % mod; }\n PLUS(u32, mod) DIFF(u32, 31, mod) SGN(u32)\n};\nstruct MP_Br\
    \ {  // mod < 2^31\n u32 mod;\n CE MP_Br(): mod(0), s(0), x(0) {}\n CE MP_Br(u32\
    \ m): mod(m), s(__lg(m - 1) + 64), x(((u128(1) << s) + m - 1) / m) {}\n CE IL\
    \ u32 mul(u32 l, u32 r) const { return rem(u64(l) * r); }\n PLUS(u32, mod) DIFF(u32,\
    \ 31, mod) SGN(u32) private: u8 s;\n u64 x;\n CE IL u64 quo(u64 n) const { return\
    \ (u128(x) * n) >> s; }\n CE IL u32 rem(u64 n) const { return n - quo(n) * mod;\
    \ }\n};\nstruct MP_Br2 {  // 2^20 < mod <= 2^41\n u64 mod;\n CE MP_Br2(): mod(0),\
    \ x(0) {}\n CE MP_Br2(u64 m): mod(m), x((u128(1) << 84) / m) {}\n CE IL u64 mul(u64\
    \ l, u64 r) const { return rem(u128(l) * r); }\n PLUS(u64, mod << 1)\n DIFF(u64,\
    \ 63, mod << 1)\n static CE IL u64 set(u64 n) { return n; }\n CE IL u64 get(u64\
    \ n) const { NORM; }\n CE IL u64 norm(u64 n) const { NORM; }\nprivate:\n u64 x;\n\
    \ CE IL u128 quo(const u128 &n) const { return (n * x) >> 84; }\n CE IL u64 rem(const\
    \ u128 &n) const { return n - quo(n) * mod; }\n};\nstruct MP_D2B1 {\n u8 s;\n\
    \ u64 mod, d, v;\n CE MP_D2B1(): s(0), mod(0), d(0), v(0) {}\n CE MP_D2B1(u64\
    \ m): s(__builtin_clzll(m)), mod(m), d(m << s), v(u128(-1) / d) {}\n CE IL u64\
    \ mul(u64 l, u64 r) const { return rem((u128(l) * r) << s) >> s; }\n PLUS(u64,\
    \ mod) DIFF(u64, 63, mod) SGN(u64) private: CE IL u64 rem(const u128 &u) const\
    \ {\n  u128 q= (u >> 64) * v + u;\n  u64 r= u64(u) - (q >> 64) * d - d;\n  if\
    \ (r > u64(q)) r+= d;\n  if (r >= d) r-= d;\n  return r;\n }\n};\ntemplate <class\
    \ u_t, class MP> CE u_t pow(u_t x, u64 k, const MP &md) {\n for (u_t ret= md.set(1);;\
    \ x= md.mul(x, x))\n  if (k & 1 ? ret= md.mul(ret, x) : 0; !(k>>= 1)) return ret;\n\
    }\n#undef NORM\n#undef PLUS\n#undef DIFF\n#undef SGN\n#undef CE\n}\n#line 4 \"\
    src/Math/ModInt.hpp\"\nnamespace math_internal {\n#define CE constexpr\nstruct\
    \ m_b {};\nstruct s_b: m_b {};\ntemplate <class mod_t> CE bool is_modint_v= is_base_of_v<m_b,\
    \ mod_t>;\ntemplate <class mod_t> CE bool is_staticmodint_v= is_base_of_v<s_b,\
    \ mod_t>;\ntemplate <class MP, u64 MOD> struct SB: s_b {\nprotected:\n static\
    \ CE MP md= MP(MOD);\n};\ntemplate <class Int, class U, class B> struct MInt:\
    \ public B {\n using Uint= U;\n static CE inline auto mod() { return B::md.mod;\
    \ }\n CE MInt(): x(0) {}\n CE MInt(const MInt& r): x(r.x) {}\n template <class\
    \ T, enable_if_t<is_modint_v<T>, nullptr_t> = nullptr> CE MInt(T v): x(B::md.set(v.val()\
    \ % B::md.mod)) {}\n template <class T, enable_if_t<is_convertible_v<T, __int128_t>,\
    \ nullptr_t> = nullptr> CE MInt(T n): x(B::md.set((n < 0 ? ((n= (-n) % B::md.mod)\
    \ ? B::md.mod - n : n) : n % B::md.mod))) {}\n CE MInt operator-() const { return\
    \ MInt() - *this; }\n#define FUNC(name, op) \\\n CE MInt name const { \\\n  MInt\
    \ ret; \\\n  ret.x= op; \\\n  return ret; \\\n }\n FUNC(operator+(const MInt&\
    \ r), B::md.plus(x, r.x))\n FUNC(operator-(const MInt& r), B::md.diff(x, r.x))\n\
    \ FUNC(operator*(const MInt& r), B::md.mul(x, r.x))\n FUNC(pow(u64 k), math_internal::pow(x,\
    \ k, B::md))\n#undef FUNC\n CE MInt operator/(const MInt& r) const { return *this\
    \ * r.inv(); }\n CE MInt& operator+=(const MInt& r) { return *this= *this + r;\
    \ }\n CE MInt& operator-=(const MInt& r) { return *this= *this - r; }\n CE MInt&\
    \ operator*=(const MInt& r) { return *this= *this * r; }\n CE MInt& operator/=(const\
    \ MInt& r) { return *this= *this / r; }\n CE bool operator==(const MInt& r) const\
    \ { return B::md.norm(x) == B::md.norm(r.x); }\n CE bool operator!=(const MInt&\
    \ r) const { return !(*this == r); }\n CE bool operator<(const MInt& r) const\
    \ { return B::md.norm(x) < B::md.norm(r.x); }\n CE inline MInt inv() const { return\
    \ mod_inv<Int>(val(), B::md.mod); }\n CE inline Uint val() const { return B::md.get(x);\
    \ }\n friend ostream& operator<<(ostream& os, const MInt& r) { return os << r.val();\
    \ }\n friend istream& operator>>(istream& is, MInt& r) {\n  i64 v;\n  return is\
    \ >> v, r= MInt(v), is;\n }\nprivate:\n Uint x;\n};\ntemplate <u64 MOD> using\
    \ ModInt= conditional_t < (MOD < (1 << 30)) & MOD, MInt<int, u32, SB<MP_Mo<u32,\
    \ u64, 32, 31>, MOD>>, conditional_t < (MOD < (1ull << 62)) & MOD, MInt<i64, u64,\
    \ SB<MP_Mo<u64, u128, 64, 63>, MOD>>, conditional_t<MOD<(1u << 31), MInt<int,\
    \ u32, SB<MP_Na, MOD>>, conditional_t<MOD<(1ull << 32), MInt<i64, u32, SB<MP_Na,\
    \ MOD>>, conditional_t<MOD <= (1ull << 41), MInt<i64, u64, SB<MP_Br2, MOD>>, MInt<i64,\
    \ u64, SB<MP_D2B1, MOD>>>>>>>;\n#undef CE\n}\nusing math_internal::ModInt, math_internal::is_modint_v,\
    \ math_internal::is_staticmodint_v;\ntemplate <class mod_t, size_t LM> mod_t get_inv(int\
    \ n) {\n static_assert(is_modint_v<mod_t>);\n static const auto m= mod_t::mod();\n\
    \ static mod_t dat[LM];\n static int l= 1;\n if (l == 1) dat[l++]= 1;\n while\
    \ (l <= n) dat[l++]= dat[m % l] * (m - m / l);\n return dat[n];\n}\n#line 3 \"\
    src/Misc/CartesianTree.hpp\"\n#include <array>\nclass CartesianTree {\n std::vector<std::array<int,\
    \ 2>> rg, ch;\n std::vector<int> par;\n int rt;\npublic:\n template <class T>\
    \ CartesianTree(const std::vector<T>& a, bool is_min= 1): rg(a.size()), ch(a.size(),\
    \ std::array{-1, -1}), par(a.size(), -1) {\n  const int n= a.size();\n  auto comp=\
    \ [&](int l, int r) { return (is_min ? a[l] < a[r] : a[l] > a[r]) || (a[l] ==\
    \ a[r] && l < r); };\n  std::vector<int> st;\n  st.reserve(n);\n  for (int i=\
    \ 0; i < n; rg[i][0]= (st.empty() ? 0 : st.back() + 1), st.push_back(i++))\n \
    \  for (; !st.empty() && comp(i, st.back()); st.pop_back()) ch[i][0]= st.back();\n\
    \  st.clear();\n  for (int i= n; i--; rg[i][1]= (st.empty() ? n : st.back()),\
    \ st.push_back(i))\n   for (; !st.empty() && comp(i, st.back()); st.pop_back())\
    \ ch[i][1]= st.back();\n  for (int i= 0; i < n; ++i)\n   for (int b= 2; b--;)\n\
    \    if (ch[i][b] != -1) par[ch[i][b]]= i;\n  for (int i= 0; i < n; ++i)\n   if\
    \ (par[i] == -1) rt= i;\n }\n std::array<int, 2> children(int i) const { return\
    \ ch[i]; }\n int parent(int i) const { return par[i]; }\n int root() const { return\
    \ rt; }\n // [l,r)\n std::array<int, 2> range(int i) const { return rg[i]; }\n\
    };\n#line 3 \"src/DataStructure/BinaryIndexedTree_RangeAdd.hpp\"\ntemplate <typename\
    \ T> class BinaryIndexedTree_RangeAdd {\n std::vector<T> dat1, dat2;\npublic:\n\
    \ BinaryIndexedTree_RangeAdd(int n): dat1(n + 1, T()), dat2(n + 1, T()) {}\n void\
    \ add_range(int l, int r, T w) {  // add w [l,r)\n  int n= dat1.size();\n  for\
    \ (int k= l + 1; k < n; k+= k & -k) dat1[k]-= w * l;\n  for (int k= r + 1; k <\
    \ n; k+= k & -k) dat1[k]+= w * r;\n  for (int k= l + 1; k < n; k+= k & -k) dat2[k]+=\
    \ w;\n  for (int k= r + 1; k < n; k+= k & -k) dat2[k]-= w;\n }\n T sum(int x)\
    \ const {  // sum [0,x)\n  T s= 0;\n  for (int k= x; k; k&= k - 1) s+= dat2[k];\n\
    \  s*= x;\n  for (int k= x; k; k&= k - 1) s+= dat1[k];\n  return s;\n }\n T sum(int\
    \ l, int r) const { return sum(r) - sum(l); }  // sum [l,r)\n T operator[](size_t\
    \ k) const { return sum(k + 1) - sum(k); }\n};\n#line 7 \"test/atcoder/arc115_e.test.cpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ using Mint= ModInt<998244353>;\n int N;\n cin >> N;\n vector<int> A(N);\n for\
    \ (int i= 0; i < N; ++i) cin >> A[i];\n CartesianTree ct(A);\n array dp{BinaryIndexedTree_RangeAdd<Mint>(N\
    \ + 1), BinaryIndexedTree_RangeAdd<Mint>(N + 1)};\n dp[0].add_range(0, 1, 1);\n\
    \ for (int i= 0; i < N; ++i) {\n  auto [l, r]= ct.range(i);\n  for (int b= 0;\
    \ b < 2; ++b) dp[!b].add_range(i + 1, r + 1, dp[b].sum(l, i + 1) * A[i]);\n }\n\
    \ bool b= N & 1;\n cout << dp[b][N] - dp[!b][N] << '\\n';\n return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/arc115/tasks/arc115_e\"\n#include\
    \ <iostream>\n#include <vector>\n#include \"src/Math/ModInt.hpp\"\n#include \"\
    src/Misc/CartesianTree.hpp\"\n#include \"src/DataStructure/BinaryIndexedTree_RangeAdd.hpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ using Mint= ModInt<998244353>;\n int N;\n cin >> N;\n vector<int> A(N);\n for\
    \ (int i= 0; i < N; ++i) cin >> A[i];\n CartesianTree ct(A);\n array dp{BinaryIndexedTree_RangeAdd<Mint>(N\
    \ + 1), BinaryIndexedTree_RangeAdd<Mint>(N + 1)};\n dp[0].add_range(0, 1, 1);\n\
    \ for (int i= 0; i < N; ++i) {\n  auto [l, r]= ct.range(i);\n  for (int b= 0;\
    \ b < 2; ++b) dp[!b].add_range(i + 1, r + 1, dp[b].sum(l, i + 1) * A[i]);\n }\n\
    \ bool b= N & 1;\n cout << dp[b][N] - dp[!b][N] << '\\n';\n return 0;\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Internal/Remainder.hpp
  - src/Misc/CartesianTree.hpp
  - src/DataStructure/BinaryIndexedTree_RangeAdd.hpp
  isVerificationFile: true
  path: test/atcoder/arc115_e.test.cpp
  requiredBy: []
  timestamp: '2023-02-28 17:13:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/arc115_e.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/arc115_e.test.cpp
- /verify/test/atcoder/arc115_e.test.cpp.html
title: test/atcoder/arc115_e.test.cpp
---