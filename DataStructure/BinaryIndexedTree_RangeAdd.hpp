/**
 * @title Binary-Indexed-Tree(区間加算)
 * @category データ構造
 * @brief O(logN)
 * @brief 0-indexed
 */

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

struct BinaryIndexedTree_RangeAdd {
  vector<long long> dat1;
  vector<long long> dat2;
  BinaryIndexedTree_RangeAdd(int n) : dat1(n + 1, 0), dat2(n + 1, 0) {}
  // add w [l,r)
  void add_range(int l, int r, long long w) {
    for (int k = l + 1; k < (int)dat1.size(); k += k & -k) dat1[k] -= w * l;
    for (int k = r + 1; k < (int)dat1.size(); k += k & -k) dat1[k] += w * r;
    for (int k = l + 1; k < (int)dat2.size(); k += k & -k) dat2[k] += w;
    for (int k = r + 1; k < (int)dat2.size(); k += k & -k) dat2[k] -= w;
  }
  // sum [0,x)
  long long operator[](int x) {
    long long s = 0;
    for (int k = x; k > 0; k &= k - 1) s += dat1[k];
    for (int k = x; k > 0; k &= k - 1) s += dat2[k] * x;
    return s;
  }
};
