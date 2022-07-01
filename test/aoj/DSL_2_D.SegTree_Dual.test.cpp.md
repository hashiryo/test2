---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/SegmentTree_Dual.hpp
    title: "Segment-Tree(\u53CC\u5BFE)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D
  bundledCode: "#line 1 \"test/aoj/DSL_2_D.SegTree_Dual.test.cpp\"\n#define PROBLEM\
    \ \\\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D\"\n\
    #include <bits/stdc++.h>\n#line 3 \"src/DataStructure/SegmentTree_Dual.hpp\"\n\
    /**\n * @title Segment-Tree(\u53CC\u5BFE)\n * @category \u30C7\u30FC\u30BF\u69CB\
    \u9020\n * @brief O(logN)\n */\n\n// BEGIN CUT HERE\n\ntemplate <typename M>\n\
    struct SegmentTree_Dual {\n  using T = typename M::T;\n  using E = typename M::E;\n\
    \  SegmentTree_Dual() {}\n  SegmentTree_Dual(int n_, T v1 = T())\n      : n(n_),\
    \ height(ceil(log2(n))), val(n, v1), laz(n * 2, {E(), false}) {}\n  SegmentTree_Dual(const\
    \ std::vector<T> &v)\n      : n(v.size()), height(ceil(log2(n))), val(v), laz(n\
    \ * 2, {E(), false}) {}\n  void apply(int a, int b, E x) {\n    a += n, b += n;\n\
    \    for (int i = height; i >= 1; i--)\n      if (((a >> i) << i) != a) eval(a\
    \ >> i);\n    for (int i = height; i >= 1; i--)\n      if (((b >> i) << i) !=\
    \ b) eval((b - 1) >> i);\n    for (int l = a, r = b; l < r; l >>= 1, r >>= 1)\
    \ {\n      if (l & 1) propagate(l++, x);\n      if (r & 1) propagate(--r, x);\n\
    \    }\n  }\n  void set(int k, T x) {\n    for (int i = height; i; i--) eval((k\
    \ + n) >> i);\n    val[k] = x, laz[k + n].flg = false;\n  }\n  T operator[](const\
    \ int k) {\n    for (int i = height; i; i--) eval((k + n) >> i);\n    if (laz[k\
    \ + n].flg)\n      M::mapping(val[k], laz[k + n].val), laz[k + n].flg = false;\n\
    \    return val[k];\n  }\n\n private:\n  const int n, height;\n  struct Lazy {\n\
    \    E val;\n    bool flg;\n  };\n  std::vector<T> val;\n  std::vector<Lazy> laz;\n\
    \  inline void eval(int k) {\n    if (!laz[k].flg) return;\n    propagate(k <<\
    \ 1 | 0, laz[k].val), propagate(k << 1 | 1, laz[k].val);\n    laz[k].flg = false;\n\
    \  }\n  inline void propagate(int k, const E &x) {\n    laz[k].flg ? (M::composition(laz[k].val,\
    \ x), x) : laz[k].val = x;\n    laz[k].flg = true;\n  }\n};\n#line 5 \"test/aoj/DSL_2_D.SegTree_Dual.test.cpp\"\
    \nusing namespace std;\n\nstruct RupdQ {\n  using T = int;\n  using E = int;\n\
    \  static void mapping(T& v, const E& f) { v = f; }\n  static void composition(E&\
    \ pre, const E& suf) { pre = suf; }\n};\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  int n, q;\n  cin >> n >> q;\n  SegmentTree_Dual<RupdQ> seg(n, INT_MAX);\n \
    \ while (q--) {\n    bool com;\n    cin >> com;\n    if (com) {\n      int i;\n\
    \      cin >> i;\n      cout << seg[i] << endl;\n    } else {\n      int s, t,\
    \ x;\n      cin >> s >> t >> x;\n      seg.apply(s, t + 1, x);\n    }\n  }\n \
    \ return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D\"\
    \n#include <bits/stdc++.h>\n#include \"src/DataStructure/SegmentTree_Dual.hpp\"\
    \nusing namespace std;\n\nstruct RupdQ {\n  using T = int;\n  using E = int;\n\
    \  static void mapping(T& v, const E& f) { v = f; }\n  static void composition(E&\
    \ pre, const E& suf) { pre = suf; }\n};\n\nsigned main() {\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  int n, q;\n  cin >> n >> q;\n  SegmentTree_Dual<RupdQ> seg(n, INT_MAX);\n \
    \ while (q--) {\n    bool com;\n    cin >> com;\n    if (com) {\n      int i;\n\
    \      cin >> i;\n      cout << seg[i] << endl;\n    } else {\n      int s, t,\
    \ x;\n      cin >> s >> t >> x;\n      seg.apply(s, t + 1, x);\n    }\n  }\n \
    \ return 0;\n}"
  dependsOn:
  - src/DataStructure/SegmentTree_Dual.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_D.SegTree_Dual.test.cpp
  requiredBy: []
  timestamp: '2022-06-20 21:11:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_D.SegTree_Dual.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_D.SegTree_Dual.test.cpp
- /verify/test/aoj/DSL_2_D.SegTree_Dual.test.cpp.html
title: test/aoj/DSL_2_D.SegTree_Dual.test.cpp
---