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
    path: src/Geometry/intersection_area.hpp
    title: "\u5186\u3068\u306E\u5171\u901A\u90E8\u5206\u306E\u9762\u7A4D"
  - icon: ':heavy_check_mark:'
    path: src/Geometry/min_enclosing_circle.hpp
    title: "\u6700\u5C0F\u5305\u542B\u5186"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0356.test.cpp
    title: test/aoj/0356.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1047.test.cpp
    title: test/aoj/1047.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1066.test.cpp
    title: test/aoj/1066.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1132.test.cpp
    title: test/aoj/1132.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1183.test.cpp
    title: test/aoj/1183.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1190.test.cpp
    title: test/aoj/1190.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1198.test.cpp
    title: test/aoj/1198.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1342.test.cpp
    title: test/aoj/1342.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2201.test.cpp
    title: test/aoj/2201.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2423.test.cpp
    title: test/aoj/2423.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2495.test.cpp
    title: test/aoj/2495.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/3034.test.cpp
    title: test/aoj/3034.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_A.test.cpp
    title: test/aoj/CGL_7_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_B.test.cpp
    title: test/aoj/CGL_7_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_C.test.cpp
    title: test/aoj/CGL_7_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_D.test.cpp
    title: test/aoj/CGL_7_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_E.test.cpp
    title: test/aoj/CGL_7_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_F.test.cpp
    title: test/aoj/CGL_7_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_G.test.cpp
    title: test/aoj/CGL_7_G.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_H.test.cpp
    title: test/aoj/CGL_7_H.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_I.test.cpp
    title: test/aoj/CGL_7_I.test.cpp
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
    \ }\n}\n#line 3 \"src/Geometry/Circle.hpp\"\nnamespace geo {\ntemplate <class\
    \ R> struct Circle {\n using P= Point<R>;\n P o;\n R r;\n Circle() {}\n Circle(const\
    \ P &o, R r): o(o), r(r) {}\n long double area() const { return r * r * M_PI;\
    \ }\n // +1: in, 0: on, -1: out\n int where(const P &p) const { return sgn(r *\
    \ r - dist2(p, o)); }\n // +1: intersect, 0: contact, -1: disjoint\n int where(const\
    \ Line<R> &l) const { return sgn(r * r - dist2(l, o)); }\n // true: c in *this\n\
    \ bool in(const Circle &c) const {\n  R a= c.r - r;\n  return sgn(a) <= 0 && sgn(dist2(o,\
    \ c.o) - a * a) <= 0;\n }\n vector<Line<R>> tangent(const P &p) const {\n  P d=\
    \ p - o, e= !d;\n  R b= norm2(d), a= b - r * r;\n  if (int s= sgn(a); s < 0) return\
    \ {};\n  else if (s == 0) return {{p, e}};\n  d*= r, e*= sqrt(a);\n  return {Line(p,\
    \ !(d + e)), Line(p, !(d - e))};\n }\n friend ostream &operator<<(ostream &os,\
    \ const Circle &c) { return os << c.o << \" \" << c.r; }\n friend Visualizer &operator<<(Visualizer\
    \ &vis, const Circle &c) { return vis.ofs << \"Circle \" << c.o.x << \" \" <<\
    \ c.o.y << \" \" << c.r << '\\n', vis; }\n};\n// 2: properly intersect, 1: contact,\
    \ 0: disjoint, 3: same\n// counter-clockwise of c and clockwise of d\ntemplate\
    \ <class R> vector<Point<R>> cross_points(const Circle<R> &c, const Circle<R>\
    \ &d) {\n Point v= d.o - c.o;\n R g= norm2(v), a= c.r - d.r, b= c.r + d.r;\n if\
    \ (!sgn(g)) {\n  if (sgn(a)) return {};\n  return {{c.o.x + c.r, c.o.y}, {c.o.x\
    \ - c.r, c.o.y}, {c.o.x, c.o.y + c.r}};\n }\n int in= sgn(g - a * a), out= sgn(g\
    \ - b * b);\n if (in < 0 || out > 0) return {};\n if (!in) return {(c.r * d.o\
    \ - d.r * c.o) / a};\n if (!out) return {(c.r * d.o + d.r * c.o) / b};\n R e=\
    \ (a * b + g) / (g * 2);\n Point q= c.o + e * v, n= !v * sqrt(c.r * c.r / g -\
    \ e * e);\n return {q - n, q + n};\n}\n// 2: properly intersect, 1: contact, 0:\
    \ disjoint\n// direction of l\ntemplate <class R> vector<Point<R>> cross_points(const\
    \ Circle<R> &c, const Line<R> &l) {\n Point<R> v= l.p - c.o;\n R a= norm2(l.d),\
    \ b= dot(l.d, v) / a, d= b * b - (norm2(v) - c.r * c.r) / a;\n int s= sgn(d);\n\
    \ if (s < 0) return {};\n if (!s) return {l.p - b * l.d};\n d= sqrt(d);\n return\
    \ {l.p - (b + d) * l.d, l.p - (b - d) * l.d};\n}\ntemplate <class R> vector<Point<R>>\
    \ cross_points(const Line<R> &l, const Circle<R> &c) { return cross_points(c,\
    \ l); }\ntemplate <class R> vector<Point<R>> cross_points(const Circle<R> &c,\
    \ const Segment<R> &s) {\n Point<R> u= s.q - s.p, v= s.p - c.o;\n R a= norm2(u),\
    \ b= dot(u, v) / a, d= b * b - (norm2(v) - c.r * c.r) / a;\n int t= sgn(d);\n\
    \ if (t < 0) return {};\n if (!t && sgn(b) <= 0 && sgn(1 + b) >= 0) return {s.p\
    \ - b * u};\n d= sqrt(d), a= -b - d, b= -b + d;\n vector<Point<R>> ps;\n if (0\
    \ <= sgn(a) && sgn(a - 1) <= 0) ps.emplace_back(s.p + a * u);\n if (0 <= sgn(b)\
    \ && sgn(b - 1) <= 0) ps.emplace_back(s.p + b * u);\n return ps;\n}\ntemplate\
    \ <class R> vector<Point<R>> cross_points(const Segment<R> &s, const Circle<R>\
    \ &c) { return cross_points(c, s); }\ntemplate <class R> Circle<R> circumscribed_circle(const\
    \ Point<R> &A, const Point<R> &B, const Point<R> &C) {\n Point u= !(B - A), v=\
    \ C - A, o= (A + B + dot(C - B, v) / dot(u, v) * u) / 2;\n return {o, dist(A,\
    \ o)};\n}\ntemplate <class R> Circle<R> inscribed_circle(const Point<R> &A, const\
    \ Point<R> &B, const Point<R> &C) {\n R a= dist(B, C), b= dist(C, A), c= dist(A,\
    \ B), s= (a + b + c) / 2;\n return {(a * A + b * B + c * C) / (s * 2), sqrt((s\
    \ - a) * (s - b) * (s - c) / s)};\n}\ntemplate <class R> vector<Line<R>> common_tangent(const\
    \ Circle<R> &c, const Circle<R> &d) {\n Point u= d.o - c.o, v= !u;\n R g= norm2(u),\
    \ b;\n if (!sgn(g)) return {};  // same origin\n vector<Line<R>> ls;\n for (R\
    \ a: {c.r - d.r, c.r + d.r}) {\n  if (int s= sgn(b= g - a * a); !s) ls.emplace_back(Line(c.o\
    \ + c.r * a / g * u, v));\n  else if (s > 0) {\n   Point x= a / g * u, y= sqrt(b)\
    \ / g * v, e= x + y, f= x - y;\n   ls.emplace_back(Line(c.o + c.r * e, !e)), ls.emplace_back(Line(c.o\
    \ + c.r * f, !f));\n  }\n }\n return ls;\n}\n}\n"
  code: "#pragma once\n#include \"src/Geometry/Segment.hpp\"\nnamespace geo {\ntemplate\
    \ <class R> struct Circle {\n using P= Point<R>;\n P o;\n R r;\n Circle() {}\n\
    \ Circle(const P &o, R r): o(o), r(r) {}\n long double area() const { return r\
    \ * r * M_PI; }\n // +1: in, 0: on, -1: out\n int where(const P &p) const { return\
    \ sgn(r * r - dist2(p, o)); }\n // +1: intersect, 0: contact, -1: disjoint\n int\
    \ where(const Line<R> &l) const { return sgn(r * r - dist2(l, o)); }\n // true:\
    \ c in *this\n bool in(const Circle &c) const {\n  R a= c.r - r;\n  return sgn(a)\
    \ <= 0 && sgn(dist2(o, c.o) - a * a) <= 0;\n }\n vector<Line<R>> tangent(const\
    \ P &p) const {\n  P d= p - o, e= !d;\n  R b= norm2(d), a= b - r * r;\n  if (int\
    \ s= sgn(a); s < 0) return {};\n  else if (s == 0) return {{p, e}};\n  d*= r,\
    \ e*= sqrt(a);\n  return {Line(p, !(d + e)), Line(p, !(d - e))};\n }\n friend\
    \ ostream &operator<<(ostream &os, const Circle &c) { return os << c.o << \" \"\
    \ << c.r; }\n friend Visualizer &operator<<(Visualizer &vis, const Circle &c)\
    \ { return vis.ofs << \"Circle \" << c.o.x << \" \" << c.o.y << \" \" << c.r <<\
    \ '\\n', vis; }\n};\n// 2: properly intersect, 1: contact, 0: disjoint, 3: same\n\
    // counter-clockwise of c and clockwise of d\ntemplate <class R> vector<Point<R>>\
    \ cross_points(const Circle<R> &c, const Circle<R> &d) {\n Point v= d.o - c.o;\n\
    \ R g= norm2(v), a= c.r - d.r, b= c.r + d.r;\n if (!sgn(g)) {\n  if (sgn(a)) return\
    \ {};\n  return {{c.o.x + c.r, c.o.y}, {c.o.x - c.r, c.o.y}, {c.o.x, c.o.y + c.r}};\n\
    \ }\n int in= sgn(g - a * a), out= sgn(g - b * b);\n if (in < 0 || out > 0) return\
    \ {};\n if (!in) return {(c.r * d.o - d.r * c.o) / a};\n if (!out) return {(c.r\
    \ * d.o + d.r * c.o) / b};\n R e= (a * b + g) / (g * 2);\n Point q= c.o + e *\
    \ v, n= !v * sqrt(c.r * c.r / g - e * e);\n return {q - n, q + n};\n}\n// 2: properly\
    \ intersect, 1: contact, 0: disjoint\n// direction of l\ntemplate <class R> vector<Point<R>>\
    \ cross_points(const Circle<R> &c, const Line<R> &l) {\n Point<R> v= l.p - c.o;\n\
    \ R a= norm2(l.d), b= dot(l.d, v) / a, d= b * b - (norm2(v) - c.r * c.r) / a;\n\
    \ int s= sgn(d);\n if (s < 0) return {};\n if (!s) return {l.p - b * l.d};\n d=\
    \ sqrt(d);\n return {l.p - (b + d) * l.d, l.p - (b - d) * l.d};\n}\ntemplate <class\
    \ R> vector<Point<R>> cross_points(const Line<R> &l, const Circle<R> &c) { return\
    \ cross_points(c, l); }\ntemplate <class R> vector<Point<R>> cross_points(const\
    \ Circle<R> &c, const Segment<R> &s) {\n Point<R> u= s.q - s.p, v= s.p - c.o;\n\
    \ R a= norm2(u), b= dot(u, v) / a, d= b * b - (norm2(v) - c.r * c.r) / a;\n int\
    \ t= sgn(d);\n if (t < 0) return {};\n if (!t && sgn(b) <= 0 && sgn(1 + b) >=\
    \ 0) return {s.p - b * u};\n d= sqrt(d), a= -b - d, b= -b + d;\n vector<Point<R>>\
    \ ps;\n if (0 <= sgn(a) && sgn(a - 1) <= 0) ps.emplace_back(s.p + a * u);\n if\
    \ (0 <= sgn(b) && sgn(b - 1) <= 0) ps.emplace_back(s.p + b * u);\n return ps;\n\
    }\ntemplate <class R> vector<Point<R>> cross_points(const Segment<R> &s, const\
    \ Circle<R> &c) { return cross_points(c, s); }\ntemplate <class R> Circle<R> circumscribed_circle(const\
    \ Point<R> &A, const Point<R> &B, const Point<R> &C) {\n Point u= !(B - A), v=\
    \ C - A, o= (A + B + dot(C - B, v) / dot(u, v) * u) / 2;\n return {o, dist(A,\
    \ o)};\n}\ntemplate <class R> Circle<R> inscribed_circle(const Point<R> &A, const\
    \ Point<R> &B, const Point<R> &C) {\n R a= dist(B, C), b= dist(C, A), c= dist(A,\
    \ B), s= (a + b + c) / 2;\n return {(a * A + b * B + c * C) / (s * 2), sqrt((s\
    \ - a) * (s - b) * (s - c) / s)};\n}\ntemplate <class R> vector<Line<R>> common_tangent(const\
    \ Circle<R> &c, const Circle<R> &d) {\n Point u= d.o - c.o, v= !u;\n R g= norm2(u),\
    \ b;\n if (!sgn(g)) return {};  // same origin\n vector<Line<R>> ls;\n for (R\
    \ a: {c.r - d.r, c.r + d.r}) {\n  if (int s= sgn(b= g - a * a); !s) ls.emplace_back(Line(c.o\
    \ + c.r * a / g * u, v));\n  else if (s > 0) {\n   Point x= a / g * u, y= sqrt(b)\
    \ / g * v, e= x + y, f= x - y;\n   ls.emplace_back(Line(c.o + c.r * e, !e)), ls.emplace_back(Line(c.o\
    \ + c.r * f, !f));\n  }\n }\n return ls;\n}\n}"
  dependsOn:
  - src/Geometry/Segment.hpp
  - src/Geometry/Line.hpp
  - src/Geometry/Point.hpp
  isVerificationFile: false
  path: src/Geometry/Circle.hpp
  requiredBy:
  - src/Geometry/intersection_area.hpp
  - src/Geometry/min_enclosing_circle.hpp
  timestamp: '2023-10-10 00:58:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/CGL_7_H.test.cpp
  - test/aoj/2495.test.cpp
  - test/aoj/CGL_7_G.test.cpp
  - test/aoj/0356.test.cpp
  - test/aoj/1190.test.cpp
  - test/aoj/CGL_7_I.test.cpp
  - test/aoj/CGL_7_D.test.cpp
  - test/aoj/1198.test.cpp
  - test/aoj/1342.test.cpp
  - test/aoj/3034.test.cpp
  - test/aoj/CGL_7_F.test.cpp
  - test/aoj/CGL_7_E.test.cpp
  - test/aoj/CGL_7_B.test.cpp
  - test/aoj/1183.test.cpp
  - test/aoj/CGL_7_A.test.cpp
  - test/aoj/CGL_7_C.test.cpp
  - test/aoj/1066.test.cpp
  - test/aoj/2201.test.cpp
  - test/aoj/2423.test.cpp
  - test/aoj/1047.test.cpp
  - test/aoj/1132.test.cpp
documentation_of: src/Geometry/Circle.hpp
layout: document
title: "\u5186"
---

## `Circle<R>` クラス
二次元空間上の円を表すクラス. \
中心を表す `Point<R>` 型のpublicメンバ変数 `o` と半径を表す `R` 型のpublicメンバ変数 `r` を持つ. \
スカラーは浮動小数点数が望ましい.

|メンバ関数|概要|
|---|---|
|`Circle()`|デフォルトコンストラクタ|
|`Circle(o,r)`|コンストラクタ.|
|`area()`| 面積を返す. |
|`where(p)`| 点 $\boldsymbol{p}$ と円の位置関係を表す. <br> +1: 円の内部, 0: 円周上, -1: 円の外部|
|`where(l)`| 直線 $l$ と円の位置関係を表す. <br> +1: 2点で交わる, 0: 接する, -1: 交わらない|
|`in(c)`|円 $c$ がこの円の中に収まるなら `true`|
|`tangent(p)`| 点 $p$ を通る円の接線を全て返す. <br> `Rational` は動かない. <br> 返り値の型は `vector<Line<R>>`|

## その他関数
どれも `Rational` は動かない.

|名前|概要|
|---|---|
|`cross_points(c,d)`|2円 $c,d$ の交点を返す. <br> 通常は交点を2点返すが( $\boldsymbol{p}, \boldsymbol{q}$ の順とする), 円 $c$ の周上を $\boldsymbol{p}\rightarrow\boldsymbol{q}$ と反時計回りに結んだ弧が円 $d$ の内部にあるようにしてある. <br> 円が一致するなら円周上の3点を返す. <br> 接するなら接点1点を返す. <br> 交わらないなら空集合を返す.<br> 返り値の型は `vector<Point<R>>`.|
|`cross_points(c,l)` <br> `cross_points(l,c)`|円 $c$ と直線 $l$ の交点を全て返す. <br> 返り値の型は `vector<Point<R>>`.|
|`cross_points(c,s)` <br> `cross_points(s,c)`|円 $c$ と線分 $s$ の交点を全て返す. <br> 返り値の型は `vector<Point<R>>`.|
|`circumscribed_circle(A,B,C)`| 三角形 $ABC$ の外接円を返す.|
|`inscribed_circle(A,B,C)`| 三角形 $ABC$ の内接円を返す.|
|`common_tangent(c,d)`| 2円 $c,d$ の共通接線を全て返す. <br> 返り値の型は `vector<Line<R>>`|