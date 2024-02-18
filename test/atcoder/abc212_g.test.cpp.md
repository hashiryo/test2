---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/Internal/Remainder.hpp
    title: "\u5270\u4F59\u306E\u9AD8\u901F\u5316"
  - icon: ':question:'
    path: src/Internal/modint_traits.hpp
    title: "modint\u3092\u6271\u3046\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':question:'
    path: src/Math/binary_gcd.hpp
    title: Binary GCD
  - icon: ':question:'
    path: src/Math/mod_inv.hpp
    title: "\u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)"
  - icon: ':question:'
    path: src/NumberTheory/ArrayOnDivisors.hpp
    title: "\u7D04\u6570\u914D\u5217"
  - icon: ':question:'
    path: src/NumberTheory/Factors.hpp
    title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3\u306A\u3069"
  - icon: ':question:'
    path: src/NumberTheory/is_prime.hpp
    title: "\u7D20\u6570\u5224\u5B9A"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc212/tasks/abc212_g
    links:
    - https://atcoder.jp/contests/abc212/tasks/abc212_g
  bundledCode: "#line 1 \"test/atcoder/abc212_g.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc212/tasks/abc212_g\"\
    \n#include <iostream>\n#line 2 \"src/Math/mod_inv.hpp\"\n#include <type_traits>\n\
    #include <cassert>\ntemplate <class Int> constexpr inline Int mod_inv(Int a, Int\
    \ mod) {\n static_assert(std::is_signed_v<Int>);\n Int x= 1, y= 0, b= mod;\n for\
    \ (Int q= 0, z= 0; b;) z= x, x= y, y= z - y * (q= a / b), z= a, a= b, b= z - b\
    \ * q;\n return assert(a == 1), x < 0 ? mod - (-x) % mod : x % mod;\n}\n#line\
    \ 2 \"src/Internal/Remainder.hpp\"\nnamespace math_internal {\nusing namespace\
    \ std;\nusing u8= unsigned char;\nusing u32= unsigned;\nusing i64= long long;\n\
    using u64= unsigned long long;\nusing u128= __uint128_t;\n#define CE constexpr\n\
    #define IL inline\n#define NORM \\\n if (n >= mod) n-= mod; \\\n return n\n#define\
    \ PLUS(U, M) \\\n CE IL U plus(U l, U r) const { return l+= r, l < (M) ? l : l\
    \ - (M); }\n#define DIFF(U, C, M) \\\n CE IL U diff(U l, U r) const { return l-=\
    \ r, l >> C ? l + (M) : l; }\n#define SGN(U) \\\n static CE IL U set(U n) { return\
    \ n; } \\\n static CE IL U get(U n) { return n; } \\\n static CE IL U norm(U n)\
    \ { return n; }\ntemplate <class u_t, class du_t, u8 B, u8 A> struct MP_Mo {\n\
    \ u_t mod;\n CE MP_Mo(): mod(0), iv(0), r2(0) {}\n CE MP_Mo(u_t m): mod(m), iv(inv(m)),\
    \ r2(-du_t(mod) % mod) {}\n CE IL u_t mul(u_t l, u_t r) const { return reduce(du_t(l)\
    \ * r); }\n PLUS(u_t, mod << 1)\n DIFF(u_t, A, mod << 1)\n CE IL u_t set(u_t n)\
    \ const { return mul(n, r2); }\n CE IL u_t get(u_t n) const {\n  n= reduce(n);\n\
    \  NORM;\n }\n CE IL u_t norm(u_t n) const { NORM; }\nprivate:\n u_t iv, r2;\n\
    \ static CE u_t inv(u_t n, int e= 6, u_t x= 1) { return e ? inv(n, e - 1, x *\
    \ (2 - x * n)) : x; }\n CE IL u_t reduce(const du_t &w) const { return u_t(w >>\
    \ B) + mod - ((du_t(u_t(w) * iv) * mod) >> B); }\n};\nstruct MP_Na {\n u32 mod;\n\
    \ CE MP_Na(): mod(0){};\n CE MP_Na(u32 m): mod(m) {}\n CE IL u32 mul(u32 l, u32\
    \ r) const { return u64(l) * r % mod; }\n PLUS(u32, mod) DIFF(u32, 31, mod) SGN(u32)\n\
    };\nstruct MP_Br {  // mod < 2^31\n u32 mod;\n CE MP_Br(): mod(0), s(0), x(0)\
    \ {}\n CE MP_Br(u32 m): mod(m), s(95 - __builtin_clz(m - 1)), x(((u128(1) << s)\
    \ + m - 1) / m) {}\n CE IL u32 mul(u32 l, u32 r) const { return rem(u64(l) * r);\
    \ }\n PLUS(u32, mod) DIFF(u32, 31, mod) SGN(u32) private: u8 s;\n u64 x;\n CE\
    \ IL u64 quo(u64 n) const { return (u128(x) * n) >> s; }\n CE IL u32 rem(u64 n)\
    \ const { return n - quo(n) * mod; }\n};\nstruct MP_Br2 {  // 2^20 < mod <= 2^41\n\
    \ u64 mod;\n CE MP_Br2(): mod(0), x(0) {}\n CE MP_Br2(u64 m): mod(m), x((u128(1)\
    \ << 84) / m) {}\n CE IL u64 mul(u64 l, u64 r) const { return rem(u128(l) * r);\
    \ }\n PLUS(u64, mod << 1)\n DIFF(u64, 63, mod << 1)\n static CE IL u64 set(u64\
    \ n) { return n; }\n CE IL u64 get(u64 n) const { NORM; }\n CE IL u64 norm(u64\
    \ n) const { NORM; }\nprivate:\n u64 x;\n CE IL u128 quo(const u128 &n) const\
    \ { return (n * x) >> 84; }\n CE IL u64 rem(const u128 &n) const { return n -\
    \ quo(n) * mod; }\n};\nstruct MP_D2B1 {\n u8 s;\n u64 mod, d, v;\n CE MP_D2B1():\
    \ s(0), mod(0), d(0), v(0) {}\n CE MP_D2B1(u64 m): s(__builtin_clzll(m)), mod(m),\
    \ d(m << s), v(u128(-1) / d) {}\n CE IL u64 mul(u64 l, u64 r) const { return rem((u128(l)\
    \ * r) << s) >> s; }\n PLUS(u64, mod) DIFF(u64, 63, mod) SGN(u64) private: CE\
    \ IL u64 rem(const u128 &u) const {\n  u128 q= (u >> 64) * v + u;\n  u64 r= u64(u)\
    \ - (q >> 64) * d - d;\n  if (r > u64(q)) r+= d;\n  if (r >= d) r-= d;\n  return\
    \ r;\n }\n};\ntemplate <class u_t, class MP> CE u_t pow(u_t x, u64 k, const MP\
    \ &md) {\n for (u_t ret= md.set(1);; x= md.mul(x, x))\n  if (k & 1 ? ret= md.mul(ret,\
    \ x) : 0; !(k>>= 1)) return ret;\n}\n#undef NORM\n#undef PLUS\n#undef DIFF\n#undef\
    \ SGN\n#undef CE\n}\n#line 3 \"src/Internal/modint_traits.hpp\"\nnamespace math_internal\
    \ {\nstruct m_b {};\nstruct s_b: m_b {};\n}\ntemplate <class mod_t> constexpr\
    \ bool is_modint_v= std::is_base_of_v<math_internal::m_b, mod_t>;\ntemplate <class\
    \ mod_t> constexpr bool is_staticmodint_v= std::is_base_of_v<math_internal::s_b,\
    \ mod_t>;\n#line 5 \"src/Math/ModInt.hpp\"\nnamespace math_internal {\n#define\
    \ CE constexpr\ntemplate <class MP, u64 MOD> struct SB: s_b {\nprotected:\n static\
    \ CE MP md= MP(MOD);\n};\ntemplate <class Int, class U, class B> struct MInt:\
    \ public B {\n using Uint= U;\n static CE inline auto mod() { return B::md.mod;\
    \ }\n CE MInt(): x(0) {}\n template <class T, typename= enable_if_t<is_modint_v<T>\
    \ && !is_same_v<T, MInt>>> CE MInt(T v): x(B::md.set(v.val() % B::md.mod)) {}\n\
    \ CE MInt(__int128_t n): x(B::md.set((n < 0 ? ((n= (-n) % B::md.mod) ? B::md.mod\
    \ - n : n) : n % B::md.mod))) {}\n CE MInt operator-() const { return MInt() -\
    \ *this; }\n#define FUNC(name, op) \\\n CE MInt name const { \\\n  MInt ret; \\\
    \n  return ret.x= op, ret; \\\n }\n FUNC(operator+(const MInt & r), B::md.plus(x,\
    \ r.x))\n FUNC(operator-(const MInt & r), B::md.diff(x, r.x))\n FUNC(operator*(const\
    \ MInt & r), B::md.mul(x, r.x))\n FUNC(pow(u64 k), math_internal::pow(x, k, B::md))\n\
    #undef FUNC\n CE MInt operator/(const MInt& r) const { return *this * r.inv();\
    \ }\n CE MInt& operator+=(const MInt& r) { return *this= *this + r; }\n CE MInt&\
    \ operator-=(const MInt& r) { return *this= *this - r; }\n CE MInt& operator*=(const\
    \ MInt& r) { return *this= *this * r; }\n CE MInt& operator/=(const MInt& r) {\
    \ return *this= *this / r; }\n CE bool operator==(const MInt& r) const { return\
    \ B::md.norm(x) == B::md.norm(r.x); }\n CE bool operator!=(const MInt& r) const\
    \ { return !(*this == r); }\n CE bool operator<(const MInt& r) const { return\
    \ B::md.norm(x) < B::md.norm(r.x); }\n CE inline MInt inv() const { return mod_inv<Int>(val(),\
    \ B::md.mod); }\n CE inline Uint val() const { return B::md.get(x); }\n friend\
    \ ostream& operator<<(ostream& os, const MInt& r) { return os << r.val(); }\n\
    \ friend istream& operator>>(istream& is, MInt& r) {\n  i64 v;\n  return is >>\
    \ v, r= MInt(v), is;\n }\nprivate:\n Uint x;\n};\ntemplate <u64 MOD> using ModInt=\
    \ conditional_t < (MOD < (1 << 30)) & MOD, MInt<int, u32, SB<MP_Mo<u32, u64, 32,\
    \ 31>, MOD>>, conditional_t < (MOD < (1ull << 62)) & MOD, MInt<i64, u64, SB<MP_Mo<u64,\
    \ u128, 64, 63>, MOD>>, conditional_t<MOD<(1u << 31), MInt<int, u32, SB<MP_Na,\
    \ MOD>>, conditional_t<MOD<(1ull << 32), MInt<i64, u32, SB<MP_Na, MOD>>, conditional_t<MOD\
    \ <= (1ull << 41), MInt<i64, u64, SB<MP_Br2, MOD>>, MInt<i64, u64, SB<MP_D2B1,\
    \ MOD>>>>>>>;\n#undef CE\n}\nusing math_internal::ModInt;\n#line 2 \"src/NumberTheory/Factors.hpp\"\
    \n#include <numeric>\n#line 5 \"src/NumberTheory/Factors.hpp\"\n#include <algorithm>\n\
    #include <vector>\n#line 3 \"src/NumberTheory/is_prime.hpp\"\nnamespace math_internal\
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
    }\n}\nusing math_internal::is_prime;\n#line 4 \"src/Math/binary_gcd.hpp\"\n#include\
    \ <cstdint>\ntemplate <class Int> constexpr int bsf(Int a) {\n if constexpr (sizeof(Int)\
    \ == 16) {\n  uint64_t lo= a & uint64_t(-1);\n  return lo ? __builtin_ctzll(lo)\
    \ : 64 + __builtin_ctzll(a >> 64);\n } else if constexpr (sizeof(Int) == 8) return\
    \ __builtin_ctzll(a);\n else return __builtin_ctz(a);\n}\ntemplate <class Int>\
    \ constexpr Int binary_gcd(Int a, Int b) {\n if (a == 0 || b == 0) return a +\
    \ b;\n int n= bsf(a), m= bsf(b), s= 0;\n for (a>>= n, b>>= m; a != b;) {\n  Int\
    \ d= a - b;\n  bool f= a > b;\n  s= bsf(d), b= f ? b : a, a= (f ? d : -d) >> s;\n\
    \ }\n return a << std::min(n, m);\n}\n#line 9 \"src/NumberTheory/Factors.hpp\"\
    \nnamespace math_internal {\ntemplate <class T> constexpr void bubble_sort(T *bg,\
    \ T *ed) {\n for (int sz= ed - bg, i= 0; i < sz; i++)\n  for (int j= sz; --j >\
    \ i;)\n   if (auto tmp= bg[j - 1]; bg[j - 1] > bg[j]) bg[j - 1]= bg[j], bg[j]=\
    \ tmp;\n}\ntemplate <class T, size_t _Nm> struct ConstexprArray {\n constexpr\
    \ size_t size() const { return sz; }\n constexpr auto &operator[](int i) const\
    \ { return dat[i]; }\n constexpr auto *begin() const { return dat; }\n constexpr\
    \ auto *end() const { return dat + sz; }\nprotected:\n T dat[_Nm]= {};\n size_t\
    \ sz= 0;\n friend ostream &operator<<(ostream &os, const ConstexprArray &r) {\n\
    \  os << \"[\";\n  for (size_t i= 0; i < r.sz; ++i) os << r[i] << \",]\"[i ==\
    \ r.sz - 1];\n  return os;\n }\n};\nclass Factors: public ConstexprArray<pair<u64,\
    \ uint16_t>, 16> {\n template <class Uint, class MP> static constexpr Uint rho(Uint\
    \ n, Uint c) {\n  const MP md(n);\n  auto f= [&md, n, c](Uint x) { return md.plus(md.mul(x,\
    \ x), c); };\n  const Uint m= 1LL << (__lg(n) / 5);\n  Uint x= 1, y= md.set(2),\
    \ z= 1, q= md.set(1), g= 1;\n  for (Uint r= 1, i= 0; g == 1; r<<= 1) {\n   for\
    \ (x= y, i= r; i--;) y= f(y);\n   for (Uint k= 0; k < r && g == 1; g= binary_gcd(md.get(q),\
    \ n), k+= m)\n    for (z= y, i= min(m, r - k); i--;) y= f(y), q= md.mul(q, md.diff(y,\
    \ x));\n  }\n  if (g == n) do {\n    z= f(z), g= binary_gcd(md.get(md.diff(z,\
    \ x)), n);\n   } while (g == 1);\n  return g;\n }\n static constexpr u64 find_prime_factor(u64\
    \ n) {\n  if (is_prime(n)) return n;\n  for (u64 i= 100; i--;)\n   if (n= n <\
    \ (1 << 30) ? rho<u32, MP_Mo<u32, u64, 32, 31>>(n, i + 1) : n < (1ull << 62) ?\
    \ rho<u64, MP_Mo<u64, u128, 64, 63>>(n, i + 1) : rho<u64, MP_D2B1>(n, i + 1);\
    \ is_prime(n)) return n;\n  return 0;\n }\n constexpr void init(u64 n) {\n  for\
    \ (u64 p= 2; p < 98 && p * p <= n; ++p)\n   if (n % p == 0)\n    for (dat[sz++].first=\
    \ p; n % p == 0;) n/= p, ++dat[sz - 1].second;\n  for (u64 p= 0; n > 1; dat[sz++].first=\
    \ p)\n   for (p= find_prime_factor(n); n % p == 0;) n/= p, ++dat[sz].second;\n\
    \ }\npublic:\n constexpr Factors()= default;\n constexpr Factors(u64 n) { init(n),\
    \ bubble_sort(dat, dat + sz); }\n};\n}  // namespace math_internal\nusing math_internal::Factors;\n\
    constexpr uint64_t totient(const Factors &f) {\n uint64_t ret= 1, i= 0;\n for\
    \ (auto [p, e]: f)\n  for (ret*= p - 1, i= e; --i;) ret*= p;\n return ret;\n}\n\
    constexpr auto totient(uint64_t n) { return totient(Factors(n)); }\ntemplate <class\
    \ Uint= uint64_t> std::vector<Uint> enumerate_divisors(const Factors &f) {\n int\
    \ k= 1;\n for (auto [p, e]: f) k*= e + 1;\n std::vector<Uint> ret(k, 1);\n k=\
    \ 1;\n for (auto [p, e]: f) {\n  int sz= k;\n  for (Uint pw= 1; pw*= p, e--;)\n\
    \   for (int j= 0; j < sz;) ret[k++]= ret[j++] * pw;\n }\n return ret;\n}\ntemplate\
    \ <class Uint> std::vector<Uint> enumerate_divisors(Uint n) { return enumerate_divisors<Uint>(Factors(n));\
    \ }\n#line 3 \"src/NumberTheory/ArrayOnDivisors.hpp\"\ntemplate <class T> struct\
    \ ArrayOnDivisors {\n uint64_t n;\n uint8_t shift;\n std::vector<int> os, id;\n\
    \ std::vector<std::pair<uint64_t, T>> dat;\n unsigned hash(uint64_t i) const {\
    \ return (i * 11995408973635179863ULL) >> shift; }\n#define _UP for (int j= k;\
    \ j < a; ++j)\n#define _DWN for (int j= a; j-- > k;)\n#define _OP(J, K, op) dat[i\
    \ + J].second op##= dat[i + K].second\n#define _FUN(J, K, name) name(dat[i + J].second,\
    \ dat[i + K].second)\n#define _ZETA(op) \\\n int k= 1; \\\n for (auto [p, e]:\
    \ factors) { \\\n  int a= k * (e + 1); \\\n  for (int i= 0, d= dat.size(); i <\
    \ d; i+= a) op; \\\n  k= a; \\\n }\npublic:\n Factors factors;\n ArrayOnDivisors()\
    \ {}\n template <class Uint> ArrayOnDivisors(uint64_t N, const Factors &factors,\
    \ const std::vector<Uint> &divisors): n(N), shift(__builtin_clzll(divisors.size())\
    \ - 1), os((1 << (64 - shift)) + 1), id(divisors.size()), dat(divisors.size()),\
    \ factors(factors) {\n  for (int i= divisors.size(); i--;) dat[i].first= divisors[i];\n\
    \  for (auto d: divisors) ++os[hash(d)];\n  std::partial_sum(os.begin(), os.end(),\
    \ os.begin());\n  for (int i= divisors.size(); i--;) id[--os[hash(divisors[i])]]=\
    \ i;\n }\n ArrayOnDivisors(uint64_t N, const Factors &factors): ArrayOnDivisors(N,\
    \ factors, enumerate_divisors(factors)) {}\n ArrayOnDivisors(uint64_t N): ArrayOnDivisors(N,\
    \ Factors(N)) {}\n T &operator[](uint64_t i) {\n  assert(i && n % i == 0);\n \
    \ for (unsigned a= hash(i), j= os[a]; j < os[a + 1]; ++j)\n   if (auto &[d, v]=\
    \ dat[id[j]]; d == i) return v;\n  assert(0);\n }\n size_t size() const { return\
    \ dat.size(); }\n auto begin() { return dat.begin(); }\n auto begin() const {\
    \ return dat.begin(); }\n auto end() { return dat.begin() + os.back(); }\n auto\
    \ end() const { return dat.begin() + os.back(); }\n /* f -> g s.t. g(n) = sum_{m|n}\
    \ f(m) */\n void divisor_zeta() { _ZETA(_UP _OP(j, j - k, +)) }\n /* f -> h s.t.\
    \ f(n) = sum_{m|n} h(m) */\n void divisor_mobius() { _ZETA(_DWN _OP(j, j - k,\
    \ -)) }\n /* f -> g s.t. g(n) = sum_{n|m} f(m) */\n void multiple_zeta() { _ZETA(_DWN\
    \ _OP(j - k, j, +)) }\n /* f -> h s.t. f(n) = sum_{n|m} h(m) */\n void multiple_mobius()\
    \ { _ZETA(_UP _OP(j - k, j, -)) }\n /* f -> g s.t. g(n) = sum_{m|n} f(m), add(T&\
    \ a, T b): a+=b */\n template <class F> void divisor_zeta(const F &add) { _ZETA(_UP\
    \ _FUN(j, j - k, add)) }\n /* f -> h s.t. f(n) = sum_{m|n} h(m), sub(T& a, T b):\
    \ a-=b */\n template <class F> void divisor_mobius(const F &sub) { _ZETA(_UP _FUN(j,\
    \ j - k, sub)) }\n /* f -> g s.t. g(n) = sum_{n|m} f(m), add(T& a, T b): a+=b\
    \ */\n template <class F> void multiple_zeta(const F &add) { _ZETA(_UP _FUN(j\
    \ - k, j, add)) }\n /* f -> h s.t. f(n) = sum_{n|m} h(m), sub(T& a, T b): a-=b\
    \ */\n template <class F> void multiple_mobius(const F &sub) { _ZETA(_UP _FUN(j\
    \ - k, j, sub)) }\n#undef _UP\n#undef _DWN\n#undef _OP\n#undef _ZETA\n // f(p,e):\
    \ multiplicative function of p^e\n template <typename F> void set_multiplicative(const\
    \ F &f) {\n  int k= 1;\n  dat[0].second= 1;\n  for (auto [p, e]: factors)\n  \
    \ for (int m= k, d= 1; d <= e; ++d)\n    for (int i= 0; i < m;) dat[k++].second=\
    \ dat[i++].second * f(p, d);\n }\n void set_totient() {\n  int k= 1;\n  dat[0].second=\
    \ 1;\n  for (auto [p, e]: factors) {\n   uint64_t b= p - 1;\n   for (int m= k;\
    \ e--; b*= p)\n    for (int i= 0; i < m;) dat[k++].second= dat[i++].second * b;\n\
    \  }\n }\n void set_mobius() {\n  set_multiplicative([](auto, auto e) { return\
    \ e == 1 ? -1 : 0; });\n }\n};\n#line 5 \"test/atcoder/abc212_g.test.cpp\"\nusing\
    \ namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n\
    \ using Mint= ModInt<998244353>;\n long long P;\n cin >> P;\n ArrayOnDivisors<Mint>\
    \ a(P - 1);\n a.set_totient();\n Mint ans= 1;\n for (auto [d, phi]: a) ans+= phi\
    \ * d;\n cout << ans << '\\n';\n return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc212/tasks/abc212_g\"\n#include\
    \ <iostream>\n#include \"src/Math/ModInt.hpp\"\n#include \"src/NumberTheory/ArrayOnDivisors.hpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(false);\n\
    \ using Mint= ModInt<998244353>;\n long long P;\n cin >> P;\n ArrayOnDivisors<Mint>\
    \ a(P - 1);\n a.set_totient();\n Mint ans= 1;\n for (auto [d, phi]: a) ans+= phi\
    \ * d;\n cout << ans << '\\n';\n return 0;\n}"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Internal/Remainder.hpp
  - src/Internal/modint_traits.hpp
  - src/NumberTheory/ArrayOnDivisors.hpp
  - src/NumberTheory/Factors.hpp
  - src/NumberTheory/is_prime.hpp
  - src/Math/binary_gcd.hpp
  isVerificationFile: true
  path: test/atcoder/abc212_g.test.cpp
  requiredBy: []
  timestamp: '2024-02-09 15:18:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc212_g.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc212_g.test.cpp
- /verify/test/atcoder/abc212_g.test.cpp.html
title: test/atcoder/abc212_g.test.cpp
---