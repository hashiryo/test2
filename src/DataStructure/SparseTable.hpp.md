---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_3_D.sparsetable.test.cpp
    title: test/aoj/DSL_3_D.sparsetable.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Sparse-Table(\u533A\u9593min)"
    links: []
  bundledCode: "#line 2 \"src/DataStructure/SparseTable.hpp\"\n#include <bits/stdc++.h>\n\
    /**\n * @title Sparse-Table(\u533A\u9593min)\n * @category \u30C7\u30FC\u30BF\u69CB\
    \u9020\n * @brief RmQ\n * @brief \u69CB\u7BC9 O(n log n)\n * @brief query O(1)\n\
    \ */\n\n// BEGIN CUT HERE\n\ntemplate <class T>\nstruct SparseTable {\n  const\
    \ std::vector<T> &x;\n  std::vector<std::vector<int>> table;\n  int argmin(int\
    \ i, int j) { return x[i] < x[j] ? i : j; }\n  SparseTable(const std::vector<T>\
    \ &x) : x(x) {\n    int logn = sizeof(int) * __CHAR_BIT__ - 1 - __builtin_clz(x.size());\n\
    \    table.assign(logn + 1, std::vector<int>(x.size()));\n    iota(table[0].begin(),\
    \ table[0].end(), 0);\n    for (int h = 0; h + 1 <= logn; ++h)\n      for (int\
    \ i = 0; i + (1 << h) < x.size(); ++i)\n        table[h + 1][i] = argmin(table[h][i],\
    \ table[h][i + (1 << h)]);\n  }\n  T range_min(int i, int j) {  // = min x[i,j)\n\
    \    int h = sizeof(int) * __CHAR_BIT__ - 1 - __builtin_clz(j - i);  // = log2\n\
    \    return x[argmin(table[h][i], table[h][j - (1 << h)])];\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n/**\n * @title Sparse-Table(\u533A\
    \u9593min)\n * @category \u30C7\u30FC\u30BF\u69CB\u9020\n * @brief RmQ\n * @brief\
    \ \u69CB\u7BC9 O(n log n)\n * @brief query O(1)\n */\n\n// BEGIN CUT HERE\n\n\
    template <class T>\nstruct SparseTable {\n  const std::vector<T> &x;\n  std::vector<std::vector<int>>\
    \ table;\n  int argmin(int i, int j) { return x[i] < x[j] ? i : j; }\n  SparseTable(const\
    \ std::vector<T> &x) : x(x) {\n    int logn = sizeof(int) * __CHAR_BIT__ - 1 -\
    \ __builtin_clz(x.size());\n    table.assign(logn + 1, std::vector<int>(x.size()));\n\
    \    iota(table[0].begin(), table[0].end(), 0);\n    for (int h = 0; h + 1 <=\
    \ logn; ++h)\n      for (int i = 0; i + (1 << h) < x.size(); ++i)\n        table[h\
    \ + 1][i] = argmin(table[h][i], table[h][i + (1 << h)]);\n  }\n  T range_min(int\
    \ i, int j) {  // = min x[i,j)\n    int h = sizeof(int) * __CHAR_BIT__ - 1 - __builtin_clz(j\
    \ - i);  // = log2\n    return x[argmin(table[h][i], table[h][j - (1 << h)])];\n\
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/SparseTable.hpp
  requiredBy: []
  timestamp: '2020-10-23 23:21:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_3_D.sparsetable.test.cpp
documentation_of: src/DataStructure/SparseTable.hpp
layout: document
redirect_from:
- /library/src/DataStructure/SparseTable.hpp
- /library/src/DataStructure/SparseTable.hpp.html
title: "Sparse-Table(\u533A\u9593min)"
---