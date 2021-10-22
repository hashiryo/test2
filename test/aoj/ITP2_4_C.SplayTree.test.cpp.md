---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/SplayTree.hpp
    title: "Splay\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/all/ITP2_4_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/all/ITP2_4_C
  bundledCode: "#line 1 \"test/aoj/ITP2_4_C.SplayTree.test.cpp\"\n#define PROBLEM\
    \ \\\n  \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/all/ITP2_4_C\"\
    \n#include <bits/stdc++.h>\n#line 3 \"src/DataStructure/SplayTree.hpp\"\n/**\n\
    \ * @title Splay\u6728\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n * @brief\
    \ O(logN)\n * \u6728\u306E\u6DF1\u3055\u304C10^5\u3050\u3089\u3044\u306B\u306A\
    \u308B\u3068\u518D\u5E30\u95A2\u6570\u304C\u30B9\u30BF\u30C3\u30AF\u30AA\u30FC\
    \u30D0\u30FC\u30D5\u30ED\u30FC\u8D77\u3053\u3059\u306E\u3067\u6CE8\u610F\n * set_balance()\
    \ \u3067\u30E9\u30F3\u30C0\u30E0\u306Bsplay\u3059\u308B\u306E\u3067\u306A\u3089\
    \u3059\u3053\u3068\u304C\u3067\u304D\u308B\u306F\u305A\n * \u5358\u4F4D\u5143\u306F\
    \u5FC5\u8981\u306A\u3057\uFF08\u9045\u5EF6\u5074\u3082\uFF09\n * \u533A\u9593\
    reverse\u304C\u3067\u304D\u308B\u3002\uFF08\u534A\u7FA4\u306E\u53EF\u63DB\u6027\
    \u3092\u4EEE\u5B9A\u3057\u3066\u3044\u306A\u3044\u306E\u3067\u7121\u99C4\u306B\
    \u30E1\u30E2\u30EA\u3068\u6642\u9593\u3092\u4F7F\u3046\u3051\u3069\uFF09\n * \u5404\
    \u30CE\u30FC\u30C9\u304C\u90E8\u5206\u6728\u306E\u30B5\u30A4\u30BA\u3092\u4FDD\
    \u6301\u3057\u3066\u3044\u308B\u306E\u3067mapping\u95A2\u6570\u3067\u306F\u5F15\
    \u6570\u3068\u3057\u3066size\u3092\u6E21\u305B\u308B\n */\n\n// BEGIN CUT HERE\n\
    #define HAS_CHECK(member, Dummy)                              \\\n  template <class\
    \ T>                                          \\\n  struct has_##member {    \
    \                                   \\\n    template <class U, Dummy>        \
    \                         \\\n    static std::true_type check(U *);          \
    \               \\\n    static std::false_type check(...);                   \
    \     \\\n    static T *mClass;                                         \\\n \
    \   static const bool value = decltype(check(mClass))::value; \\\n  };\n#define\
    \ HAS_MEMBER(member) HAS_CHECK(member, int dummy = (&U::member, 0))\n#define HAS_TYPE(member)\
    \ HAS_CHECK(member, class dummy = typename U::member)\n\ntemplate <class M, bool\
    \ reversible = false>\nclass SplayTree {\n  HAS_MEMBER(op);\n  HAS_MEMBER(mapping);\n\
    \  HAS_MEMBER(composition)\n  HAS_TYPE(T);\n  HAS_TYPE(E);\n  template <class\
    \ L>\n  using semigroup = std::conjunction<has_T<L>, has_op<L>>;\n  template <class\
    \ L>\n  using dual =\n      std::conjunction<has_T<L>, has_E<L>, has_mapping<L>,\
    \ has_composition<L>>;\n  template <class T, class tDerived, class F = std::nullptr_t>\n\
    \  struct Node_B {\n    using E = F;\n    T val;\n    tDerived *ch[2];\n    std::size_t\
    \ size;\n  };\n  template <bool sg_, bool du_, bool rev_, typename tEnable = void>\n\
    \  struct Node_D : Node_B<M, Node_D<sg_, du_, rev_, tEnable>> {};\n  template\
    \ <bool sg_, bool du_, bool rev_>\n  struct Node_D<sg_, du_, rev_, typename std::enable_if_t<sg_\
    \ && !du_ && !rev_>>\n      : Node_B<typename M::T, Node_D<sg_, du_, rev_>> {\n\
    \    typename M::T sum;\n  };\n  template <bool sg_, bool du_, bool rev_>\n  struct\
    \ Node_D<sg_, du_, rev_, typename std::enable_if_t<!sg_ && du_ && !rev_>>\n  \
    \    : Node_B<typename M::T, Node_D<sg_, du_, rev_>, typename M::E> {\n    typename\
    \ M::E lazy;\n    bool lazy_flg = false;\n  };\n  template <bool sg_, bool du_,\
    \ bool rev_>\n  struct Node_D<sg_, du_, rev_, typename std::enable_if_t<sg_ &&\
    \ du_ && !rev_>>\n      : Node_B<typename M::T, Node_D<sg_, du_, rev_>, typename\
    \ M::E> {\n    typename M::T sum;\n    typename M::E lazy;\n    bool lazy_flg\
    \ = false;\n  };\n  template <bool sg_, bool du_, bool rev_>\n  struct Node_D<sg_,\
    \ du_, rev_, typename std::enable_if_t<!sg_ && !du_ && rev_>>\n      : Node_B<M,\
    \ Node_D<sg_, du_, rev_>> {\n    bool rev_flg = false;\n  };\n  template <bool\
    \ sg_, bool du_, bool rev_>\n  struct Node_D<sg_, du_, rev_, typename std::enable_if_t<sg_\
    \ && !du_ && rev_>>\n      : Node_B<typename M::T, Node_D<sg_, du_, rev_>> {\n\
    \    typename M::T sum, rsum;\n    bool rev_flg = false;\n  };\n  template <bool\
    \ sg_, bool du_, bool rev_>\n  struct Node_D<sg_, du_, rev_, typename std::enable_if_t<!sg_\
    \ && du_ && rev_>>\n      : Node_B<typename M::T, Node_D<sg_, du_, rev_>, typename\
    \ M::E> {\n    typename M::E lazy;\n    bool lazy_flg = false, rev_flg = false;\n\
    \  };\n  template <bool sg_, bool du_, bool rev_>\n  struct Node_D<sg_, du_, rev_,\
    \ typename std::enable_if_t<sg_ && du_ && rev_>>\n      : Node_B<typename M::T,\
    \ Node_D<sg_, du_, rev_>, typename M::E> {\n    typename M::T sum, rsum;\n   \
    \ typename M::E lazy;\n    bool lazy_flg = false, rev_flg = false;\n  };\n  using\
    \ Node = Node_D<semigroup<M>::value, dual<M>::value, reversible>;\n  using T =\
    \ decltype(Node::val);\n  using E = typename Node::E;\n  Node *root;\n  Node *make_tree(T\
    \ *beg, T *ed) {\n    if (beg == ed) return nullptr;\n    T *mid = beg + (ed -\
    \ beg) / 2;\n    return pushup(\n        new Node{*mid, {make_tree(beg, mid),\
    \ make_tree(mid + 1, ed)}});\n  }\n  Node *make_tree(std::size_t beg, std::size_t\
    \ ed, const T &val) {\n    if (beg == ed) return nullptr;\n    std::size_t mid\
    \ = beg + (ed - beg) / 2;\n    return pushup(\n        new Node{val, {make_tree(beg,\
    \ mid, val), make_tree(mid + 1, ed, val)}});\n  }\n  void dump(typename std::vector<T>::iterator\
    \ itr, Node *t) {\n    if (!t) return;\n    if constexpr (dual<M>::value) eval_propagate(t);\n\
    \    if constexpr (reversible) eval_toggle(t);\n    dump(itr, t->ch[0]);\n   \
    \ std::size_t sz = t->ch[0] ? t->ch[0]->size : 0;\n    *(itr + sz) = t->val;\n\
    \    dump(itr + sz + 1, t->ch[1]);\n  }\n  inline Node *pushup(Node *t) {\n  \
    \  if (!t) return t;\n    t->size = 1;\n    if constexpr (semigroup<M>::value)\
    \ {\n      t->sum = t->val;\n      if constexpr (reversible) t->rsum = t->val;\n\
    \    }\n    if (t->ch[0]) {\n      t->size += t->ch[0]->size;\n      if constexpr\
    \ (semigroup<M>::value) {\n        t->sum = M::op(t->ch[0]->sum, t->sum);\n  \
    \      if constexpr (reversible) t->rsum = M::op(t->rsum, t->ch[0]->rsum);\n \
    \     }\n    }\n    if (t->ch[1]) {\n      t->size += t->ch[1]->size;\n      if\
    \ constexpr (semigroup<M>::value) {\n        t->sum = M::op(t->sum, t->ch[1]->sum);\n\
    \        if constexpr (reversible) t->rsum = M::op(t->ch[1]->rsum, t->rsum);\n\
    \      }\n    }\n    return t;\n  }\n  inline Node *propagate(Node *t, const E\
    \ &x) {\n    t->lazy = t->lazy_flg ? M::composition(t->lazy, x) : x;\n    if constexpr\
    \ (semigroup<M>::value) {\n      t->sum = M::mapping(t->sum, x, t->size);\n  \
    \    if constexpr (reversible) t->rsum = M::mapping(t->rsum, x, t->size);\n  \
    \  }\n    return t->val = M::mapping(t->val, x, 1), t->lazy_flg = true, t;\n \
    \ }\n  inline Node *toggle(Node *t) {\n    if constexpr (semigroup<M>::value)\
    \ std::swap(t->sum, t->rsum);\n    return std::swap(t->ch[0], t->ch[1]), t->rev_flg\
    \ = !t->rev_flg, t;\n  }\n  inline void eval_propagate(Node *t) {\n    if (!t->lazy_flg)\
    \ return;\n    if (t->ch[0]) propagate(t->ch[0], t->lazy);\n    if (t->ch[1])\
    \ propagate(t->ch[1], t->lazy);\n    t->lazy_flg = false;\n  }\n  inline void\
    \ eval_toggle(Node *t) {\n    if (!t->rev_flg) return;\n    if (t->ch[0]) toggle(t->ch[0]);\n\
    \    if (t->ch[1]) toggle(t->ch[1]);\n    t->rev_flg = false;\n  }\n  inline void\
    \ rot(Node *&t, bool d) {\n    Node *s = t->ch[d];\n    t->ch[d] = s->ch[!d],\
    \ s->ch[!d] = pushup(t), t = pushup(s);\n  }\n  inline void splay(Node *&t, std::size_t\
    \ k) {\n    if (!t) return;\n    if constexpr (dual<M>::value) eval_propagate(t);\n\
    \    if constexpr (reversible) eval_toggle(t);\n    static std::size_t sz;\n \
    \   sz = t->ch[0] ? t->ch[0]->size : 0;\n    if (sz == k) return;\n    bool d\
    \ = sz < k;\n    if (d) k -= sz + 1;\n    if constexpr (dual<M>::value) eval_propagate(t->ch[d]);\n\
    \    if constexpr (reversible) eval_toggle(t->ch[d]);\n    sz = t->ch[d]->ch[0]\
    \ ? t->ch[d]->ch[0]->size : 0;\n    if (sz != k) {\n      bool c = sz < k;\n \
    \     if (c) k -= sz + 1;\n      splay(t->ch[d]->ch[c], k);\n      c == d ? rot(t,\
    \ d) : rot(t->ch[d], !d);\n    }\n    rot(t, d);\n  }\n  template <class F>\n\
    \  void query(std::size_t a, std::size_t b, const F &f) {\n    if (size() == b)\
    \ {\n      a-- ? splay(root, a), f(root->ch[1]), pushup(root) : f(root);\n   \
    \ } else {\n      splay(root, b);\n      a-- ? (splay(root->ch[0], a), f(root->ch[0]->ch[1]),\
    \ pushup(root->ch[0]))\n          : f(root->ch[0]);\n      pushup(root);\n   \
    \ }\n  }\n  static inline unsigned xor128() {\n    static unsigned x = 123456789,\
    \ y = 362436069, z = 521288629, w = 88675123;\n    unsigned t = (x ^ (x << 11));\n\
    \    return x = y, y = z, z = w, (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));\n  }\n\
    \n public:\n  SplayTree(Node *t = nullptr) : root(t) {}\n  SplayTree(std::size_t\
    \ n, T val) { root = make_tree(0, n, val); }\n  SplayTree(T *beg, T *ed) { root\
    \ = make_tree(beg, ed); }\n  SplayTree(const std::vector<T> &ar) {\n    root =\
    \ make_tree(ar.data(), ar.data() + ar.size());\n  }\n  std::vector<T> dump() {\n\
    \    std::vector<T> ret(size());\n    return dump(ret.begin(), root), ret;\n \
    \ }\n  static std::string which_available() {\n    std::string ret = \"\";\n \
    \   if constexpr (semigroup<M>::value) ret += \"\\\"fold\\\" \";\n    if constexpr\
    \ (dual<M>::value) ret += \"\\\"apply\\\" \";\n    if constexpr (reversible) ret\
    \ += \"\\\"reverse\\\" \";\n    return ret;\n  }\n  std::size_t size() { return\
    \ root ? root->size : 0; }\n  void clear() { root = nullptr; }\n  const T &operator[](std::size_t\
    \ k) { return splay(root, k), root->val; }\n  void set_val(std::size_t k, T val)\
    \ {\n    splay(root, k), root->val = val, pushup(root);\n  }\n  void set_balance()\
    \ {\n    if (root) splay(root, xor128() % size()), splay(root, xor128() % size());\n\
    \  }\n  T fold(std::size_t a, std::size_t b) {\n    static_assert(semigroup<M>::value,\
    \ \"\\\"fold\\\" is not available\");\n    if (size() == b) {\n      return a--\
    \ ? splay(root, a), root->ch[1]->sum : root->sum;\n    } else {\n      splay(root,\
    \ b);\n      return a-- ? (splay(root->ch[0], a), root->ch[0]->ch[1]->sum)\n \
    \                : root->ch[0]->sum;\n    }\n  }\n  void apply(std::size_t a,\
    \ std::size_t b, E x) {\n    static_assert(dual<M>::value, \"\\\"apply\\\" is\
    \ not available\");\n    query(a, b, [&](Node *t) { return propagate(t, x); });\n\
    \  }\n  void reverse(std::size_t a, std::size_t b) {\n    static_assert(reversible,\
    \ \"\\\"reverse\\\" is not available\");\n    query(a, b, [&](Node *t) { return\
    \ toggle(t); });\n  }\n  std::pair<SplayTree, SplayTree> split(std::size_t k)\
    \ {\n    assert(k <= size());\n    if (size() == k) return {*this, SplayTree()};\n\
    \    splay(root, k);\n    Node *l = root->ch[0];\n    root->ch[0] = nullptr;\n\
    \    return {SplayTree(l), SplayTree(pushup(root))};\n  }\n  std::tuple<SplayTree,\
    \ SplayTree, SplayTree> split3(std::size_t a,\n                              \
    \                       std::size_t b) {\n    auto [tmp, right] = split(b);\n\
    \    auto [left, center] = tmp.split(a);\n    return {left, center, right};\n\
    \  }\n  SplayTree &operator+=(SplayTree rhs) {  // merge\n    root ? (splay(root,\
    \ root->size - 1), root->ch[1] = rhs.root, pushup(root))\n         : root = rhs.root;\n\
    \    return *this;\n  }\n  SplayTree &operator+(SplayTree rhs) { return *this\
    \ += rhs; }\n  void push_back(T val) { insert(size(), val); }\n  void push_front(T\
    \ val) { insert(0, val); }\n  void insert(std::size_t k, T val) {\n    assert(!k\
    \ || (root && k <= root->size));\n    if (size() == k) {\n      root = pushup(new\
    \ Node{val, {root, nullptr}});\n    } else {\n      splay(root, k), root = new\
    \ Node{val, {root->ch[0], root}};\n      root->ch[1]->ch[0] = nullptr, pushup(root->ch[1]),\
    \ pushup(root);\n    }\n  }\n  T pop_back() { return erase(root->size - 1); }\n\
    \  T pop_front() { return erase(0); }\n  T erase(std::size_t k) {\n    assert(root\
    \ && k < root->size);\n    splay(root, k);\n    T ret = root->val;\n    splay(root->ch[1],\
    \ 0);\n    if (root->ch[1])\n      root->ch[1]->ch[0] = root->ch[0], root = pushup(root->ch[1]);\n\
    \    else\n      root = root->ch[0];\n    return ret;\n  }\n};\n#line 5 \"test/aoj/ITP2_4_C.SplayTree.test.cpp\"\
    \nusing namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  int n;\n  cin >> n;\n  int a[n];\n  for (int i = 0; i < n; i++) cin >> a[i];\n\
    \  SplayTree<int> ar(a, a + n);\n  int q;\n  cin >> q;\n  for (int i = 0; i <\
    \ q; i++) {\n    int b, e, t;\n    cin >> b >> e >> t;\n    int f = t + e - b;\n\
    \    if (t < b) swap(b, t), swap(e, f);\n    auto [tl, tc, tr] = ar.split3(t,\
    \ f);\n    auto [bl, bc, br] = tl.split3(b, e);\n    ar = bl + tc + br + bc +\
    \ tr;\n  }\n  auto ans = ar.dump();\n  for (int i = 0; i < n; i++) cout << (i\
    \ ? \" \" : \"\") << ans[i];\n  cout << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/all/ITP2_4_C\"\
    \n#include <bits/stdc++.h>\n#include \"src/DataStructure/SplayTree.hpp\"\nusing\
    \ namespace std;\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  int n;\n  cin >> n;\n  int a[n];\n  for (int i = 0; i < n; i++) cin >> a[i];\n\
    \  SplayTree<int> ar(a, a + n);\n  int q;\n  cin >> q;\n  for (int i = 0; i <\
    \ q; i++) {\n    int b, e, t;\n    cin >> b >> e >> t;\n    int f = t + e - b;\n\
    \    if (t < b) swap(b, t), swap(e, f);\n    auto [tl, tc, tr] = ar.split3(t,\
    \ f);\n    auto [bl, bc, br] = tl.split3(b, e);\n    ar = bl + tc + br + bc +\
    \ tr;\n  }\n  auto ans = ar.dump();\n  for (int i = 0; i < n; i++) cout << (i\
    \ ? \" \" : \"\") << ans[i];\n  cout << '\\n';\n  return 0;\n}"
  dependsOn:
  - src/DataStructure/SplayTree.hpp
  isVerificationFile: true
  path: test/aoj/ITP2_4_C.SplayTree.test.cpp
  requiredBy: []
  timestamp: '2021-10-21 17:43:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ITP2_4_C.SplayTree.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ITP2_4_C.SplayTree.test.cpp
- /verify/test/aoj/ITP2_4_C.SplayTree.test.cpp.html
title: test/aoj/ITP2_4_C.SplayTree.test.cpp
---