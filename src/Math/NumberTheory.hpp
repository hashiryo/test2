#pragma once
#include <bits/stdc++.h>
/**
 * @title 篩など
 * @category 数学
 * 線形篩による素数列挙の前処理
 * 乗法的関数 テーブル列挙 や gcd畳み込みなど
 * @see https://37zigen.com/linear-sieve/
 * @see https://qiita.com/convexineq/items/afc84dfb9ee4ec4a67d5
 * @see https://en.wikipedia.org/wiki/Dirichlet_convolution
 */

// BEGIN CUT HERE

class NumberTheory {
  static constexpr int MAX_N = 1 << 24;
  static inline int ps[MAX_N >> 4], mpf[MAX_N], psz = 0, lim = 2;
  static inline void sieve(int N) {
    if (lim > N) return;
    for (int d = lim; d <= N; d++) {
      if (!mpf[d]) mpf[d] = ps[psz++] = d;
      for (int j = 0; j < psz && ps[j] <= mpf[d] && ps[j] * d <= N; j++)
        mpf[ps[j] * d] = ps[j];
    }
    lim = N + 1;
  }

 public:
  static int min_prime_factor(int n) { return sieve(n), mpf[n]; }
  // O(log n)
  static std::map<int, short> factorize(int n) {
    std::map<int, short> ret;
    for (sieve(n); n > 1;) ret[mpf[n]]++, n /= mpf[n];
    return ret;
  }
  // O(log n)
  static std::vector<int> divisors(int n) {
    std::vector<int> ret = {1};
    for (auto [p, e] : factorize(n))
      for (std::size_t sz = ret.size(), pw = p; e--; pw *= p)
        for (int i = sz - 1; i >= 0; i--) ret.push_back(ret[i] * pw);
    return std::sort(ret.begin(), ret.end()), ret;
  }
  // O(N)
  static std::vector<int> get_primes(int N) {
    return sieve(N), std::vector<int>(ps, std::upper_bound(ps, ps + psz, N));
  }
  template <class T, class F>
  static std::vector<T> completely_multiplicative_table(int N, const F &f) {
    std::vector<T> ret(N + 1);
    sieve(N);
    for (int i = 2; i <= N; i++)
      ret[i] = mpf[i] == i ? f(i, 1) : ret[mpf[i]] * ret[i / mpf[i]];
    return ret[1] = 1, ret;
  }
  template <class T, class F>
  static std::vector<T> multiplicative_table(int N, const F &f) {
    std::vector<T> ret(N + 1, 0);
    auto dfs = [&](auto rc, int i, long long x, T y) -> void {
      if ((ret[x] = y) == T(0)) return;
      for (int j = i + 1; j < psz && ps[j] * x <= (long long)N; j++)
        for (long long e = 1, nx = ps[j] * x; nx <= N; nx *= ps[j], e++)
          rc(rc, j, nx, y * f(ps[j], e));
    };
    return sieve(N), dfs(dfs, -1, 1, 1), ret;
  }
  // O(N log k / log N)
  template <class T>
  static std::vector<T> pow_table(int N, std::uint64_t k) {
    auto f = [k](int p, short) {
      T ret = 1, b = p;
      for (auto e = k; e; e >>= 1, b *= b)
        if (e & 1) ret *= b;
      return ret;
    };
    return completely_multiplicative_table<T>(N, f);
  }
  // O(N)
  template <class T>
  static std::vector<T> inv_table(int N) {
    return completely_multiplicative_table<T>(
        N, [](int p, short) { return T(1) / p; });
  }
  // naive , O(N log N)
  template <class T>
  static std::vector<T> dirichlet_conv(const std::vector<T> &a,
                                       const std::vector<T> &b) {
    std::size_t N = std::max(a.size(), b.size()), i, j;
    std::vector<T> ret(N, 0);
    for (i = a.size(); --i;)
      for (j = std::min(b.size(), N / i); --j;) ret[i * j] += a[i] * b[j];
    return ret;
  }
  // f -> g s.t. g(n) = sum_{m|n} f(m) , O(N log log N)
  template <typename T>
  static void divisor_zeta(std::vector<T> &f) {
    std::size_t N = f.size(), i, j;
    for (sieve(N), i = 0; i < psz && ps[i] < N; i++)
      for (j = 1; ps[i] * j < N; j++) f[ps[i] * j] += f[j];
  }
  // f -> h s.t. f(n) = sum_{m|n} h(m) , O(N log log N)
  template <typename T>
  static void divisor_mobius(std::vector<T> &f) {
    std::size_t N = f.size(), i, j;
    for (sieve(N), i = 0; i < psz && ps[i] < N; i++)
      for (j = (N - 1) / ps[i]; j; j--) f[ps[i] * j] -= f[j];
  }
  // O(N log log N)
  template <typename T>
  static std::vector<T> lcm_conv(std::vector<T> a, std::vector<T> b) {
    std::size_t N = std::max(a.size(), b.size());
    a.resize(N), b.resize(N), divisor_zeta(a), divisor_zeta(b);
    for (; N--;) a[N] *= b[N];
    return divisor_mobius(a), a;
  }
  // f -> g s.t. g(n) = sum_{n|m} f(m) , O(N log log N)
  template <typename T>
  static void multiple_zeta(std::vector<T> &f) {
    std::size_t N = f.size(), i, j;
    for (sieve(N), i = 0; i < psz && ps[i] < N; i++)
      for (j = (N - 1) / ps[i]; j > 0; j--) f[j] += f[ps[i] * j];
  }
  // f -> h s.t. f(n) = sum_{n|m} h(m) , O(N log log N)
  template <typename T>
  static void multiple_mobius(std::vector<T> &f) {
    std::size_t N = f.size(), i, j;
    for (sieve(N), i = 0; i < psz && ps[i] < N; i++)
      for (j = 1; ps[i] * j < N; j++) f[j] -= f[ps[i] * j];
  }
  // O(N log log N)
  template <typename T>
  static std::vector<T> gcd_conv(std::vector<T> a, std::vector<T> b) {
    std::size_t N = std::max(a.size(), b.size());
    a.resize(N), b.resize(N), multiple_zeta(a), multiple_zeta(b);
    for (; N--;) a[N] *= b[N];
    return multiple_mobius(a), a;
  }
};