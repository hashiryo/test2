---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Geometry/Line.hpp
    title: "\u76F4\u7DDA"
  - icon: ':heavy_check_mark:'
    path: src/Geometry/Point.hpp
    title: "\u70B9"
  - icon: ':heavy_check_mark:'
    path: src/Geometry/Segment.hpp
    title: "\u7DDA\u5206"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/Geometry/Convex.hpp
    title: "\u51F8\u591A\u89D2\u5F62"
  - icon: ':heavy_check_mark:'
    path: src/Geometry/intersection_area.hpp
    title: "\u5186\u3068\u306E\u5171\u901A\u90E8\u5206\u306E\u9762\u7A4D"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0253.test.cpp
    title: test/aoj/0253.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/0265.test.cpp
    title: test/aoj/0265.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/0342.test.cpp
    title: test/aoj/0342.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/0356.test.cpp
    title: test/aoj/0356.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/0375.test.cpp
    title: test/aoj/0375.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/0445.test.cpp
    title: test/aoj/0445.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1050.test.cpp
    title: test/aoj/1050.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1066.test.cpp
    title: test/aoj/1066.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1157.test.cpp
    title: test/aoj/1157.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1198.test.cpp
    title: test/aoj/1198.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1242.longdouble.test.cpp
    title: test/aoj/1242.longdouble.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1242.rational.test.cpp
    title: test/aoj/1242.rational.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1267.test.cpp
    title: test/aoj/1267.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1342.test.cpp
    title: test/aoj/1342.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2402.test.cpp
    title: test/aoj/2402.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2495.test.cpp
    title: test/aoj/2495.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2514.test.cpp
    title: test/aoj/2514.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2626.test.cpp
    title: test/aoj/2626.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3049.test.cpp
    title: test/aoj/3049.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_3_A.test.cpp
    title: test/aoj/CGL_3_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_3_B.test.cpp
    title: test/aoj/CGL_3_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_3_C.test.cpp
    title: test/aoj/CGL_3_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_4_A.test.cpp
    title: test/aoj/CGL_4_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_4_B.test.cpp
    title: test/aoj/CGL_4_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_4_C.test.cpp
    title: test/aoj/CGL_4_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_H.test.cpp
    title: test/aoj/CGL_7_H.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_I.test.cpp
    title: test/aoj/CGL_7_I.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc202_f.test.cpp
    title: test/atcoder/abc202_f.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Geometry/Segment.hpp\"\n#include <algorithm>\n#line\
    \ 2 \"src/Geometry/Line.hpp\"\n#include <vector>\n#line 2 \"src/Geometry/Point.hpp\"\
    \n#include <iostream>\n#include <fstream>\n#include <iomanip>\n#include <cmath>\n\
    #include <cassert>\nnamespace geo {\nusing namespace std;\nstruct Visualizer {\n\
    \ ofstream ofs;\n Visualizer(string s= \"visualize.txt\"): ofs(s) { ofs << fixed\
    \ << setprecision(10); }\n friend Visualizer &operator<<(Visualizer &vis, const\
    \ string &s) { return vis.ofs << s, vis; }\n};\ntemplate <class K> int sgn(K x)\
    \ {\n if constexpr (is_floating_point_v<K>) {\n  static constexpr K EPS= 1e-9;\n\
    \  return x < -EPS ? -1 : x > EPS;\n } else return x < 0 ? -1 : x > 0;\n}\ntemplate\
    \ <class K> K err_floor(K x) {\n K y= floor(x);\n if constexpr (is_floating_point_v<K>)\n\
    \  if (K z= y + 1, w= x - z; 0 <= sgn(w) && sgn(w - 1) < 0) return z;\n return\
    \ y;\n}\ntemplate <class K> K err_ceil(K x) {\n K y= ceil(x);\n if constexpr (is_floating_point_v<K>)\n\
    \  if (K z= y - 1, w= x - z; 0 < sgn(w + 1) && sgn(w) <= 0) return z;\n return\
    \ y;\n}\ntemplate <class K> struct Point {\n K x, y;\n Point(K x= K(), K y= K()):\
    \ x(x), y(y) {}\n Point &operator+=(const Point &p) { return x+= p.x, y+= p.y,\
    \ *this; }\n Point &operator-=(const Point &p) { return x-= p.x, y-= p.y, *this;\
    \ }\n Point &operator*=(K a) { return x*= a, y*= a, *this; }\n Point &operator/=(K\
    \ a) { return x/= a, y/= a, *this; }\n Point operator+(const Point &p) const {\
    \ return {x + p.x, y + p.y}; }\n Point operator-(const Point &p) const { return\
    \ {x - p.x, y - p.y}; }\n Point operator*(K a) const { return {x * a, y * a};\
    \ }\n Point operator/(K a) const { return {x / a, y / a}; }\n friend Point operator*(K\
    \ a, const Point &p) { return {a * p.x, a * p.y}; }\n Point operator-() const\
    \ { return {-x, -y}; }\n bool operator<(const Point &p) const {\n  int s= sgn(x\
    \ - p.x);\n  return s ? s < 0 : sgn(y - p.y) < 0;\n }\n bool operator>(const Point\
    \ &p) const { return p < *this; }\n bool operator<=(const Point &p) const { return\
    \ !(p < *this); }\n bool operator>=(const Point &p) const { return !(*this < p);\
    \ }\n bool operator==(const Point &p) const { return !sgn(x - p.x) && !sgn(y -\
    \ p.y); }\n bool operator!=(const Point &p) const { return sgn(x - p.x) || sgn(y\
    \ - p.y); }\n Point operator!() const { return {-y, x}; }  // rotate 90 degree\n\
    \ friend istream &operator>>(istream &is, Point &p) { return is >> p.x >> p.y;\
    \ }\n friend ostream &operator<<(ostream &os, const Point &p) { return os << \"\
    (\" << p.x << \", \" << p.y << \")\"; }\n friend Visualizer &operator<<(Visualizer\
    \ &vis, const Point &p) { return vis.ofs << p.x << \" \" << p.y << \"\\n\", vis;\
    \ }\n};\ntemplate <class K> K dot(const Point<K> &p, const Point<K> &q) { return\
    \ p.x * q.x + p.y * q.y; }\n// left turn: > 0, right turn: < 0\ntemplate <class\
    \ K> K cross(const Point<K> &p, const Point<K> &q) { return p.x * q.y - p.y *\
    \ q.x; }\ntemplate <class K> K norm2(const Point<K> &p) { return dot(p, p); }\n\
    template <class K> long double norm(const Point<K> &p) { return sqrt(norm2(p));\
    \ }\ntemplate <class K> K dist2(const Point<K> &p, const Point<K> &q) { return\
    \ norm2(p - q); }\ntemplate <class T, class U> long double dist(const T &a, const\
    \ U &b) { return sqrt(dist2(a, b)); }\nenum CCW { COUNTER_CLOCKWISE, CLOCKWISE,\
    \ ONLINE_BACK, ONLINE_FRONT, ON_SEGMENT };\nostream &operator<<(ostream &os, CCW\
    \ c) { return os << (c == COUNTER_CLOCKWISE ? \"COUNTER_CLOCKWISE\" : c == CLOCKWISE\
    \ ? \"CLOCKWISE\" : c == ONLINE_BACK ? \"ONLINE_BACK\" : c == ONLINE_FRONT ? \"\
    ONLINE_FRONT\" : \"ON_SEGMENT\"); }\ntemplate <class K> CCW ccw(const Point<K>\
    \ &p0, const Point<K> &p1, const Point<K> &p2) {\n Point a= p1 - p0, b= p2 - p0;\n\
    \ int s;\n if constexpr (is_floating_point_v<K>) s= sgn(sgn(cross(a, b) / sqrt(norm2(a)\
    \ * norm2(b))));\n else s= sgn(cross(a, b));\n if (s) return s > 0 ? COUNTER_CLOCKWISE\
    \ : CLOCKWISE;\n if (K d= dot(a, b); sgn(d) < 0) return ONLINE_BACK;\n else return\
    \ sgn(d - norm2(a)) > 0 ? ONLINE_FRONT : ON_SEGMENT;\n}\ntemplate <class K> struct\
    \ Line;\ntemplate <class K> struct Segment;\ntemplate <class K> struct Polygon;\n\
    template <class K> struct Convex;\ntemplate <class K> struct Affine {\n K a00=\
    \ 1, a01= 0, a10= 0, a11= 1;\n Point<K> b;\n Point<K> operator()(const Point<K>\
    \ &p) const { return {a00 * p.x + a01 * p.y + b.x, a10 * p.x + a11 * p.y + b.y};\
    \ }\n Line<K> operator()(const Line<K> &l);\n Segment<K> operator()(const Segment<K>\
    \ &s);\n Polygon<K> operator()(const Polygon<K> &p);\n Convex<K> operator()(const\
    \ Convex<K> &c);\n Affine operator*(const Affine &r) const { return {a00 * r.a00\
    \ + a01 * r.a10, a00 * r.a01 + a01 * r.a11, a10 * r.a00 + a11 * r.a10, a10 * r.a01\
    \ + a11 * r.a11, (*this)(r)}; }\n Affine &operator*=(const Affine &r) { return\
    \ *this= *this * r; }\n};\ntemplate <class K> Affine<K> translate(const Point<K>\
    \ &p) { return {1, 0, 0, 1, p}; }\n}\n#line 4 \"src/Geometry/Line.hpp\"\nnamespace\
    \ geo {\ntemplate <class K> struct Line {\n using P= Point<K>;\n P p, d;  // p+td\n\
    \ Line() {}\n // p + td\n Line(const P &p, const P &d): p(p), d(d) { assert(sgn(norm2(d)));\
    \ }\n // ax+by+c=0 ................. ax+by+c>0: left, ax+by+c=0: on, ax+by+c<0:\
    \ right\n Line(K a, K b, K c) {\n  int sa= sgn(a), sb= sgn(b);\n  assert(sa ||\
    \ sb);\n  d= P{b, -a}, p= sb ? P{0, -c / b} : P{-c / a, 0};\n }\n bool operator==(const\
    \ Line &l) const { return !sgn(cross(d, l.d)) && !where(l.p); }\n bool operator!=(const\
    \ Line &l) const { return sgn(cross(d, l.d)) || where(l.p); }\n // +1: left, 0:\
    \ on, -1: right\n int where(const P &q) const { return sgn(cross(d, q - p)); }\n\
    \ P project(const P &q) const { return p + dot(q - p, d) / norm2(d) * d; }\n //\
    \ return  a,b,c of ax+by+c=0\n tuple<K, K, K> coef() const { return make_tuple(-d.y,\
    \ d.x, cross(p, d)); }\n friend ostream &operator<<(ostream &os, const Line &l)\
    \ { return os << l.p << \" + t\" << l.d; }\n friend Visualizer &operator<<(Visualizer\
    \ &vis, const Line &l) {\n  auto [a, b, c]= l.coef();\n  return vis.ofs << \"\
    Line \" << a << \" \" << b << \" \" << c << \"\\n\", vis;\n }\n};\n// p + t(q-p)\n\
    template <class K> Line<K> line_through(const Point<K> &p, const Point<K> &q)\
    \ { return Line(p, q - p); }\ntemplate <class K> bool is_parallel(const Line<K>\
    \ &l, const Line<K> &m) { return !sgn(cross(l.d, m.d)); }\ntemplate <class K>\
    \ bool is_orthogonal(const Line<K> &l, const Line<K> &m) { return !sgn(dot(l.d,\
    \ m.d)); }\n// 1 : properly crossing, 0 : disjoint parallel, 2 : same line\ntemplate\
    \ <class K> vector<Point<K>> cross_points(const Line<K> &l, const Line<K> &m)\
    \ {\n K a= cross(m.d, l.d), b= cross(l.p - m.p, l.d);\n if (sgn(a)) return {m.p\
    \ + b / a * m.d};  // properly crossing\n if (sgn(b)) return {};             \
    \      // disjoint parallel\n return {m.p, m.p + m.d};                 // same\
    \ line\n}\n// perpendicular bisector ............ p on leftside\ntemplate <class\
    \ K> Line<K> bisector(const Point<K> &p, const Point<K> &q) { return Line((p +\
    \ q) / 2, !(q - p)); }\n// angle bisector ........... parallel -> 1 line, non-parallel\
    \ -> 2 lines\ntemplate <class K> vector<Line<K>> bisector(const Line<K> &l, const\
    \ Line<K> &m) {\n auto cp= cross_points(l, m);\n if (cp.size() != 1) return {Line((l.p\
    \ + m.p) / 2, l.d)};\n auto d= l.d / norm(l.d) + m.d / norm(m.d);\n return {Line(cp[0],\
    \ d), Line(cp[0], !d)};\n}\ntemplate <class K> K dist2(const Line<K> &l, const\
    \ Point<K> &p) {\n K a= cross(l.d, p - l.p);\n return a * a / norm2(l.d);\n}\n\
    template <class K> K dist2(const Point<K> &p, const Line<K> &l) { return dist2(l,\
    \ p); }\ntemplate <class K> K dist2(const Line<K> &l, const Line<K> &m) { return\
    \ is_parallel(l, m) ? dist2(l, m.p) : 0; }\ntemplate <class K> Affine<K> reflect(const\
    \ Line<K> &l) {\n K a= l.d.x * l.d.x, b= l.d.x * l.d.y * 2, c= l.d.y * l.d.y,\
    \ d= a + c;\n a/= d, b/= d, c/= d, d= a - c;\n return {d, b, b, -d, Point<K>{c\
    \ * 2 * l.p.x - b * l.p.y, a * 2 * l.p.y - b * l.p.x}};\n}\ntemplate <class K>\
    \ Line<K> Affine<K>::operator()(const Line<K> &l) { return line_through((*this)(l.p),\
    \ (*this)(l.p + l.d)); }\n}\n#line 4 \"src/Geometry/Segment.hpp\"\nnamespace geo\
    \ {\ntemplate <class K> struct Segment {\n using P= Point<K>;\n P p, q;\n Segment()\
    \ {}\n Segment(const P &p, const P &q): p(p), q(q) {}\n // do not consider the\
    \ direction\n bool operator==(const Segment &s) const { return (p == s.p && q\
    \ == s.q) || (p == s.q && q == s.p); }\n bool operator!=(const Segment &s) const\
    \ { return !(*this == s); }\n bool on(const P &r) const { return ccw(p, q, r)\
    \ == ON_SEGMENT; }\n P &operator[](int i) { return i ? q : p; }\n const P &operator[](int\
    \ i) const { return i ? q : p; }\n long double length() const { return dist(p,\
    \ q); }\n P closest_point(const P &r) const {\n  P d= q - p;\n  K a= dot(r - p,\
    \ d), b;\n  return sgn(a) > 0 ? sgn(a - (b= norm2(d))) < 0 ? p + a / b * d : q\
    \ : p;\n }\n friend ostream &operator<<(ostream &os, const Segment &s) { return\
    \ os << s.p << \"---\" << s.q; }\n friend Visualizer &operator<<(Visualizer &vis,\
    \ const Segment &s) { return vis.ofs << \"Segment \" << s.p.x << \" \" << s.p.y\
    \ << \" \" << s.q.x << \" \" << s.q.y << \"\\n\", vis; }\n};\n// 1: properly crossing,\
    \ 0: no intersect, 2: same line\ntemplate <class K> vector<Point<K>> cross_points(const\
    \ Segment<K> &s, const Line<K> &l) {\n Point d= s.q - s.p;\n K a= cross(d, l.d),\
    \ b= cross(l.p - s.p, l.d);\n if (sgn(a)) {\n  if (b/= a; sgn(b) < 0 || sgn(b\
    \ - 1) > 0) return {};  // no intersect\n  else return {s.p + b * d};        \
    \                   // properly crossing}\n }\n if (sgn(b)) return {};  // disjoint\
    \ parallel\n return {s.p, s.q};      // same line\n}\ntemplate <class K> vector<Point<K>>\
    \ cross_points(const Line<K> &l, const Segment<K> &s) { return cross_points(s,\
    \ l); }\n// 2: same line, 0: no intersect, 1: ...\ntemplate <class K> vector<Point<K>>\
    \ cross_points(const Segment<K> &s, const Segment<K> &t) {\n Point d= s.q - s.p,\
    \ e= t.q - t.p;\n K a= cross(d, e), b= cross(t.p - s.p, e);\n if (sgn(a)) {\n\
    \  if (b/= a; sgn(b) < 0 || sgn(b - 1) > 0) return {};                       //\
    \ no intersect\n  if (b= cross(d, s.p - t.p) / a; sgn(b) < 0 || sgn(b - 1) > 0)\
    \ return {};  // no intersect\n  return {t.p + b * e};                       \
    \                              // properly crossing\n }\n if (sgn(b)) return {};\
    \  // disjoint parallel\n vector<Point<K>> ps;    // same line\n auto insert_if_possible=\
    \ [&](const Point<K> &p) {\n  for (auto q: ps)\n   if (p == q) return;\n  ps.emplace_back(p);\n\
    \ };\n if (sgn(dot(t.p - s.p, t.q - s.p)) <= 0) insert_if_possible(s.p);\n if\
    \ (sgn(dot(t.p - s.q, t.q - s.q)) <= 0) insert_if_possible(s.q);\n if (sgn(dot(s.p\
    \ - t.p, s.q - t.p)) <= 0) insert_if_possible(t.p);\n if (sgn(dot(s.p - t.q, s.q\
    \ - t.q)) <= 0) insert_if_possible(t.q);\n return ps;\n}\nenum INTERSECTION {\
    \ CROSSING, TOUCHING, DISJOINT, OVERLAP };\nostream &operator<<(ostream &os, INTERSECTION\
    \ i) { return os << (i == CROSSING ? \"CROSSING\" : i == TOUCHING ? \"TOUCHING\"\
    \ : i == DISJOINT ? \"DISJOINT\" : \"OVERLAP\"); }\ntemplate <class K> INTERSECTION\
    \ intersection(const Segment<K> &s, const Segment<K> &t) {\n auto cp= cross_points(s,\
    \ t);\n return cp.size() == 0 ? DISJOINT : cp.size() == 2 ? OVERLAP : cp[0] ==\
    \ s.p || cp[0] == s.q || cp[0] == t.p || cp[0] == t.q ? TOUCHING : CROSSING;\n\
    }\ntemplate <class K> K dist2(const Segment<K> &s, const Point<K> &p) { return\
    \ dist2(p, s.closest_point(p)); }\ntemplate <class K> K dist2(const Point<K> &p,\
    \ const Segment<K> &s) { return dist2(s, p); }\ntemplate <class K> K dist2(const\
    \ Segment<K> &s, const Line<K> &l) { return cross_points(s, l).size() ? 0 : min(dist2(s.p,\
    \ l), dist2(s.q, l)); }\ntemplate <class K> K dist2(const Line<K> &l, const Segment<K>\
    \ &s) { return dist2(s, l); }\ntemplate <class K> K dist2(const Segment<K> &s,\
    \ const Segment<K> &t) { return cross_points(s, t).size() ? 0 : min({dist2(s,\
    \ t.p), dist2(s, t.q), dist2(t, s.p), dist2(t, s.q)}); }\ntemplate <class K> Segment<K>\
    \ Affine<K>::operator()(const Segment<K> &s) { return {(*this)(s.p), (*this)(s.q)};\
    \ }\n}\n#line 3 \"src/Geometry/Polygon.hpp\"\nnamespace geo {\n// build counterclockwise\n\
    template <class K> class Polygon {\n using P= Point<K>;\n K a2= 0;\nprotected:\n\
    \ vector<P> dat;\n void build() {\n  if (dat.empty()) return;\n  a2= cross(dat.back(),\
    \ dat[0]);\n  for (int i= this->size(); --i;) a2+= cross(dat[i - 1], dat[i]);\n\
    \  if (a2 < 0) reverse(dat.begin(), dat.end()), a2= -a2;\n }\n template <int opp>\
    \ inline bool contain(const Segment<K> &s) const {\n  assert(dat.size());\n  if\
    \ (where(s.p) == opp || where(s.q) == opp) return false;\n  vector<P> ps, qs;\n\
    \  for (const auto &e: edges())\n   if (auto cp= cross_points(s, e); cp.size())\
    \ ps.insert(ps.end(), cp.begin(), cp.end());\n  if (ps.empty()) return true;\n\
    \  sort(ps.begin(), ps.end()), ps.erase(unique(ps.begin(), ps.end()), ps.end());\n\
    \  for (int i= ps.size(); --i;) qs.emplace_back((ps[i] + ps[i - 1]) / 2);\n  for\
    \ (const auto &q: qs)\n   if (where(q) == opp) return false;\n  return true;\n\
    \ }\npublic:\n Polygon() {}\n Polygon(const vector<P> &ps): dat(ps) { build();\
    \ }\n inline int prev(int i) const { return i ? i - 1 : (int)this->size() - 1;\
    \ }\n inline int next(int i) const { return i + 1 >= (int)this->size() ? 0 : i\
    \ + 1; }\n const P &operator[](int i) const { return dat[i]; }\n auto begin()\
    \ const { return dat.begin(); }\n auto end() const { return dat.end(); }\n size_t\
    \ size() const { return dat.size(); }\n vector<Segment<K>> edges() const {\n \
    \ vector<Segment<K>> es;\n  for (int i= 0, e= dat.size(); i < e; ++i) es.emplace_back(dat[i],\
    \ dat[next(i)]);\n  return es;\n }\n // assuming no self-intersections\n bool\
    \ is_convex() const {\n  assert(dat.size());\n  for (int i= dat.size(); i--;)\n\
    \   if (P a= dat[i], b= a - dat[prev(i)], c= dat[next(i)] - a; sgn(cross(b, c))\
    \ < 0) return false;\n  return true;\n }\n K area() const { return a2 / 2; }\n\
    \ // for integer\n K area2() const { return a2; }\n // 1: in, 0: on, -1: out\n\
    \ int where(const P &p) const {\n  assert(dat.size());\n  bool in= false;\n  for\
    \ (int i= dat.size(); i--;) {\n   Point a= dat[i] - p, b= dat[next(i)] - p;\n\
    \   if (a.y > b.y) swap(a, b);\n   int s= sgn(cross(a, b));\n   if (!s && sgn(dot(a,\
    \ b)) <= 0) return 0;\n   if (s < 0 && sgn(a.y) <= 0 && 0 < sgn(b.y)) in= !in;\n\
    \  }\n  return in ? 1 : -1;\n }\n bool in(const Segment<K> &s) const { return\
    \ contain<-1>(s); }\n bool out(const Segment<K> &s) const { return contain<+1>(s);\
    \ }\n friend ostream &operator<<(ostream &os, const Polygon &g) {\n  for (int\
    \ i= 0, e= g.size(); i < e; ++i) os << \"--\" << g[i] << \"-\";\n  return os;\n\
    \ }\n friend Visualizer &operator<<(Visualizer &vis, const Polygon &g) {\n  vis.ofs\
    \ << \"Polygon\" << '\\n';\n  for (const auto &p: g) vis << p;\n  return vis.ofs\
    \ << \"...\" << '\\n', vis;\n }\n};\ntemplate <class K> K dist2(const Polygon<K>\
    \ &g, const Point<K> &p) {\n if (g.where(p) != -1) return 0;\n K ret= numeric_limits<K>::max();\n\
    \ for (const auto &e: g.edges()) ret= min(ret, dist2(e, p));\n return ret;\n}\n\
    template <class K> K dist2(const Point<K> &p, const Polygon<K> &g) { return dist2(g,\
    \ p); }\ntemplate <class K> K dist2(const Polygon<K> &g, const Line<K> &l) {\n\
    \ K ret= numeric_limits<K>::max();\n for (const auto &e: g.edges()) ret= min(ret,\
    \ dist2(e, l));\n return ret;\n}\ntemplate <class K> K dist2(const Line<K> &l,\
    \ const Polygon<K> &g) { return dist2(g, l); }\ntemplate <class K> K dist2(const\
    \ Polygon<K> &g, const Segment<K> &s) {\n if (g.where(s.p) != -1 || g.where(s.q)\
    \ != -1) return 0;\n K ret= numeric_limits<K>::max();\n for (const auto &e: g.edges())\
    \ ret= min(ret, dist2(e, s));\n return ret;\n}\ntemplate <class K> K dist2(const\
    \ Segment<K> &s, const Polygon<K> &g) { return dist2(g, s); }\ntemplate <class\
    \ K> K dist2(const Polygon<K> &g, const Polygon<K> &h) {\n K ret= numeric_limits<K>::max();\n\
    \ for (const auto &e: g.edges()) ret= min(ret, dist2(h, e));\n return ret;\n}\n\
    template <class K> Polygon<K> Affine<K>::operator()(const Polygon<K> &g) {\n vector<Point<K>>\
    \ ps;\n for (const auto &p: g) ps.emplace_back((*this)(p));\n return Polygon(ps);\n\
    }\n}\n"
  code: "#pragma once\n#include \"src/Geometry/Segment.hpp\"\nnamespace geo {\n//\
    \ build counterclockwise\ntemplate <class K> class Polygon {\n using P= Point<K>;\n\
    \ K a2= 0;\nprotected:\n vector<P> dat;\n void build() {\n  if (dat.empty()) return;\n\
    \  a2= cross(dat.back(), dat[0]);\n  for (int i= this->size(); --i;) a2+= cross(dat[i\
    \ - 1], dat[i]);\n  if (a2 < 0) reverse(dat.begin(), dat.end()), a2= -a2;\n }\n\
    \ template <int opp> inline bool contain(const Segment<K> &s) const {\n  assert(dat.size());\n\
    \  if (where(s.p) == opp || where(s.q) == opp) return false;\n  vector<P> ps,\
    \ qs;\n  for (const auto &e: edges())\n   if (auto cp= cross_points(s, e); cp.size())\
    \ ps.insert(ps.end(), cp.begin(), cp.end());\n  if (ps.empty()) return true;\n\
    \  sort(ps.begin(), ps.end()), ps.erase(unique(ps.begin(), ps.end()), ps.end());\n\
    \  for (int i= ps.size(); --i;) qs.emplace_back((ps[i] + ps[i - 1]) / 2);\n  for\
    \ (const auto &q: qs)\n   if (where(q) == opp) return false;\n  return true;\n\
    \ }\npublic:\n Polygon() {}\n Polygon(const vector<P> &ps): dat(ps) { build();\
    \ }\n inline int prev(int i) const { return i ? i - 1 : (int)this->size() - 1;\
    \ }\n inline int next(int i) const { return i + 1 >= (int)this->size() ? 0 : i\
    \ + 1; }\n const P &operator[](int i) const { return dat[i]; }\n auto begin()\
    \ const { return dat.begin(); }\n auto end() const { return dat.end(); }\n size_t\
    \ size() const { return dat.size(); }\n vector<Segment<K>> edges() const {\n \
    \ vector<Segment<K>> es;\n  for (int i= 0, e= dat.size(); i < e; ++i) es.emplace_back(dat[i],\
    \ dat[next(i)]);\n  return es;\n }\n // assuming no self-intersections\n bool\
    \ is_convex() const {\n  assert(dat.size());\n  for (int i= dat.size(); i--;)\n\
    \   if (P a= dat[i], b= a - dat[prev(i)], c= dat[next(i)] - a; sgn(cross(b, c))\
    \ < 0) return false;\n  return true;\n }\n K area() const { return a2 / 2; }\n\
    \ // for integer\n K area2() const { return a2; }\n // 1: in, 0: on, -1: out\n\
    \ int where(const P &p) const {\n  assert(dat.size());\n  bool in= false;\n  for\
    \ (int i= dat.size(); i--;) {\n   Point a= dat[i] - p, b= dat[next(i)] - p;\n\
    \   if (a.y > b.y) swap(a, b);\n   int s= sgn(cross(a, b));\n   if (!s && sgn(dot(a,\
    \ b)) <= 0) return 0;\n   if (s < 0 && sgn(a.y) <= 0 && 0 < sgn(b.y)) in= !in;\n\
    \  }\n  return in ? 1 : -1;\n }\n bool in(const Segment<K> &s) const { return\
    \ contain<-1>(s); }\n bool out(const Segment<K> &s) const { return contain<+1>(s);\
    \ }\n friend ostream &operator<<(ostream &os, const Polygon &g) {\n  for (int\
    \ i= 0, e= g.size(); i < e; ++i) os << \"--\" << g[i] << \"-\";\n  return os;\n\
    \ }\n friend Visualizer &operator<<(Visualizer &vis, const Polygon &g) {\n  vis.ofs\
    \ << \"Polygon\" << '\\n';\n  for (const auto &p: g) vis << p;\n  return vis.ofs\
    \ << \"...\" << '\\n', vis;\n }\n};\ntemplate <class K> K dist2(const Polygon<K>\
    \ &g, const Point<K> &p) {\n if (g.where(p) != -1) return 0;\n K ret= numeric_limits<K>::max();\n\
    \ for (const auto &e: g.edges()) ret= min(ret, dist2(e, p));\n return ret;\n}\n\
    template <class K> K dist2(const Point<K> &p, const Polygon<K> &g) { return dist2(g,\
    \ p); }\ntemplate <class K> K dist2(const Polygon<K> &g, const Line<K> &l) {\n\
    \ K ret= numeric_limits<K>::max();\n for (const auto &e: g.edges()) ret= min(ret,\
    \ dist2(e, l));\n return ret;\n}\ntemplate <class K> K dist2(const Line<K> &l,\
    \ const Polygon<K> &g) { return dist2(g, l); }\ntemplate <class K> K dist2(const\
    \ Polygon<K> &g, const Segment<K> &s) {\n if (g.where(s.p) != -1 || g.where(s.q)\
    \ != -1) return 0;\n K ret= numeric_limits<K>::max();\n for (const auto &e: g.edges())\
    \ ret= min(ret, dist2(e, s));\n return ret;\n}\ntemplate <class K> K dist2(const\
    \ Segment<K> &s, const Polygon<K> &g) { return dist2(g, s); }\ntemplate <class\
    \ K> K dist2(const Polygon<K> &g, const Polygon<K> &h) {\n K ret= numeric_limits<K>::max();\n\
    \ for (const auto &e: g.edges()) ret= min(ret, dist2(h, e));\n return ret;\n}\n\
    template <class K> Polygon<K> Affine<K>::operator()(const Polygon<K> &g) {\n vector<Point<K>>\
    \ ps;\n for (const auto &p: g) ps.emplace_back((*this)(p));\n return Polygon(ps);\n\
    }\n}"
  dependsOn:
  - src/Geometry/Segment.hpp
  - src/Geometry/Line.hpp
  - src/Geometry/Point.hpp
  isVerificationFile: false
  path: src/Geometry/Polygon.hpp
  requiredBy:
  - src/Geometry/Convex.hpp
  - src/Geometry/intersection_area.hpp
  timestamp: '2023-10-10 00:58:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/CGL_7_H.test.cpp
  - test/aoj/1157.test.cpp
  - test/aoj/1242.rational.test.cpp
  - test/aoj/CGL_4_B.test.cpp
  - test/aoj/0375.test.cpp
  - test/aoj/1050.test.cpp
  - test/aoj/2402.test.cpp
  - test/aoj/2514.test.cpp
  - test/aoj/0445.test.cpp
  - test/aoj/1267.test.cpp
  - test/aoj/1198.test.cpp
  - test/aoj/CGL_3_C.test.cpp
  - test/aoj/0253.test.cpp
  - test/aoj/CGL_4_A.test.cpp
  - test/aoj/CGL_3_B.test.cpp
  - test/aoj/1342.test.cpp
  - test/aoj/1066.test.cpp
  - test/aoj/0265.test.cpp
  - test/aoj/3049.test.cpp
  - test/aoj/CGL_7_I.test.cpp
  - test/aoj/CGL_3_A.test.cpp
  - test/aoj/0342.test.cpp
  - test/aoj/2495.test.cpp
  - test/aoj/CGL_4_C.test.cpp
  - test/aoj/2626.test.cpp
  - test/aoj/0356.test.cpp
  - test/aoj/1242.longdouble.test.cpp
  - test/atcoder/abc202_f.test.cpp
