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
    path: src/LinearAlgebra/Matrix.hpp
    title: "\u884C\u5217"
  - icon: ':question:'
    path: src/LinearAlgebra/Vector.hpp
    title: "\u30D9\u30AF\u30C8\u30EB"
  - icon: ':x:'
    path: src/LinearAlgebra/characteristic_polynomial.hpp
    title: "\u884C\u5217\u306E\u7279\u6027\u591A\u9805\u5F0F \u4ED6"
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  - icon: ':question:'
    path: src/Math/mod_inv.hpp
    title: "\u9006\u5143 ($\\mathbb{Z}/m\\mathbb{Z}$)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc323/tasks/abc323_g
    links:
    - https://atcoder.jp/contests/abc323/tasks/abc323_g
  bundledCode: "#line 1 \"test/atcoder/abc323_g.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc323/tasks/abc323_g\"\
    \n#include <iostream>\n#include <vector>\n#include <numeric>\n#line 2 \"src/Math/mod_inv.hpp\"\
    \n#include <type_traits>\n#include <cassert>\ntemplate <class Int> constexpr inline\
    \ Int mod_inv(Int a, Int mod) {\n static_assert(std::is_signed_v<Int>);\n Int\
    \ x= 1, y= 0, b= mod;\n for (Int q= 0, z= 0; b;) z= x, x= y, y= z - y * (q= a\
    \ / b), z= a, a= b, b= z - b * q;\n return assert(a == 1), x < 0 ? mod - (-x)\
    \ % mod : x % mod;\n}\n#line 2 \"src/Internal/Remainder.hpp\"\nnamespace math_internal\
    \ {\nusing namespace std;\nusing u8= unsigned char;\nusing u32= unsigned;\nusing\
    \ i64= long long;\nusing u64= unsigned long long;\nusing u128= __uint128_t;\n\
    #define CE constexpr\n#define IL inline\n#define NORM \\\n if (n >= mod) n-= mod;\
    \ \\\n return n\n#define PLUS(U, M) \\\n CE IL U plus(U l, U r) const { return\
    \ l+= r, l < (M) ? l : l - (M); }\n#define DIFF(U, C, M) \\\n CE IL U diff(U l,\
    \ U r) const { return l-= r, l >> C ? l + (M) : l; }\n#define SGN(U) \\\n static\
    \ CE IL U set(U n) { return n; } \\\n static CE IL U get(U n) { return n; } \\\
    \n static CE IL U norm(U n) { return n; }\ntemplate <class u_t, class du_t, u8\
    \ B, u8 A> struct MP_Mo {\n u_t mod;\n CE MP_Mo(): mod(0), iv(0), r2(0) {}\n CE\
    \ MP_Mo(u_t m): mod(m), iv(inv(m)), r2(-du_t(mod) % mod) {}\n CE IL u_t mul(u_t\
    \ l, u_t r) const { return reduce(du_t(l) * r); }\n PLUS(u_t, mod << 1)\n DIFF(u_t,\
    \ A, mod << 1)\n CE IL u_t set(u_t n) const { return mul(n, r2); }\n CE IL u_t\
    \ get(u_t n) const {\n  n= reduce(n);\n  NORM;\n }\n CE IL u_t norm(u_t n) const\
    \ { NORM; }\nprivate:\n u_t iv, r2;\n static CE u_t inv(u_t n, int e= 6, u_t x=\
    \ 1) { return e ? inv(n, e - 1, x * (2 - x * n)) : x; }\n CE IL u_t reduce(const\
    \ du_t &w) const { return u_t(w >> B) + mod - ((du_t(u_t(w) * iv) * mod) >> B);\
    \ }\n};\nstruct MP_Na {\n u32 mod;\n CE MP_Na(): mod(0){};\n CE MP_Na(u32 m):\
    \ mod(m) {}\n CE IL u32 mul(u32 l, u32 r) const { return u64(l) * r % mod; }\n\
    \ PLUS(u32, mod) DIFF(u32, 31, mod) SGN(u32)\n};\nstruct MP_Br {  // mod < 2^31\n\
    \ u32 mod;\n CE MP_Br(): mod(0), s(0), x(0) {}\n CE MP_Br(u32 m): mod(m), s(95\
    \ - __builtin_clz(m - 1)), x(((u128(1) << s) + m - 1) / m) {}\n CE IL u32 mul(u32\
    \ l, u32 r) const { return rem(u64(l) * r); }\n PLUS(u32, mod) DIFF(u32, 31, mod)\
    \ SGN(u32) private: u8 s;\n u64 x;\n CE IL u64 quo(u64 n) const { return (u128(x)\
    \ * n) >> s; }\n CE IL u32 rem(u64 n) const { return n - quo(n) * mod; }\n};\n\
    struct MP_Br2 {  // 2^20 < mod <= 2^41\n u64 mod;\n CE MP_Br2(): mod(0), x(0)\
    \ {}\n CE MP_Br2(u64 m): mod(m), x((u128(1) << 84) / m) {}\n CE IL u64 mul(u64\
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
    }\n#undef NORM\n#undef PLUS\n#undef DIFF\n#undef SGN\n#undef CE\n}\n#line 3 \"\
    src/Internal/modint_traits.hpp\"\nnamespace math_internal {\nstruct m_b {};\n\
    struct s_b: m_b {};\n}\ntemplate <class mod_t> constexpr bool is_modint_v= std::is_base_of_v<math_internal::m_b,\
    \ mod_t>;\ntemplate <class mod_t> constexpr bool is_staticmodint_v= std::is_base_of_v<math_internal::s_b,\
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
    \ MOD>>>>>>>;\n#undef CE\n}\nusing math_internal::ModInt;\n#line 3 \"src/LinearAlgebra/characteristic_polynomial.hpp\"\
    \n#include <algorithm>\n#line 2 \"src/LinearAlgebra/Vector.hpp\"\n#include <cstdint>\n\
    #include <valarray>\nnamespace _la_internal {\nusing namespace std;\ntemplate\
    \ <class R> struct Vector: public valarray<R> {\n using valarray<R>::valarray;\n\
    };\nusing u128= __uint128_t;\nusing u8= uint8_t;\nclass Ref {\n u128 *ref;\n u8\
    \ i;\n bool val;\npublic:\n Ref(u128 *r, u8 j, bool v): ref(r), i(j), val(v) {}\n\
    \ ~Ref() {\n  if (val ^ ((*ref >> i) & 1)) *ref^= u128(1) << i;\n }\n Ref &operator=(const\
    \ Ref &r) { return val= r.val, *this; }\n Ref &operator=(bool b) { return val=\
    \ b, *this; }\n Ref &operator|=(bool b) { return val|= b, *this; }\n Ref &operator&=(bool\
    \ b) { return val&= b, *this; }\n Ref &operator^=(bool b) { return val^= b, *this;\
    \ }\n operator bool() const { return val; }\n};\ntemplate <> class Vector<bool>\
    \ {\n size_t n;\n valarray<u128> dat;\npublic:\n Vector(): n(0) {}\n Vector(size_t\
    \ n): n(n), dat((n + 127) >> 7) {}\n Vector(bool b, size_t n): n(n), dat(-u128(b),\
    \ (n + 127) >> 7) {}\n Ref operator[](int i) {\n  u128 *ref= begin(dat) + (i >>\
    \ 7);\n  u8 j= i & 127;\n  bool val= (*ref >> j) & 1;\n  return Ref{ref, j, val};\n\
    \ }\n bool operator[](int i) const { return (dat[i >> 7] >> (i & 127)) & 1; }\n\
    \ Vector &operator+=(const Vector &r) { return dat^= r.dat, *this; }\n Vector\
    \ &operator-=(const Vector &r) { return dat^= r.dat, *this; }\n Vector &operator*=(bool\
    \ b) {\n  if (!b) dat= 0;\n  return *this;\n }\n Vector operator+(const Vector\
    \ &r) const { return Vector(*this)+= r; }\n Vector operator-(const Vector &r)\
    \ const { return Vector(*this)-= r; }\n Vector operator*(bool b) const { return\
    \ Vector(*this)*= b; }\n size_t size() const { return n; }\n u128 *data() { return\
    \ begin(dat); }\n friend Vector operator*(bool b, const Vector &r) { return r\
    \ * b; }\n};\n}\nusing _la_internal::Vector;\n#line 5 \"src/LinearAlgebra/Matrix.hpp\"\
    \nnamespace _la_internal {\ntemplate <class R> class Matrix {\npublic:\n size_t\
    \ W;\n valarray<R> dat;\npublic:\n static Matrix identity_matrix(int n) {\n  Matrix\
    \ ret(n, n);\n  return ret.dat[slice(0, n, n + 1)]= R(true), ret;\n }\n Matrix():\
    \ W(0) {}\n Matrix(size_t h, size_t w, R v= R()): W(w), dat(v, h * w) {}\n size_t\
    \ width() const { return W; }\n size_t height() const { return W ? dat.size()\
    \ / W : 0; }\n explicit operator bool() const { return W; }\n auto operator[](int\
    \ i) { return next(begin(dat), i * W); }\n auto operator[](int i) const { return\
    \ next(begin(dat), i * W); }\n Matrix submatrix(const vector<int> &rows, const\
    \ vector<int> &cols) const {\n  Matrix ret(rows.size(), cols.size());\n  for (int\
    \ i= rows.size(); i--;)\n   for (int j= cols.size(); j--;) ret[i][j]= (*this)[rows[i]][cols[j]];\n\
    \  return ret;\n }\n bool operator==(const Matrix &r) const {\n  if (W != r.W\
    \ || dat.size() != r.dat.size()) return false;\n  for (int i= dat.size(); i--;)\n\
    \   if (dat[i] != r.dat[i]) return false;\n  return true;\n }\n bool operator!=(const\
    \ Matrix &r) const { return !(*this == r); }\n Matrix &operator+=(const Matrix\
    \ &r) { return assert(dat.size() == r.dat.size()), assert(W == r.W), dat+= r.dat,\
    \ *this; }\n Matrix operator+(const Matrix &r) const { return Matrix(*this)+=\
    \ r; }\n Matrix operator*(const Matrix &r) const {\n  const size_t h= height(),\
    \ w= r.W, l= W;\n  assert(l == r.height());\n  Matrix ret(h, w);\n  auto a= begin(dat);\n\
    \  auto c= begin(ret.dat);\n  for (int i= h; i--; advance(c, w)) {\n   auto b=\
    \ begin(r.dat);\n   for (int k= l; k--; ++a) {\n    auto d= c;\n    auto v= *a;\n\
    \    for (int j= w; j--; ++b, ++d) *d+= v * *b;\n   }\n  }\n  return ret;\n }\n\
    \ Matrix &operator*=(const Matrix &r) { return *this= *this * r; }\n Matrix &operator*=(R\
    \ r) { return dat*= r, *this; }\n Matrix operator*(R r) const { return Matrix(*this)*=\
    \ r; }\n Vector<R> operator*(const Vector<R> &r) const {\n  assert(W == r.size());\n\
    \  const size_t h= height();\n  Vector<R> ret(h);\n  auto a= begin(dat);\n  for\
    \ (int i= 0; i < h; ++i)\n   for (int k= 0; k < W; ++k, ++a) ret[i]+= *a * r[k];\n\
    \  return ret;\n }\n Vector<R> operator()(const Vector<R> &r) const { return *this\
    \ * r; }\n Matrix pow(uint64_t k) const {\n  assert(W * W == dat.size());\n  for\
    \ (auto ret= identity_matrix(W), b= *this;; b*= b)\n   if (k & 1 ? ret*= b, !(k>>=\
    \ 1) : !(k>>= 1)) return ret;\n }\n};\ntemplate <> class Matrix<bool> {\n size_t\
    \ H, W, m;\n valarray<u128> dat;\n class Array {\n  u128 *bg;\n public:\n  Array(u128\
    \ *it): bg(it) {}\n  u128 *data() const { return bg; }\n  Ref operator[](int i)\
    \ {\n   u128 *ref= bg + (i >> 7);\n   u8 j= i & 127;\n   bool val= (*ref >> j)\
    \ & 1;\n   return Ref{ref, j, val};\n  }\n  bool operator[](int i) const { return\
    \ (bg[i >> 7] >> (i & 127)) & 1; }\n };\n class ConstArray {\n  const u128 *bg;\n\
    \ public:\n  ConstArray(const u128 *it): bg(it) {}\n  const u128 *data() const\
    \ { return bg; }\n  bool operator[](int i) const { return (bg[i >> 7] >> (i &\
    \ 127)) & 1; }\n };\npublic:\n static Matrix identity_matrix(int n) {\n  Matrix\
    \ ret(n, n);\n  for (; n--;) ret[n][n]= 1;\n  return ret;\n }\n Matrix(): H(0),\
    \ W(0), m(0) {}\n Matrix(size_t h, size_t w): H(h), W(w), m((w + 127) >> 7), dat(u128(0),\
    \ h * m) {}\n size_t width() const { return W; }\n size_t height() const { return\
    \ H; }\n explicit operator bool() const { return W; }\n Array operator[](int i)\
    \ { return {next(begin(dat), i * m)}; }\n ConstArray operator[](int i) const {\
    \ return {next(begin(dat), i * m)}; }\n ConstArray get(int i) const { return {next(begin(dat),\
    \ i * m)}; }\n Matrix submatrix(const std::vector<int> &rows, const std::vector<int>\
    \ &cols) const {\n  Matrix ret(rows.size(), cols.size());\n  for (int i= rows.size();\
    \ i--;)\n   for (int j= cols.size(); j--;) ret[i][j]= (*this)[rows[i]][cols[j]];\n\
    \  return ret;\n }\n bool operator==(const Matrix &r) const { return W == r.W\
    \ && H == r.H && (dat == r.dat).min(); }\n bool operator!=(const Matrix &r) const\
    \ { return W != r.W || H != r.H || (dat != r.dat).max(); }\n Matrix &operator+=(const\
    \ Matrix &r) { return assert(H == r.H), assert(W == r.W), dat^= r.dat, *this;\
    \ }\n Matrix operator+(const Matrix &r) const { return Matrix(*this)+= r; }\n\
    \ Matrix operator*(const Matrix &r) const {\n  assert(W == r.H);\n  Matrix ret(H,\
    \ r.W);\n  u128 *c= begin(ret.dat);\n  for (size_t i= 0; i < H; ++i, advance(c,\
    \ m)) {\n   ConstArray a= this->operator[](i);\n   const u128 *b= begin(r.dat);\n\
    \   for (size_t k= 0; k < W; ++k, advance(b, r.m))\n    if (a[k])\n     for (size_t\
    \ j= 0; j < r.m; ++j) c[j]^= b[j];\n  }\n  return ret;\n }\n Matrix &operator*=(const\
    \ Matrix &r) { return *this= *this * r; }\n Vector<bool> operator*(const Vector<bool>\
    \ &r) const {\n  assert(W == r.size());\n  Vector<bool> ret(H);\n  auto a= begin(dat);\n\
    \  for (size_t i= 0; i < H; ++i)\n   for (size_t j= 0; j < m; ++j, ++a) ret[i]^=\
    \ *a & r[j];\n  return ret;\n }\n Vector<bool> operator()(const Vector<bool> &r)\
    \ const { return *this * r; }\n Matrix pow(uint64_t k) const {\n  assert(W ==\
    \ H);\n  for (auto ret= identity_matrix(W), b= *this;; b*= b)\n   if (k & 1 ?\
    \ ret*= b, !(k>>= 1) : !(k>>= 1)) return ret;\n }\n};\ntemplate <class K> static\
    \ bool is_zero(K x) {\n if constexpr (is_floating_point_v<K>) return abs(x) <\
    \ 1e-8;\n else return x == K();\n}\n}\nusing _la_internal::Matrix;\n#line 5 \"\
    src/LinearAlgebra/characteristic_polynomial.hpp\"\ntemplate <class K> Matrix<K>\
    \ hessenberg(Matrix<K> A, bool mint= false) {\n using _la_internal::is_zero;\n\
    \ const size_t n= A.width();\n assert(n == A.height());\n for (size_t j= 0, i,\
    \ r; j + 2 < n; ++j) {\n  if constexpr (std::is_floating_point_v<K>) {\n   for\
    \ (i= j + 1, r= j + 2; r < n; ++r)\n    if (std::abs(A[i][j]) < std::abs(A[r][j]))\
    \ i= r;\n  } else\n   for (i= r= j + 1; r < n; ++r)\n    if (A[r][j] != K()) i=\
    \ r, r= n;\n  if (i != j + 1) {\n   for (r= 0; r < n; ++r) std::swap(A[j + 1][r],\
    \ A[i][r]);\n   for (; r--;) std::swap(A[r][j + 1], A[r][i]);\n  }\n  if (is_zero(A[j\
    \ + 1][j])) continue;\n  if (K s, iv; mint) {\n   for (i= j + 2; i < n; ++i)\n\
    \    if (!is_zero(A[i][j])) {\n     K m00= K(1), m01= K(), m10= K(), m11= K(1);\n\
    \     for (uint64_t a= A[j + 1][j].val(), b= A[i][j].val(), t, l; b;) l= b, b=\
    \ a - (t= a / b) * b, a= l, s= m10, m10= m00 - m10 * t, m00= s, s= m11, m11= m01\
    \ - m11 * t, m01= s;\n     for (r= 0; r < n; ++r) s= m00 * A[j + 1][r] + m01 *\
    \ A[i][r], A[i][r]= m10 * A[j + 1][r] + m11 * A[i][r], A[j + 1][r]= s;\n     for\
    \ (; r--;) s= m11 * A[r][j + 1] - m10 * A[r][i], A[r][i]= m00 * A[r][i] - m01\
    \ * A[r][j + 1], A[r][j + 1]= s;\n    }\n  } else {\n   for (iv= K(1) / A[j +\
    \ 1][j], i= j + 2; i < n; ++i)\n    if (!is_zero(A[i][j])) {\n     for (s= A[i][r=\
    \ j] * iv; r < n; ++r) A[i][r]-= s * A[j + 1][r];\n     for (; r--;) A[r][j +\
    \ 1]+= s * A[r][i];\n    }\n  }\n }\n return A;\n}\ntemplate <class K> std::vector<K>\
    \ characteristic_polynomial(const Matrix<K> &A, bool mint= false) {\n size_t n=\
    \ A.width(), i= 0, k, j;\n assert(n == A.height());\n auto b= hessenberg(A, mint);\n\
    \ std::vector<K> fss((n + 1) * (n + 2) / 2);\n K *pr= fss.data(), *nx= pr, prod,\
    \ tmp, s;\n for (fss[0]= 1; i < n; ++i, pr= nx) {\n  for (prod= 1, tmp= -b[i][i],\
    \ nx= pr + i + 1, std::copy_n(pr, i + 1, nx + 1), k= 0; k <= i; ++k) nx[k]+= tmp\
    \ * pr[k];\n  for (j= i; j--;)\n   for (pr-= j + 1, s= (prod*= b[j + 1][j]) *\
    \ -b[j][i], k= 0; k <= j; ++k) nx[k]+= s * pr[k];\n }\n return std::vector<K>(fss.begin()\
    \ + n * (n + 1) / 2, fss.end());\n}\ntemplate <class K> std::vector<K> det_of_first_degree_poly_mat(Matrix<K>\
    \ M0, Matrix<K> M1) {\n const size_t n= M0.height();\n assert(n == M1.height()),\
    \ assert(n == M0.width()), assert(n == M1.width());\n size_t cnt= 0;\n K det=\
    \ 1, v, iv;\n for (size_t p= 0, piv, r, i; p < n;) {\n  if constexpr (std::is_floating_point_v<K>)\
    \ {\n   for (piv= p, r= p + 1; r < n; ++r)\n    if (std::abs(M1[piv][p]) < std::abs(M1[r][p]))\
    \ piv= r;\n  } else\n   for (piv= p; piv < n; ++piv)\n    if (M1[piv][p] != K())\
    \ break;\n  if (piv == n || _la_internal::is_zero(M1[piv][p])) {\n   if (++cnt\
    \ > n) return std::vector<K>(n + 1);\n   for (r= p; r--;)\n    for (v= M1[r][p],\
    \ M1[r][p]= K(), i= n; i--;) M0[i][p]-= v * M0[i][r];\n   for (i= n; i--;) std::swap(M0[i][p],\
    \ M1[i][p]);\n   continue;\n  }\n  if (piv != p) {\n   for (det*= -1, i= 0; i\
    \ < n; ++i) std::swap(M0[p][i], M0[piv][i]);\n   for (; i--;) std::swap(M1[p][i],\
    \ M1[piv][i]);\n  }\n  for (det*= v= M1[p][p], iv= K(1) / v, i= 0; i < n; ++i)\
    \ M0[p][i]*= iv;\n  for (; i--;) M1[p][i]*= iv;\n  for (r= n; r--;)\n   if (r\
    \ != p) {\n    for (v= M1[r][p], i= 0; i < n; ++i) M0[r][i]-= v * M0[p][i];\n\
    \    for (; i--;) M1[r][i]-= v * M1[p][i];\n   }\n  ++p;\n }\n auto poly= characteristic_polynomial(M0\
    \ * -1);\n poly.erase(poly.begin(), poly.begin() + cnt);\n for (auto &x: poly)\
    \ x*= det;\n return poly.resize(n + 1), poly;\n}\n#line 7 \"test/atcoder/abc323_g.test.cpp\"\
    \nusing namespace std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n\
    \ using Mint= ModInt<998244353>;\n int N;\n cin >> N;\n vector<int> P(N);\n for\
    \ (int i= 0; i < N; ++i) cin >> P[i];\n Matrix<Mint> M0(N, N), M1(N, N);\n for\
    \ (int i= N; i--;)\n  for (int j= i; j--;) {\n   if (P[i] > P[j]) M0[i][j]= M0[j][i]=\
    \ -1, M0[i][i]+= 1, M0[j][j]+= 1;\n   else M1[i][j]= M1[j][i]= -1, M1[i][i]+=\
    \ 1, M1[j][j]+= 1;\n  }\n vector<int> id(N - 1);\n iota(id.begin(), id.end(),\
    \ 0);\n auto p= det_of_first_degree_poly_mat(M0.submatrix(id, id), M1.submatrix(id,\
    \ id));\n for (int k= 0; k < N; ++k) cout << p[k] << \" \\n\"[k + 1 == N];\n return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc323/tasks/abc323_g\"\n#include\
    \ <iostream>\n#include <vector>\n#include <numeric>\n#include \"src/Math/ModInt.hpp\"\
    \n#include \"src/LinearAlgebra/characteristic_polynomial.hpp\"\nusing namespace\
    \ std;\nsigned main() {\n cin.tie(0);\n ios::sync_with_stdio(0);\n using Mint=\
    \ ModInt<998244353>;\n int N;\n cin >> N;\n vector<int> P(N);\n for (int i= 0;\
    \ i < N; ++i) cin >> P[i];\n Matrix<Mint> M0(N, N), M1(N, N);\n for (int i= N;\
    \ i--;)\n  for (int j= i; j--;) {\n   if (P[i] > P[j]) M0[i][j]= M0[j][i]= -1,\
    \ M0[i][i]+= 1, M0[j][j]+= 1;\n   else M1[i][j]= M1[j][i]= -1, M1[i][i]+= 1, M1[j][j]+=\
    \ 1;\n  }\n vector<int> id(N - 1);\n iota(id.begin(), id.end(), 0);\n auto p=\
    \ det_of_first_degree_poly_mat(M0.submatrix(id, id), M1.submatrix(id, id));\n\
    \ for (int k= 0; k < N; ++k) cout << p[k] << \" \\n\"[k + 1 == N];\n return 0;\n\
    }"
  dependsOn:
  - src/Math/ModInt.hpp
  - src/Math/mod_inv.hpp
  - src/Internal/Remainder.hpp
  - src/Internal/modint_traits.hpp
  - src/LinearAlgebra/characteristic_polynomial.hpp
  - src/LinearAlgebra/Matrix.hpp
  - src/LinearAlgebra/Vector.hpp
  isVerificationFile: true
  path: test/atcoder/abc323_g.test.cpp
  requiredBy: []
  timestamp: '2024-02-18 22:00:56+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc323_g.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc323_g.test.cpp
- /verify/test/atcoder/abc323_g.test.cpp.html
title: test/atcoder/abc323_g.test.cpp
---