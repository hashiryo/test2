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
    path: src/Math/is_prime.hpp
    title: "\u7D20\u6570\u5224\u5B9A"
  - icon: ':question:'
    path: src/Math/mod_inv.hpp
    title: "\u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)"
  - icon: ':heavy_check_mark:'
    path: src/Math/mod_sqrt.hpp
    title: "\u5E73\u65B9\u6839 ($\\mathbb{F}_p$)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc222_h.sparse_FPS.test.cpp
    title: test/atcoder/abc222_h.sparse_FPS.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc276_g.sparse_FPS.test.cpp
    title: test/atcoder/abc276_g.sparse_FPS.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/exp_of_sparse_FPS.test.cpp
    title: test/yosupo/exp_of_sparse_FPS.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/inv_of_sparse_FPS.test.cpp
    title: test/yosupo/inv_of_sparse_FPS.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/log_of_sparse_FPS.test.cpp
    title: test/yosupo/log_of_sparse_FPS.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/pow_of_sparse_FPS.test.cpp
    title: test/yosupo/pow_of_sparse_FPS.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sqrt_of_sparse_FPS.test.cpp
    title: test/yosupo/sqrt_of_sparse_FPS.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1080.sparse_FPS.test.cpp
    title: test/yukicoder/1080.sparse_FPS.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1533.test.cpp
    title: test/yukicoder/1533.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1939.test.cpp
    title: test/yukicoder/1939.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Math/sparse_fps.hpp\"\n#include <bits/stdc++.h>\n#line\
    \ 3 \"src/Math/mod_inv.hpp\"\ntemplate <class Int> constexpr inline Int mod_inv(Int\
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
    \ return dat[n];\n}\n#line 4 \"src/Math/is_prime.hpp\"\nnamespace math_internal\
    \ {\ntemplate <class Uint, class MP, u64... args> constexpr bool miller_rabin(Uint\
    \ n) {\n const MP md(n);\n const Uint s= __builtin_ctzll(n - 1), d= n >> s, one=\
    \ md.set(1), n1= md.norm(md.set(n - 1));\n for (auto a: {args...})\n  if (Uint\
    \ b= a % n; b)\n   if (Uint p= md.norm(pow(md.set(b), d, md)); p != one)\n   \
    \ for (int i= s; p != n1; p= md.norm(md.mul(p, p)))\n     if (!(--i)) return 0;\n\
    \ return 1;\n}\nconstexpr bool is_prime(u64 n) {\n if (n < 2 || n % 6 % 4 != 1)\
    \ return (n | 1) == 3;\n if (n < (1 << 30)) return miller_rabin<u32, MP_Mo<u32,\
    \ u64, 32, 31>, 2, 7, 61>(n);\n if (n < (1ull << 62)) return miller_rabin<u64,\
    \ MP_Mo<u64, u128, 64, 63>, 2, 325, 9375, 28178, 450775, 9780504, 1795265022>(n);\n\
    \ return miller_rabin<u64, MP_D2B1, 2, 325, 9375, 28178, 450775, 9780504, 1795265022>(n);\n\
    }\n}\nusing math_internal::is_prime;\n#line 4 \"src/Math/mod_sqrt.hpp\"\nnamespace\
    \ math_internal {\ntemplate <class Int, class MP> constexpr i64 inner_sqrt(Int\
    \ a, Int p) {\n const MP md(p);\n Int e= (p - 1) >> 1, one= md.set(1);\n if (a=\
    \ md.set(a); md.norm(pow(a, e, md)) != one) return -1;\n Int b= 0, d= md.diff(0,\
    \ a), ret= one, r2= 0, b2= one;\n while (md.norm(pow(d, e, md)) == one) b= md.plus(b,\
    \ one), d= md.diff(md.mul(b, b), a);\n auto mult= [&md, d](Int &u1, Int &u2, Int\
    \ v1, Int v2) {\n  Int tmp= md.plus(md.mul(u1, v1), md.mul(md.mul(u2, v2), d));\n\
    \  u2= md.plus(md.mul(u1, v2), md.mul(u2, v1)), u1= tmp;\n };\n for (++e;; mult(b,\
    \ b2, b, b2)) {\n  if (e & 1) mult(ret, r2, b, b2);\n  if (!(e>>= 1)) return ret=\
    \ md.get(ret), ret * 2 < p ? ret : p - ret;\n }\n}\nconstexpr i64 mod_sqrt(i64\
    \ a, i64 p) {\n assert(p > 0), assert(a >= 0), assert(is_prime(p)), a%= p;\n if\
    \ (a <= 1 || p == 2) return a;\n if (p < (1 << 30)) return inner_sqrt<u32, MP_Mo<u32,\
    \ u64, 32, 31>>(a, p);\n if (p < (1ll << 62)) return inner_sqrt<u64, MP_Mo<u64,\
    \ u128, 64, 63>>(a, p);\n return inner_sqrt<u64, MP_D2B1>(a, p);\n}\n}\nusing\
    \ math_internal::mod_sqrt;\n#line 5 \"src/Math/sparse_fps.hpp\"\ntemplate <class\
    \ K> std::vector<K> sparse_inv(const std::vector<K> &f, int n) {\n assert(f[0]\
    \ != K(0));\n std::vector<std::pair<int, K>> dat;\n for (int i= 1, ed= std::min<int>(n,\
    \ f.size()); i < ed; ++i)\n  if (f[i] != K(0)) dat.emplace_back(i, f[i]);\n std::vector<K>\
    \ ret(n);\n const K iv= ret[0]= K(1) / f[0];\n for (int i= 1; i < n; ret[i++]*=\
    \ iv)\n  for (auto &&[j, v]: dat) {\n   if (i < j) break;\n   ret[i]-= ret[i -\
    \ j] * v;\n  }\n return ret;\n}\ntemplate <class K> std::vector<K> sparse_div(std::vector<K>\
    \ f, const std::vector<K> &g, int n) {\n assert(g[0] != K(0));\n std::vector<std::pair<int,\
    \ K>> dat;\n for (int i= 1, ed= std::min<int>(n, g.size()); i < ed; ++i)\n  if\
    \ (g[i] != K(0)) dat.emplace_back(i, g[i]);\n f.resize(n);\n const K iv= K(1)\
    \ / g[0];\n for (int i= 0; i < n; f[i++]*= iv)\n  for (auto &&[j, v]: dat) {\n\
    \   if (i < j) break;\n   f[i]-= f[i - j] * v;\n  }\n return f;\n}\ntemplate <class\
    \ mod_t, std::size_t LM= 1 << 24> std::vector<mod_t> sparse_log(const std::vector<mod_t>\
    \ &f, int n) {\n assert(f[0] == mod_t(1));\n std::vector<mod_t> df(n - 1);\n for\
    \ (int i= 1, ed= std::min<int>(n, f.size()); i < ed; ++i) df[i - 1]+= f[i] * i;\n\
    \ df= sparse_div(df, f, n - 1);\n std::vector<mod_t> ret(n);\n for (int i= 1;\
    \ i < n; ++i) ret[i]= df[i - 1] * get_inv<mod_t, LM>(i);\n return ret;\n}\ntemplate\
    \ <class mod_t, std::size_t LM= 1 << 24> std::vector<mod_t> sparse_exp(const std::vector<mod_t>\
    \ &f, int n) {\n assert(f[0] == mod_t(0));\n std::vector<std::pair<int, mod_t>>\
    \ dat;\n for (int i= 1, ed= std::min<int>(n, f.size()); i < ed; ++i)\n  if (f[i]\
    \ != mod_t(0)) dat.emplace_back(i - 1, f[i] * i);\n std::vector<mod_t> ret(n);\n\
    \ ret[0]= 1;\n for (int i= 1; i < n; ret[i]*= get_inv<mod_t, LM>(i), ++i)\n  for\
    \ (auto &&[j, v]: dat) {\n   if (i <= j) break;\n   ret[i]+= ret[i - 1 - j] *\
    \ v;\n  }\n return ret;\n}\ntemplate <class mod_t, std::size_t LM= 1 << 24> std::vector<mod_t>\
    \ sparse_pow(const std::vector<mod_t> &f, std::uint64_t k, int n) {\n std::vector<mod_t>\
    \ ret(n);\n if (k == 0) return ret[0]= 1, ret;\n int cnt= 0, ed= std::min<int>(n,\
    \ f.size());\n while (cnt < ed && f[cnt] == mod_t(0)) cnt++;\n const __int128_t\
    \ ofs= (__int128_t)k * cnt, sz= n - ofs;\n if (sz <= 0) return ret;\n std::vector<std::pair<int,\
    \ mod_t>> dat;\n for (int i= cnt + 1; i < ed; ++i)\n  if (f[i] != mod_t(0)) dat.emplace_back(i\
    \ - cnt, f[i]);\n mod_t *bf= ret.data() + k * cnt, mk= k, iv= mod_t(1) / f[cnt];\n\
    \ bf[0]= f[cnt].pow(k);\n for (int i= 1; i < sz; bf[i]*= get_inv<mod_t, LM>(i)\
    \ * iv, ++i)\n  for (auto &&[j, v]: dat) {\n   if (i < j) break;\n   bf[i]+= v\
    \ * (mk * j - (i - j)) * bf[i - j];\n  }\n return ret;\n}\ntemplate <class mod_t,\
    \ std::size_t LM= 1 << 24> std::vector<mod_t> sparse_sqrt(const std::vector<mod_t>\
    \ &f, int n) {\n std::vector<mod_t> ret(n);\n int cnt= 0, ed= std::min<int>(n,\
    \ f.size());\n while (cnt < ed && f[cnt] == mod_t(0)) cnt++;\n if (cnt == ed)\
    \ return ret;\n if (cnt & 1) return {};  // no solution\n const int ofs= cnt >>\
    \ 1, sz= n - ofs;\n std::vector<std::pair<int, mod_t>> dat;\n for (int i= cnt\
    \ + 1; i < ed; ++i)\n  if (f[i] != mod_t(0)) dat.emplace_back(i - cnt, f[i]);\n\
    \ mod_t *bf= ret.data() + ofs, mk= mod_t(1) / 2, iv= mod_t(1) / f[cnt];\n bf[0]=\
    \ mod_sqrt(f[cnt].val(), mod_t::mod());\n if (bf[0] * bf[0] != f[cnt]) return\
    \ {};  // no solution\n for (int i= 1; i < sz; bf[i]*= get_inv<mod_t, LM>(i) *\
    \ iv, ++i)\n  for (auto &&[j, v]: dat) {\n   if (i < j) break;\n   bf[i]+= v *\
    \ (mk * j - (i - j)) * bf[i - j];\n  }\n return ret;\n}\n// F'/F = f(x)/g(x),\
    \ F[0]=1\ntemplate <class mod_t, std::size_t LM= 1 << 24> std::vector<mod_t> sparse_log_differentiation(const\
    \ std::vector<mod_t> &f, const std::vector<mod_t> &g, int n) {\n assert(g[0] ==\
    \ mod_t(1));\n std::vector<std::pair<int, mod_t>> dat_f, dat_g;\n for (int i=\
    \ 0, ed= std::min<int>(f.size(), n); i < ed; ++i)\n  if (f[i] != mod_t(0)) dat_f.emplace_back(i,\
    \ f[i]);\n for (int i= 1, ed= std::min<int>(g.size(), n); i < ed; ++i)\n  if (g[i]\
    \ != mod_t(0)) dat_g.emplace_back(i, g[i]);\n std::vector<mod_t> ret(n), d(n -\
    \ 1);\n ret[0]= 1;\n for (int i= 0; i < n - 1; ++i) {\n  for (auto &&[j, v]: dat_g)\
    \ {\n   if (i < j) break;\n   d[i]-= v * d[i - j];\n  }\n  for (auto &&[j, v]:\
    \ dat_f) {\n   if (i < j) break;\n   d[i]+= v * ret[i - j];\n  }\n  ret[i + 1]=\
    \ d[i] * get_inv<mod_t, LM>(i + 1);\n }\n return ret;\n}\ntemplate <class mod_t,\
    \ std::size_t LM= 1 << 24>  // exp(f/g)\nstd::vector<mod_t> sparse_exp_of_div(const\
    \ std::vector<mod_t> &f, const std::vector<mod_t> &g, int n) {\n assert(f[0] ==\
    \ mod_t(0)), assert(g[0] == mod_t(1));\n std::vector<std::pair<int, mod_t>> dat_f,\
    \ dat_g;\n for (int i= 1, ed= std::min<int>(f.size(), n); i < ed; ++i)\n  if (f[i]\
    \ != mod_t(0)) dat_f.emplace_back(i, f[i]);\n for (int i= 0, ed= std::min<int>(g.size(),\
    \ n); i < ed; ++i)\n  if (g[i] != mod_t(0)) dat_g.emplace_back(i, g[i]);\n std::vector<mod_t>\
    \ a(f.size() + g.size() - 2), b(2 * g.size() - 1);\n for (auto &&[i, x]: dat_f)\n\
    \  for (auto &&[j, y]: dat_g)\n   if (i || j) a[i + j - 1]+= x * y * (i - j);\n\
    \ for (auto &&[i, x]: dat_g)\n  for (auto &&[j, y]: dat_g) b[i + j]+= x * y; \
    \ // a = f'g-fg', b = g^2\n return sparse_log_differentiation<mod_t, LM>(a, b,\
    \ n);\n}\ntemplate <class mod_t, std::size_t LM= 1 << 24>  // (f/g)^k\nstd::vector<mod_t>\
    \ sparse_pow_of_div(const std::vector<mod_t> &f, const std::vector<mod_t> &g,\
    \ std::uint64_t k, int n) {\n assert(f[0] == mod_t(1)), assert(g[0] == mod_t(1));\n\
    \ std::vector<std::pair<int, mod_t>> dat_f, dat_g;\n for (int i= 0, ed= std::min<int>(f.size(),\
    \ n); i < ed; ++i)\n  if (f[i] != mod_t(0)) dat_f.emplace_back(i, f[i]);\n for\
    \ (int i= 0, ed= std::min<int>(g.size(), n); i < ed; ++i)\n  if (g[i] != mod_t(0))\
    \ dat_g.emplace_back(i, g[i]);\n std::vector<mod_t> a(f.size() + g.size() - 2),\
    \ b(2 * g.size() - 1);\n for (auto &&[i, x]: dat_f)\n  for (auto &&[j, y]: dat_g)\n\
    \   if (i || j) a[i + j - 1]+= x * y * (i - j) * k;\n for (auto &&[i, x]: dat_f)\n\
    \  for (auto &&[j, y]: dat_g) b[i + j]+= x * y;  // a = k(f'g-fg'), b = fg\n return\
    \ sparse_log_differentiation<mod_t, LM>(a, b, n);\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"src/Math/ModInt.hpp\"\n\
    #include \"src/Math/mod_sqrt.hpp\"\ntemplate <class K> std::vector<K> sparse_inv(const\
    \ std::vector<K> &f, int n) {\n assert(f[0] != K(0));\n std::vector<std::pair<int,\
    \ K>> dat;\n for (int i= 1, ed= std::min<int>(n, f.size()); i < ed; ++i)\n  if\
    \ (f[i] != K(0)) dat.emplace_back(i, f[i]);\n std::vector<K> ret(n);\n const K\
    \ iv= ret[0]= K(1) / f[0];\n for (int i= 1; i < n; ret[i++]*= iv)\n  for (auto\
    \ &&[j, v]: dat) {\n   if (i < j) break;\n   ret[i]-= ret[i - j] * v;\n  }\n return\
    \ ret;\n}\ntemplate <class K> std::vector<K> sparse_div(std::vector<K> f, const\
    \ std::vector<K> &g, int n) {\n assert(g[0] != K(0));\n std::vector<std::pair<int,\
    \ K>> dat;\n for (int i= 1, ed= std::min<int>(n, g.size()); i < ed; ++i)\n  if\
    \ (g[i] != K(0)) dat.emplace_back(i, g[i]);\n f.resize(n);\n const K iv= K(1)\
    \ / g[0];\n for (int i= 0; i < n; f[i++]*= iv)\n  for (auto &&[j, v]: dat) {\n\
    \   if (i < j) break;\n   f[i]-= f[i - j] * v;\n  }\n return f;\n}\ntemplate <class\
    \ mod_t, std::size_t LM= 1 << 24> std::vector<mod_t> sparse_log(const std::vector<mod_t>\
    \ &f, int n) {\n assert(f[0] == mod_t(1));\n std::vector<mod_t> df(n - 1);\n for\
    \ (int i= 1, ed= std::min<int>(n, f.size()); i < ed; ++i) df[i - 1]+= f[i] * i;\n\
    \ df= sparse_div(df, f, n - 1);\n std::vector<mod_t> ret(n);\n for (int i= 1;\
    \ i < n; ++i) ret[i]= df[i - 1] * get_inv<mod_t, LM>(i);\n return ret;\n}\ntemplate\
    \ <class mod_t, std::size_t LM= 1 << 24> std::vector<mod_t> sparse_exp(const std::vector<mod_t>\
    \ &f, int n) {\n assert(f[0] == mod_t(0));\n std::vector<std::pair<int, mod_t>>\
    \ dat;\n for (int i= 1, ed= std::min<int>(n, f.size()); i < ed; ++i)\n  if (f[i]\
    \ != mod_t(0)) dat.emplace_back(i - 1, f[i] * i);\n std::vector<mod_t> ret(n);\n\
    \ ret[0]= 1;\n for (int i= 1; i < n; ret[i]*= get_inv<mod_t, LM>(i), ++i)\n  for\
    \ (auto &&[j, v]: dat) {\n   if (i <= j) break;\n   ret[i]+= ret[i - 1 - j] *\
    \ v;\n  }\n return ret;\n}\ntemplate <class mod_t, std::size_t LM= 1 << 24> std::vector<mod_t>\
    \ sparse_pow(const std::vector<mod_t> &f, std::uint64_t k, int n) {\n std::vector<mod_t>\
    \ ret(n);\n if (k == 0) return ret[0]= 1, ret;\n int cnt= 0, ed= std::min<int>(n,\
    \ f.size());\n while (cnt < ed && f[cnt] == mod_t(0)) cnt++;\n const __int128_t\
    \ ofs= (__int128_t)k * cnt, sz= n - ofs;\n if (sz <= 0) return ret;\n std::vector<std::pair<int,\
    \ mod_t>> dat;\n for (int i= cnt + 1; i < ed; ++i)\n  if (f[i] != mod_t(0)) dat.emplace_back(i\
    \ - cnt, f[i]);\n mod_t *bf= ret.data() + k * cnt, mk= k, iv= mod_t(1) / f[cnt];\n\
    \ bf[0]= f[cnt].pow(k);\n for (int i= 1; i < sz; bf[i]*= get_inv<mod_t, LM>(i)\
    \ * iv, ++i)\n  for (auto &&[j, v]: dat) {\n   if (i < j) break;\n   bf[i]+= v\
    \ * (mk * j - (i - j)) * bf[i - j];\n  }\n return ret;\n}\ntemplate <class mod_t,\
    \ std::size_t LM= 1 << 24> std::vector<mod_t> sparse_sqrt(const std::vector<mod_t>\
    \ &f, int n) {\n std::vector<mod_t> ret(n);\n int cnt= 0, ed= std::min<int>(n,\
    \ f.size());\n while (cnt < ed && f[cnt] == mod_t(0)) cnt++;\n if (cnt == ed)\
    \ return ret;\n if (cnt & 1) return {};  // no solution\n const int ofs= cnt >>\
    \ 1, sz= n - ofs;\n std::vector<std::pair<int, mod_t>> dat;\n for (int i= cnt\
    \ + 1; i < ed; ++i)\n  if (f[i] != mod_t(0)) dat.emplace_back(i - cnt, f[i]);\n\
    \ mod_t *bf= ret.data() + ofs, mk= mod_t(1) / 2, iv= mod_t(1) / f[cnt];\n bf[0]=\
    \ mod_sqrt(f[cnt].val(), mod_t::mod());\n if (bf[0] * bf[0] != f[cnt]) return\
    \ {};  // no solution\n for (int i= 1; i < sz; bf[i]*= get_inv<mod_t, LM>(i) *\
    \ iv, ++i)\n  for (auto &&[j, v]: dat) {\n   if (i < j) break;\n   bf[i]+= v *\
    \ (mk * j - (i - j)) * bf[i - j];\n  }\n return ret;\n}\n// F'/F = f(x)/g(x),\
    \ F[0]=1\ntemplate <class mod_t, std::size_t LM= 1 << 24> std::vector<mod_t> sparse_log_differentiation(const\
    \ std::vector<mod_t> &f, const std::vector<mod_t> &g, int n) {\n assert(g[0] ==\
    \ mod_t(1));\n std::vector<std::pair<int, mod_t>> dat_f, dat_g;\n for (int i=\
    \ 0, ed= std::min<int>(f.size(), n); i < ed; ++i)\n  if (f[i] != mod_t(0)) dat_f.emplace_back(i,\
    \ f[i]);\n for (int i= 1, ed= std::min<int>(g.size(), n); i < ed; ++i)\n  if (g[i]\
    \ != mod_t(0)) dat_g.emplace_back(i, g[i]);\n std::vector<mod_t> ret(n), d(n -\
    \ 1);\n ret[0]= 1;\n for (int i= 0; i < n - 1; ++i) {\n  for (auto &&[j, v]: dat_g)\
    \ {\n   if (i < j) break;\n   d[i]-= v * d[i - j];\n  }\n  for (auto &&[j, v]:\
    \ dat_f) {\n   if (i < j) break;\n   d[i]+= v * ret[i - j];\n  }\n  ret[i + 1]=\
    \ d[i] * get_inv<mod_t, LM>(i + 1);\n }\n return ret;\n}\ntemplate <class mod_t,\
    \ std::size_t LM= 1 << 24>  // exp(f/g)\nstd::vector<mod_t> sparse_exp_of_div(const\
    \ std::vector<mod_t> &f, const std::vector<mod_t> &g, int n) {\n assert(f[0] ==\
    \ mod_t(0)), assert(g[0] == mod_t(1));\n std::vector<std::pair<int, mod_t>> dat_f,\
    \ dat_g;\n for (int i= 1, ed= std::min<int>(f.size(), n); i < ed; ++i)\n  if (f[i]\
    \ != mod_t(0)) dat_f.emplace_back(i, f[i]);\n for (int i= 0, ed= std::min<int>(g.size(),\
    \ n); i < ed; ++i)\n  if (g[i] != mod_t(0)) dat_g.emplace_back(i, g[i]);\n std::vector<mod_t>\
    \ a(f.size() + g.size() - 2), b(2 * g.size() - 1);\n for (auto &&[i, x]: dat_f)\n\
    \  for (auto &&[j, y]: dat_g)\n   if (i || j) a[i + j - 1]+= x * y * (i - j);\n\
    \ for (auto &&[i, x]: dat_g)\n  for (auto &&[j, y]: dat_g) b[i + j]+= x * y; \
    \ // a = f'g-fg', b = g^2\n return sparse_log_differentiation<mod_t, LM>(a, b,\
    \ n);\n}\ntemplate <class mod_t, std::size_t LM= 1 << 24>  // (f/g)^k\nstd::vector<mod_t>\
    \ sparse_pow_of_div(const std::vector<mod_t> &f, const std::vector<mod_t> &g,\
    \ std::uint64_t k, int n) {\n assert(f[0] == mod_t(1)), assert(g[0] == mod_t(1));\n\
    \ std::vector<std::pair<int, mod_t>> dat_f, dat_g;\n for (int i= 0, ed= std::min<int>(f.size(),\
    \ n); i < ed; ++i)\n  if (f[i] != mod_t(0)) dat_f.emplace_back(i, f[i]);\n for\
    \ (int i= 0, ed= std::min<int>(g.size(), n); i < ed; ++i)\n  if (g[i] != mod_t(0))\
    \ dat_g.emplace_back(i, g[i]);\n std::vector<mod_t> a(f.size() + g.size() - 2),\
    \ b(2 * g.size() - 1);\n for (auto &&[i, x]: dat_f)\n  for (auto &&[j, y]: dat_g)\n\
    \   if (i || j) a[i + j - 1]+= x * y * (i - j) * k;\n for (auto &&[i, x]: dat_f)\n\
    \  for (auto &&[j, y]: dat_g) b[i + j]+= x * y;  // a = k(f'g-fg'), b = fg\n return\
    \ sparse_log_differentiation<mod_t, LM>(a, b, n);\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Internal/Remainder.hpp
  - src/Math/mod_sqrt.hpp
  - src/Math/is_prime.hpp
  isVerificationFile: false
  path: src/Math/sparse_fps.hpp
  requiredBy: []
  timestamp: '2023-01-17 13:31:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/pow_of_sparse_FPS.test.cpp
  - test/yosupo/sqrt_of_sparse_FPS.test.cpp
  - test/yosupo/inv_of_sparse_FPS.test.cpp
  - test/yosupo/log_of_sparse_FPS.test.cpp
  - test/yosupo/exp_of_sparse_FPS.test.cpp
  - test/yukicoder/1080.sparse_FPS.test.cpp
  - test/yukicoder/1939.test.cpp
  - test/yukicoder/1533.test.cpp
  - test/atcoder/abc276_g.sparse_FPS.test.cpp
  - test/atcoder/abc222_h.sparse_FPS.test.cpp
documentation_of: src/Math/sparse_fps.hpp
layout: document
title: "\u758E\u306A\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570"
---
## 参考
[https://maspypy.com/多項式・形式的べき級数-高速に計算できるもの](https://maspypy.com/%E5%A4%9A%E9%A0%85%E5%BC%8F%E3%83%BB%E5%BD%A2%E5%BC%8F%E7%9A%84%E3%81%B9%E3%81%8D%E7%B4%9A%E6%95%B0-%E9%AB%98%E9%80%9F%E3%81%AB%E8%A8%88%E7%AE%97%E3%81%A7%E3%81%8D%E3%82%8B%E3%82%82%E3%81%AE)