documentation_of: src/Geometry/Polygon.hpp
layout: document
title: "\u591A\u89D2\u5F62"
---

## `Polygon<K>` クラス
二次元空間上の多角形を表すクラス. \
頂点が反時計回りになるようにしてある. \
頂点数を $n$ とする.

|メンバ関数|概要|計算量|
|---|---|---|
|`Polygon()`|デフォルトコンストラクタ||
|`Polygon(ps)`|コンストラクタ. <br> 引数として `vector<Point<K>>` で点列を与え, 順に線を結ぶことで多角形を作る. <br> ただし反時計回りになるように頂点を順序づける.|$\mathcal{O}(n)$|
|`prev(i)`|頂点 `i` の (反時計回りで) 一つ前の頂点番号を返す.|$\mathcal{O}(1)$|
|`next(i)`|頂点 `i` の (反時計回りで) 一つ次の頂点番号を返す.|$\mathcal{O}(1)$|
|`operator[](i)`| `i` 番目の頂点を返す.|$\mathcal{O}(1)$|
|`begin()`|頂点列の最初. (範囲for文のため)||
|`end()`|頂点列の最後. (範囲for文のため)||
|`size()`|頂点の数を返す.|$\mathcal{O}(1)$|
|`edges()`| 辺の列を返す. <br> 各辺の端点は多角形の頂点順に並んでいる. <br> 返り値の型は `vector<Segment<K>>`.|$\mathcal{O}(n)$|
|`area()`|多角形の面積を返す.|$\mathcal{O}(1)$|
|`area2()`|多角形の面積の2倍を返す. <br>これは整数のまま扱うことを想定したもの.|$\mathcal{O}(1)$|
|`is_convex()`| 凸多角形なら `true`. <br> 自己交差がある場合は未定義. |$\mathcal{O}(n)$|
|`where(p)`|点 $\boldsymbol{p}$ と多角形の位置関係を表す. <br> +1: 多角形内部: 0: 多角形の周上, -1: 多角形外部. |$\mathcal{O}(n)$|
|`in(s)`|線分 $s$ が多角形内部にあるなら `true`.|$\mathcal{O}(n)$|
|`out(s)`|線分 $s$ が多角形外部にあるなら `true`.|$\mathcal{O}(n)$|


## その他関数

|名前|概要|
|---|---|
|`dist2(g,p)` <br> `dist2(p,g)`| 多角形 $g$ と点 $\boldsymbol{p}$ との距離の二乗. <br>ただし点 $\boldsymbol{p}$ が多角形 $g$ の内部にあるなら 0.|
|`dist2(g,l)` <br> `dist2(l,g)`| 多角形 $g$ と直線 $l$ との距離の二乗. ただし交わるときは 0.|
|`dist2(g,s)` <br> `dist2(s,g)`| 多角形 $g$ と 線分 $s$ との距離の二乗. <br> ただし線分 $s$ が多角形 $g$ の内部にあるときや交わるときは 0.|
|`dist2(g,h)`|多角形 $g,h$ の間の距離の二乗. <br>ただし一方がもう一方の内部にあるときや交わるときは 0.|
