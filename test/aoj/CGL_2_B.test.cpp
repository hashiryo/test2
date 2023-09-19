#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_B"
#include <iostream>
#include "src/Geometry/Segment.hpp"
using namespace std;
signed main() {
 cin.tie(0);
 ios::sync_with_stdio(false);
 using namespace geo;
 int q;
 cin >> q;
 while (q--) {
  Segment<Point<long double>> s, t;
  cin >> s.p >> s.q >> t.p >> t.q;
  cout << (cross_points(s, t).size() > 0) << '\n';
 }
 return 0;
}