---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/DataStructure/LinkCutTree.hpp
    title: Link-Cut-Tree
  - icon: ':question:'
    path: src/Math/ModInt.hpp
    title: ModInt
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite
  bundledCode: "#line 1 \"test/yosupo/dynamic_tree_vertex_set_path_composite.LCT.test.cpp\"\
    \n#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite\"\
    \n#include <bits/stdc++.h>\n#line 3 \"src/DataStructure/LinkCutTree.hpp\"\n/**\n\
    \ * @title Link-Cut-Tree\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n * @brief\
    \ O(logN)\n * \u5358\u4F4D\u5143\u306F\u5FC5\u8981\u306A\u3057\uFF08\u9045\u5EF6\
    \u5074\u3082\uFF09\n * \u5404\u30CE\u30FC\u30C9\u304C\u90E8\u5206\u6728\u306E\u30B5\
    \u30A4\u30BA\u3092\u4FDD\u6301\u3057\u3066\u3044\u306A\u3044\u306E\u3067mapping\u95A2\
    \u6570\u3067\u306F\u5F15\u6570\u3068\u3057\u3066size\u3092\u6E21\u305B\u306A\u3044\
    \n */\n\n// BEGIN CUT HERE\n\n#define HAS_CHECK(member, Dummy)               \
    \               \\\n  template <class T>                                     \
    \     \\\n  struct has_##member {                                       \\\n \
    \   template <class U, Dummy>                                 \\\n    static std::true_type\
    \ check(U *);                         \\\n    static std::false_type check(...);\
    \                        \\\n    static T *mClass;                           \
    \              \\\n    static const bool value = decltype(check(mClass))::value;\
    \ \\\n  };\n#define HAS_MEMBER(member) HAS_CHECK(member, int dummy = (&U::member,\
    \ 0))\n#define HAS_TYPE(member) HAS_CHECK(member, class dummy = typename U::member)\n\
    \ntemplate <typename M = void>\nclass LinkCutTree {\n  HAS_MEMBER(op);\n  HAS_MEMBER(mapping);\n\
    \  HAS_MEMBER(composition)\n  HAS_TYPE(T);\n  HAS_TYPE(E);\n  template <class\
    \ L>\n  using semigroup = std::conjunction<has_T<L>, has_op<L>>;\n  template <class\
    \ L>\n  using dual =\n      std::conjunction<has_T<L>, has_E<L>, has_mapping<L>,\
    \ has_composition<L>>;\n  template <class tDerived, class U = std::nullptr_t,\
    \ class F = std::nullptr_t>\n  struct Node_B {\n    using T = U;\n    using E\
    \ = F;\n    tDerived *ch[2], *par;\n    bool rev_flg;\n  };\n  template <bool\
    \ sg_, bool du_, typename tEnable = void>\n  struct Node_D : Node_B<Node_D<sg_,\
    \ du_, tEnable>> {};\n  template <bool sg_, bool du_>\n  struct Node_D<sg_, du_,\
    \ typename std::enable_if_t<sg_ && !du_>>\n      : Node_B<Node_D<sg_, du_>, typename\
    \ M::T> {\n    typename M::T val, sum, rsum;\n  };\n  template <bool sg_, bool\
    \ du_>\n  struct Node_D<sg_, du_, typename std::enable_if_t<!sg_ && du_>>\n  \
    \    : Node_B<Node_D<sg_, du_>, typename M::T, typename M::E> {\n    typename\
    \ M::T val;\n    typename M::E lazy;\n    bool lazy_flg;\n  };\n  template <bool\
    \ sg_, bool du_>\n  struct Node_D<sg_, du_, typename std::enable_if_t<sg_ && du_>>\n\
    \      : Node_B<Node_D<sg_, du_>, typename M::T, typename M::E> {\n    typename\
    \ M::T val, sum, rsum;\n    typename M::E lazy;\n    bool lazy_flg;\n  };\n  using\
    \ Node = Node_D<semigroup<M>::value, dual<M>::value>;\n  using T = typename Node::T;\n\
    \  using E = typename Node::E;\n  inline int dir(Node *&t) {\n    if (t->par)\
    \ {\n      if (t->par->ch[0] == t) return 0;\n      if (t->par->ch[1] == t) return\
    \ 1;\n    }\n    return 2;\n  }\n  inline void rot(Node *t) {\n    Node *p = t->par;\n\
    \    int d = dir(t);\n    if ((p->ch[d] = t->ch[!d])) p->ch[d]->par = p;\n   \
    \ t->ch[!d] = p;\n    if constexpr (semigroup<M>::value) pushup(p), pushup(t);\n\
    \    t->par = p->par;\n    if ((d = dir(p)) < 2) {\n      p->par->ch[d] = t;\n\
    \      if constexpr (semigroup<M>::value) pushup(t->par);\n    }\n    p->par =\
    \ t;\n  }\n  inline void splay(Node *t) {\n    eval(t);\n    for (int t_d = dir(t),\
    \ p_d; t_d < 2; rot(t), t_d = dir(t)) {\n      if ((p_d = dir(t->par)) < 2) eval(t->par->par);\n\
    \      eval(t->par), eval(t);\n      if (p_d < 2) rot(t_d == p_d ? t->par : t);\n\
    \    }\n  }\n  inline void pushup(Node *t) {\n    t->rsum = t->sum = t->val;\n\
    \    if (t->ch[0])\n      t->sum = M::op(t->ch[0]->sum, t->sum),\n      t->rsum\
    \ = M::op(t->rsum, t->ch[0]->rsum);\n    if (t->ch[1])\n      t->sum = M::op(t->sum,\
    \ t->ch[1]->sum),\n      t->rsum = M::op(t->ch[1]->rsum, t->rsum);\n  }\n  inline\
    \ void propagate(Node *t, const E &x) {\n    t->lazy = t->lazy_flg ? M::composition(t->lazy,\
    \ x) : x;\n    t->val = M::mapping(t->val, x);\n    if constexpr (semigroup<M>::value)\n\
    \      t->sum = M::mapping(t->sum, x), t->rsum = M::mapping(t->rsum, x);\n   \
    \ t->lazy_flg = true;\n  }\n  inline void toggle(Node *t) {\n    std::swap(t->ch[0],\
    \ t->ch[1]);\n    if constexpr (semigroup<M>::value) std::swap(t->sum, t->rsum);\n\
    \    t->rev_flg = !t->rev_flg;\n  }\n  inline void eval(Node *t) {\n    if constexpr\
    \ (dual<M>::value) {\n      if (t->lazy_flg) {\n        if (t->ch[0]) propagate(t->ch[0],\
    \ t->lazy);\n        if (t->ch[1]) propagate(t->ch[1], t->lazy);\n        t->lazy_flg\
    \ = false;\n      }\n    }\n    if (t->rev_flg) {\n      if (t->ch[0]) toggle(t->ch[0]);\n\
    \      if (t->ch[1]) toggle(t->ch[1]);\n      t->rev_flg = false;\n    }\n  }\n\
    \  inline Node *expose(Node *t) {\n    Node *r = nullptr;\n    for (Node *p =\
    \ t; p; r = p, p = p->par) {\n      splay(p), p->ch[1] = r;\n      if constexpr\
    \ (semigroup<M>::value) pushup(p);\n    }\n    return splay(t), r;\n  }\n  std::vector<Node>\
    \ ns;\n\n public:\n  LinkCutTree(std::size_t n) : ns(n) {}\n  LinkCutTree(std::size_t\
    \ n, T val) : ns(n) {\n    for (std::size_t i = n; i--;) ns[i].val = val;\n  }\n\
    \  void evert(std::size_t k) { expose(&ns[k]), toggle(&ns[k]), eval(&ns[k]); }\n\
    \  void link(std::size_t c, std::size_t p) {\n    evert(c), expose(&ns[p]);\n\
    \    assert(!ns[c].par);\n    ns[p].ch[1] = &ns[c], ns[c].par = &ns[p];\n    if\
    \ constexpr (semigroup<M>::value) pushup(&ns[p]);\n  }\n  void cut(std::size_t\
    \ c, std::size_t p) {\n    evert(p), expose(&ns[c]);\n    assert(ns[c].ch[0] ==\
    \ &ns[p]);\n    ns[c].ch[0] = ns[c].ch[0]->par = nullptr;\n    if constexpr (semigroup<M>::value)\
    \ pushup(&ns[c]);\n  }\n  int par(std::size_t x) {\n    expose(&ns[x]);\n    Node\
    \ *t = ns[x].ch[0];\n    if (!t) return -1;\n    while (t->ch[1]) eval(t), t =\
    \ t->ch[1];\n    return splay(t), t - &ns[0];\n  }\n  int lca(std::size_t x, std::size_t\
    \ y) {\n    if (x == y) return x;\n    expose(&ns[x]);\n    Node *u = expose(&ns[y]);\n\
    \    return ns[x].par ? u - &ns[0] : -1;\n  }\n  const T &operator[](std::size_t\
    \ k) { return expose(&ns[k]), ns[k].val; }\n  void set_val(std::size_t k, T v)\
    \ {\n    static_assert(semigroup<M>::value || dual<M>::value,\n              \
    \    \"\\\"set_val\\\" is not available\\n\");\n    expose(&ns[k]), ns[k].val\
    \ = v;\n    if constexpr (semigroup<M>::value) pushup(&ns[k]);\n  }\n  T fold(std::size_t\
    \ a, std::size_t b) {  // [a,b] closed section\n    static_assert(semigroup<M>::value,\
    \ \"\\\"fold\\\" is not available\\n\");\n    return evert(a), expose(&ns[b]),\
    \ ns[b].sum;\n  }\n  void apply(std::size_t a, std::size_t b, E v) {  // [a,b]\
    \ closed section\n    static_assert(dual<M>::value, \"\\\"apply\\\" is not available\\\
    n\");\n    evert(a), expose(&ns[b]), propagate(&ns[b], v), eval(&ns[b]);\n  }\n\
    \  static std::string which_available() {\n    std::string ret = \"\";\n    if\
    \ constexpr (semigroup<M>::value) ret += \"\\\"fold\\\" \";\n    if constexpr\
    \ (dual<M>::value) ret += \"\\\"apply\\\" \";\n    return ret;\n  }\n};\n#line\
    \ 3 \"src/Math/ModInt.hpp\"\n/**\n * @title ModInt\n * @category \u6570\u5B66\n\
    \ */\n\n// BEGIN CUT HERE\n\ntemplate <std::uint64_t mod, std::uint64_t prim_root\
    \ = 0>\nclass ModInt {\n  using u64 = std::uint64_t;\n  using u128 = __uint128_t;\n\
    \  static constexpr u64 mul_inv(u64 n, int e = 6, u64 x = 1) {\n    return e ==\
    \ 0 ? x : mul_inv(n, e - 1, x * (2 - x * n));\n  }\n  static constexpr u64 inv\
    \ = mul_inv(mod, 6, 1), r2 = -u128(mod) % mod;\n  static constexpr u64 init(u64\
    \ w) { return reduce(u128(w) * r2); }\n  static constexpr u64 reduce(const u128\
    \ w) {\n    return u64(w >> 64) + mod - ((u128(u64(w) * inv) * mod) >> 64);\n\
    \  }\n\n public:\n  constexpr ModInt() : x(0) {}\n  constexpr ModInt(std::int64_t\
    \ n) : x(init(n < 0 ? mod - (-n) % mod : n)) {}\n  ~ModInt() = default;\n  static\
    \ constexpr u64 modulo() { return mod; }\n  static constexpr u64 norm(u64 w) {\
    \ return w - (mod & -(w >= mod)); }\n  static constexpr u64 pr_rt() { return prim_root;\
    \ }\n  constexpr ModInt operator-() const {\n    ModInt ret;\n    return ret.x\
    \ = ((mod << 1) & -(x != 0)) - x, ret;\n  }\n  constexpr ModInt &operator+=(const\
    \ ModInt &rhs) {\n    return x += rhs.x - (mod << 1), x += (mod << 1) & -(x >>\
    \ 63), *this;\n  }\n  constexpr ModInt &operator-=(const ModInt &rhs) {\n    return\
    \ x -= rhs.x, x += (mod << 1) & -(x >> 63), *this;\n  }\n  constexpr ModInt &operator*=(const\
    \ ModInt &rhs) {\n    return this->x = reduce(u128(this->x) * rhs.x), *this;\n\
    \  }\n  constexpr ModInt &operator/=(const ModInt &rhs) {\n    return this->operator*=(rhs.inverse());\n\
    \  }\n  ModInt operator+(const ModInt &rhs) const { return ModInt(*this) += rhs;\
    \ }\n  ModInt operator-(const ModInt &rhs) const { return ModInt(*this) -= rhs;\
    \ }\n  ModInt operator*(const ModInt &rhs) const { return ModInt(*this) *= rhs;\
    \ }\n  ModInt operator/(const ModInt &rhs) const { return ModInt(*this) /= rhs;\
    \ }\n  bool operator==(const ModInt &rhs) const { return norm(x) == norm(rhs.x);\
    \ }\n  bool operator!=(const ModInt &rhs) const { return norm(x) != norm(rhs.x);\
    \ }\n  u64 val() const {\n    u64 ret = reduce(x) - mod;\n    return ret + (mod\
    \ & -(ret >> 63));\n  }\n  constexpr ModInt pow(u64 k) const {\n    ModInt ret\
    \ = ModInt(1);\n    for (ModInt base = *this; k; k >>= 1, base *= base)\n    \
    \  if (k & 1) ret *= base;\n    return ret;\n  }\n  constexpr ModInt inverse()\
    \ const { return pow(mod - 2); }\n  constexpr ModInt sqrt() const {\n    if (*this\
    \ == ModInt(0) || mod == 2) return *this;\n    if (pow((mod - 1) >> 1) != 1) return\
    \ ModInt(0);  // no solutions\n    ModInt ONE = 1, b(2), w(b * b - *this);\n \
    \   while (w.pow((mod - 1) >> 1) == ONE) b += ONE, w = b * b - *this;\n    auto\
    \ mul = [&](std::pair<ModInt, ModInt> u, std::pair<ModInt, ModInt> v) {\n    \
    \  ModInt a = (u.first * v.first + u.second * v.second * w);\n      ModInt b =\
    \ (u.first * v.second + u.second * v.first);\n      return std::make_pair(a, b);\n\
    \    };\n    u64 e = (mod + 1) >> 1;\n    auto ret = std::make_pair(ONE, ModInt(0));\n\
    \    for (auto bs = std::make_pair(b, ONE); e; e >>= 1, bs = mul(bs, bs))\n  \
    \    if (e & 1) ret = mul(ret, bs);\n    return ret.first.val() * 2 < mod ? ret.first\
    \ : -ret.first;\n  }\n  friend std::istream &operator>>(std::istream &is, ModInt\
    \ &rhs) {\n    return is >> rhs.x, rhs.x = init(rhs.x), is;\n  }\n  friend std::ostream\
    \ &operator<<(std::ostream &os, const ModInt &rhs) {\n    return os << rhs.val();\n\
    \  }\n  u64 x;\n};\n#line 6 \"test/yosupo/dynamic_tree_vertex_set_path_composite.LCT.test.cpp\"\
    \nusing namespace std;\n#undef call_from_test\n\nusing Mint = ModInt<998244353>;\n\
    struct RcompositeQ {\n  using T = pair<Mint, Mint>;\n  static T op(const T &l,\
    \ const T &r) {\n    return make_pair(r.first * l.first, r.first * l.second +\
    \ r.second);\n  }\n};\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  int N, Q;\n  cin >> N >> Q;\n  LinkCutTree<RcompositeQ> lct(N);\n  for (int\
    \ i = 0; i < N; i++) {\n    Mint a, b;\n    cin >> a >> b;\n    lct.set_val(i,\
    \ {a, b});\n  }\n  for (int i = 0; i < N - 1; i++) {\n    int u, v;\n    cin >>\
    \ u >> v;\n    lct.link(u, v);\n  }\n  while (Q--) {\n    int op;\n    cin >>\
    \ op;\n    if (op == 0) {\n      int u, v, w, x;\n      cin >> u >> v >> w >>\
    \ x;\n      lct.cut(u, v);\n      lct.link(w, x);\n    } else if (op == 1) {\n\
    \      int p;\n      Mint c, d;\n      cin >> p >> c >> d;\n      lct.set_val(p,\
    \ {c, d});\n    } else {\n      int u, v;\n      Mint x;\n      cin >> u >> v\
    \ >> x;\n      auto ans = lct.fold(u, v);\n      cout << ans.first * x + ans.second\
    \ << endl;\n    }\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite\"\
    \n#include <bits/stdc++.h>\n#include \"src/DataStructure/LinkCutTree.hpp\"\n#include\
    \ \"src/Math/ModInt.hpp\"\nusing namespace std;\n#undef call_from_test\n\nusing\
    \ Mint = ModInt<998244353>;\nstruct RcompositeQ {\n  using T = pair<Mint, Mint>;\n\
    \  static T op(const T &l, const T &r) {\n    return make_pair(r.first * l.first,\
    \ r.first * l.second + r.second);\n  }\n};\n\nsigned main() {\n  cin.tie(0);\n\
    \  ios::sync_with_stdio(0);\n  int N, Q;\n  cin >> N >> Q;\n  LinkCutTree<RcompositeQ>\
    \ lct(N);\n  for (int i = 0; i < N; i++) {\n    Mint a, b;\n    cin >> a >> b;\n\
    \    lct.set_val(i, {a, b});\n  }\n  for (int i = 0; i < N - 1; i++) {\n    int\
    \ u, v;\n    cin >> u >> v;\n    lct.link(u, v);\n  }\n  while (Q--) {\n    int\
    \ op;\n    cin >> op;\n    if (op == 0) {\n      int u, v, w, x;\n      cin >>\
    \ u >> v >> w >> x;\n      lct.cut(u, v);\n      lct.link(w, x);\n    } else if\
    \ (op == 1) {\n      int p;\n      Mint c, d;\n      cin >> p >> c >> d;\n   \
    \   lct.set_val(p, {c, d});\n    } else {\n      int u, v;\n      Mint x;\n  \
    \    cin >> u >> v >> x;\n      auto ans = lct.fold(u, v);\n      cout << ans.first\
    \ * x + ans.second << endl;\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - src/DataStructure/LinkCutTree.hpp
  - src/Math/ModInt.hpp
  isVerificationFile: true
  path: test/yosupo/dynamic_tree_vertex_set_path_composite.LCT.test.cpp
  requiredBy: []
  timestamp: '2021-10-22 14:35:08+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/dynamic_tree_vertex_set_path_composite.LCT.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/dynamic_tree_vertex_set_path_composite.LCT.test.cpp
- /verify/test/yosupo/dynamic_tree_vertex_set_path_composite.LCT.test.cpp.html
title: test/yosupo/dynamic_tree_vertex_set_path_composite.LCT.test.cpp
---