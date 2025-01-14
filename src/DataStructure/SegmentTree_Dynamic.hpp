#pragma once
#include <array>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>
#include <cstddef>
#include <cstdint>
#include "src/Internal/HAS_CHECK.hpp"
template <typename M, bool persistent= false, uint8_t HEIGHT= 31> class SegmentTree_Dynamic {
 HAS_MEMBER(op);
 HAS_MEMBER(ti);
 HAS_MEMBER(mp);
 HAS_MEMBER(cp);
 HAS_TYPE(T);
 HAS_TYPE(E);
 NULLPTR_OR(E);
 template <class L> static constexpr bool monoid_v= std::conjunction_v<has_T<L>, has_op<L>, has_ti<L>>;
 template <class L> static constexpr bool dual_v= std::conjunction_v<has_T<L>, has_E<L>, has_mp<L>, has_cp<L>>;
 using id_t= long long;
 template <class T, class tDerived> struct Node_B {
  T val;
  tDerived *ch[2]= {nullptr, nullptr};
 };
 template <bool mo, bool du, typename tEnable= void> struct Node_D: Node_B<M, Node_D<mo, du, tEnable>> {};
 template <bool mo, bool du> struct Node_D<mo, du, typename std::enable_if_t<mo && !du>>: Node_B<typename M::T, Node_D<mo, du>> {};
 template <bool mo, bool du> struct Node_D<mo, du, typename std::enable_if_t<du>>: Node_B<typename M::T, Node_D<mo, du>> {
  typename M::E lazy;
  bool lazy_flg= false;
 };
 using Node= Node_D<monoid_v<M>, dual_v<M>>;
 using T= decltype(Node::val);
 using E= nullptr_or_E_t<M>;
 using np= Node *;
 np root;
 static inline constexpr T def_val() {
  if constexpr (monoid_v<M>) return M::ti();
  else return T();
 }
 template <class S> np build(id_t n, id_t l, id_t r, const S &bg) {
  if (n <= l) return nullptr;
  if (r - l == 1) {
   if constexpr (std::is_same_v<S, T>) return new Node{bg};
   else return new Node{*(bg + l)};
  }
  id_t m= (r + l) / 2;
  np t= new Node{def_val(), {build(n, l, m, bg), build(n, m, r, bg)}};
  if constexpr (monoid_v<M>) update(t);
  return t;
 }
 void dump(np t, const id_t &l, const id_t &r, std::array<id_t, 2> b, typename std::vector<T>::iterator itr) {
  if (r <= b[0] || b[1] <= l) return;
  if (l <= b[0] && b[1] <= r && !t) {
   for (id_t i= b[0]; i < b[1]; i++) *(itr + i)= def_val();
  } else if (b[1] - b[0] != 1) {
   if constexpr (dual_v<M>) push(t, b[1] - b[0]);
   auto m= (b[0] + b[1]) >> 1;
   dump(t ? t->ch[0] : nullptr, l, r, {b[0], m}, itr);
   dump(t ? t->ch[1] : nullptr, l, r, {m, b[1]}, itr);
  } else *(itr + b[0])= t->val;
 }
 static inline void update(np &t) {
  t->val= def_val();
  if (t->ch[0]) t->val= M::op(t->ch[0]->val, t->val);
  if (t->ch[1]) t->val= M::op(t->val, t->ch[1]->val);
 }
 static inline void map(T &v, E x, int sz) {
  if constexpr (std::is_invocable_r_v<void, decltype(M::mp), T &, E, int>) M::mp(v, x, sz);
  else M::mp(v, x);
 }
 static inline T &reflect(np &t) {
  if constexpr (dual_v<M> && !monoid_v<M>)
   if (t->lazy_flg) map(t->val, t->lazy, 1), t->lazy_flg= false;
  return t->val;
 }
 static inline void propagate(np &t, const E &x, const id_t &sz) {
  t->lazy_flg ? (M::cp(t->lazy, x), x) : t->lazy= x;
  t->lazy_flg= true;
  if constexpr (monoid_v<M>) map(t->val, x, sz);
 }
 static inline void cp_node(np &t) {
  if (!t) t= new Node{def_val()};
  else if constexpr (persistent) t= new Node(*t);
 }
 static inline void push(np &t, const id_t &sz) {
  if (!t->lazy_flg) return;
  cp_node(t->ch[0]), cp_node(t->ch[1]), t->lazy_flg= false;
  propagate(t->ch[0], t->lazy, sz / 2), propagate(t->ch[1], t->lazy, sz / 2);
 }
 T prod(np &t, const id_t &l, const id_t &r, std::array<id_t, 2> b, const id_t &bias) {
  if (!t || r <= b[0] || b[1] <= l) return def_val();
  if (l <= b[0] && b[1] <= r) return t->val;
  if constexpr (dual_v<M>) push(t, b[1] - b[0]);
  id_t m= (b[0] + b[1]) >> 1;
  bool flg= (bias >> (__builtin_ctzll(b[1] - b[0]) - 1)) & 1;
  return M::op(prod(t->ch[flg], l, r, {b[0], m}, bias), prod(t->ch[!flg], l, r, {m, b[1]}, bias));
 }
 void apply(np &t, const id_t &l, const id_t &r, std::array<id_t, 2> b, const E &x) {
  if (r <= b[0] || b[1] <= l) return;
  id_t m= (b[0] + b[1]) >> 1;
  if (cp_node(t); l <= b[0] && b[1] <= r) return propagate(t, x, b[1] - b[0]);
  push(t, b[1] - b[0]);
  apply(t->ch[0], l, r, {b[0], m}, x), apply(t->ch[1], l, r, {m, b[1]}, x);
  if constexpr (monoid_v<M>) update(t);
 }
 void set_val(np &t, const id_t &k, const T &val, uint8_t h) {
  if (cp_node(t); !h) return reflect(t)= val, void();
  if constexpr (dual_v<M>) push(t, 1LL << h);
  set_val(t->ch[(k >> (h - 1)) & 1], k, val, h - 1);
  if constexpr (monoid_v<M>) update(t);
 }
 T &at_val(np &t, const id_t &k, uint8_t h) {
  if (cp_node(t); !h) return reflect(t);
  if constexpr (dual_v<M>) push(t, 1LL << h);
  return at_val(t->ch[(k >> (h - 1)) & 1], k, h - 1);
 }
 bool is_null(np &t, const id_t &k, uint8_t h) {
  if (!t) return true;
  if (!h) return false;
  if constexpr (dual_v<M>) push(t, 1LL << h);
  return is_null(t->ch[(k >> (h - 1)) & 1], k, h - 1);
 }
 T get_val(np &t, const id_t &k, uint8_t h) {
  if (!t) return def_val();
  if (!h) return reflect(t);
  if constexpr (dual_v<M>) push(t, 1LL << h);
  return get_val(t->ch[(k >> (h - 1)) & 1], k, h - 1);
 }
 template <bool last> static inline T calc_op(np &t, const T &v) {
  if constexpr (last) return M::op((t ? t->val : def_val()), v);
  else return M::op(v, (t ? t->val : def_val()));
 }
 template <bool last> static inline bool is_in(const id_t &m, const id_t &k) {
  if constexpr (last) return k <= m;
  else return m <= k;
 }
 template <bool last, class C, std::size_t N> static id_t find(const id_t &k, std::array<id_t, 2> b, const id_t &bias, uint8_t h, const C &check, std::array<np, N> &ts, std::array<T, N> &sums) {
  static_assert(monoid_v<M>, "\"find\" is not available\n");
  static std::array<T, N> sums2;
  if (std::all_of(ts.begin(), ts.end(), [](np t) { return !t; })) return -1;
  if (!h) {
   for (std::size_t i= N; i--;) sums[i]= calc_op<last>(ts[i], sums[i]);
   return std::apply(check, sums) ? std::get<last>(b) : -1;
  } else if (is_in<last>(k, b[0])) {
   for (std::size_t i= N; i--;) sums2[i]= calc_op<last>(ts[i], sums[i]);
   if (!std::apply(check, sums2)) return sums= std::move(sums2), -1;
  }
  if constexpr (dual_v<M>)
   for (std::size_t i= N; i--;) push(ts[i], b[1] - b[0]);
  std::array<np, N> ss;
  id_t m= (b[0] + b[1]) >> 1;
  bool flg= (bias >> (h - 1)) & 1;
  if (!is_in<last>(m, k)) {
   for (std::size_t i= N; i--;) ss[i]= ts[i] ? ts[i]->ch[flg] : nullptr;
   id_t ret= find<last>(k, {b[0], m}, bias, h - 1, check, ss, sums);
   if (ret >= 0) return ret;
  }
  for (std::size_t i= N; i--;) ss[i]= ts[i] ? ts[i]->ch[!flg] : nullptr;
  return find<last>(k, {m, b[1]}, bias, h - 1, check, ss, sums);
 }
public:
 SegmentTree_Dynamic(np t= nullptr): root(t) {}
 SegmentTree_Dynamic(std::size_t n, T val): root(build(n, 0, 1LL << HEIGHT, val)) {}
 SegmentTree_Dynamic(const T *bg, const T *ed): root(build(ed - bg, 0, 1LL << HEIGHT, bg)) {}
 SegmentTree_Dynamic(const std::vector<T> &ar): SegmentTree_Dynamic(ar.data(), ar.data() + ar.size()) {}
 void set(id_t k, T val) { set_val(root, k, val, HEIGHT); }
 T get(id_t k) { return get_val(root, k, HEIGHT); }
 bool is_null(id_t k) { return is_null(root, k, HEIGHT); }
 T &at(id_t k) {
  static_assert(!monoid_v<M>, "\"at\" is not available\n");
  return at_val(root, k, HEIGHT);
 }
 template <class L= M, std::enable_if_t<monoid_v<L>, std::nullptr_t> = nullptr> T operator[](id_t k) { return get(k); }
 template <class L= M, std::enable_if_t<!monoid_v<L>, std::nullptr_t> = nullptr> T &operator[](id_t k) { return at(k); }
 T prod(id_t a, id_t b, id_t bias= 0) {
  static_assert(monoid_v<M>, "\"prod\" is not available\n");
  return prod(root, a, b, {0, 1LL << HEIGHT}, bias);
 }
 // find i s.t.
 //  check(prod(a,i)) == False, check(prod(a,i+1)) == True
 // return -1 if not found
 template <class C> id_t find_first(id_t a, C check, id_t bias= 0) {
  std::array<T, 1> sum{def_val()};
  std::array<np, 1> t{root};
  return find<0>(a, {0, 1LL << HEIGHT}, bias, HEIGHT, check, t, sum);
 }
 template <std::size_t N, class C> static id_t find_first(id_t a, C check, std::array<SegmentTree_Dynamic, N> segs, id_t bias= 0) {
  std::array<T, N> sums;
  sums.fill(def_val());
  std::array<np, N> ts;
  for (std::size_t i= 0; i < N; i++) ts[i]= segs[i].root;
  return find<0>(a, {0, 1LL << HEIGHT}, bias, HEIGHT, check, ts, sums);
 }
 // find i s.t.
 //  check(prod(i+1,b)) == False, check(prod(i,b)) == True
 // return -1 if not found
 template <class C> id_t find_last(id_t b, C check, id_t bias= 0) {
  std::array<T, 1> sum{def_val()};
  std::array<np, 1> t{root};
  return find<1>(b, {1LL << HEIGHT, 0}, ~bias, HEIGHT, check, t, sum);
 }
 template <std::size_t N, class C> static id_t find_last(id_t b, C check, std::array<SegmentTree_Dynamic, N> segs, id_t bias= 0) {
  std::array<T, N> sums;
  sums.fill(def_val());
  std::array<np, N> ts;
  for (std::size_t i= 0; i < N; i++) ts[i]= segs[i].root;
  return find<1>(b, {1LL << HEIGHT, 0}, ~bias, HEIGHT, check, ts, sums);
 }
 void apply(id_t a, id_t b, E x) {
  static_assert(dual_v<M>, "\"apply\" is not available\n");
  apply(root, a, b, {0, 1LL << HEIGHT}, x);
 }
 std::vector<T> dump(id_t bg, id_t ed) {
  std::vector<T> ret(ed - bg);
  return dump(root, bg, ed, {0, 1LL << HEIGHT}, ret.begin()), ret;
 }
 static std::string which_available() {
  std::string ret= "";
  if constexpr (monoid_v<M>) ret+= "\"prod\" \"find\" ";
  else ret+= "\"at\" ";
  if constexpr (dual_v<M>) ret+= "\"apply\" ";
  return ret;
 }
};